#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Animation.h"
struct Button {
  uint8_t pin;
  unsigned long lastDebounceTime = 0;
  int state = HIGH;
  int lastState = HIGH;

  Button(uint8_t p)
      : pin(p) {}
};
#define BTN_OK   PA12
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Button btnOk(BTN_OK);

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int currentFrame = 0;
unsigned long lastFrame = 0;

const uint16_t FRAME_DELAY = 75;
void setupButtons() {
  pinMode(btnOk.pin, INPUT_PULLUP);
 
}

bool ButtonPress(Button &btn, unsigned long debounceDelay = 25) {
  int reading = digitalRead(btn.pin);

  if (reading != btn.lastState)
    btn.lastDebounceTime = millis();

  if ((millis() - btn.lastDebounceTime) > debounceDelay) {
    if (reading != btn.state) {
      btn.state = reading;
      if (btn.state == LOW) {
        btn.lastState = reading;
        return true;
      }
    }
  }

  btn.lastState = reading;
  return false;
}
void setup() {

    Serial.begin(115200);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        while (1);
    }
    setupButtons();
    display.clearDisplay();
    display.display();
}
void loop() {

    if (millis() - lastFrame >= FRAME_DELAY) {

        display.clearDisplay();

        display.drawBitmap(
            0,
            0,
            epd_bitmap_allArray[currentFrame],
            128,
            64,
            SSD1306_WHITE
        );
    if (ButtonPress(btnOk)) {
    currentFrame = 0;
}
        display.display();

        currentFrame++;

        if (currentFrame >= epd_bitmap_allArray_LEN)
            currentFrame = 1;

        lastFrame = millis();
    }
}