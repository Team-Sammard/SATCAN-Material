#include <SD.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; 

const int chipSelect = 10; /*MOSI = pin 11 arduino nano
                           MISO = pin 12 arduino nano
                           SCK  = pin 13 arduino nano
                           CS   = pin 10 arduino nano*/
float referencePressure;

File dataFile;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //----------------SD card setup---------------//
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card not initialised");
    while (1);
  }
  
  //----------------BMP280 setup------------------//
  if(!bmp.begin()){
    Serial.println("BMP not initialised....");
    while(1);
  }
  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  
  referencePressure = bmp.readPressure();
}

void loop() {

  String dataString = "";
  
  //--------------------working of BMP280---------------------//
  if(bmp.readPressure()){
    float pressure = 100*(bmp.readPressure());//multiplied by hundred because sensor gives output in hPa unit
    Serial.print("Pressure:    ");
    Serial.print(pressure);
    Serial.println(" Pa");
 
    float temperature = bmp.readTemperature();
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    float Altitude = bmp.readAltitude(referencePressure); 
    Serial.print("Altitude:    ");
    Serial.print(Altitude); 
    Serial.println(" m");
    Serial.println("");

    dataString += "Altitude: " + String(Altitude) +" m"+ " Temperature: " + String(temperature) +" C"+ " Pressure: " + String(pressure)+" Pa"; 
    /* Example
    Altitude: 412.24 m Temperature: 31.2 C Pressure: 109876.45 Pa*/
  }
  else{
    Serial.println("Sensor error");
  }

 
  //--------------------------------Using the SD card module-------------//
  dataFile = SD.open("satcan_data.txt", FILE_WRITE);       // Create file to write data to
  if (dataFile) {
    dataFile.println(dataString);
    Serial.println("card works");
    dataFile.close();
  }
  else {
    Serial.println("error opening satcan_data.txt");
  }
}
