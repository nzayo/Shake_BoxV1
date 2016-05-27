void setcolour(int r, int g, int b)
{
  value.r = r;
  value.g = g;
  value.b = b;
}
void randomLED()
{
  int rand_id=0;
  rand_id=random(1,15);
  setcolour(155,155,155); // RGB Value -> Blue
  LED.set_crgb_at(rand_id, value); // Set value at LED found at index 0
  LED.sync(); // Sends the value to the LED
  LEDoff();
}
void Temp2LED()
{
  int red = 0, blue = 0;
  red = (Temp, 28, 40, 0, 200);
  blue = (Temp, 20, 30, 200, 0);
  for (int i = 0; i < numLED; i++)
  {
    setcolour(red, 0, blue); // RGB Value -> Blue
    LED.set_crgb_at(i, value); // Set value at LED found at index 0
    LED.sync(); // Sends the value to the LED
  }
}
void whiteLight()
{
  for (int i = 0; i < numLED; i++)
  {
    setcolour(150 , 150, 150); // RGB Value -> Blue
    LED.set_crgb_at(i, value); // Set value at LED found at index 0
    LED.sync(); // Sends the value to the LED
  }
}
void LEDoff()
{
  for (int i = 0; i < numLED; i++)
  {
    setcolour(0, 0, 0); // RGB Value -> Blue
    LED.set_crgb_at(i, value); // Set value at LED found at index 0
    LED.sync(); // Sends the value to the LED
  }
}

