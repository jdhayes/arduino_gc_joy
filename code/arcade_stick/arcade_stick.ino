/* Arduino USB Joystick HID demo */

/* Author: Darran Hunt
 * Released into the public domain.
 */

#define DEBUG

#define NUM_BUTTONS	40
#define NUM_AXES	8	       // 8 axes, X, Y, Z, etc

typedef struct joyReport_t {
    int16_t axis[NUM_AXES];
    uint8_t button[(NUM_BUTTONS+7)/8]; // 8 buttons per byte
} joyReport_t;

joyReport_t joyReport;


void setup(void);
void loop(void);
void setButton(joyReport_t *joy, uint8_t button);
void clearButton(joyReport_t *joy, uint8_t button);
void sendJoyReport(joyReport_t *report);

// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() 
{
    Serial.begin(115200);
    delay(200);

    for (uint8_t ind=0; ind<sizeof(joyReport.button); ind++) {
        joyReport.button[ind] = 0;
    }
    
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);
}

// Send an HID report to the USB interface
void sendJoyReport(struct joyReport_t *report)
{
#ifndef DEBUG
    Serial.write((uint8_t *)report, sizeof(joyReport_t));
#else
    Serial.println();
    for (uint8_t ind=0; ind<NUM_BUTTONS/8; ind++) {
	Serial.print("button[");
	Serial.print(ind);
	Serial.print("]= ");
	Serial.print(report->button[ind], HEX);
	Serial.print(" ");
    }
    Serial.println();
#endif
}

// turn a button on
void setButton(joyReport_t *joy, uint8_t button) {
    uint8_t index = button/8;
    uint8_t bit = button - 8*index;

    joy->button[index] |= 1 << bit;
}

// turn a button off
void clearButton(joyReport_t *joy, uint8_t button) {
    uint8_t index = button/8;
    uint8_t bit = button - 8*index;

    joy->button[index] &= ~(1 << bit);
}

uint8_t button=0;	// current button
bool press = true;	// turn buttons on?

/* Turn each button on in sequence 1 - 40, then off 1 - 40
 * add values to each axis each loop
 */
void loop() 
{
    
        // read the state of the pushbutton value:
        buttonState = digitalRead(buttonPin);

        Serial.print(buttonState);
        Serial.print('\n');
        
        //delay(25);
}
