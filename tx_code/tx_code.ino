//A very simple example of sending a string of characters
//from the serial monitor, capturing the individual
//characters into a String, then evaluating the contents
//of the String to possibly perform an action (on/off board LED).


int ledPin=13;
int ledPin2=12;
long delay_time=100; //set 20ms for 50Hz, 100ms for 10Hz
char value; //value to insert one bit
String values; //bit string for transmission
String stringValues;
String zeros;
String header = "0110";
int length; //value to store the length of transmission string
int left_zeros; //count no. of zero on the left for a byte of ascii char
boolean Send;

void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode(ledPin2, OUTPUT);
 Serial.begin(115200); //open serial port and sent data rate at specified rate
 
 String initial_msg = "The transmitter circuit is initializing.";
 Serial.println(initial_msg);
 delay(1000);
 
 digitalWrite(ledPin, HIGH);
 delay(10);
 digitalWrite(ledPin, LOW);
 String initial_msg2 = "Initialization finishes.";
 Serial.println(initial_msg2);
}

void loop() {
 
 while (Serial.available()) {
   value = Serial.read(); //read ascii char in serial console 
   
   left_zeros = 8 - String(value,BIN).length(); //count no. of zero on the left for each byte of char
   
   for (int i=0; i<left_zeros; ++i)
   {    
    zeros = zeros + "0";   
   }
   stringValues = stringValues + String(value);
   
   if(values !="")
   {
   values = values + header + zeros + String(value,BIN); //bit string of transmission data
   }
   else
   {
   values = header + zeros + String(value,BIN); //bit string of transmission data
   }   
   
  zeros = ""; //clear content of zero
  delay(1);// wait 1ms for another char
 }

 if(values != "") 
 {
  length = values.length();
  Send = true;

  Serial.println(stringValues);
  Serial.println(values);
 }

 if(Send)
 {

  //transmission by On-off keying modulation
  digitalWrite(ledPin, HIGH);
  delay(3000); //turn on LED for 3s for start of tx
  digitalWrite(ledPin2, HIGH);
  
 for(int i=0; i<length ; i++)
  {
    if (i != length -1)
    {
      if(values.charAt(i) == '0') 
      {
        digitalWrite(ledPin, LOW);
        delay(delay_time);
      }
      else if(values.charAt(i) == '1')
      {
        digitalWrite(ledPin, HIGH);
        delay(delay_time);
      }
    }
    //consider the last bit of transmission
    else {
      if(values.charAt(i) == '0')
      {
        digitalWrite(ledPin, LOW);
        delay(delay_time);
      }
      else if(values.charAt(i) == '1') 
      {
        digitalWrite(ledPin, HIGH);
        delay(delay_time);
        digitalWrite(ledPin, LOW); // a long sequence of zero for indicating the end of tx
      }
    }
  }

 values = ""; //clear content of bit string of transmission data
 stringValues =""; //clear content of input string
 digitalWrite(ledPin2, LOW);
 Send = false;
}
}
