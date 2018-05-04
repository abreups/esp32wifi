/*

Como configurar o Wi-Fi no ESP32 LoRa
Autor: Paulo S. Abreu
04-maio-2018

*/

// change next line to use with another board/shield
#include <WiFi.h>

const char *ssid     = "seu ssid";
const char *password = "sua senha wi-fi";

void setup(){
  // para debug, abra o monitor serial na IDE do Arduino
  // e certifique-se de que a velocidade está em 115200
  Serial.begin(115200);

  WiFi.begin(ssid, password);   // inicializa o Wi-Fi

  // aguarda a conexão à rede Wi-Fi
  // Note que este loop é "infinito" até que a conexão
  // seja estabelecida.
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  Serial.println("Conectado ao Wi-Fi");

}

void loop() {

}
