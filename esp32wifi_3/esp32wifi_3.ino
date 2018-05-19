/*

Como configurar o Wi-Fi no ESP32 LoRa
Autor: Paulo S. Abreu
04-maio-2018

*/

// change next line to use with another board/shield
#include <WiFi.h>
//biblioteca para comunicação com o display
#include "SSD1306.h"

// construtor do objeto do display
// parametros: address,SDA,SCL
// (Documentação da placa WiFi LoRa 32)
SSD1306 tela(0x3c, 4, 15); 

// ssid e senha da rede Wi-Fi à qual
// você pretende se conectar.
const char *ssid     = "ssid da rede wifi";
const char *password = "senha da rede wifi";

void setup(){

  // Preparação do display

  //configura GPIO16 como saida
  pinMode(16,OUTPUT);       // GPIO16 como saída
  digitalWrite(16, LOW);    // reseta o OLED
  delay(10);                // aguarda pelo menos 5 ms
  digitalWrite(16, HIGH);   // mantém GPIO16 em 1 durante uso do OLED
  tela.init();              // inicializa o display
  tela.clear();             // limpa a tela do display

  // Coloca aviso de que vamos tentar nos conectar ao Wi-Fi
  tela.drawString(0, 0, "Conectando ao Wi-Fi");
  tela.display();

  // Conexão ao Wi-Fi
  WiFi.begin(ssid, password);   // inicializa o Wi-Fi

  // aguarda a conexão à rede Wi-Fi
  // Sai do loop se 60 * 500ms = 30s se passarem sem
  // que conexão seja estabelecida.
  int count = 0;
  while ( WiFi.status() != WL_CONNECTED && count < 60) {
    delay ( 500 );
    count++;
    tela.drawString(count, 10, "o");  // prepara o texto.
    tela.display();                   // mostra o texto no display.
  }
  if (count == 60) {
    tela.clear();   // apaga o texto que está no display
    tela.drawString(0, 0, "Falha tentando conectar ao Wi-Fi");
    tela.display(); // mostra o texto preparado no display
  } else {
    tela.clear();   // apaga o texto que está no display
    tela.drawString(0, 0, "Conectado ao Wi-Fi");
    // mostra o ssid da rede wifi
    tela.drawString(0, 10, WiFi.SSID());
    // mostra o endereço IP recebido
    tela.drawString(0, 20, WiFi.localIP().toString());
    // mostra o endereço MAC da placa
    tela.drawString(0, 30, WiFi.macAddress());
    tela.display(); // mostra o texto preparado no display
  }
}

void loop() {

}
