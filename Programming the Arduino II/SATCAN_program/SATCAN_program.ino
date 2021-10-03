#include <SPI.h>
#include <SD.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; 

const int chipSelect = 10; /*MOSI = pin 11 arduino nano
                           MISO = pin 12 arduino nano
                           SCK  = pin 13 arduino nano
                           CS   = pin 10 arduino nano*/

// Declare all the variables we will use to store data
float referencePressure;
float temperature;
float pressure;
float altitude;
String dataString = "";

File dataFile;

void setup() {
  Serial.begin(9600);    // Initialize XBee for telemetry
 
  SD.begin(chipSelect);  // Initialize SD card module
  bmp.begin();           // Initialize BMP280 sensor

  // Set the default settings of BMP280 to get correct data 
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  
  referencePressure = bmp.readPressure();  // Reference pressure to calculate altitude above ground level
}

void loop() {
  get_data();     // Get weather data
  send_data();    // Send weather data to groundstation
  store_data();   // Store the weather data to SD card for backup
}

void get_data()
{
  temperature = bmp.readTemperature();
  pressure = bmp.readPressure();
  altitude = bmp.readAltitude(referencePressure);
}

void send_data()
{
  dataString =  String(altitude) + "," + String(temperature) + "," + String(pressure);     // Create data string containing all weather data in CSV (Comma Seperated Value) format
  // 412.24,31.2,109876.45   
  Serial.println(dataString);    // Send the data string to XBee which will transmit it to ground station XBee
}

void store_data()
{
  dataFile = SD.open("satcan_data.txt", FILE_WRITE);       // Create file to write data to
  if (dataFile) {            // Check if dataFile exists
    dataFile.println(dataString);     // Write the data string to SD card dataFile
    dataFile.close();                 // Close the dataFile
  }
}
