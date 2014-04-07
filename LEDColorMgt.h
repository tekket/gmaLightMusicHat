#ifndef LEDCOLORMGT_H
#define LEDCOLORMGT_H

#include <Arduino.h>
#include <FastLED.h>

CRGB Wheel(uint16_t _wheelPos);
void showMirrored( uint8_t _row, CRGB* _halfleds, uint8_t _merge );
void paintAllRows( CRGB* _rowleds );
void solidColor( CRGB _color);
void solidColorLedsRow( CRGB _color);
void solidColorRow( CRGB _color, uint8_t _row );
void shiftLEDs( int8_t _distance );
uint16_t getLedIndex( uint8_t _row, uint16_t _rowindex);
uint16_t getKRLedIndex( uint8_t _row, uint16_t _rowindex, uint8_t _width);
void dimLeds(uint8_t _dimspeed, uint8_t _random = 0);
CRGB HeatColor(uint8_t _temperature);
void clearAllLeds();
void clearRowLeds();

#endif
