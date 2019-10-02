# epaper-badge
Simple project to use a Heltec (or similar) epaper module as a name badge.  


Included here is a simple set of tools that allow you to write images to a cheap epaper display module
using a NodeMCU or the like.  A library of images is stored on the module itself, and you flip through
them by pushing the flash button.  The module can then be disconnected from the device, put in a case, and
pinned to your shirt.  It's a rather more understated version of the LED badges that are so popular 
these days.  Epaper being what it is, no batteries are required in the badge itself.  The programmer
I built powers itself over USB, and you can use a car charger, portable battery, or OTG cable if you
like.  The following things are included:

   * The libraries for driving these displays distributed by Heltec with their example code, for convenience.
   * An Arduino sketch suitable for a NodeMCU or similar microcontroller board, using the esp8266 core and the above libraries.
   * The *pinout* file, which describes, more or less, how to hook the NodeMCU up to the display for writing images to it.
   * A *Mathematica* notebook I've been using to make raw images for loading onto the epaper display.
   * An example raw image generated using the notebook above.

Aside from the Arduino environment, you'll need the ESP8266 core to use your NodeMCU.  
See the insructions here: http://arduino.esp8266.com/Arduino/versions/2.0.0/doc/installing.html
   
You'll also want the SPIFFS data uploader, so that once you have a library of images, you can 
write them into the module.  
See the instructions here: https://github.com/esp8266/arduino-esp8266fs-plugin
   
