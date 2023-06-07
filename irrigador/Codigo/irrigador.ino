/********************************************************************
  Autor:  Glauber Apolinário de Freitas
  Projeto:  Sistema de irrigação aumotmático para Arduino
  Data:  06/06/2023
  Drtalhes:
********************************************************************/

#define pin_botao_ligar 2 //Define que o texto pin_botao_ligar representa o número 2
#define pin_botao_desligar 3 //Define que o texto pin_botao_desligar representa o número 3
#define pin_led 4
#define pin_rele_bomba 5
#define pin_sensor_umidade_solo A0

void setup() {
  Serial.begin(9600);  
  pinMode(pin_botao_ligar, INPUT_PULLUP);
  pinMode(pin_botao_desligar, INPUT_PULLUP);
  pinMode(pin_botao_led, OUTPUT);
  pinMode(pin_rele_bomba, OUTPUT);
  
  digitalWrite(pin_rele_bomba, HIGH);
}

void loop() {
  Serial.println(analogRead(pin_sensor_umidade_solo));
  if(analogRead(pin_sensor_umidade_solo)>=380 && digitalRead(pin_botao_led == 1)){
    digitalWrite(pin_rele_bomba, LOW)
  } 
  if(digitalRead(pin_botao_ligar)==0){
    digitalWrite(pin_botao_led, HIGH)
  } 
   if(digitalRead(pin_botao_ligar)==1){
    digitalWrite(pin_botao_led, LOW)
  } 
}
