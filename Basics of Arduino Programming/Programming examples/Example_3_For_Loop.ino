// For loop
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int i;
  int n = 5;
  for(i=0;i<n;i++)  // Start with i = 0, check if it is less than 'n', then increase the value of 'i' by 1. When 'i' is no longer less than 'n', then exit this loop
  {
      Serial.println("hello world");
  }   
}

void loop() {
  // put your main code here, to run repeatedly:

}
