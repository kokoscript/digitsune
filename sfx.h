#define REST 0
#define B0  31
#define C1  33
#define CS1 35
#define D1  37
#define DS1 39
#define E1  41
#define F1  44
#define FS1 46
#define G1  49
#define GS1 52
#define A1  55
#define AS1 58
#define B1  62
#define C2  65
#define CS2 69
#define D2  73
#define DS2 78
#define E2  82
#define F2  87
#define FS2 93
#define G2  98
#define GS2 104
#define A2  110
#define AS2 117
#define B2  123
#define C3  131
#define CS3 139
#define D3  147
#define DS3 156
#define E3  165
#define F3  175
#define FS3 185
#define G3  196
#define GS3 208
#define A3  220
#define AS3 233
#define B3  247
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A5  880
#define AS5 932
#define B5  988
#define C6  1047
#define CS6 1109
#define D6  1175
#define DS6 1245
#define E6  1319
#define F6  1397
#define FS6 1480
#define G6  1568
#define GS6 1661
#define A6  1760
#define AS6 1865
#define B6  1976
#define C7  2093
#define CS7 2217
#define D7  2349
#define DS7 2489
#define E7  2637
#define F7  2794
#define FS7 2960
#define G7  3136
#define GS7 3322
#define A7  3520
#define AS7 3729
#define B7  3951
#define C8  4186
#define CS8 4435
#define D8  4699
#define DS8 4978

void modeBlip() {
  CircuitPlayground.playTone(100, 10);
}

void happyChirp() {
  CircuitPlayground.playTone(1500, 25);
  CircuitPlayground.playTone(3500, 25);
  CircuitPlayground.playTone(5500, 25);
  delay(125);
  CircuitPlayground.playTone(3000, 25);
  CircuitPlayground.playTone(5000, 25);
  CircuitPlayground.playTone(7000, 25);
}

void errChirp() {
  CircuitPlayground.playTone(500, 15);
  CircuitPlayground.playTone(2500, 15);
  CircuitPlayground.playTone(4500, 15);
}

void blinkSnd() {
  CircuitPlayground.playTone(2000, 10);
}

void infoJingle() {
  CircuitPlayground.playTone(C4, 50);
  CircuitPlayground.playTone(E4, 50);
  CircuitPlayground.playTone(G4, 50);
  CircuitPlayground.playTone(AS4, 50);
}

void sighIn() {
  for(int i = 0; i < 30; i++){
    CircuitPlayground.playTone(500 + (i*16), 8);
  }
}

void sighOut() {
  for(int i = 30; i > 0; i--){
    CircuitPlayground.playTone(600 + (i*16), 8);
  }
}

void ynSnd1() {
  CircuitPlayground.playTone(500, 80);
}

void ynSnd2() {
  CircuitPlayground.playTone(1000, 80);
}

int note[][2] = { // intro drums
                  {B1, REST},{REST},{B1, REST},{REST},{B1, REST},{REST},{B1, B1},{B1, B1},
                  {B1, REST},{REST},{B1, REST},{REST},{B1, REST},{REST},{B1},{B1},
                  {B1, REST},{REST},{B1, REST},{REST},{B1, REST},{REST},{B1, B1},{B1, B1},
                  {B1, REST},{REST},{B1, REST},{REST},{B1, REST},{REST},{B1},{B1},
                  {B1, REST},{REST},{B1, REST},{REST},{B1, REST},{REST},{B1, B1},{B1, B1},
                  {B1, REST},{REST},{B1, REST},{REST},{B1, REST},{REST},{B1},{B1},
                  {B1, REST},{REST},{B1, REST},{REST},{B1, REST},{REST},{B1, B1},{B1, B1},
                  {B1, REST},{REST},{B1, REST},{REST},{B1, REST},{REST},{B1},{B1},
                  // leadup to melody
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {FS3, DS3}, {GS3}, {FS3, GS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {GS3}, {FS3, GS3}, {FS3}, {DS3, FS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {FS3, DS3}, {GS3}, {FS3, GS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {GS3}, {FS3, GS3}, {FS3}, {DS3, FS3},
                  // melody, verse 1
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {DS5}, {CS5},
                  {AS4}, {REST}, {DS4}, {REST}, {AS4}, {GS4}, {FS4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {GS4}, {FS4},
                  {F4}, {DS4}, {F4}, {FS4}, {F4}, {DS4}, {D4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {DS5}, {CS5},
                  {AS4}, {REST}, {DS4}, {REST}, {AS4}, {GS4}, {FS4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {GS4}, {FS4},
                  {F4}, {F4}, {FS4}, {FS4}, {GS4}, {GS4}, {AS4}, {AS4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {DS5}, {CS5},
                  {AS4}, {REST}, {DS4}, {REST}, {AS4}, {GS4}, {FS4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {GS4}, {FS4},
                  {F4}, {DS4}, {F4}, {FS4}, {F4}, {DS4}, {D4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {DS5}, {CS5},
                  {AS4}, {REST}, {DS4}, {REST}, {AS4}, {GS4}, {FS4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {GS4}, {FS4},
                  {F4}, {F4}, {FS4}, {FS4}, {GS4}, {GS4}, {AS4}, {AS4},
                  // melody, verse 2
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {GS4}, {FS4}, {F4}, {CS4}, {DS4}, {REST}, {CS4}, {DS4},
                  {F4}, {FS4}, {GS4}, {AS4}, {DS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {GS4}, {FS4}, {F4}, {CS4}, {DS4}, {REST}, {CS4}, {DS4},
                  {F4}, {FS4}, {GS4}, {AS4}, {DS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {DS5}, {F5},
                  //
                  {FS5}, {F5}, {DS5}, {CS5}, {AS4}, {REST}, {GS4}, {AS4},
                  {GS4}, {FS4}, {F4}, {CS4}, {DS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {GS4}, {FS4}, {F4}, {CS4}, {DS4}, {REST}, {CS4}, {DS4},
                  {F4}, {FS4}, {GS4}, {AS4}, {DS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {GS4}, {FS4}, {F4}, {CS4}, {DS4}, {REST}, {CS4}, {DS4},
                  {F4}, {FS4}, {GS4}, {AS4}, {DS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {DS5}, {F5},
                  {FS5}, {F5}, {DS5}, {CS5}, {AS4}, {REST}, {GS4}, {AS4},
                  {GS4}, {FS4}, {F4}, {CS4}, {DS4}, {REST}, {REST}, {REST},
                  // bridge
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {FS3, DS3}, {GS3}, {FS3, GS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {GS3}, {FS3, GS3}, {FS3}, {DS3, FS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {FS3, DS3}, {GS3}, {FS3, GS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3},
                  {DS3}, {DS3, DS3}, {REST, DS3}, {CS3, DS3}, {GS3}, {FS3, GS3}, {FS3}, {DS3, FS3},
                  // melody, verse 3
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {DS5}, {CS5},
                  {AS4}, {REST}, {DS4}, {REST}, {AS4}, {GS4}, {FS4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {GS4}, {FS4},
                  {F4}, {DS4}, {F4}, {FS4}, {F4}, {DS4}, {D4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {DS5}, {CS5},
                  {AS4}, {REST}, {DS4}, {REST}, {AS4}, {GS4}, {FS4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {GS4}, {FS4},
                  {F4}, {F4}, {FS4}, {FS4}, {GS4}, {GS4}, {AS4}, {AS4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {DS5}, {CS5},
                  {AS4}, {REST}, {DS4}, {REST}, {AS4}, {GS4}, {FS4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {GS4}, {FS4},
                  {F4}, {DS4}, {F4}, {FS4}, {F4}, {DS4}, {D4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {DS5}, {CS5},
                  {AS4}, {REST}, {DS4}, {REST}, {AS4}, {GS4}, {FS4}, {F4},
                  {DS4}, {F4}, {FS4}, {GS4}, {AS4}, {REST}, {GS4}, {FS4},
                  {F4}, {F4}, {FS4}, {FS4}, {GS4}, {GS4}, {AS4}, {AS4},
                  // melody, verse 2
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {GS4}, {FS4}, {F4}, {CS4}, {DS4}, {REST}, {CS4}, {DS4},
                  {F4}, {FS4}, {GS4}, {AS4}, {DS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {GS4}, {FS4}, {F4}, {CS4}, {DS4}, {REST}, {CS4}, {DS4},
                  {F4}, {FS4}, {GS4}, {AS4}, {DS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {GS4}, {AS4},
                  {CS5}, {DS5}, {AS4}, {GS4}, {AS4}, {REST}, {DS5}, {F5},
                  // pitch-shifted part
                  {FS5}, {F5}, {DS5}, {CS5}, {AS4}, {REST}, {GS4}, {AS4},
                  {GS4}, {FS4}, {F4}, {CS4}, {DS4}, {REST}, {GS4}, {AS4},
                  {CS6}, {DS6}, {AS5}, {GS5}, {AS5}, {REST}, {GS5}, {AS5},
                  {CS6}, {DS6}, {AS5}, {GS5}, {AS5}, {REST}, {GS5}, {AS5},
                  {GS5}, {FS5}, {F5}, {CS5}, {DS5}, {REST}, {CS5}, {DS5},
                  {F5}, {FS5}, {GS5}, {AS5}, {DS5}, {REST}, {GS5}, {AS5},
                  {CS6}, {DS6}, {AS5}, {GS5}, {AS5}, {REST}, {GS5}, {AS5},
                  {CS6}, {DS6}, {AS5}, {GS5}, {AS5}, {REST}, {GS5}, {AS5},
                  {GS5}, {FS5}, {F5}, {CS5}, {DS5}, {REST}, {CS5}, {DS5},
                  {F5}, {FS5}, {GS5}, {AS5}, {DS5}, {REST}, {GS5}, {AS5},
                  {CS6}, {DS6}, {AS5}, {GS5}, {AS5}, {REST}, {GS5}, {AS5},
                  {CS6}, {DS6}, {AS5}, {GS5}, {AS5}, {REST}, {DS6}, {F6},
                  {FS6}, {F6}, {DS6}, {CS6}, {AS5}, {REST}, {GS5}, {AS5},
                  {GS5}, {FS5}, {F5}, {CS5}, {DS5}, {REST}, {REST}, {REST},
                  // outro
                  {B2}, {REST, B2}, {B2, REST}, {REST},
                  {B2}, {REST, B2}, {B2, REST}, {REST},
                  {B2}, {REST, B2}, {B2, REST}, {REST},
                  {B2}, {REST, B2}, {B2, REST}, {REST},
                  {B2}, {REST, B2}, {B2, REST}, {REST},
                  {B2}, {REST, B2}, {B2, REST}, {REST},
                  {B2}, {REST, B2}, {B2, REST}, {REST},
                  {B2}, {REST, B2}, {B2, REST}, {REST},
                  {B2}, {REST, B2}, {B2, REST},
                  // silence!!
                  {REST}, {REST}, {REST}, {REST}, {REST}, {REST}, {REST}, {REST},
                  {REST}, {REST}, {REST}, {REST}, {REST}, {REST}, {REST}, {REST}
                };
                
int len[][2] =  { // intro drums
                  {1,1},{2},{1,1},{2},{1,1},{2},{1,1},{1,1},
                  {1,1},{2},{1,1},{2},{1,1},{2},{2},{2},
                  {1,1},{2},{1,1},{2},{1,1},{2},{1,1},{1,1},
                  {1,1},{2},{1,1},{2},{1,1},{2},{2},{2},
                  {1,1},{2},{1,1},{2},{1,1},{2},{1,1},{1,1},
                  {1,1},{2},{1,1},{2},{1,1},{2},{2},{2},
                  {1,1},{2},{1,1},{2},{1,1},{2},{1,1},{1,1},
                  {1,1},{2},{1,1},{2},{1,1},{2},{2},{2},
                  // leadup to melody
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {1, 1}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {2}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {1, 1}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {2}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {1, 1}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {2}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {1, 1}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {2}, {1, 1},
                  // melody, verse 1
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  // melody, verse 2
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  //
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  // bridge
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {1, 1}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {2}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {1, 1}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {2}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {1, 1}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {2}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {1, 1}, {1, 1},
                  {2}, {1, 1}, {1, 1}, {1, 1}, {2}, {1, 1}, {2}, {1, 1},
                  // melody, verse 1
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  // melody, verse 2
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  //
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  {2},{2},{2},{2},{2},{2},{2},{2},
                  // outro
                  {2}, {1, 1}, {1, 1}, {2},
                  {2}, {1, 1}, {1, 1}, {2},
                  {2}, {1, 1}, {1, 1}, {2},
                  {2}, {1, 1}, {1, 1}, {2},
                  {2}, {1, 1}, {1, 1}, {2},
                  {2}, {1, 1}, {1, 1}, {2},
                  {2}, {1, 1}, {1, 1}, {2},
                  {2}, {1, 1}, {1, 1}, {2},
                  {2}, {1, 1}, {1, 1},
                  {2}, {2}, {2}, {2}, {2}, {2}, {2}, {2},
                  {2}, {2}, {2}, {2}, {2}, {2}, {2}, {2}
                 };
void do_song_part(int pos) {
  int totalLen = 0;
  int noteOffset = 0;
  while (totalLen < 3) {
    totalLen += len[pos][noteOffset];
    if (totalLen < 3) {
      CircuitPlayground.playTone(note[pos][noteOffset], 45*len[pos][noteOffset]);
      noteOffset++;
    }
  }
}
