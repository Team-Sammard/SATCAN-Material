/*  This is another way of writing comments. This is helpful when you want to write multiple lines of comments.
 *  Functions are very important as they make writing big programs very easy. Functions are blocks of codes. We can give any name to a function. 
 *  When a function is called inside void setup or void loop, the program will jump to that block of code which has that function name.
 *  Once it is done executing that block of code, it will come back to void setup or void loop and continue executing rest of the code.
 *  In this example, we have made 3 functions with the names "addd", "add" and "addition". Let us understand how these 3 functions work.
 */ 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int a, x=2, y=3;
  Serial.println("Output of the function addd()");
  addd(x,y);        // The code will jump to the "addd" function. This function takes variables 'x' and 'y' as input parameters
  Serial.println("Output of the function add(x,y)");
  add();            // The code will jump to the "add" function
  Serial.println("Output of the function addition()");
  a = addition();   // The code will jump to the "addition" function. The variable 'a' will store the value returned by this function.  
  Serial.println(a);  // Display the value of 'a' in Serial Monitor
}

void loop() {
  // put your main code here, to run repeatedly:

}

/*  Instructions are only executed inside void setup() and void loop() so anything outside these are not executed by the microcontroller.
 *  But we can define functions below and call those functions by their names inside void setup() or void loop(). In this example we have called them inside void setup().
 */

// Function of type "void" do not return any value

void addd(int x, int y)    // 'x' and 'y' are input parameters 
{
    int c;
    c=x+y;                 // Add the two input parameters 'x' and 'y' and store it to variable 'c'   
    Serial.println(c);       // Displays the value of 'c' in Serial Monitor
}

void add()                // This function does not take any input parameters
{
   int c,a=5, b=10;
   c=a+b;                 // Add the two variables 'a' and 'b' defined insided this function and store it to 'c' 
   Serial.println(c);       // Displays the value of 'c' in Serial Monitor
}

// Function of type "int" will return a value of datatype "int"
int addition()            //  
{
   int c,a=5, b=15;
   c=a+b; 
   return(c);            // Returns the value of the variable 'c' which is of datatype "int" 
}
