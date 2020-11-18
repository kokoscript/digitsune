#include "digitsune.h"

void emoteHappy() {
  mode = DISP_MODE_EMOTEHAPPY;
  for(int i = 0; i < 4; i++){
    switch(i){
      case 0:
      case 2:
        display_bitmap_delay(6, 60);
        break;
      case 1:
        display_bitmap_delay(7, 60);
        break;
      case 3:
        display_bitmap(5);
        happyChirp();
        break;
      default:
        display_bitmap_delay(0, 100);
        break;
    }
  }
}

void emoteLaugh() {
  mode = DISP_MODE_EMOTELAUGH;
  for(int i = 0; i < 11; i++){
    switch(i){
      case 0:
        display_bitmap(10);
        delay(75);
        break;
      case 1:
        display_bitmap(11);
        delay(75);
        break;
      case 2:
        display_bitmap_delay(12, 30);
        CircuitPlayground.playTone(1500, 35);
        break;
      case 4:
        display_bitmap_delay(12, 30);
        CircuitPlayground.playTone(1250, 35);
        break;
      case 6:
        display_bitmap_delay(12, 30);
        CircuitPlayground.playTone(1350, 35);
        break;
      case 8:
        display_bitmap_delay(12, 30);
        CircuitPlayground.playTone(1150, 35);
        break;
      case 10:
        display_bitmap_delay(12, 30);
        CircuitPlayground.playTone(875, 35);
        break;
      case 3:
      case 5:
      case 7:
      case 9:
        display_bitmap_delay(13, 90);
        break;
      default:
        display_bitmap_delay(0, 100);
        break;
    }
  }
}

void emoteError() {
  mode = DISP_MODE_EMOTEERROR;
  for(int i = 0; i < 7; i++){
    switch(i){
      case 0:
      case 2:
        display_bitmap_delay(6, 60);
        break;
      case 1:
        display_bitmap_delay(7, 60);
        break;
      case 3:
        display_bitmap_delay(14, 60);
        break;
      case 4:
        display_bitmap(15);
        errChirp();
        break;
      case 5:
        display_bitmap(16);
        errChirp();
        break;
      case 6:
        display_bitmap(17);
        errChirp();
        break;
      default:
        display_bitmap_delay(0, 100);
        break;
    }
  }
}

void emoteFlushed() {
  mode = DISP_MODE_EMOTEFLUSHED;
  for(int i = 0; i < 10; i++){
    switch(i){
      case 0:
        display_bitmap_delay(8, 200);
        break;
      case 1:
        display_bitmap_delay(18, 1000);
        break;
      case 2:
      case 4:
      case 6:
      case 8:
        display_bitmap_delay(19, 45);
        break;
      case 3:
      case 7:
        display_bitmap_delay(20, 35);
        blinkSnd();
        break;
      case 5:
        display_bitmap_delay(18, 80);
      case 9:
        display_bitmap(18);
        break;
      default:
        display_bitmap_delay(0, 100);
        break;
    }
  }
}

void emotePensive() {
  mode = DISP_MODE_EMOTEPENSIVE;
  for(int i = 0; i < 8; i++){
    switch(i){
      case 0:
        display_bitmap_delay(8, 200);
        break;
      case 1:
        display_bitmap_delay(21, 1000);
        break;
      case 2:
        display_bitmap_delay(22, 80);
        break;
      case 3:
        display_bitmap_delay(23, 80);
        break;
      case 4:
        display_bitmap(24);
        sighIn();
        delay(780);
        break;
      case 5:
        display_bitmap_delay(25, 80);
        break;
      case 6:
        sighOut();
        display_bitmap_delay(22, 80);
        break;
      case 7:
        display_bitmap(21);
        break;
      default:
        display_bitmap_delay(0, 100);
        break;
    }
  }
}

void emoteYes() {
  mode = DISP_MODE_EMOTEYES;
  for(int i = 0; i < 13; i++){
    switch(i){
      case 0:
      case 4:
      case 8:
      case 12:
        display_bitmap(1);
        if(i == 0 || i == 4 || i == 8) ynSnd1();
        break;
      case 1:
      case 3:
      case 5:
      case 7:
      case 9:
      case 11:
        display_bitmap_delay(26, 80);
        break;
      case 2:
      case 6:
      case 10:
        display_bitmap(27);
        ynSnd2();
        break;
      default:
        display_bitmap_delay(0, 100);
        break;
    }
  }
}


void emoteNo() {
  mode = DISP_MODE_EMOTENO;
  for(int i = 0; i < 17; i++){
    switch(i){
      case 0:
      case 4:
      case 8:
      case 12:
      case 16:
        display_bitmap_delay(30, 50);
        break;
      case 1:
      case 3:
      case 9:
      case 11:
        display_bitmap_delay(29, 50);
        break;
      case 2:
      case 10:
        display_bitmap(28);
        ynSnd2();
        break;
      case 5:
      case 7:
      case 13:
      case 15:
        display_bitmap_delay(31, 50);
        break;
      case 6:
      case 14:
        display_bitmap_delay(32, 50);
        ynSnd1();
        break;
      default:
        display_bitmap_delay(0, 100);
        break;
    }
  }
}
