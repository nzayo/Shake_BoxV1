void getTemp()
{
  Temp = smeHumidity.readTemperature();
}
void printTemp()
{
  Temp = smeHumidity.readTemperature();
  Serial.print("Temp :");
  Serial.print(Temp);
  Serial.println(" c");
}
