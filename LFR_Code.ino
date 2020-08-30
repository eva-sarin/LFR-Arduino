//declaring all the variables
//IR sensors
int IR1 = 2;
int IR2 = 3;
int IR3 = 4;
//motors
int MR0 = A0;
int MR1 = A1;
int ML0 = A2;
int ML1 = A3;

void setup() {
  // declaring the input of the IR sensors
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);

  //declaring the motor pins
  pinMode(MR0, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(ML0, OUTPUT);
  pinMode(ML1, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  analogWrite(5, LOW);
  analogWrite(10, HIGH);
  analogWrite(11, HIGH);
  analogWrite(12, HIGH);
}

//declaring the operation functions
void forward()
{ analogWrite(MR0, 150);
  analogWrite(MR1, 0);
  analogWrite(ML0, 150);
  analogWrite(ML1, 0);
}
void right()
{
  analogWrite(MR1, 0);
  analogWrite(MR0, 0);
  analogWrite(ML1, 0);
  analogWrite(ML0, 150);
}

void left()
{ analogWrite(MR0, 150);
  analogWrite(MR1, 0);
  analogWrite(ML0, 0);
  analogWrite(ML1, 0);
}

void wait() //to stop
{ analogWrite(MR0, 0);
  analogWrite(MR1, 0);
  analogWrite(ML0, 0);
  analogWrite(ML1, 0);
}

void loop() {
  //taking values from the IR sensors
  digitalWrite(5, LOW); //made-up ground
  digitalWrite(10,HIGH); //made-up vcc
  digitalWrite(11, HIGH);//made-up vcc
  digitalWrite(12, HIGH);//made-up vcc

  IR1 = digitalRead(2);
  IR2 = digitalRead(3);
  IR3 = digitalRead(4);

  // the main algorithm
  if ((IR1 == 1) && (IR2 == 0) && (IR3 == 1)) //straight
  { forward();
  }
  if ((IR1 == 0) && (IR2 == 0) && (IR3 == 1)) //soft left
  { left();
  }
  if ((IR1 == 1) && (IR2 == 0) && (IR3 == 0)) //soft right
  { right();
  }
  if ((IR1 == 1) && (IR2 == 1) && (IR3 == 1)) // white space
  { forward();
    //wait();
  }
  if ((IR1 == 1) && (IR2 == 1) && (IR3 == 0)) //hard right
  { right();
  }
  if ((IR1 == 0) && (IR2 == 1) && (IR3 == 1)) //hard left
  { left();
  }
  if ((IR1 == 0) && (IR2 == 1) && (IR3 == 0)) // black white black
  { wait();
  }
  if ((IR1 == 0) && (IR2 == 0) && (IR3 == 0)) //tea-point
  { wait();
  }

}
