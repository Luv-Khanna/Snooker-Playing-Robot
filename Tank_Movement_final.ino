int YsensorValue = 0; 
int XsensorValue = 0;
/*define M1*/
int M1YoutputValue = 0;
int M1XoutputValue = 0;
/*define M2*/
int M2YoutputValue = 0;
int M2XoutputValue = 0;
   const int YanalogInPin = A0; 
   const int XanalogInPin = A1;
   const int M1analogOutPin = 8; 
   const int M2analogOutPin = 4;

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  /*control Forward/Backward */
  
  /*taking the input value of joystick and setting the motor values*/
  YsensorValue = analogRead(YanalogInPin);
  XsensorValue = analogRead(XanalogInPin);

  if (XsensorValue >=400 && XsensorValue<= 600)
  {
   if ( YsensorValue >= 400 && YsensorValue <=600)
  {
    /* MAPPING OF SPEED*/
  M1YoutputValue = map (YsensorValue, 400, 600, 0,0);
  analogWrite(M1analogOutPin, M1YoutputValue);
  M2YoutputValue = map (YsensorValue, 400, 600, 0,0);
  analogWrite(M2analogOutPin, M2YoutputValue);

  /* STATIONARY POSITION*/
  digitalWrite(11, LOW); /*direction*/
  digitalWrite(10, LOW); /*direciton*/
  analogWrite(8, M1YoutputValue); /*speed 180 (range from 76 to 255*/
  digitalWrite(3, LOW); /*direction*/
  digitalWrite(2, LOW); /*direciton*/
  analogWrite(4, M2YoutputValue); /*speed 180 (range from 76 to 255*/
 
  }
  else if(YsensorValue < 400)
  {
    /* MAPPING OF SPEED*/
  M1YoutputValue = map (YsensorValue, 0, 400, 255,0);
  analogWrite(M1analogOutPin, M1YoutputValue);
  M2YoutputValue = map (YsensorValue, 0, 400, 255,0);
  analogWrite(M2analogOutPin, M2YoutputValue);

  /* BACKWARD MOVEMENT*/
  digitalWrite(11, LOW); /*direction*/
  digitalWrite(10, HIGH); /*direciton*/
  analogWrite(8, M1YoutputValue); /*speed 180 (range from 76 to 255*/
  digitalWrite(3, HIGH); /*direction*/
  digitalWrite(2, LOW); /*direciton*/
  analogWrite(4, M2YoutputValue); /*speed 180 (range from 76 to 255*/

  }
  else 
  {
      /* MAPPING OF SPEED*/
  M1YoutputValue = map (YsensorValue, 600, 1023, 0,255);
  analogWrite(M1analogOutPin, M1YoutputValue);
  M2YoutputValue = map (YsensorValue, 600, 1023, 0,255);
  analogWrite(M2analogOutPin, M2YoutputValue);

  /* FORWARD MOVEMENT*/
  digitalWrite(11, HIGH); /*direction*/
  digitalWrite(10, LOW); /*direciton*/
  analogWrite(8, M1YoutputValue); /*speed 180 (range from 76 to 255*/
  digitalWrite(3, LOW); /*direction*/
  digitalWrite(2, HIGH); /*direciton*/
  analogWrite(4, M2YoutputValue); /*speed 180 (range from 76 to 255*/

  }
  
  }
  
 /* LEFT RIGHT MOVEMENT*/
    
  if (YsensorValue >=400 && YsensorValue<= 600)
  {
  if(XsensorValue >=400 && XsensorValue <=600)
  {
   /* MAPPING OF THE SPEED*/
  M1XoutputValue = map (XsensorValue, 400, 600, 0, 0);
  analogWrite(M1analogOutPin, M1XoutputValue);
  M2XoutputValue = map (XsensorValue, 400, 600, 0, 0);
  analogWrite(M2analogOutPin, M2XoutputValue);
   /*STATIONARY POSITION*/
  digitalWrite(11, LOW); /*direction*/
  digitalWrite(10, LOW); /*direciton*/
  analogWrite(8, M1XoutputValue); /*speed 180 (range from 76 to 255*/
  digitalWrite(3, LOW); /*direction*/
  digitalWrite(2, LOW); /*direciton*/
  analogWrite(4, M2XoutputValue); /*speed 180 (range from 76 to 255*/
  
  }
  else if(XsensorValue < 400)
  {
   /* MAPPING OF THE SPEED*/
  M1XoutputValue = map (XsensorValue, 0, 400, 255,0);
  analogWrite(M1analogOutPin, M1XoutputValue);
  M2XoutputValue = map (XsensorValue, 0, 400, 255,0);
  analogWrite(M2analogOutPin, M2XoutputValue);

  /* RIGHT */
  digitalWrite(11, LOW); /*direction*/
  digitalWrite(10, HIGH); /*direciton*/
  analogWrite(8, M1XoutputValue); /*speed 180 (range from 76 to 255*/
  digitalWrite(3, LOW); /*direction*/
  digitalWrite(2, HIGH); /*direciton*/
  analogWrite(4, M2XoutputValue); /*speed 180 (range from 76 to 255*/
  }

  else
  {
   /* MAPPING OF THE SPEED*/
  M1XoutputValue = map (XsensorValue, 600, 1023, 0,255);
  analogWrite(M1analogOutPin, M1XoutputValue);
  M2XoutputValue = map (XsensorValue, 600, 1023, 0,255);
  analogWrite(M2analogOutPin, M2XoutputValue);

  /* LEFT */
  digitalWrite(11, HIGH); /*direction*/
  digitalWrite(10, LOW); /*direciton*/
  analogWrite(8, M1XoutputValue); /*speed 180 (range from 76 to 255*/
  digitalWrite(3, HIGH); /*direction*/
  digitalWrite(2, LOW); /*direciton*/
  analogWrite(4, M2XoutputValue); /*speed 180 (range from 76 to 255*/
  }
  
  
  }
  /*print X sensor and output Value**/
  Serial.print("X sensor = ");
  Serial.print(XsensorValue);
  Serial.print("\t Y sensor = ");
  Serial.println(YsensorValue);
  delay (2); 
  
    
   
}
