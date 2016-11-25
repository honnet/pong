#include "Encoder.h"
// remove it if you use teensy, it's included and it would conflict
// source: http://www.pjrc.com/teensy/td_libs_Encoder.html

// We're using an arduino leonardo and these pins allow interruptions:
Encoder knob0(0, 1);
Encoder knob1(2, 3);


void setup() {
    Serial.begin(115200);
}

long pos0 = -999;
long pos1 = -999;

void loop() {
    long newPos0 = knob0.read();
    long newPos1 = knob1.read();

    if (newPos0 != pos0 || newPos1 != pos1) {
        Serial.print(newPos0);
        Serial.print(" ");
        Serial.println(newPos1);

        pos0 = newPos0;
        pos1 = newPos1;
    }

    // if a character is sent from the serial monitor,
    // reset both back to zero.
    if (Serial.available()) {
        Serial.read();
        knob0.write(0);
        knob1.write(0);
    }
}

