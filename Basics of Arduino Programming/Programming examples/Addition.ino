// These are called comments. They are for our reference and are not executed as instructions by the microcontroller

//ADD program
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Starts the serial monitor where we will see the output
  int a=10;           // Storing the integer value 10 in the variable 'a'
  int b=10;           // Storing the integer value 10 in the variable 'b'
  int c;              // Declare an integer type variable 'c' but no value given to it
  c=a+b;              // The variable 'c' will store the value of the mathematical operation a+b
  Serial.println(c);  // Displays the value of 'c' on serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
}
