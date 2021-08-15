// Infinite While loop
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(1)   // There is no condition given so it will keep entering the loop forever
  {
       Serial.println("infinite loop"); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
