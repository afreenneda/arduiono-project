#include <LiquidCrystal.h>
#include <Servo.h>


/*Global Objects */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo myservo;



/*Global Variables */
int pos = 0;    // variable to store the servo position
int shouldunlock=0;
char Incoming_value = 0; 
int readytoaccept=1;
String Incoming_value_str;
int ledPin = 13;  // LED connected to digital pin 13
int inPin = 7;    // pushbutton connected to digital pin 7
int val = 0;      // variable to store the read value
int starttime=0,endtime=0;
int otp;

void initlcd()
{ lcd.setCursor(0,0);
  lcd.print("Neda H.A.S.");
}

void lock()
{
      pos=50;
      myservo.write(pos);
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print("Door Locked");

      delay(1000);
      printready();
}




void genotp()
{
  otp= (random(1000, 9999) + millis()) % 10000;
  
  lcd.clear();
  initlcd();
  lcd.setCursor(0,1);
  lcd.print("OTP GNRTD");
  delay(1000);
  lcd.print(otp);
  delay(2000);
  printready();
}

void unlock()
{
      starttime=(millis()/1000);
      endtime=(millis()/1000)+10;
      //autolock after 10sec
      pos=360;
      myservo.write(pos);
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print("Door Unlocked");
      delay(1000);
      printready();
}
void lighton()
{
      digitalWrite(ledPin , HIGH);
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print("LED ON");
      delay(1000);
      printready();
}

void lightoff()
{
      digitalWrite(ledPin , LOW);
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
 
      lcd.print("LED OFF");
      delay(1000);
      printready();
}

void setup() {
  //LCD Setup
  lcd.begin(16, 2);
  //lcd.print("Neda H.A.S.");
  printready();
  
  
  //SERVO SETUP
  myservo.attach(10);

  //OVERRIDELOCKPIN SETUP
  pinMode(ledPin, OUTPUT);  // sets the digital pin 13 as output
  pinMode(inPin, INPUT);    // sets the digital pin 7 as input


  //BT Module
  Serial.begin(9600);
  //necessary actions
  
}

void printready()
{
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print("Ready");
}

int checkotp(char d1, char d2, char d3, char d4)
{
      int givenotp;
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print(((int)d1)-48);
      lcd.print(((int)d2)-48);
      lcd.print(((int)d3)-48);
      lcd.print(((int)d4)-48);

      givenotp= ((((int)d1)-48) *10*10*10) + ((((int)d2)-48) *10*10) + ((((int)d3)-48) *10) + ((((int)d4)-48));
      if (givenotp==otp)
         return(1);
      
      else
      {
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print("WRONG OTP");  
      delay(1000);
      printready();
      return(0);

      }
}

void bluetoothlockvoice()
{
  
  if(Serial.available() > 0)  
  {
    Incoming_value_str = Serial.readString();

    Serial.println(Incoming_value_str);        //Print Value of Incoming_value in Serial monitor
    //Serial.println("\n");        //New line 
    
    
    if(Incoming_value_str == "lock the door" || Incoming_value_str=="1" ) 
     { //Checks whether value of Incoming_value is equal to 1 
        lock();
     }

     else if
     (Incoming_value_str == "0")
     {       //Checks whether value of Incoming_value is equal to 0
           genotp();
     }
     else if
     (Incoming_value_str[0] == 'O' && Incoming_value_str[1] == 'T' && Incoming_value_str[2] == 'P')
     {
       if(checkotp(Incoming_value_str[3], Incoming_value_str[4], Incoming_value_str[5], Incoming_value_str[6]))unlock();
     }

     
     else if
     (Incoming_value_str == "unlock the door")
     {       //Checks whether value of Incoming_value is equal to 0
           unlock();
     }

     else if(Incoming_value_str == "turn on LED" || Incoming_value_str == "LED on" || Incoming_value_str=="2" || Incoming_value_str == "LED on karo") 
     { //Checks whether value of Incoming_value is equal to 1 
       //If value is 1 then LED turns ON
     lighton();
     }
     
     else if(Incoming_value_str == "turn off LED" || Incoming_value_str == "LED off" || Incoming_value_str=="3" || Incoming_value_str == "LED off karo"){       //Checks whether value of Incoming_value is equal to 0
     //If value is 0 then LED turns OFF
     lightoff();
     }
  } 
 


}


void loop()
{
  int temp=0;
  delay(100);
   
  bluetoothlockvoice();
  //bluetoothlockbutton();
   //if (endtime<(millis()/1000))lock();
  

 
}#include <LiquidCrystal.h>
#include <Servo.h>


/*Global Objects */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo myservo;



/*Global Variables */
int pos = 0;    // variable to store the servo position
int shouldunlock=0;
char Incoming_value = 0; 
int readytoaccept=1;
String Incoming_value_str;
int ledPin = 13;  // LED connected to digital pin 13
int inPin = 7;    // pushbutton connected to digital pin 7
int val = 0;      // variable to store the read value
int starttime=0,endtime=0;
int otp;

void initlcd()
{ lcd.setCursor(0,0);
  lcd.print("Neda H.A.S.");
}

void lock()
{
      pos=50;
      myservo.write(pos);
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print("Door Locked");

      delay(1000);
      printready();
}




void genotp()
{
  otp= (random(1000, 9999) + millis()) % 10000;
  
  lcd.clear();
  initlcd();
  lcd.setCursor(0,1);
  lcd.print("OTP GNRTD");
  delay(1000);
  lcd.print(otp);
  delay(2000);
  printready();
}

void unlock()
{
      starttime=(millis()/1000);
      endtime=(millis()/1000)+10;
      //autolock after 10sec
      pos=360;
      myservo.write(pos);
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print("Door Unlocked");
      delay(1000);
      printready();
}
void lighton()
{
      digitalWrite(ledPin , HIGH);
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print("LED ON");
      delay(1000);
      printready();
}

void lightoff()
{
      digitalWrite(ledPin , LOW);
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
 
      lcd.print("LED OFF");
      delay(1000);
      printready();
}

void setup() {
  //LCD Setup
  lcd.begin(16, 2);
  //lcd.print("Neda H.A.S.");
  printready();
  
  
  //SERVO SETUP
  myservo.attach(10);

  //OVERRIDELOCKPIN SETUP
  pinMode(ledPin, OUTPUT);  // sets the digital pin 13 as output
  pinMode(inPin, INPUT);    // sets the digital pin 7 as input


  //BT Module
  Serial.begin(9600);
  //necessary actions
  
}

void printready()
{
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print("Ready");
}

int checkotp(char d1, char d2, char d3, char d4)
{
      int givenotp;
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print(((int)d1)-48);
      lcd.print(((int)d2)-48);
      lcd.print(((int)d3)-48);
      lcd.print(((int)d4)-48);

      givenotp= ((((int)d1)-48) *10*10*10) + ((((int)d2)-48) *10*10) + ((((int)d3)-48) *10) + ((((int)d4)-48));
      if (givenotp==otp)
         return(1);
      
      else
      {
      lcd.clear();
      initlcd();
      lcd.setCursor(0,1);
      lcd.print("WRONG OTP");  
      delay(1000);
      printready();
      return(0);

      }
}

void bluetoothlockvoice()
{
  
  if(Serial.available() > 0)  
  {
    Incoming_value_str = Serial.readString();

    Serial.println(Incoming_value_str);        //Print Value of Incoming_value in Serial monitor
    //Serial.println("\n");        //New line 
    
    
    if(Incoming_value_str == "lock the door" || Incoming_value_str=="1" ) 
     { //Checks whether value of Incoming_value is equal to 1 
        lock();
     }

     else if
     (Incoming_value_str == "0")
     {       //Checks whether value of Incoming_value is equal to 0
           genotp();
     }
     else if
     (Incoming_value_str[0] == 'O' && Incoming_value_str[1] == 'T' && Incoming_value_str[2] == 'P')
     {
       if(checkotp(Incoming_value_str[3], Incoming_value_str[4], Incoming_value_str[5], Incoming_value_str[6]))unlock();
     }

     
     else if
     (Incoming_value_str == "unlock the door")
     {       //Checks whether value of Incoming_value is equal to 0
           unlock();
     }

     else if(Incoming_value_str == "turn on LED" || Incoming_value_str == "LED on" || Incoming_value_str=="2" || Incoming_value_str == "LED on karo") 
     { //Checks whether value of Incoming_value is equal to 1 
       //If value is 1 then LED turns ON
     lighton();
     }
     
     else if(Incoming_value_str == "turn off LED" || Incoming_value_str == "LED off" || Incoming_value_str=="3" || Incoming_value_str == "LED off karo"){       //Checks whether value of Incoming_value is equal to 0
     //If value is 0 then LED turns OFF
     lightoff();
     }
  } 
 


}


void loop()
{
  int temp=0;
  delay(100);
   
  bluetoothlockvoice();
  //bluetoothlockbutton();
   //if (endtime<(millis()/1000))lock();
  

 
}
