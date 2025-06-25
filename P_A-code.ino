int spole1 = 10; 
//Kopplad till digital pin 10 
int spole2 = 9; 
//Kopplad till digital pin 9 
int spole3 = 11; 
//Kopplad till digital pin 11 
int sensor1 = 5; 
//Kopplad till digital pin 5 
int sensor3 = 3; 
//Kopplad till digital pin 3 
int sensor2 = 7; 
//Kopplad till digital pin 7 
int led1 = 4; 
int led3 = 8; 
int led2 = 12; 
//Deklarerar variabler för våra counters och sätter startvärdet till 0 
double startcount1 = 0; 
double endcount1 = 0; 
double startcount2 = 0; 
double endcount2 = 0; 
double startcount3 = 0; 
double endcount3 = 0; 
int a=50; int c = 0; 
float t1 =0; 
float t2 =0; 
float t3 =0; 
float t4 =0; 
int count = 0; 
float varvtid; v
oid setup() { // put your setup code here, to run once:
 Serial.begin(9600); 
 pinMode(spole1, OUTPUT); 
 //Sätter pin 3 som en output pin 
 pinMode(spole2, OUTPUT); 
 //Sätter pin 4 som en output pin
  pinMode(spole3, OUTPUT); 
  //Sätter pin 5 som en output pin 
  pinMode(sensor1, INPUT); //Sätter pin 6 som en input pin 
  pinMode(sensor2, INPUT); //Sätter pin 7 som en input pin 
  pinMode(sensor3, INPUT); //Sätter pin 8 som en input pin
pinMode(led1, OUTPUT); 
pinMode(led2, OUTPUT); 
pinMode(led3, OUTPUT); 
digitalWrite(led1, HIGH); 
digitalWrite(led2, HIGH); 
digitalWrite(led3, HIGH); }
 void 
 varv(float tt, float t){ 
  float dt = tt-t; 
  if (count != 2){ 
    varvtid += dt ; count++; 
    } 
  else{ varvtid += dt; Serial.println(varvtid/1000);
   count = 0; varvtid=0; } } 
   void loop() { // put your main code here, to run repeatedly: //Läser värdet för sensorerna, antingen 0/1 
   int sensor1value = digitalRead(sensor1); 
   int sensor2value = digitalRead(sensor2); 
   int sensor3value = digitalRead(sensor3); 
   while(c==0){ 
    if(sensor1value == 1){ //När sensorn känner av kulan ska spolen vara igång 
    digitalWrite(led1, LOW); 
    digitalWrite(led2, HIGH); 
    digitalWrite(led3, LOW); 
    digitalWrite(spole1, HIGH); 
    t1 = millis(); //Skriver värden till våra counters
//Vi måste allid läsa värdet på sensorerna (Osäker om det behövs) //
int sensor1value = digitalRead(sensor1); 
//int sensor2value = digitalRead(sensor2); 
delay(a); 
digitalWrite(spole1, LOW); 
c = 2; } 
if(sensor2value == 1){ 
  //När sensorn känner av kulan ska spolen vara igång 
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW); 
  digitalWrite(led3, HIGH); 
  digitalWrite(spole2, HIGH); 
  t2 = millis(); 
  delay(a); 
  digitalWrite(spole2, LOW); 
  c =3; } 
  if(sensor3value == 1){ //När sensorn känner av kulan ska spolen vara igång 
  digitalWrite(led1, HIGH); 
  digitalWrite(led2, LOW); 
  digitalWrite(led3, LOW); 
  digitalWrite(spole3, HIGH); 
  t3 = millis(); 
  delay(a); 
  digitalWrite(spole3, LOW); 
  c =1; } //När kulan lämnar sensorn stängs spolen av 
  else{ digitalWrite(spole2, LOW);
digitalWrite(spole3, LOW); 
digitalWrite(spole1, LOW); } } 
switch(c){ 
  case 1: sensor1value = digitalRead(sensor1); 
    if(sensor1value == 1){ digitalWrite(led1, LOW); 
    digitalWrite(led2, HIGH); 
    digitalWrite(led3, LOW); 
    digitalWrite(spole1, HIGH); 
    delay(a); 
    digitalWrite(spole1, LOW); 
    varv(millis(), t3); 
    t1=millis(); c =2; } //Skriver värden till våra counters break; 
  case 2: sensor2value = digitalRead(sensor2); 
    if(sensor2value == 1){ 
      digitalWrite(led1, LOW); 
      digitalWrite(led2, LOW); 
      digitalWrite(led3, HIGH); 
      digitalWrite(spole2, HIGH); 
      delay(a); 
      digitalWrite(spole2, LOW); 
      varv(millis(), t1); 
      t2=millis(); 
      c =3; } 
      break;
  case 3: sensor3value = digitalRead(sensor3); 
    if(sensor3value == 1){ digitalWrite(led1, HIGH); 
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
    digitalWrite(spole3, HIGH); 
    delay(a); 
    digitalWrite(spole3, LOW); 
    varv(millis(), t3); 
    t3=millis(); 
    c =1; }
 break; 
 } 
 }