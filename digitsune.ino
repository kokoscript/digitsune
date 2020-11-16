#include "anims.h"

Adafruit_NeoMatrix *matrix = new Adafruit_NeoMatrix(DISP_WIDTH, DISP_HEIGHT, DISP_PIN, NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG, NEO_GRB + NEO_KHZ800);
uint16_t curColor = TEAL;

void display_bitmap(uint8_t bmp_num) {
    // Clear prior bitmap first
    matrix->fillScreen(0);
    matrix->drawBitmap(0, 0, bmpDat[bmp_num], 8, 168, curColor);
    matrix->show();
    currentBitmap = bmp_num;
}

void display_bitmap_delay(uint8_t bmp_num, uint16_t time){
    matrix->fillScreen(0);
    matrix->drawBitmap(0, 0, bmpDat[bmp_num], 8, 168, curColor);
    matrix->show();
    currentBitmap = bmp_num;
    delay(time);
}

// Measurepeak function 
float measurePeak(uint32_t milliseconds) {
  float soundMax = 0;
  // Loop until the specified number of milliseconds have ellapsed.
  uint32_t start = millis();
  uint32_t current = start;
  while ((current - start) < milliseconds) {
    // Inside the loop check the sound pressure level 10ms at a time
    float sample = CircuitPlayground.mic.soundPressureLevel(10);
    //Serial.println(sample);
    soundMax = max(sample, soundMax);
    current = millis();
  }
  return soundMax;
}

void infoScreen(){
  mode = DISP_MODE_INFO;
  display_bitmap(9);
  infoJingle();
}

void loop() {
  // Voice mode display update
  if(mode == DISP_MODE_VOICE){
    float current = measurePeak(25);
    if(current > 62.41 && current <= 64.91){
      display_bitmap(2);
    }
    else if(current > 64.91 && current <= 66.85){
      display_bitmap(3);
    }
    else if(current > 66.85 && current <= 75.79){
      display_bitmap(4);
    }
    else if(current > 75.79){
      display_bitmap(5);
    }
    else {
      display_bitmap(1);
    }
    delay(25);
  }

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
    case RMT_VOICE:
      modeBlip();
      mode = DISP_MODE_VOICE;
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
      //emoteHappy();
      break;
    case RMT_EMOTENO:
      modeBlip();
      //emoteHappy();
      break;
    case RMT_INFO:
      modeBlip();
      infoScreen();
      break;
    case RMT_COLTEAL:
      modeBlip();
      curColor = TEAL;
      display_bitmap(currentBitmap);
      break;
    case RMT_COLPINK:
      modeBlip();
      curColor = PINK;
      display_bitmap(currentBitmap);
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
  matrix->setBrightness(DISP_BRIGHTNESS);
  CircuitPlayground.speaker.enable(true);
  CircuitPlayground.irReceiver.enableIRIn();
  
  #if DISP_DEBUG
    matrix->fillScreen(TEAL);
    matrix->show();
  #else // if not debugging the display, show the boot img and then main
    display_bitmap(0);
    happyChirp();
    //sng1();
    delay(1000);
    display_bitmap(1);
  #endif
}

// Acknowledgements:
// measurepeak function, under the MIT License
// from https://github.com/adafruit/Adafruit_CircuitPlayground/blob/master/examples/Microphone_Demos/Birthday_Candles/Birthday_Candles.ino:
/* Copyright Tony DiCola

   Permission is hereby granted, free of charge, to any person obtaining a copy of this software
   and associated documentation files (the "Software"), to deal in the Software without restriction,
   including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
   subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all copies or substantial
   portions of the Software.
*/
