void setup(){
   // LED is connected to digital pin 4
   pinMode(4, OUTPUT);  // set LED pin as output
   // Photoresistor is conencted to analog pin 0
   pinMode(A0, INPUT);  // set Photoresistor pin as input 
   Serial.begin(9600);  // Start serial monitor
}

void loop(){
  int LightValue;               // variable to store photoresistor value
  LightValue = analogRead(A0);  // read photoresistor value from pin A0
  Serial.println(LightValue);   // Display photoresistor value on serial monitor
    
  if(LightValue < 200){          // If light value is less than 200
      digitalWrite(4, HIGH);     // Turn LED on
      }
        
  else{                          // If light value is not less than 200
      digitalWrite(4,LOW);       // Turn LED off   
      }
}
