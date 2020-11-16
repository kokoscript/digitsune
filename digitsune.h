#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>
#include "bitmapData.h"
#include "sfx.h"

#define DISP_PIN 10
#define DISP_BRIGHTNESS 4 // Max is 255, but would likely kill the battery
#define DISP_WIDTH 8
#define DISP_HEIGHT 168
#define DISP_DEBUG false

#define TEAL 0b0000011111110000
#define PINK 0b1111100000010000
#define WHITE 0b1111111111111111

#define RMT_MAIN 0x40BF708F
#define RMT_VOICE 0x40BFD02F
#define RMT_EMOTEHAPPY 0x40BFE817
#define RMT_EMOTELAUGH 0x40BF827D
#define RMT_EMOTEERROR 0x40BF02FD
#define RMT_EMOTEFLUSHED 0x40BF42BD
#define RMT_EMOTEPENSIVE 0x40BF22DD
#define RMT_EMOTEYES 0x40BFD22D
#define RMT_EMOTENO 0x40BFF20D
#define RMT_INFO 0x40BFCA35
#define RMT_COLTEAL 0x40BF20DF
#define RMT_COLPINK 0x40BF40BF
#define RMT_COLPURPLE 0x40BFC03F
#define RMT_DEBUG true

enum DISP_MODE {
  DISP_MODE_MAIN,
  DISP_MODE_VOICE,
  DISP_MODE_EMOTEHAPPY,
  DISP_MODE_EMOTELAUGH,
  DISP_MODE_EMOTEERROR,
  DISP_MODE_EMOTEFLUSHED,
  DISP_MODE_EMOTEPENSIVE,
  DISP_MODE_EMOTEYES,
  DISP_MODE_EMOTENO,
  DISP_MODE_INFO
} mode = DISP_MODE_MAIN;

int currentBitmap = 0;

void display_bitmap(uint8_t bmp_num);
void display_bitmap_delay(uint8_t bmp_num, uint16_t time);
