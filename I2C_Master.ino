/*
 * To demostarate I2C master
 */

#include<Wire.h>                                    //Library to use I2C communication
#define SLAVE_ADDR 9                                //Slave Address: 0x09
#define MSG_SIZE 5                                  //Size of the message to be sent

/*=============================================================================================================================
 *                                                  Parameters setup
 *===========================================================================================================================*/

void setup() {
  Wire.begin();                                     //Enabling communication...
                                                    //If no parameters are passed then the device is a master
  Serial.begin(9600);                               //Enabling Serial communication with baud rate 9600
  while(!Serial);                                   //Checks whether the serial communication is set
  Serial.println("Master");                         //Prints message on the serial monitor
  Serial.println("Starting I2C communication\n");   //Prints message on the serial monitor
}

/*=============================================================================================================================
 *                                                  Beginning of the Loop
 *===========================================================================================================================*/
 
void loop() {
  delay(5000);                                        //delay of 50 milliseconds for effective communication
  Serial.println("Writing to Slave....");           //Prints message on the serial monitor
  Wire.beginTransmission(SLAVE_ADDR);               //Begins I2C communication with the slave whose address is mentioned
  Wire.write(1);                                    //Writes message to the slave
  Wire.endTransmission(true);                       //Ends the I2C communication

  Serial.println("Recieving data from slave....");  //Prints message on the serial monitor
  Wire.beginTransmission(SLAVE_ADDR);               //Begins the I2C communication with the slave
  Wire.requestFrom(SLAVE_ADDR,MSG_SIZE);            //Master requests the message (having some predefined size) from the slave
  String msg = " ";                                 //String variable declaration and initialization to null
  while(Wire.available()){                          //Keeps communicating with the slave until the communication ends
    char ch = Wire.read();                          //Reads character by character from the slave
    msg += ch;                                      //Appending each character to the string
  }
  Serial.println(msg);                              //Print the message received from the slave
  //while(true);
}

/*=============================================================================================================================
 *                                                  End of the Loop
 *===========================================================================================================================*/
