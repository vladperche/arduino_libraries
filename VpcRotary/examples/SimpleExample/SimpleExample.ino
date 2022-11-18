#include <VpcRotary.h>

VpcRotary rotaryMenu(34,36,39);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  rotaryMenu.check();
  if(rotaryMenu.isClockwise())
  {
    Serial.println("Moved clockwise");
  }
  if(rotaryMenu.isCounterclock())
  {
    Serial.println("Moved counterclock");
  }
  if(rotaryMenu.buttonDown())
  {
    Serial.println("Button pressed");
  }
  if(rotaryMenu.buttonUp())
  {
    Serial.println("Button released");
  }
}
