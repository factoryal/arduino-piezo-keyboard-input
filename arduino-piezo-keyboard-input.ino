/*
 * arduino-piezo-keyboard-input
 * https://github.com/factoryal/arduino-piezo-keyboard-input
 * 
 * Feel free to use this source code!
 * 
 * Thanks for leaving the authorship.
 * 
 * 
 * Available on Arduino has USB CDC feature (like Leonardo, Micro, ...)
 */


 
// Key1
// Define key to press and release.
// Check here for supported keys.
// https://www.arduino.cc/reference/tr/language/functions/usb/keyboard/keyboardmodifiers/
#define Key1 'Z'

// Threshold
// If read value lower than THRESHOLD, ignore it.
// Higher value, lower sensitivity.
#define THRESHOLD 1

// Cool Time
// If over threshold value read time less than COOL_TIME(ms) passed last read time, ignore it.
// Assume that human can input 50 inputs per second. 1000 / 50 = 20 (quite fast enough)
#define COOL_TIME 20



#include <Keyboard.h>

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
  analogReference(INTERNAL);
}

void loop() {
  static unsigned long oldTime = 0;
  int r = analogRead(A0);
  
  if(r > THRESHOLD) {
    unsigned long nowTime = millis();
    if(nowTime - oldTime > COOL_TIME) {
      Keyboard.press(Key1);
      delay(1);
      Keyboard.release(Key1);
      oldTime = nowTime;
    }
  }
}
