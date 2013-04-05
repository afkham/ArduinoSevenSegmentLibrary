
#include "Arduino.h"
#include "SevenSegment.h"

// Simply change commonCathode to 1 for common cathode 7-seg display
#define commonCathode 0

// ---------------------------------------------------------------------------
// SevenSegment constructor
// ---------------------------------------------------------------------------

SevenSegment::SevenSegment(unsigned int type) {
	_type = type; 
	_segmentA = 2;
	_segmentB = 3;
	_segmentC = 4;
	_segmentD = 5;
	_segmentE = 6;
	_segmentF = 7;
	_segmentG = 8;
	_segmentDP = 9;
	pinMode(_segmentA, OUTPUT);   
  	pinMode(_segmentB, OUTPUT); 
  	pinMode(_segmentC, OUTPUT); 
  	pinMode(_segmentD, OUTPUT); 
  	pinMode(_segmentE, OUTPUT); 
  	pinMode(_segmentF, OUTPUT); 
  	pinMode(_segmentG, OUTPUT); 

  	byte nums[10] = { B11000000, // 0
					  B11111001, // 1
					  B10100100, // 2
					  B10110000, // 3
					  B10011001, // 4
					  B10010010, // 5
					  B10000010, // 6
					  B11111000, // 7
					  B10000000, // 8
					  B10010000  // 9
					};
	for(unsigned int i=0; i < sizeof(nums); i++){
		_numbers[i] = nums[i];
	}
  	digitalWrite(_segmentDP, 0);
}


// ---------------------------------------------------------------------------
// Standard ping methods
// ---------------------------------------------------------------------------

void SevenSegment::writeDigit(unsigned int digit) {
	byte pin = 2;
    int number =  _numbers[digit];
    for (int bitIndex = 0; bitIndex < 7; bitIndex++){
      if(_type == COMMON_CATHODE){
        digitalWrite(pin, 1-bitRead(number, bitIndex));
      } else {
        digitalWrite(pin, bitRead(number, bitIndex));
      }
      ++pin;
    }
}
