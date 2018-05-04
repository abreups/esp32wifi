/*

Como configurar o Wi-Fi no ESP32 LoRa
Autor: Paulo S. Abreu
04-maio-2018

*/

// change next line to use with another board/shield
#include <WiFi.h>

const char *ssid     = "ssid";
const char *password = "sua senha wi-fi";

void setup(){
  // para debug, abra o monitor serial na IDE do Arduino
  // e certifique-se de que a velocidade está em 115200
  Serial.begin(115200);

  WiFi.begin(ssid, password);   // inicializa o Wi-Fi

  // aguarda a conexão à rede Wi-Fi
  // Sai do loop se 60 * 500ms = 30s se passarem sem
  // que conexão seja estabelecida.
  int count = 0;
  while ( WiFi.status() != WL_CONNECTED && count < 60) {
    delay ( 500 );
    count++;
    Serial.println ( count );   // para debug. Acompanha o loop.
  }
  if (count == 60) {
    Serial.println("Falha tentando conectar ao Wi-Fi");  
  } else {
    Serial.println("Conectado ao Wi-Fi");  
  }
}

void loop() {

}
