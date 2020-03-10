/*
 * To demostrate I2C slave
 */
 
#include<Wire.h>                                    //Library to use I2C communication
#define SLAVE_ADDR 9                                //Defines the slave address
#define MSG_SIZE 5                                  //Sets the message size to be sent

String msg = "HELLO";                               //Message to be sent

/*=============================================================================================================================
 *                                                  Parameters Setup
 *===========================================================================================================================*/
 
void setup() {
  Wire.begin(SLAVE_ADDR);                          1//Enabling communication...
;                                                    //Slave address is passed as a parameter which notifies this code is for slave device
  Serial.begin(9600);                               //Enabling Serial communication with baud rate 9600
  while (!Serial);                                  //Checks whether the serial communication is set
  Serial.println("Slave");                          //Prints message to serial monitor
  Serial.println("Starting I2C communication\n");   //Prints message to serial monitor
  Wire.onRequest(requestEvent);                     //requestEvent() method is called whenever master requests any data from slave
  Wire.onReceive(recieveEvent);                     //receiveEvent() method is called whenever master send data to the slave
}

/*=============================================================================================================================
 *                                                  Method requestEvent()
 *===========================================================================================================================*/

void requestEvent() {                               //Method returns nothing hence, void
  byte response[MSG_SIZE];                          //Declare a byte array to format string to character
  for (byte i = 0; i < MSG_SIZE; i++)               //Beginning of the for loop
    response[i] = (byte)msg.charAt(i);              //Formatting string character wise in response[] string
  Wire.write(response, sizeof(response));           //Write the response array to the master along with its size
  Serial.println("Request Event");                  //Prints message to serial monitor
}                                                   //End of the requestEvent() method

/*=============================================================================================================================
 *                                                  Method receiveEvent()
 *===========================================================================================================================*/

void recieveEvent() {                               //Method returns nothing hence, void
  byte val;                                         //Variable declaration
  while (Wire.available()) {                        //Checks whether the master is available for communication
    val = Wire.read();                              //Reads the data from the Master
  }                                                 //End of while(Wire.available())
  Serial.println("Receive Event");                  //Prints message to serial monitor
  Serial.print("Received message: ");               //Prints message to serial monitor
  Serial.println(val);                              //Prints the data received from the Master
  Serial.println();                                 //Prints a new line character (Next Line)
}                                                   //End of receiveEvent() method

/*=============================================================================================================================
 *                                                  Beginning of the Loop
 *===========================================================================================================================*/

void loop() {
  //Nothing much to do in loop
  delay(5000);                                        //Delay for 50 milliseconds
  //while(true);
}

/*=============================================================================================================================
 *                                                  End of Loop
 *===========================================================================================================================*/
