#include <SevenSegment.h>

SevenSegment sevenSeg(COMMON_ANODE);

void setup(){
}

void loop(){
  for (byte count = 10; count > 0; --count) {
     sevenSeg.writeDigit(count-1);
     delay(1000);
  }
  delay(4000);
}
