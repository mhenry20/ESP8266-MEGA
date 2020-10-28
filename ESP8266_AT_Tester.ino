/*
 * MHENRY: 10/28/2020
 * Program for testing AT commands with a Arduino connected to a ESP WiFI
 * board.
 * Use Serial Monitor to send AT commands and see results.
 */


int i=0;
char rx_string[500];


boolean DEBUG=true;

void showResponse(int waitTime){
    long t=millis();
    char c;
    while (t+waitTime>millis()){
      if (Serial3.available()){
        c=Serial3.read();
        if (DEBUG) Serial.print(c);
      }
    }                   
}

void setup() {
  DEBUG=true;

  rx_string[0]=0;

  Serial.begin(115200);                 // key element: enable serial to see program action in serial monitor
  Serial3.begin(115200);                // key element: enable serial3; printing to Serial3 sends information directly to ESP8266

  Serial.println("Serial Talk back to Arduino.");
  
  Serial3.println("AT+RST");          // if needed, Enable this AT command line to reset the module;
  showResponse(2000);

  Serial3.println("AT+GMR");
  Serial.println("Response from AT+GMR");
  showResponse(2000);
  
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
       showResponse(2000);
       i=0;
       rx_string[i] = 0;
    }
   } 
}
