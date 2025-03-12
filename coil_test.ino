#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET    -1
Adafruit_SSD1306 display(128, 32, &Wire, OLED_RESET);

#define IGNITION_PIN  8
#define BUTTON_DWELL  9
#define BUTTON_RPM    10

unsigned int rpm = 0;
float dwell = 2.0; 
bool lastDwellButtonState = HIGH;
bool lastRpmButtonState = HIGH;
unsigned long lastMillis = 0;

void setup() {
    pinMode(IGNITION_PIN, OUTPUT);
    pinMode(BUTTON_DWELL, INPUT_PULLUP);
    pinMode(BUTTON_RPM, INPUT_PULLUP);
    digitalWrite(IGNITION_PIN, LOW); 
    
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
}

void loop() {

    bool rpmButtonState = digitalRead(BUTTON_RPM);
    if (rpmButtonState == LOW && lastRpmButtonState == HIGH) {
        delay(50); // 
        if (digitalRead(BUTTON_RPM) == LOW) {
            rpm += 500;
            if (rpm > 7000) rpm = 0;
        }
    }
    lastRpmButtonState = rpmButtonState;


    bool dwellButtonState = digitalRead(BUTTON_DWELL);
    if (dwellButtonState == LOW && lastDwellButtonState == HIGH) {
        delay(50); 
        if (digitalRead(BUTTON_DWELL) == LOW) {
            dwell += 0.5;
            if (dwell > 7.0) dwell = 2.0;
        }
    }
    lastDwellButtonState = dwellButtonState;

    if (rpm > 0) {
        unsigned long period = 60000000UL / (rpm * 4); // RPM period
        unsigned long dwellTime = dwell * 1000; // Dwell time

        digitalWrite(IGNITION_PIN, HIGH);
        delayMicroseconds(dwellTime);
        digitalWrite(IGNITION_PIN, LOW);
        delayMicroseconds(period - dwellTime);
    } else {
        digitalWrite(IGNITION_PIN, LOW); 
    }
    
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("RPM: ");
    display.print(rpm);
    display.setCursor(0, 16);
    display.print("Dwell: ");
    display.print(dwell, 1);
    display.print(" ms");
    display.display();
}
