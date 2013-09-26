//mode 0: red kr effect
//mode 1: blue kr effect
//mode 2: green kr effect
//mode 3: rainbow kr effect 

#include "zEffectClass.h"
#include "Effect_KR.h"

EffectKR::EffectKR(uint8_t _mode) : EffectClass(_mode) {
  currDelay = DELAY_KR;
  LEDS.setBrightness(NORMBRIGHT);
  switch(effectMode) {
    case 0:
      currColor = CRGB(255,32,0); // red
    break;
    case 1:
      currColor = CRGB(32,128,255); // blue-ish
    break;
    case 2:
      currColor = CRGB(0,255,0); // green
    break;
  }
}

void EffectKR::step() {
  clearAllLeds();
  if(effectMode = 3) {
    currColor = Wheel(currFrame);
  }
  for(uint8_t i=0; i<NUM_ROWS; i++) {
    uint16_t startIndex = getKRLedIndex(i, currFrame, KR_WIDTH);
    uint16_t endIndex;
    if(i%2==0) {
      endIndex = startIndex + KR_WIDTH;
      for(uint16_t j=startIndex; j<endIndex; j++) {
        if(j==startIndex || j==endIndex-1) { // fade edges for better effect
          leds[j] = currColor - CRGB(128,128,128);
        } else {
          leds[j] = currColor;
        }
      }
    } else {
      startIndex += 1;
      endIndex = startIndex - KR_WIDTH;
      for(uint16_t j=endIndex; j<startIndex; j++) {
        leds[j] = currColor;
      }
    }
  }
}
