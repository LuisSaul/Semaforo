#define button 2
#define rojo 3
#define amarillo 4
#define verde 5
#define rojoPeaton 6
#define ledPeaton 8
#define pot A1
#define speakerPin 9
int valorPot = 0;
int val2=0;
boolean espera= false;
void setup() {
  Serial.begin(9600);
  pinMode(rojo,OUTPUT);
  pinMode(amarillo,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(ledPeaton,OUTPUT);
  pinMode(rojoPeaton,OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  valorPot = analogRead(pot);
  Serial.print("Valor de pot; ");
  Serial.print(valorPot);
  Serial.println(": KOhms");
  reiniciaSemaforo();
}

void reiniciaSemaforo(){
  digitalWrite(rojoPeaton,HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(ledPeaton, LOW);
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, LOW);
  if(espera){
    espera=false;
    delay(3000);
  }
  while(val2<20){
  if(digitalRead(button)==LOW){
    enciendePeaton();
  }else{
    delay(valorPot/5);
  }
  val2++;
  }
  val2=0;
}

void enciendePeaton(){
  val2=0;
  espera=true;
    analogWrite(speakerPin,128);
    digitalWrite(rojoPeaton,HIGH);
    digitalWrite(amarillo, HIGH);
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    delay(1000);
    analogWrite(speakerPin,0);
    digitalWrite(ledPeaton, HIGH);
    digitalWrite(amarillo, LOW);
    digitalWrite(rojo, HIGH);
    digitalWrite(rojoPeaton,LOW);
    delay(valorPot*5);
    reiniciaSemaforo();
}
