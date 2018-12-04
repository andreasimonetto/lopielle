#include <xc.h>
#include <stdint.h>
#include <string.h>
#include "mcc_generated_files/mcc.h"

uint8_t sprintn(char* buf, uint8_t n)
{
char *p = buf;

    if(n < 10)
        goto sprintn_unit;
    else if(n < 100)
        goto sprintn_dec;

    *p++ = '0' + (n / 100);
    n %= 100;
    
    sprintn_dec:
    *p++ = '0' + (n / 10);
    n %= 10;
    
    sprintn_unit:
    *p++ = '0' + n;
    
    return (p - buf);
}

#define OPLL_ADDR_USER_TONE      0x00
#define OPLL_ADDR_RHYTHM_CTL     0x0E
#define OPLL_ADDR_TEST           0x0F
#define OPLL_ADDR_OPLL_FNUM_LSB  0x10
#define OPLL_ADDR_OPLL_FNUM_MSB  0x20
#define OPLL_ADDR_INST           0x30
#define OPLL_ADDR_RHYTHM_VOL     0x36

typedef struct {
    uint8_t am      : 1;
    uint8_t vib     : 1;
    uint8_t eg_type : 1;
    uint8_t ksr     : 1;
    uint8_t multi   : 4;
} opll_mult_factor_t;

typedef struct {
    uint8_t attack_rate : 4;
    uint8_t decay_rate  : 4;
} opll_AD_t;

typedef struct {
    uint8_t sustain_level : 4;
    uint8_t release_rate  : 4;
} opll_SR_t;

typedef struct {
    uint8_t _padding : 2;
    uint8_t sustain  : 1;
    uint8_t key      : 1;
    uint8_t block    : 3;
    uint8_t fnum     : 1;
} opll_block_t;

typedef struct {
    uint8_t inst : 4;
    uint8_t vol  : 4; // 3dB, 6dB, 12dB, 24dB
} opll_inst_t;


enum {
    OPLL_INST_USER,
    OPLL_INST_VIOLIN,
    OPLL_INST_GUITAR,
    OPLL_INST_PIANO,
    OPLL_INST_FLUTE,
    OPLL_INST_CLARINET,
    OPLL_INST_OBOE,
    OPLL_INST_TRUMPET,
    OPLL_INST_ORGAN,
    OPLL_INST_HORN,
    OPLL_INST_SYNTH,
    OPLL_INST_HARP,
    OPLL_INST_VIBRAPHONE,
    OPLL_INST_BASS_SYNTH,
    OPLL_INST_BASS_ACOUSTIC,
    OPLL_INST_GUITAR_ELECTRIC
};

const char SYNTH_INSTRUMENT_DESC[][12] = {
    "User",
    "Violin",
    "Guitar",
    "Piano",
    "Flute",
    "Clarinet",
    "Oboe",
    "Trumpet",
    "Organ",
    "Horn",
    "Synth",
    "Harp",
    "Vibraphone",
    "Bass synth",
    "Bass acoust",
    "Elec guitar"
};

// OPLL@4MHz
const uint16_t OPLL_FNUM[12] = { 154, 163, 173, 184, 194, 206, 218, 231, 245, 260, 275, 291 };

#define opll_enable() OPLL_CS_SetLow()
#define opll_disable() OPLL_CS_SetHigh()

void opll_reset(void)
{
    OPLL_WE_SetHigh();
    OPLL_CS_SetHigh();
    OPLL_IC_SetLow();
    __delay_us(20);
    OPLL_IC_SetHigh();
}

void opll_write(uint8_t addr, uint8_t val)
{
    // Address
    OPLL_A0_SetLow();
    OPLL_WE_SetLow();
    PORTB = addr;
    OPLL_CS_SetLow();
    OPLL_CS_SetHigh();
    OPLL_WE_SetHigh();
    __delay_us(3);
    
    // Data
    OPLL_A0_SetHigh();
    OPLL_WE_SetLow();
    PORTB = val;
    OPLL_CS_SetLow();
    OPLL_CS_SetHigh();
    OPLL_WE_SetHigh();
    __delay_us(12);
}

typedef struct {
    uint8_t channel;
    uint8_t instrument;
    opll_AD_t modulator_ad;
    opll_AD_t carrier_ad;
    opll_SR_t modulator_sr;
    opll_SR_t carrier_sr;
} synth_t;

enum {
    SYNTH_PARAM_CHANNEL,
    SYNTH_PARAM_INSTRUMENT,
    SYNTH_PARAM_CARRIER_ATTACK,
    SYNTH_PARAM_CARRIER_DECAY,
    SYNTH_PARAM_CARRIER_SUSTAIN,
    SYNTH_PARAM_CARRIER_RELEASE,
    SYNTH_PARAM_MODULATOR_ATTACK,
    SYNTH_PARAM_MODULATOR_DECAY,
    SYNTH_PARAM_MODULATOR_SUSTAIN,
    SYNTH_PARAM_MODULATOR_RELEASE
};

static const char SYNTH_PARAM_DESC[][13] = {
    "Channel",
    "Inst",
    "Car. attack",
    "Car. decay",
    "Car. sustain",
    "Car. release",
    "Mod. attack",
    "Mod. decay",
    "Mod. sustain",
    "Mod. release"
};

typedef struct {
    uint8_t key;
    uint8_t prio    : 4;
    uint8_t _unused : 3;
    uint8_t on      : 1;
} chan_t;

#define CHANNELS_NUM 8

static chan_t chan[CHANNELS_NUM];
static synth_t synth = { 0, OPLL_INST_PIANO };

void opll_play(uint8_t key, uint8_t vel)
{
uint16_t n;
uint8_t i, ch, oct;

    if(key >= 12)
        key -= 12;

    n = OPLL_FNUM[key % 12];

    oct = key / 12;
    if(oct > 7)
        oct = 7;    
    oct = (oct << 1) | (n >> 8);
    
    vel >>= 3;

    for(ch = 0; ch < CHANNELS_NUM; ++ch) {
        if(chan[ch].key == key)
            break;
    }
    
    if(vel) {
        if(ch == CHANNELS_NUM) {
            for(ch = 0; ch < CHANNELS_NUM; ++ch) {
                if(!chan[ch].prio)
                    break;
            }
        }
        
        chan[ch].on = 1;
        chan[ch].key = key;
        
        opll_write(OPLL_ADDR_OPLL_FNUM_MSB + ch, 0);
        opll_write(OPLL_ADDR_INST + ch, (synth.instrument << 4) | (~vel & 0xf));
        opll_write(OPLL_ADDR_OPLL_FNUM_LSB + ch, (uint8_t)n);
        opll_write(OPLL_ADDR_OPLL_FNUM_MSB + ch, 0x10 | oct);
        
        for(i = 0; i < CHANNELS_NUM; ++i) {
            if(chan[i].prio)
                --chan[i].prio;
        }
    }
    else if(ch != CHANNELS_NUM && chan[ch].on) {
        for(i = 0; i < CHANNELS_NUM; ++i) {
            if(chan[i].prio > chan[ch].prio)
                --chan[i].prio;
        }

        chan[ch].on = 0;
        
        opll_write(OPLL_ADDR_OPLL_FNUM_MSB + ch, 0x00 | oct);
    }
    else
        return;
    
    chan[ch].prio = CHANNELS_NUM - 1;
}






#define DPY_FRAMEBUF_SIZE 32

static volatile char dpy_framebuf[DPY_FRAMEBUF_SIZE] = {
    ' ', ' ', ' ', ' ', 'L', 'a', 'z', 'y', ' ', '\'', '8', '8', ' ', ' ', ' ', ' ', 
    ' ', 'a', 's', 'd', 'r', 'e', 'a', ' ', '@', ' ', '2', '0', '1', '8', ' ', 0xbc
};
static volatile uint8_t dpy_need_update = 0;

void dpy_write_instruction(uint8_t x)
{
    OPLL_WE_SetLow(); // RW: Write
    OPLL_A0_SetLow(); // RS: Instruction
    LATB = x;
    DPY_CS_SetHigh();
    NOP(); NOP(); NOP(); NOP(); NOP();
    DPY_CS_SetLow();
    OPLL_WE_SetHigh(); // RW: Read (default)
    __delay_us(1);
}

void dpy_write_data(uint8_t x)
{
    OPLL_WE_SetLow(); // RW: Write
    OPLL_A0_SetHigh(); // RS: Data
    LATB = x;
    DPY_CS_SetHigh();
    NOP(); NOP(); NOP(); NOP(); NOP();
    DPY_CS_SetLow();
    OPLL_WE_SetHigh(); // RW: Read (default)
    __delay_us(1);
}

void dpy_reset(void)
{
    dpy_write_instruction(0x3f);
    __delay_us(37);

    dpy_write_instruction(0x01);
    __delay_ms(2);
    
    dpy_write_instruction(0x0c);
    __delay_us(37);
}

void dpy_cursor_show()
{
    dpy_write_instruction(0x0d);
    __delay_us(37);
}

void dpy_cursor_hide()
{
    dpy_write_instruction(0x0c);
    __delay_us(37);
}

void dpy_cursor_move(uint8_t row, uint8_t col)
{
    dpy_write_instruction(0x80 | (40 * row + col));
    __delay_us(37);
}

void dpy_update()
{
uint8_t i;
char c;

    dpy_write_instruction(0x80);
    __delay_us(37);
    for(i = 0; i < 16; ++i) {
        if(!(c = dpy_framebuf[i]))
            c = ' ';
        dpy_write_data(c);
        __delay_us(37);
    }

    dpy_write_instruction(0xa8);
    __delay_us(37);
    for(; i < 32; ++i) {
        if(!(c = dpy_framebuf[i]))
            c = ' ';
        dpy_write_data(c);
        __delay_us(37);
    }
}













enum {
    CTL_ENCODER_A       = 0x01,
    CTL_ENCODER_B       = 0x02,
    CTL_ENCODER_BUTTON  = 0x04,
    CTL_BUTTON1         = 0x08,
    CTL_BUTTON2         = 0x10,
    CTL_BUTTON3         = 0x20,
    CTL_BUTTON4         = 0x40
};

static volatile uint8_t ctl_status_prev, ctl_status;
static volatile uint8_t button_press_ms[4];

#define ctl_changed(ctl) ((ctl_status & (ctl)) != (ctl_status_prev & (ctl)))
#define ctl_button_isup(ctl) (ctl_status & (ctl))
#define ctl_button_isdown(ctl) (!ctl_button_isup(ctl))
#define ctl_button_released(ctl) (ctl_changed(ctl) && ctl_button_isup(ctl))
#define ctl_button_pressed(ctl) (ctl_changed(ctl) && ctl_button_isdown(ctl))

void ctl_status_update(void)
{
uint8_t i;

    ctl_status = 0;
    for(i = 0; i < 8; ++i) {
        LATA = (LATA & 0xf8) | i;
        NOP(); NOP(); NOP(); NOP();
        ctl_status |= (CTL_DATA_GetValue() << i);
    }
}

void ctl_status_reset(void)
{
    ctl_status_update();
    ctl_status_prev = ctl_status;
}

extern volatile uint8_t timer0ReloadVal;

static volatile uint8_t synth_param_cur = 0;
static volatile uint8_t synth_param_editing = 0;

#define SYNTH_PARAMS_NUM 10


















uint8_t synth_param_change(uint8_t param, int8_t amount)
{
uint8_t d;

    switch(param) {
        case SYNTH_PARAM_CHANNEL:
            d = synth.channel + amount;
            if(d >= 16)
                return 0;
            synth.channel = d;
            return 1;

        case SYNTH_PARAM_INSTRUMENT:
            d = synth.instrument + amount;
            if(d >= 16)
                return 0;
            synth.instrument = d;
            return 1;

        case SYNTH_PARAM_CARRIER_ATTACK:
            d = synth.carrier_ad.attack_rate + amount;
            if(d >= 16)
                return 0;
            synth.carrier_ad.attack_rate = d;
            return 1;

        case SYNTH_PARAM_CARRIER_DECAY:
            d = synth.carrier_ad.decay_rate + amount;
            if(d >= 16)
                return 0;
            synth.carrier_ad.decay_rate = d;
            return 1;

        case SYNTH_PARAM_CARRIER_SUSTAIN:
            d = synth.carrier_sr.sustain_level + amount;
            if(d >= 16)
                return 0;
            synth.carrier_sr.sustain_level = d;
            return 1;

        case SYNTH_PARAM_CARRIER_RELEASE:
            d = synth.carrier_sr.release_rate + amount;
            if(d >= 16)
                return 0;
            synth.carrier_sr.release_rate = d;
            return 1;

        case SYNTH_PARAM_MODULATOR_ATTACK:
            d = synth.modulator_ad.attack_rate + amount;
            if(d >= 16)
                return 0;
            synth.modulator_ad.attack_rate = d;
            return 1;

        case SYNTH_PARAM_MODULATOR_DECAY:
            d = synth.modulator_ad.decay_rate + amount;
            if(d >= 16)
                return 0;
            synth.modulator_ad.decay_rate = d;
            return 1;
            
        case SYNTH_PARAM_MODULATOR_SUSTAIN:
            d = synth.modulator_sr.sustain_level + amount;
            if(d >= 16)
                return 0;
            synth.modulator_sr.sustain_level = d;
            return 1;

        case SYNTH_PARAM_MODULATOR_RELEASE:
            d = synth.modulator_sr.release_rate + amount;
            if(d >= 16)
                return 0;
            synth.modulator_sr.release_rate = d;
            return 1;
    }
    
    return 0;
}

uint8_t synth_param_snprint(char* buf, uint8_t buf_len, uint8_t param)
{
uint8_t d1, d2;
const char *desc = SYNTH_PARAM_DESC[param];
uint8_t d = strlen(desc);

    memcpy(buf, desc, d);
    buf[d++] = ' ';
    d1 = d;
    
    switch(param) {
        case SYNTH_PARAM_CHANNEL:
            d += sprintn(buf + d, synth.channel);
            break;

        case SYNTH_PARAM_INSTRUMENT:
            desc = SYNTH_INSTRUMENT_DESC[synth.instrument];
            d2 = strlen(desc);
            memcpy(buf + d, desc, d2);
            d += d2;
            break;

        case SYNTH_PARAM_CARRIER_ATTACK:
            d += sprintn(buf + d, synth.carrier_ad.attack_rate);
            break;

        case SYNTH_PARAM_CARRIER_DECAY:
            d += sprintn(buf + d, synth.carrier_ad.decay_rate);
            break;

        case SYNTH_PARAM_CARRIER_SUSTAIN:
            d += sprintn(buf + d, synth.carrier_sr.sustain_level);
            break;

        case SYNTH_PARAM_CARRIER_RELEASE:
            d += sprintn(buf + d, synth.carrier_sr.release_rate);
            break;

        case SYNTH_PARAM_MODULATOR_ATTACK:
            d += sprintn(buf + d, synth.modulator_ad.attack_rate);
            break;

        case SYNTH_PARAM_MODULATOR_DECAY:
            d += sprintn(buf + d, synth.modulator_ad.decay_rate);
            break;

        case SYNTH_PARAM_MODULATOR_SUSTAIN:
            d += sprintn(buf + d, synth.modulator_sr.sustain_level);
            break;

        case SYNTH_PARAM_MODULATOR_RELEASE:
            d += sprintn(buf + d, synth.modulator_sr.release_rate);
            break;
    }
    
    while(d < buf_len)
        buf[d++] = ' ';
    return d1;
}

void TMR0_ISR(void)
{
int8_t ctl_encoder_dir = 0;
uint8_t i;

    INTCONbits.TMR0IF = 0;
    TMR0 = timer0ReloadVal;

    ctl_status_prev = ctl_status;
    ctl_status_update();
    
    for(i = 0; i < 4; ++i) {
        if(!button_press_ms[i])
            continue;
        ++button_press_ms[i];
    }

    if((ctl_changed(CTL_ENCODER_A) || ctl_changed(CTL_ENCODER_B)) && (ctl_status & 0x3) == 0) {
        if((ctl_status_prev & 0x3) == 1)
            ctl_encoder_dir = -1;
        else if((ctl_status_prev & 0x3) == 2)
            ctl_encoder_dir = 1;
    }
    
    if(ctl_encoder_dir) {
        if(synth_param_editing) {
            if(synth_param_change(synth_param_cur, ctl_encoder_dir))
                dpy_need_update = 1;
        }
        else if((ctl_encoder_dir > 0 && synth_param_cur < (SYNTH_PARAMS_NUM - 1)) || (ctl_encoder_dir < 0 && synth_param_cur > 0)) {
            synth_param_cur += ctl_encoder_dir;
            dpy_need_update = 1;
        }
    }
    
    if(ctl_button_pressed(CTL_ENCODER_BUTTON)) {
        synth_param_editing = !synth_param_editing;
        dpy_need_update = 1;
    }
        
    if(ctl_button_pressed(CTL_BUTTON1)) {
        button_press_ms[0] = 1;
    }
    else if(ctl_button_released(CTL_BUTTON1)) {
        button_press_ms[0] = 0;
    }
}
  
//void PIN_MANAGER_IOC(void)
//{   
//	// Interrupt on change for pin PWR_BTN
//    if(IOCAFbits.IOCAF5) {
//        AMP_OE_SetDigitalOutput();
//        AMP_PWR_SetLow();
//        IOCAFbits.IOCAF5 = 0;
//    }	
//}


void main(void)
{
uint8_t msg = 0, midi_data_len = 0;
uint8_t d, cur_col, midi_data[8];

    SYSTEM_Initialize();
    __delay_ms(5);

    AMP_PWR_SetHigh();
    
    dpy_reset();
    dpy_update();
    __delay_ms(1000);
    dpy_need_update = 1;
    
    opll_reset();
    ctl_status_reset();
    
    AMP_OE_SetDigitalInput();
    IOCAFbits.IOCAF5 = 0;
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    //opll_write(0, 0x20);
    //opll_write(1, 0x20);
    //opll_write(6, 0xf0);
    //opll_write(7, 0xf0);
    
    while(1) {
        if(dpy_need_update) {
            cur_col = synth_param_snprint((char*)dpy_framebuf, DPY_FRAMEBUF_SIZE / 2, synth_param_cur);
            if(!synth_param_editing)
                cur_col = 0;
            
            if(synth_param_cur < (SYNTH_PARAMS_NUM - 1))
                synth_param_snprint((char*)dpy_framebuf + DPY_FRAMEBUF_SIZE / 2, DPY_FRAMEBUF_SIZE / 2, synth_param_cur + 1);
            else
                memset((void*)(dpy_framebuf + DPY_FRAMEBUF_SIZE / 2), ' ', DPY_FRAMEBUF_SIZE / 2);

            dpy_cursor_hide();
            dpy_update();
            dpy_cursor_move(0, cur_col);
            dpy_cursor_show();
            dpy_need_update = 0;
            
            opll_write(0x2, 36);
            opll_write(0x3, 41);
            opll_write(0x4, *((uint8_t*)&synth.modulator_ad));
            opll_write(0x5, *((uint8_t*)&synth.carrier_ad));
            opll_write(0x6, *((uint8_t*)&synth.modulator_sr));
            opll_write(0x7, *((uint8_t*)&synth.carrier_sr));
        }
            
        if(!EUSART_is_rx_ready())
            continue;

        d = EUSART_Read();
        if((d >> 7)) {
            midi_data_len = 0;
            
            if((d & 0xf) == synth.channel)
                msg = (d >> 4);
            else
                msg = 0;

            continue;
        }
        
        midi_data[midi_data_len++] = d;

        switch(msg) {
            case 0b1000: // Note off
                if(midi_data_len != 2)
                    break;

                opll_play(midi_data[0], 0);
                midi_data_len = 0;
                break;
            case 0b1001: // Note on
                if(midi_data_len != 2)
                    break;

                opll_play(midi_data[0], midi_data[1]);
                midi_data_len = 0;
                break;
        }
    }
}
