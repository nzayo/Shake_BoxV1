void calibrateAG()
{
  Serial.println("Calibrate set Zero.");
  delay(300);
  imu.readAccel();
  imu.readGyro();
  deltaAG[0] = imu.calcAccel(imu.ax);
  deltaAG[1] = imu.calcAccel(imu.ay);
  deltaAG[2] = imu.calcAccel(imu.az);
  deltaAG[3] = imu.calcGyro(imu.gx);
  deltaAG[4] = imu.calcGyro(imu.gy);
  deltaAG[5] = imu.calcGyro(imu.gz);
  delay(300);
}
void getAccelo()
{
  imu.readAccel();
  Accelo[0] = imu.calcAccel(imu.ax) - deltaAG[0];
  Accelo[1] = imu.calcAccel(imu.ay) - deltaAG[1];
  Accelo[2] = imu.calcAccel(imu.az) - deltaAG[2];
}

void printAccelo()
{
  // To read from the accelerometer, you must first call the
  // readAccel() function. When this exits, it'll update the
  // ax, ay, and az variables with the most current data.
  imu.readAccel();

  // Now we can use the ax, ay, and az variables as we please.
  // Either print them as raw ADC values, or calculated in g's.
  Serial.print("A: ");

  // If you want to print calculated values, you can use the
  // calcAccel helper function to convert a raw ADC value to
  // g's. Give the function the value that you want to convert.
  Serial.print(imu.calcAccel(imu.ax) - deltaAG[0], 2);
  Serial.print(", ");
  Serial.print(imu.calcAccel(imu.ay) - deltaAG[1], 2);
  Serial.print(", ");
  Serial.print(imu.calcAccel(imu.az) - deltaAG[2], 2);
  Serial.println(" g");
}

void getGyro()
{
  imu.readGyro();
  Gyro[0] = imu.calcGyro(imu.gx);
  Gyro[1] = imu.calcGyro(imu.gy);
  Gyro[2] = imu.calcGyro(imu.gz);
}

void printGyro()
{
  imu.readGyro();

  Serial.print("G: ");
  Serial.print(imu.calcGyro(imu.gx), 2);
  Serial.print(", ");
  Serial.print(imu.calcGyro(imu.gy), 2);
  Serial.print(", ");
  Serial.print(imu.calcGyro(imu.gz), 2);
  Serial.println(" deg/s");
}

