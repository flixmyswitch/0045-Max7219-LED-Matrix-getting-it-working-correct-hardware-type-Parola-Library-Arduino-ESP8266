// Program to demonstrate the MD_Parola library
//
// Uses the Arduino Print Class extension with various output types
//
// MD_MAX72XX library can be found at https://github.com/MajicDesigns/MD_MAX72XX
//
// Flixmyswitch 2022
//
// Edited by Andy Shrimpton www.flixmyswitch.com  -- YouTube search for "flixmyswitch"
//
// Video number 1 in this series

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

const uint16_t WAIT_TIME = 1500;      // the delay in ms between characters

// uncomment only ONE  of the next four options
// select which type of matrix you are using

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
//#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
//#define HARDWARE_TYPE MD_MAX72XX::ICSTATION_HW

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted

#define MAX_DEVICES 4

#define CLK_PIN   14 // or SCK
#define DATA_PIN  13 // or MOSI
#define CS_PIN    15 // or SS

// Hardware SPI connection
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);  // I called this "P" but you can call it anything
// Arbitrary output pins
// MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup(void)
{
  P.begin();            // initiate the dispaly
  P.displayClear();     // clear the display
  P.setIntensity(1);    // set the intensity 0 to 15
  P.setInvert(false);   // sets invert for all zones OK, we will cover zones in another video
}

void loop(void)
{
  P.print("Hello");       // Hello
  delay(WAIT_TIME);
  P.print(1234, DEC);     // 1234
  delay(WAIT_TIME);
  P.print(1234, HEX);     // 4D2
  delay(WAIT_TIME);
  P.print(12);            // print the whole number 12
  delay(WAIT_TIME);
  P.print(14.7);          // float not supported by Arduino Print class so will print 14.70
  delay(WAIT_TIME);
  P.println("end");       // avoid using println as it does not work
  delay(WAIT_TIME);
  P.print("end");         // end
  delay(WAIT_TIME);
  P.write(77);            // print standard ASCII valves 0 to 126 in this case "M"  https://www.w3schools.com/charsets/ref_html_ascii.asp
  delay(WAIT_TIME);
  P.print(77);            // 77
  delay(WAIT_TIME);
  P.write('A');           // A
  delay(WAIT_TIME);
  P.write('B');           // B
  delay(WAIT_TIME);
  P.write('C');           // C
  delay(WAIT_TIME);       
}
