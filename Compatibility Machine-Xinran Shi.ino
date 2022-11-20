//Xinran Shi's assignment for creative coding Week 10: Compatibility Machine
//reference: https://www.arduino.cc/reference/en/

int y=0;//define photo-resistor's pin number
int LED_1=12;//orange light: declare and initialize the LED 1 (pin number 12)
int LED_2=11;//green light: declare and initialize the LED 2 (pin number 11)
int result;

void setup(){
 Serial.begin(9600);//initialize serial communication at 9600 bits per second
   pinMode(LED_1,OUTPUT);//set pin 12 to output mode
   pinMode(LED_2,OUTPUT);//set pin 11 to input mode
   pinMode(y, INPUT_PULLUP);//set pin A0 to input_pullup mode
//about how to use randomSeed(), reference from: https://www.arduino.cc/reference/en/language/functions/random-numbers/randomseed/
randomSeed(analogRead(0));//reduce the regularity of random numbers
  }

void loop(){
//about how to use analogRead(), reference from: https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/
   y=analogRead(0);//values read from the analog input pins of the arduino
   Serial.println(y);
   if(y>1000){ //1000 is the value tested from serial monitor, representing dark surrounding lights
    result=random(3); //result will generate a random number between 0 and 3 (0,1,2, not include 3)
//about how to use switch...case...,reference from: https://www.arduino.cc/reference/en/language/structure/control-structure/switchcase/
  switch(result){
        case 0: //case result = 0
        //orange LED turns on, green LED turns off
         digitalWrite(LED_1, HIGH);
         digitalWrite(LED_2, LOW);
         delay(2000);//wait 2000 milliseconds
          break; //jump out of the loop
        case 1: //case result = 1
        //green LED turns on, orange LED turns off
         digitalWrite(LED_2, HIGH);
         digitalWrite(LED_1, LOW);
         delay(2000);//wait 2000 milliseconds       
          break; //jump out of the loop
      case 2: //case result =2
        //both orange and green LEDs turn on
        digitalWrite(LED_1, HIGH);
        digitalWrite(LED_2, HIGH);      
        delay(2000); //wait 2000 milliseconds
          break;
}
}
   else{ //when the surrounding environment is bright, both LEDs turn off
         digitalWrite(LED_1, LOW);
         digitalWrite(LED_2, LOW);
   delay(1);//delay in between reads for stability
}
}