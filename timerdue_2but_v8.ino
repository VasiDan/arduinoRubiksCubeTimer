
#include <DueTimer.h>
int ledr=16;
int ledv=17;
int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=8;
int p=9;

int d1=10;
int d2=11;
int d3=12;
int d4=13;

long n=0;
long n1=0;
long n2=0; //minute
long n3=0; //ore
long n4=0; //ore 2 zecimale
int x=10;
int del=5;
int count=0;
int count1=0;// schimbare s-m
int count2=0; //pt led
int count3=0; // clipire


int s=0; //schimbare sec-min
int s1=0;
int s2=0;
int s3=0; // schimbare ora
int s4=0; // schimbare ora 2 zcimale
//schimbare punct
boolean sm = HIGH; 
boolean sm1= LOW;

int bc=0;
int bb=0;
int pl1=0; //constanta pt ledr
int pl2=0; //buton stanga
int ptli=0;

const int buttonPin2 = 14; 
const int buttonPin1 = 15;   
const int buttonPin3 = 18;

int buttonState1;             // the current reading from the input pin
int lastButtonState1 = LOW;   // the previous reading from the input pin

int buttonState2;             // the current reading from the input pin
int lastButtonState2 = LOW; 

int buttonState3;             
int lastButtonState3 = LOW;

int bs2=0; //schimbare buton
int bs3=0; //
// last sol leduri off
int tfl=0;
//schimbare 2 but cu 1
int bbo=0;
int bbo1=0;

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;


void setup() {
  Serial.begin(9600);
  pinMode(a, OUTPUT);     
  pinMode(b, OUTPUT);     
  pinMode(c, OUTPUT);     
  pinMode(d, OUTPUT);     
  pinMode(e, OUTPUT);     
  pinMode(f, OUTPUT);     
  pinMode(g, OUTPUT);  
  pinMode(p, OUTPUT);  
  pinMode(d1, OUTPUT);  
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT); 
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(ledr,OUTPUT);
  pinMode(ledv,OUTPUT);

   Timer4.attachInterrupt(add).setFrequency(1000).start();
   
}

void loop() {
//schimbare secunde - minute
switch(s)
{
    default: 
      {
     clearLEDs();
     pickDigit(0);
     pickNumber((n/1000));
     delay(del);
    
     clearLEDs();
     pickDigit(1);
     pickNumber((n%1000)/100);
     delay(del);
    
     clearLEDs();
     pickDigit(2);
     pickNumber((n%100)/10);
     delay(del);
    
     clearLEDs();
     pickDigit(3);
     pickNumber(n%10);
     delay(del);
    }
      break;
    case 1:
      {
     clearLEDs();
     pickDigit(0);
     pickNumber(n1);
     delay(del);
    
     clearLEDs();
     pickDigit(1);
     pickNumber((n/1000));
     delay(del);
    
     clearLEDs();
     pickDigit(2);
     pickNumber((n%1000)/100);
     delay(del);
    
     clearLEDs();
     pickDigit(3);
     pickNumber((n%100)/10);
     delay(del);
    }
      break;
    case 2:
    {
     clearLEDs();
     pickDigit(0);
     pickNumber(n2);
     delay(del);
    
     clearLEDs();
     pickDigit(1);
     pickNumber(n1);
     delay(del);
    
     clearLEDs();
     pickDigit(2);
     pickNumber((n/1000));
     delay(del);
    
     clearLEDs();
     pickDigit(3);
     pickNumber((n%1000)/100);
     delay(del);
    }
    break;
    case 3:
    {
     clearLEDs();
     pickDigit(0);
     pickNumber(n3);
     delay(del);
    
     clearLEDs();
     pickDigit(1);
     pickNumber(n2);
     delay(del);
    
     clearLEDs();
     pickDigit(2);
     pickNumber(n1);
     delay(del);
    
     clearLEDs();
     pickDigit(3);
     pickNumber((n/1000));
     delay(del);
    }
    break;
    case 4:
    {
     clearLEDs();
     pickDigit(0);
     pickNumber(n4);
     delay(del);
    
     clearLEDs();
     pickDigit(1);
     pickNumber(n3);
     delay(del);
    
     clearLEDs();
     pickDigit(2);
     pickNumber(n2);
     delay(del);
    
     clearLEDs();
     pickDigit(3);
     pickNumber(n1);
     delay(del);
    }
    break;
}    
 
   int reading1 = digitalRead(buttonPin1);
   int reading2 = digitalRead(buttonPin2);
   int reading3 = digitalRead(buttonPin3);

    if (reading1 != lastButtonState1) {
    // reset the debouncing timer
    lastDebounceTime = millis();
    }
    
   if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading1 != buttonState1) {
      buttonState1 = reading1;
      
      if (buttonState1 == HIGH) {
           bc=0;
           bb=0;
           n=0;
           n1=0;
           n2=0;
           n3=0;
           n4=0;
           s=0;
           s1=0;
           s2=0;
           s3=0;
           s4=0;
           pl1=0;
           pl2=0;
           ptli=0;
           count1=0;
           count2=0;
           count3=0;
           sm=HIGH;
           sm1=LOW;
           bs2=0;
           bs3=0;
           tfl=0;
      }
    }
  }
    if (reading2 != lastButtonState2) {
    lastDebounceTime = millis();
  }
   if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading2 != buttonState2) {
      buttonState2 = reading2;
         if (buttonState2 == HIGH) { 
          bbo1++;                    
          bb++;
          bc=0;
          pl1=1;
         }
         if (buttonState2==LOW){
           bb++;
           ptli=1;
                if (count2>300)
                {
                bc=1;
                ptli=0;
                }
        }
    }
   }
      
    if (reading3 != lastButtonState3) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading3 != buttonState3) {
      buttonState3 = reading3;
         if (buttonState3 == HIGH) {
          bbo++;
          bs2++;
          bs3=1;
         }
         if (buttonState3 ==LOW){
          bs2++;
          bs3++;
         }
    }
   }
  if (bs3>1)
  {
     ptli=1;
        if (count2>300)
        {
        bc=1;
        ptli=0;
        }
  }  
  
 //buton dreapta
  switch(bbo)
  {
    
     case 2:
      bs3=1;
      break;
    case 3:
      bbo=0;
      break;
    case 1: // ca sa mearga cand e cu 2 butoane
      if (pl1==1)
        bbo=0;
     break;
  }

  if ((bb==3 & bs3==1) | (bb>=3 & bs2>=3) | (bb==1 & bs2==3) | (bs2==1 & bb==3))
  {
     pl2=0;
     bc=0;
     pl1=0;
     count2=0;
     ptli=0;
     tfl=1;
  }

  lastButtonState1 = reading1;
  lastButtonState2 = reading2;
  lastButtonState3 = reading3;
}


void pickDigit(int x)
{
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);

  switch(x)
  {
    case 0:
    digitalWrite(d1,LOW);
    digitalWrite(p, sm1);
    break;
    case 1:
    digitalWrite(d2,LOW);
    digitalWrite(p, sm);
    break;
    case 2:
    digitalWrite(d3,LOW);
    digitalWrite(p, sm1);
    break;
    case 3:
    digitalWrite(d4,LOW);
    break;
  }
}

void pickNumber(int x)
{
  switch(x)
  {
    default: 
      zero();
      break;
    case 1:
      one();
      break;
    case 2:
      two();
      break;      
    case 3:
      three();
      break;      
    case 4:
      four();
      break;      
    case 5:
      five();
      break;
    case 6:
      six();
      break; 
    case 7:
      seven();
      break;
    case 8:
      eight();
      break; 
    case 9:
      nine();
      break;                  
  }
}

void clearLEDs()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(p, LOW);
}

void zero()
{
   digitalWrite(a, HIGH);   
   digitalWrite(b, HIGH);   
   digitalWrite(c, HIGH);   
   digitalWrite(d, HIGH);   
   digitalWrite(e, HIGH);   
   digitalWrite(f, HIGH);   
   digitalWrite(g, LOW);  
}

void one()
{
   digitalWrite(a, LOW);   
   digitalWrite(b, HIGH);   
   digitalWrite(c, HIGH);   
   digitalWrite(d, LOW);   
   digitalWrite(e, LOW);   
   digitalWrite(f, LOW);   
   digitalWrite(g, LOW);  
}

void two()
{
   digitalWrite(a, HIGH);   
   digitalWrite(b, HIGH);   
   digitalWrite(c, LOW);   
   digitalWrite(d, HIGH);   
   digitalWrite(e, HIGH);   
   digitalWrite(f, LOW);   
   digitalWrite(g, HIGH);  
}

void three()
{
   digitalWrite(a, HIGH);   
   digitalWrite(b, HIGH);   
   digitalWrite(c, HIGH);   
   digitalWrite(d, HIGH);   
   digitalWrite(e, LOW);   
   digitalWrite(f, LOW);   
   digitalWrite(g, HIGH);  
}

void four()
{
   digitalWrite(a, LOW);   
   digitalWrite(b, HIGH);   
   digitalWrite(c, HIGH);   
   digitalWrite(d, LOW);   
   digitalWrite(e, LOW);   
   digitalWrite(f, HIGH);   
   digitalWrite(g, HIGH);  
}

void five()
{
   digitalWrite(a, HIGH);   
   digitalWrite(b, LOW);   
   digitalWrite(c, HIGH);   
   digitalWrite(d, HIGH);   
   digitalWrite(e, LOW);   
   digitalWrite(f, HIGH);   
   digitalWrite(g, HIGH);  
}

void six()
{
   digitalWrite(a, HIGH);   
   digitalWrite(b, LOW);   
   digitalWrite(c, HIGH);   
   digitalWrite(d, HIGH);   
   digitalWrite(e, HIGH);   
   digitalWrite(f, HIGH);   
   digitalWrite(g, HIGH);  
}

void seven()
{
   digitalWrite(a, HIGH);   
   digitalWrite(b, HIGH);   
   digitalWrite(c, HIGH);   
   digitalWrite(d, LOW);   
   digitalWrite(e, LOW);   
   digitalWrite(f, LOW);   
   digitalWrite(g, LOW);  
}

void eight()
{
   digitalWrite(a, HIGH);   
   digitalWrite(b, HIGH);   
   digitalWrite(c, HIGH);   
   digitalWrite(d, HIGH);   
   digitalWrite(e, HIGH);   
   digitalWrite(f, HIGH);   
   digitalWrite(g, HIGH);  
}

void nine()
{
   digitalWrite(a, HIGH);   
   digitalWrite(b, HIGH);   
   digitalWrite(c, HIGH);   
   digitalWrite(d, LOW);   
   digitalWrite(e, LOW);   
   digitalWrite(f, HIGH);   
   digitalWrite(g, HIGH);  
}
void add()
{
  //counter
  if (bc==1 & bs3>=1)
  {
  count ++;
  count1 ++;
  if (count==10)
  {
    count=0;
    n++;
     if (count1==60000)
     {
      s=1;
      count1=0;
      n1++;
      s1++;
      n=0;
      }
   }
  }
  // minute
   if (n1==10)
         {
        s2++;
        n1=0;
        n2++;
         }
  // ore
   if (n2==6)
        {
          n2=0;
          n3++;
          s3++;
        }
  //ore 2
  if (n3==10)
        {
          n3=0;
          n4++;
          s4++;
        }

  //
   if(s1>=1)
      {
      sm=LOW;
      sm1=HIGH;
      s=1;
      }
   if (s2>=1)
   {
        sm=HIGH;
        sm1=LOW;
        s=2;
    }
        if (s3>=1)
   {
        sm=LOW;
        sm1=HIGH;
        s=3;
    }
         if (s4>=1)
   {
        sm=HIGH;
        sm1=LOW;
        s=4;
    }
    
  //leduri
  if (tfl==0)
  {
  digitalWrite(ledr,LOW);
  digitalWrite(ledv,LOW);
  if (pl1==1 & bs3==1)
  {
    count2++;
    digitalWrite(ledr,HIGH);
    if (count2>300)
        {
          digitalWrite(ledr,LOW);
          digitalWrite(ledv,HIGH);
        }
  }
   if(ptli==1)
        {
          count2=0; 
          digitalWrite(ledr,HIGH);
          digitalWrite(ledv,LOW);
        }
    //clipire
   if (bc==1 & bs3>=1)
   {
    count3++;
    if (count3<25)
    {
      digitalWrite(ledr,LOW);
    }
    if (count3>25 & count3<50)
    {
      digitalWrite(ledr,HIGH);
    }
    if (count3>50 & count3<75)
    {
      digitalWrite(ledv,LOW);
    }
    if (count3>75 & count3<100)
    {
      digitalWrite(ledv,HIGH);
    }
    

   }
   if (count3>100)
   {
    count3=0;
   }
  }
  else
  {
     digitalWrite(ledr,LOW);
     digitalWrite(ledv,LOW);
  }
}


