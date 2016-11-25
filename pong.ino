#include <Encoder.h>
// source: http://www.pjrc.com/teensy/td_libs_Encoder.html

// We're using an arduino leonardo and these pins allow interruptions:
Encoder knob0(0, 1);
Encoder knob1(2, 3);

const int button0 = 4;
const int button1 = 5;

void setup() {
    Serial.begin(115200);
    pinMode(button0, INPUT_PULLUP);
    pinMode(button1, INPUT_PULLUP);
}

long pos0 = -999;
long pos1 = -999;

bool state0 = 0;
bool state1 = 0;

void loop() {
    long newPos0 = knob0.read();
    long newPos1 = knob1.read();

    bool newState0 = digitalRead(button0);
    bool newState1 = digitalRead(button1);

    if (newPos0 != pos0 || newPos1 != pos1 ||
        newState0 != state0 || newState1 != state1 )
    {
        Serial.print(newPos0); Serial.print(", "); Serial.print(newState0);
        Serial.print(" - ");
        Serial.print(newPos1); Serial.print(", "); Serial.print(newState1);
        Serial.print("\n");

        pos0 = newPos0;
        pos1 = newPos1;

        state0 = newState0;
        state1 = newState1;
    }

    // if a character is sent from the serial monitor,
    // reset both back to zero.
    if (Serial.available()) {
        Serial.read();
        knob0.write(0);
        knob1.write(0);
    }
}

