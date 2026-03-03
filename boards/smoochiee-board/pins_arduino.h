#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

static const uint8_t TX = 1;
static const uint8_t RX = 2;

static const uint8_t SDA = 39;
static const uint8_t SCL = 38;

// Modified elsewhere
static const uint8_t SS = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 13;
static const uint8_t SCK = 12;

#define SERIAL_RX 2
#define SERIAL_TX 1
#define BAD_RX SERIAL_RX
#define BAD_TX SERIAL_TX
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX
#define USB_as_HID 1

#define BTN_ALIAS "\"OK\""
#define HAS_5_BUTTONS
#define SEL_BTN 0
#define UP_BTN 3
#define DW_BTN 8
#define R_BTN 14
#define L_BTN 9
#define BTN_ACT LOW

#define RXLED 4
#define TXLED 5
#define LED_ON HIGH
#define LED_OFF LOW

#define USE_CC1101_VIA_SPI
#define CC1101_GDO0_PIN -1
#define CC1101_GDO2_PIN -1
#define CC1101_SS_PIN 17
#define CC1101_MOSI_PIN SPI_MOSI_PIN
#define CC1101_SCK_PIN SPI_SCK_PIN
#define CC1101_MISO_PIN SPI_MISO_PIN

#define USE_NRF24_VIA_SPI
#define NRF24_CE_PIN 15
#define NRF24_SS_PIN 18
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

#define FP 1
#define FM 2
#define FG 3

#define HAS_SCREEN 1
#define ROTATION 4
#define MINBRIGHT (uint8_t)1

#define USER_SETUP_LOADED 1
#define ST7789_DRIVER 1
#define TFT_RGB_ORDER 0
#define TFT_WIDTH 240
#define TFT_HEIGHT 240
#define TFT_BACKLIGHT_ON 1
#define TFT_BL 42
#define TFT_RST 45
#define TFT_DC 40
#define TFT_MISO -1
#define TFT_MOSI 47
#define TFT_SCLK 21
#define TFT_CS 41
#define TOUCH_CS -1 // SDCARD_CS to make sure SDCard works
#define SMOOTH_FONT 1
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 20000000
#define SPI_TOUCH_FREQUENCY 2500000

#define SDCARD_CS 10
#define SDCARD_SCK 12
#define SDCARD_MISO 13
#define SDCARD_MOSI 11

#define GROVE_SDA 39
#define GROVE_SCL 38

#define SPI_SCK_PIN 12
#define SPI_MOSI_PIN 11
#define SPI_MISO_PIN 13
#define SPI_SS_PIN 10

// RGB LED

#define HAS_RGB_LED 1
#define RGB_LED 45
#define LED_TYPE WS2812B
#define LED_ORDER GRB
#define LED_TYPE_IS_RGBW 0
#define LED_COUNT 16

#define LED_COLOR_STEP 15

#define XPOWERS_CHIP_BQ25896

// USE BOOST ENABLE PMIC 5V OUTPUT
#define USE_BOOST

// Mic#
#define PIN_CLK 5
#define PIN_DATA 6
#define PIN_WS 4

// IO EXPANDER
#define USE_IO_EXPANDER
#define IO_EXPANDER_AW9523
#define IO_EXP_GPS 13
#define IO_EXP_MIC 4
#define IO_EXP_VIBRO 2
#define IO_EXP_CC_RX 7
#define IO_EXP_CC_TX 12
#endif /* Pins_Arduino_h */
