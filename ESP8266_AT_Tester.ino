/*
 * Author: Mike Henry 10/28/2020
 * Program for testing AT commands with a Arduino connected to a ESP WiFI
 * board.
 * Use Serial Monitor to send AT commands and see results.
 */

int i=0;
char rx_string[500];

void setup() {

  rx_string[0]=0;

  Serial.begin(115200);                 // key element: enable serial to see program action in serial monitor
  Serial3.begin(115200);                // key element: enable serial3; printing to Serial3 sends information directly to ESP8266

  Serial.println("Serial Talk back to Arduino.");
  
  Serial3.println("AT+RST");          // if needed, Enable this AT command line to reset the module;
  display_serial(2000);

  Serial3.println("AT+GMR");
  Serial.println("Response from AT+GMR");
  display_serial(2000);
  
}

void loop() {
char rx_byte = 0;

if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    rx_string[i] = rx_byte;
    i++;
    if( rx_byte == '\n' ){
       rx_string[i-1] = 0;
       Serial.print("Sending: ");
       Serial.println(rx_string);
       Serial3.println(rx_string);
       Serial.println("Received: ");
       display_serial(2000);
       i=0;
       rx_string[i] = 0;
    }
   } 
}

void display_serial(int wait_time){
    long t=millis();
    char c;
    while (t+wait_time>millis()){
      if (Serial3.available()){
        c=Serial3.read();
        Serial.print(c);
      }
    }                   
}
