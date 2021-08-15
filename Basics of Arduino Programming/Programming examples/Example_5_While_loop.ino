// While loop
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int n=5;  
  int i=0;
  while(i<n)    // While the condition (i<n) is true, it will keep entering the loop. Once it is false, it will exit the loop   
  {
      Serial.println("hello world");
      i++;    // Increase the value of 'i' by 1
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}



  
