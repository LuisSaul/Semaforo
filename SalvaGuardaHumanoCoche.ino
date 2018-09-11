#define button 2
#define rojo 3
#define amarillo 4
#define verde 5
#define ledPeaton 8
#define pot A1
int valorPot = 0;
int val2=0;
void setup() {
  Serial.begin(9600);
  pinMode(rojo,OUTPUT);
  pinMode(amarillo,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(ledPeaton,OUTPUT);
}

void loop() {
  valorPot = analogRead(pot);
  Serial.print("Valor de pot; ");
  Serial.print(valorPot);
  Serial.println(": KOhms");
  reiniciaSemaforo();
}

void reiniciaSemaforo(){
  digitalWrite(ledPeaton, LOW);
  digitalWrite(rojo, HIGH);
  while(val2<20){
  if(digitalRead(button)==LOW){
    enciendePeaton();
  }else{
    delay(valorPot/5);
  }
  val2++;
  }
  val2=0;
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, HIGH);
  while(val2<10){
  if(digitalRead(button)==LOW){
    enciendePeaton();
  }else{
    delay(100);
  }
  val2++;
  }
  val2=0;
  digitalWrite(verde, HIGH);
  digitalWrite(amarillo, LOW);
  while(val2<20){
  if(digitalRead(button)==LOW){
    enciendePeaton();
  }else{
    delay(100);
  }
  val2++;
  }
  val2=0;
  digitalWrite(verde, LOW);
  digitalWrite(rojo, HIGH);
}

void enciendePeaton(){
  val2=0;
    digitalWrite(rojo, HIGH);
    digitalWrite(amarillo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(ledPeaton, HIGH);
    delay(3000);
    reiniciaSemaforo();
}
