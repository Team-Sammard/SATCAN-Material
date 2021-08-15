// Infinite loop using For loop
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for( ; ;)    // There is no condition to stop here so it will never exit the loop
  {
       Serial.println("infinite loop");    // The program will keep displaying this because it will never exit this loop
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
