#include "rffc5072.h"
#include "log.h"

#define PRE_CLK_DELAY()		do { \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	} while(0)
#define POST_CLK_DELAY()		do { \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	asm volatile("NOP"); \
	} while(0)

typedef enum {
	REG_LF	= 0x00,
	REG_XO 	= 0x01,
	REG_CAL_TIME = 0x02,
	REG_VCO_CTRL = 0x03,
	REG_CT_CAL1 = 0x04,
	REG_CT_CAL2 = 0x05,
	REG_PLL_CAL1 = 0x06,
	REG_PLL_CAL2 = 0x07,
	REG_VCO_AUTO = 0x08,
	REG_PLL_CTRL = 0x09,
	REG_PLL_BIAS = 0x0A,
	REG_MIX_CONT = 0x0B,
	REG_P1_FREQ1 = 0x0C,
	REG_P1_FREQ2 = 0x0D,
	REG_P1_FREQ3 = 0x0E,
	REG_P2_FREQ1 = 0x0F,
	REG_P2_FREQ2 = 0x10,
	REG_P2_FREQ3 = 0x11,
	REG_FN_CTRL	 = 0x12,
	REG_EXT_MOD = 0x13,
	REG_FMOD = 0x14,
	REG_SDI_CTRL = 0x15,
	REG_GPO = 0x16,
	REG_T_VCO = 0x17,
	REG_IQMOD1 = 0x18,
	REG_IQMOD2 = 0x19,
	REG_IQMOD3 = 0x1A,
	REG_IQMOD4 = 0x1B,
	REG_T_CTRL = 0x1C,
	REG_DEV_CTRL = 0x1D,
	REG_TEST = 0x1E,
	REG_READBACK = 0x1F,
} rffc5072_reg_t;

static inline void pin_low(rffc5072_pin_t pin) {
	pin.gpio->BSRR = pin.pin << 16;
}
static inline void pin_high(rffc5072_pin_t pin) {
	pin.gpio->BSRR = pin.pin;
}
static inline uint8_t pin_read(rffc5072_pin_t pin) {
	if (pin.gpio->IDR & pin.pin) {
		return 1;
	} else {
		return 0;
	}
}
static inline void pin_config_output(rffc5072_pin_t pin) {
	GPIO_InitTypeDef g;
	g.Mode = GPIO_MODE_OUTPUT_PP;
	g.Pin = pin.pin;
	g.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(pin.gpio, &g);
}
static inline void pin_config_input(rffc5072_pin_t pin) {
	GPIO_InitTypeDef g;
	g.Mode = GPIO_MODE_INPUT;
	g.Pull = GPIO_PULLDOWN;
	g.Pin = pin.pin;
	HAL_GPIO_Init(pin.gpio, &g);
}

static void clock_pulse(rffc5072_t *r) {
	PRE_CLK_DELAY();
	pin_high(r->CLK);
	POST_CLK_DELAY();
	pin_low(r->CLK);
}

static void write_reg(rffc5072_t *r, uint8_t addr, uint16_t value) {
	uint32_t data = ((addr & 0x1F) | ((r->slice_address & 0x03) << 5)) << 16
			| value;
	clock_pulse(r);
	clock_pulse(r);
	clock_pulse(r);
	pin_low(r->ENX);
	clock_pulse(r);
	for (uint8_t i = 0; i < 24; i++) {
		if (data & 0x00800000) {
			pin_high(r->DATA);
		} else {
			pin_low(r->DATA);
		}
		clock_pulse(r);
		data <<= 1;
	}
	pin_high(r->ENX);
	clock_pulse(r);
	clock_pulse(r);
	LOG(Log_RFFC5072, LevelDebug, "Wrote 0x%04x to 0x%02x", value, addr);
}

static uint16_t read_reg(rffc5072_t *r, uint8_t addr) {
	uint8_t data = (addr & 0x7F) | ((r->slice_address & 0x03) << 5) | 0x80;
	clock_pulse(r);
	clock_pulse(r);
	clock_pulse(r);
	pin_low(r->ENX);
	clock_pulse(r);
	for (uint8_t i = 0; i < 8; i++) {
		if (data & 0x80) {
			pin_high(r->DATA);
		} else {
			pin_low(r->DATA);
		}
		clock_pulse(r);
		data <<= 1;
	}
	pin_config_input(r->DATA);
	clock_pulse(r);
	uint16_t read = 0;
	for (uint8_t i = 0; i < 16; i++) {
		clock_pulse(r);
		read <<= 1;
		if (pin_read(r->DATA)) {
			read |= 0x01;
		}
	}
	pin_high(r->ENX);
	clock_pulse(r);
	clock_pulse(r);
	pin_config_output(r->DATA);
	LOG(Log_RFFC5072, LevelDebug, "Read 0x%04x from 0x%02x", read, addr);
	return read;
}

static void modify_reg(rffc5072_t *r, uint8_t addr, uint16_t val, uint16_t mask) {
	uint16_t reg = read_reg(r, addr);
	reg &= ~mask;
	reg |= (val & mask);
	write_reg(r, addr, reg);
}

rffc5072_result_t rffc5072_init(rffc5072_t *r) {
	pin_config_output(r->CLK);
	pin_config_output(r->ENX);
	pin_config_output(r->DATA);
	pin_high(r->ENX);
	pin_low(r->CLK);

	// enable addr mode
//	if (r->slice_address != -1) {
		uint8_t s_buf = r->slice_address;
		r->slice_address = 0x00;
		modify_reg(r, REG_SDI_CTRL, 0x0800, 0x0800);
		r->slice_address = s_buf;
//	}

	vTaskDelay(10);

	for(uint8_t i=0;i<=0x1E;i++){
		read_reg(r, i);
	}

	// check for device ID
	modify_reg(r, REG_DEV_CTRL, 0x0000, 0xF000);
	uint16_t device_id = read_reg(r, REG_READBACK);
	if (device_id != 0x8A01) {
		LOG(Log_RFFC5072, LevelError,
				"Failed to initialize slice 0x%02x, wrong device id (0x%04x!=0x8A01)",
				r->slice_address, device_id);
		return RFFC5072_RES_ERROR;
	}

	// set recommended default values
	modify_reg(r, REG_P2_FREQ1, 0x0000, 0x0003); // P2_FREQ1:p2vcosel=0
	modify_reg(r, REG_VCO_AUTO, 0x7F00, 0x7FFE); // VCO_AUTO:ct_min=0,ct_max=127
	modify_reg(r, REG_CT_CAL1, 0x0C00, 0x1F00); // CT_CAL1:p1ctv = 12
	modify_reg(r, REG_CT_CAL2, 0x0C00, 0x1F00); // CT_CAL2:p2ctv = 12
	modify_reg(r, REG_TEST, 0x0004, 0x0004); // TEST:rgbyp = 1

	// enable control via 3-wire bus
	modify_reg(r, REG_SDI_CTRL, 0x8000, 0x8000);

	// set mixer current to approx. midrange
	modify_reg(r, REG_MIX_CONT, 0x4800, 0x7E00);

	// route lock signal to GPO4
	write_reg(r, REG_GPO, 0x0003);

	// set lowest frequency possible
	rffc5072_set_LO(r, 85000000);

	LOG(Log_RFFC5072, LevelInfo, "Initialized slice 0x%02x", r->slice_address);
	return RFFC5072_RES_OK;
}

rffc5072_result_t rffc5072_set_LO(rffc5072_t *r, uint32_t freq) {
	if(freq < 85000000 || freq > 4200000000) {
		return RFFC5072_RES_ERROR;
	}
	log_flush();
	// calculate LO divider
	uint32_t lo_div = 5400000000ULL / freq;
	// round down to nearest power of 2
	uint8_t power = 31 - __builtin_clz(lo_div);
	lo_div = 0x01UL << power;
	uint64_t f_vco = (uint64_t) freq * lo_div;
	uint8_t fbk_div = f_vco < 3200000000 ? 2 : 4;
	uint64_t n_div = ((f_vco << 24) / fbk_div) / r->RefCLKFreq;
	LOG(Log_RFFC5072, LevelDebug,
			"Setting frequency: %lu (lo_div: %d, f_vco: %lu%09lu, fbk_div: %d, n_div: %lu%09lu",
			freq, lo_div, (uint32_t ) (f_vco / 1000000000),
			(uint32_t ) (f_vco % 1000000000), fbk_div,
			(uint32_t ) (n_div / 1000000000), (uint32_t ) (n_div % 1000000000));
	uint16_t freq1 = ((n_div >> 24) << 7) | (power << 4)
			| ((fbk_div >> 1) << 2);
	uint16_t freq2 = (n_div >> 8) & 0xFFFF;
	uint16_t freq3 = (n_div & 0xFF) << 8;
	write_reg(r, REG_P2_FREQ1, freq1);
	write_reg(r, REG_P2_FREQ2, freq2);
	write_reg(r, REG_P2_FREQ3, freq3);

	return RFFC5072_RES_OK;
}

rffc5072_result_t rffc5072_enabled(rffc5072_t *r, uint8_t enabled) {
	if (enabled) {
		modify_reg(r, REG_SDI_CTRL, 0x6000, 0x6000);
	} else {
		modify_reg(r, REG_SDI_CTRL, 0x2000, 0x6000);
	}
	return RFFC5072_RES_OK;
}

rffc5072_result_t rffc5072_locked(rffc5072_t *r) {
	modify_reg(r, REG_DEV_CTRL, 0x1000, 0xF000);
	uint16_t readback = read_reg(r, REG_READBACK);
	if (readback & 0x8000) {
		return RFFC5072_RES_OK;
	} else {
		return RFFC5072_RES_ERROR;
	}
}
