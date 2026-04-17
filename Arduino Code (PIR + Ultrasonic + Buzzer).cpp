Arduino Code (PIR + Ultrasonic + Buzzer) 
#define PIR 7 
#define TRIG 9 
#define ECHO 10 
#define BUZZER 8 
long duraƟ on;
int distance; 
void setup() 
{ 
 Serial.begin(9600); 
 pinMode(PIR, INPUT); 
 pinMode(TRIG, OUTPUT); 
 pinMode(ECHO, INPUT); 
 pinMode(BUZZER, OUTPUT); 
} 
void loop() 
{ 
 int moƟ on = digitalRead(PIR); 
 if(moƟ on == HIGH) 
 { 
 Serial.println("MoƟ on detected"); 
 digitalWrite(TRIG, LOW); 
 delayMicroseconds(2); 
 digitalWrite(TRIG, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(TRIG, LOW); 
 duraƟ on = pulseIn(ECHO, HIGH); 
 distance = duraƟ on * 0.034 / 2; 
 Serial.print("Distance: "); 
 Serial.println(distance); 
 if(distance < 200) 
 { 
 Serial.println("Human/Object detected"); 
 digitalWrite(BUZZER, HIGH); 
 } 
 else 
 { 
 digitalWrite(BUZZER, LOW); 
 } 
 } 
 else 
 { 
 digitalWrite(BUZZER, LOW); 
 Serial.println("No moƟ on"); 
 } 
 delay(500); 
}