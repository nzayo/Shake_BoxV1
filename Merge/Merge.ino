//Accelo&Gyro
#include <Wire.h>
#include <SparkFunLSM9DS1.h>

LSM9DS1 imu;
#define LSM9DS1_M  0x1C
#define LSM9DS1_AG  0x6A // Would be 0x6A if SDO_AG 

#define shakeValue 1

float Accelo[3] = {0};
float Gyro[3] = {0};
float deltaAG[6] = {0}; //difference between First value and Second value

//Buzzer
#define buzzPin 10

//LED ID
#include <WS2812.h>
#define numLED 15
#define LEDOutput 9

WS2812 LED(5);
cRGB value;

//TEMP
#include <HTS221.h>

double Temp  = 0;

//milis
unsigned long previousMillis = 0;        // will store last time was updated
// constants won't change :
const long interval = 300;

//Other
#define BoardLED 13
#define wait4Place 2000

#define shakeSet 20
int shakeCount = 0;

void setup()
{
  Serial.begin(115200);

  //Accelo&Gyro
  Wire.begin();
  imu.settings.device.commInterface = IMU_MODE_I2C;
  imu.settings.device.mAddress = LSM9DS1_M;
  imu.settings.device.agAddress = LSM9DS1_AG;
  // The above lines will only take effect AFTER calling
  // imu.begin(), which verifies communication with the IMU
  // and turns it on.
  if (!imu.begin())
  {
    Serial.println("Failed to communicate with LSM9DS1.");
    while (1);
  }
  calibrateAG();

  //Buzzer
  pinMode(buzzPin,OUTPUT);

  //LED
  LED.setOutput(LEDOutput);

  //Temp
  smeHumidity.begin();

  pinMode(BoardLED,OUTPUT);
}
void loop()
{
  unsigned long currentMillis = millis();
  whiteLight();
  getGyro();
  //digitalWrite(BoardLED,HIGH);
  if (abs(Gyro[0]) > 60 || abs(Gyro[1]) > 60 || abs(Gyro[2]) > 60 )
  {
    LEDoff();
    makeNoise();
    digitalWrite(BoardLED,LOW); //4Debug
    for (shakeCount = 0; shakeCount < shakeSet;)
    {
      currentMillis = millis();
      getAccelo();
      if ((abs(Accelo[0]) > shakeValue || abs(Accelo[1]) > shakeValue || abs(Accelo[2]) > shakeValue) && (currentMillis - previousMillis >= interval))
      {
        // save the last time you blinked the LED
        previousMillis = currentMillis;
        shakeCount++;
        //Serial.println(shakeCount);
        if(shakeCount==10)
          randomLED();
      }
    whiteLight();
    shutNoise();
    delay(wait4Place);
  }
}



