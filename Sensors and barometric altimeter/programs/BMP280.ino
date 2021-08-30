#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C Interface

void setup() {
  //initialise serial communication at 9600 rate
  Serial.begin(9600);

  //wait till communication is estalbished between BMP and arduino
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop() {
    Serial.print("Temperature = ");//displaying temperature in celsius
    float temperature = bmp.readTemperature();
    Serial.print(temperature);
    Serial.println(" *C");

    Serial.print("Pressure = ");
    float pressure = bmp.readPressure();
    Serial.print(pressure); //displaying the Pressure in Pa
    Serial.println(" Pa");

    Serial.print("Approx altitude = ");
    float altitude = bmp.readAltitude(1019.66);
    Serial.print(altitude); //The "1019.66" is the pressure(hPa) at sea level in day in your region
    Serial.println(" m");                    //If you don't know it, modify it until you get your current altitude

    Serial.println();
    delay(2000);
}
