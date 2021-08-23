void setup()
{
  // LED is connected to digital pin 3
  pinMode(3,OUTPUT);    // Digital pin 3 is set as output
}

void loop()
{
  digitalWrite(3,HIGH);   // Write a HIGH signal to digital pin 3 to turn on LED 
  delay(1000);            // Wait for 1000 milliseconds i.e 1 second
  digitalWrite(3,LOW);    // Write a LOW signal to digital pin 3 to turn off LED
  delay(1000);            // Wait for 1000 milliseconds i.e 1 second
}
