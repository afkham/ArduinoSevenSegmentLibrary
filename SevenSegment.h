#ifndef SevenSegment_h
#define SevenSegment_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#else
	#include <WProgram.h>
	#include <pins_arduino.h>
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

#define COMMON_ANODE 3
#define COMMON_CATHODE 4

class SevenSegment {
	public:
		SevenSegment(unsigned int type = COMMON_ANODE);
		void writeDigit(unsigned int digit);
	private:
		unsigned int _type;
		// The Arduino digital pin numbers connected to the segments
		unsigned int _segmentA;
		unsigned int _segmentB;
		unsigned int _segmentC;
		unsigned int _segmentD;
		unsigned int _segmentE;
		unsigned int _segmentF;
		unsigned int _segmentG;
		unsigned int _segmentDP;

		/*
		10 digits:
		 Each defines which segments should be on/off for that digit: A,B,C,D,E,F,G,P
		 */
		byte _numbers[10];
};


#endif
