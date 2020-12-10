
// Setting Left Side Motors

const int leftEnable = 5;
const int highLeft = 6;
const int lowLeft = 7;

// Setting Right Side Motors

const int rightEnable = 10;
const int highRight = 8;
const int lowRight = 9;



const int D0 = 0;       //Raspberry pin 21    LSB
const int D1 = 1;       //Raspberry pin 22
const int D2 = 2;       //Raspberry pin 23
const int D3 = 3;       //Raspberry pin 24    MSB

int a,b,c,d,data;




void setup() {
  // put your setup code here, to run once:

  pinMode(leftEnable, OUTPUT);
  pinMode(highLeft, OUTPUT);
  pinMode(lowLeft, OUTPUT);
      
  pinMode(rightEnable, OUTPUT);
  pinMode(highRight, OUTPUT);
  pinMode(lowRight, OUTPUT);

  pinMode(D0, INPUT_PULLUP);
  pinMode(D1, INPUT_PULLUP);  
  pinMode(D2, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);


}



void Data()
{
   a = digitalRead(D0);
   b = digitalRead(D1);
   c = digitalRead(D2);
   d = digitalRead(D3);

   data = 8*d+4*c+2*b+a;
}


void Forward(){
  digitalWrite(highLeft, LOW);
  digitalWrite(lowLeft, HIGH);
  analogWrite(leftEnable, 255);

  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite(rightEnable, 255);
}

void Backward(){
  digitalWrite(highLeft, HIGH);
  digitalWrite(lowLeft, LOW);
  analogWrite(leftEnable, 255);

  digitalWrite(highRight, HIGH);
  digitalWrite(lowRight, LOW);
  analogWrite(rightEnable, 255);
}


void Stop()
{
  digitalWrite(highLeft, LOW);
  digitalWrite(lowLeft, HIGH);
  analogWrite(leftEnable,0);

  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite(rightEnable,0);
  
}


void Left1(){
  digitalWrite(highLeft, LOW);
  digitalWrite(lowLeft, HIGH);
  analogWrite(leftEnable, 160);

  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite(rightEnable, 255);
}

void Left2(){
  digitalWrite(highLeft, LOW);
  digitalWrite(lowLeft, HIGH);
  analogWrite(leftEnable, 95);

  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite(rightEnable, 255);
}
void Left3(){
  digitalWrite(highLeft, LOW);
  digitalWrite(lowLeft, HIGH);
  analogWrite(leftEnable, 55);

  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite(rightEnable, 255);
}

void Right1(){
  digitalWrite(highLeft, LOW);
  digitalWrite(lowLeft, HIGH);
  analogWrite(leftEnable, 255);

  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite(rightEnable, 160);
}


void Right2(){
  digitalWrite(highLeft, LOW);
  digitalWrite(lowLeft, HIGH);
  analogWrite(leftEnable, 255);

  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite(rightEnable, 95);
}
void Right3(){
  digitalWrite(highLeft, LOW);
  digitalWrite(lowLeft, HIGH);
  analogWrite(leftEnable, 255);

  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite(rightEnable, 55);
}


void MakeUTurn()
{
  
  analogWrite (leftEnable, 0);
  analogWrite (rightEnable, 0);
  delay(400);

  //move forward
  analogWrite (leftEnable, 250);
  analogWrite (rightEnable, 250);
  delay(1000);

  analogWrite (leftEnable, 0);
  analogWrite (rightEnable, 0);
  delay(400);

  //Turn Left and pause

  digitalWrite(highLeft, HIGH);
  digitalWrite(lowLeft, LOW);
  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite (leftEnable, 255);
  analogWrite (rightEnable, 255);
  delay(800);

  analogWrite (leftEnable, 0);
  analogWrite (rightEnable, 0);
  delay(400);


  //Move Forward a bit

  digitalWrite(highLeft, LOW);
  digitalWrite(lowLeft, HIGH);
  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite (leftEnable, 255);
  analogWrite (rightEnable, 255);
  delay(800);

  analogWrite (leftEnable, 0);
  analogWrite (rightEnable, 0);
  delay(400);

  //Turn Left and pause

  digitalWrite(highLeft, HIGH);
  digitalWrite(lowLeft, LOW);
  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite (leftEnable, 255);
  analogWrite (rightEnable, 255);
  delay(700);

  analogWrite (leftEnable, 0);
  analogWrite (rightEnable, 0);
  delay(1000);


  digitalWrite(highLeft, LOW);
  digitalWrite(lowLeft, HIGH);
  digitalWrite(highRight, LOW);
  digitalWrite(lowRight, HIGH);
  analogWrite (leftEnable, 150);
  analogWrite (rightEnable, 150);
  delay(300);
  
}
 


void loop() {
  // put your main code here, to run repeatedly:
 Data();
  if(data==0)
   {
     Forward();
   }
   
  else if(data==1)
   {
     Right1();
   }
     
  else if(data==2)
   {
     Right2();
   }
     
  else if(data==3)
   {
     Right3();
   }
     
  else if(data==4)
   {
     Left1();
   }
    
  else if(data==5)
   {
     Left2();
   }
    
  else if(data==6)
   {
     Left3();
   }

  else if(data==7)
   {
     MakeUTurn();
   }
  
  else if (data>7)
   {
     Stop();
   }
   


}