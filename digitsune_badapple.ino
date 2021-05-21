#include "anims.h"

Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(DISP_WIDTH, DISP_HEIGHT, DISP_PIN, NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel *earPix = new Adafruit_NeoPixel(2, 9, NEO_GRB + NEO_KHZ800);
uint16_t curColor = TEAL;
uint32_t curColor32 = TEAL32;
unsigned char curMovDat[168];

void display_bitmap(uint8_t bmp_num) {
    // Clear prior bitmap first
    matrix->fillScreen(0);
    matrix->drawBitmap(0, 0, bmpDat[bmp_num], 8, 168, curColor);
    matrix->show();
    currentBitmap = bmp_num;
}

void display_bitmap_delay(uint8_t bmp_num, uint16_t time) {
    matrix->fillScreen(0);
    matrix->drawBitmap(0, 0, bmpDat[bmp_num], 8, 168, curColor);
    matrix->show();
    currentBitmap = bmp_num;
    delay(time);
}

void display_movie_bitmap(uint16_t bmp_num) {
    for (int i = 0; i < 160; i++) {
        curMovDat[i+8] = badAppleDat[bmp_num][i];
    }
    // Clear prior bitmap first
    matrix->fillScreen(0);
    matrix->drawBitmap(0, 0, curMovDat, 8, 168, curColor);
    matrix->show();
}

void setEarColor(uint32_t col){
  earPix->fill(col, 0, 2);
  earPix->show();
}

void infoScreen(){
  mode = DISP_MODE_INFO;
  display_bitmap(9);
  infoJingle();
}

void loop() {
  // IR input
  if (! CircuitPlayground.irReceiver.getResults()) {
    return;
  }
  if (!CircuitPlayground.irDecoder.decode()) {
    CircuitPlayground.irReceiver.enableIRIn();
    return;
  }
  #if RMT_DEBUG
    CircuitPlayground.irDecoder.dumpResults(false); // to get buttoncodes
  #endif
  if (!CircuitPlayground.irDecoder.protocolNum == NEC) {
    CircuitPlayground.irReceiver.enableIRIn();
    return;
  }
  
  switch(CircuitPlayground.irDecoder.value){
    case RMT_MAIN:
      modeBlip();
      mode = DISP_MODE_MAIN;
      display_bitmap(1);
      break;
    case RMT_MOVIE:
      modeBlip();
      mode = DISP_MODE_MOVIE;
      for (uint16_t i = 0; i < 877; i++) {
        display_movie_bitmap(i);
        do_song_part(i);
      }
      mode = DISP_MODE_MAIN;
      display_bitmap(1);
      break;
    case RMT_EMOTEHAPPY:
      modeBlip();
      emoteHappy();
      break;
    case RMT_EMOTELAUGH:
      modeBlip();
      emoteLaugh();
      break;
    case RMT_EMOTEERROR:
      modeBlip();
      emoteError();
      break;
    case RMT_EMOTEFLUSHED:
      modeBlip();
      emoteFlushed();
      break;
    case RMT_EMOTEPENSIVE:
      modeBlip();
      emotePensive();
      break;
    case RMT_EMOTEYES:
      modeBlip();
      emoteYes();
      break;
    case RMT_EMOTENO:
      modeBlip();
      emoteNo();
      break;
    case RMT_INFO:
      modeBlip();
      infoScreen();
      break;
    case RMT_COLTEAL:
      modeBlip();
      curColor = TEAL;
      display_bitmap(currentBitmap);
      setEarColor(TEAL32);
      break;
    case RMT_COLPINK:
      modeBlip();
      curColor = PINK;
      display_bitmap(currentBitmap);
      setEarColor(PINK32);
      break;
    case RMT_COLPURPLE:
      modeBlip();
      curColor = PURPLE;
      display_bitmap(currentBitmap);
      setEarColor(PURPLE32);
      break;
    case RMT_COLRED:
      modeBlip();
      curColor = RED;
      display_bitmap(currentBitmap);
      setEarColor(RED32);
      break;
    case RMT_COLGREEN:
      modeBlip();
      curColor = GREEN;
      display_bitmap(currentBitmap);
      setEarColor(GREEN32);
      break;
    case RMT_COLBLUE:
      modeBlip();
      curColor = BLUE;
      display_bitmap(currentBitmap);
      setEarColor(BLUE32);
      break;
    case RMT_COLWHITE:
      modeBlip();
      curColor = WHITE;
      display_bitmap(currentBitmap);
      setEarColor(WHITE32);
      break;
  }
  
  CircuitPlayground.irReceiver.enableIRIn();
}

void setup() {
  #if RMT_DEBUG
    Serial.begin(9600);
  #endif
  CircuitPlayground.begin();
  matrix->begin();
  earPix->begin();
  matrix->setBrightness(DISP_BRIGHTNESS);
  CircuitPlayground.speaker.enable(true);
  CircuitPlayground.irReceiver.enableIRIn();

  #if DISP_DEBUG
    matrix->fillScreen(TEAL);
    matrix->show();
  #else // if not debugging the display, show the boot img and then main
    display_bitmap(0);
    setEarColor(TEAL32);
    happyChirp();
    //sng1();
    delay(1000);
    display_bitmap(1);
  #endif
}
