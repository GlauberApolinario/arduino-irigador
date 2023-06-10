/********************************************************************
  Autor:  Glauber Apolinário de Freitas
  Projeto:  Sistema de irrigação automático para Arduino
  Data:  06/06/2023
  Detalhes:
********************************************************************/

#define pin_botao_ligar 2 //Define que o texto pin_botao_ligar representa o número 2
#define pin_botao_desligar 3 //Define que o texto pin_botao_desligar representa o número 3
#define pin_led 4
#define pin_rele_bomba 5
#define pin_sensor_umidade_solo A0

void setup() {
  //Inicia a comunicação serial com velocidade de 9600 bits por segundo
  Serial.begin(9600);

  //Define os pinos como entrada com resistores de pullup internos  
  pinMode(pin_botao_ligar, INPUT_PULLUP);
  pinMode(pin_botao_desligar, INPUT_PULLUP);

  //Define os pinos como saídas
  pinMode(pin_led, OUTPUT);
  pinMode(pin_rele_bomba, OUTPUT);
  
  digitalWrite(pin_rele_bomba, HIGH); //Lógica de acionamento do rele é invertida, por isso ele tem q iniciar como HIGH para iniciar desligado
}

void loop() {
  //Printa no monitor serial o valor do sensor de umidade de solo 0 - 1023
  Serial.println(analogRead(pin_sensor_umidade_solo));
  
  //Se o sensor de umidade de solo detectar o solo como seco e o sistema estiver ligado
  if(analogRead(pin_sensor_umidade_solo) >= 380 && digitalRead(pin_led == 1)){
    digitalWrite(pin_rele_bomba, LOW);//Liga a bomba d'água
  }

  //Se o sensor de umidade de solo detectar o solo como molhado
  if(analogRead(pin_sensor_umidade_solo) <= 350)
  {
    digitalWrite(pin_rele_bomba, HIGH);//Desliga a bomba d'água
  } 
  
  //Se o botão ligar for pressionado 
  if(digitalRead(pin_botao_ligar)==0){ //Se o botão ligar for pressionado 
    digitalWrite(pin_led, HIGH); //Liga o LED
  }

   //Se o botão desligar for pressionado 
   if(digitalRead(pin_botao_desligar)==0){
    digitalWrite(pin_led, LOW);//Desliga o LED
    digitalWrite(pin_rele_bomba, HIGH);//Desliga a bomba d'água
  } 
}

