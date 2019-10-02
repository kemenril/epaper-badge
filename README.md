# epaper-badge
Simple project to use a Heltec (or similar) epaper module as a name badge.  


Included here is a simple set of tools that allow you to write images to a cheap epaper display module
using a NodeMCU or the like.  A library of images is stored on the module itself, and you flip through
them by pushing the flash button.  The module can then be disconnected from the device, put in a case, and
pinned to your shirt.  It's a rather more understated version of the LED badges that are so popular 
these days.  Epaper being what it is, no batteries are required in the badge itself.  The programmer
I built powers itself over USB, and you can use a car charger, portable battery, or OTG cable if you
like.  The following things are included:

   * The libraries for driving these displays distributed by Heltec with their example code, for convenience.  You should copy the contents of the libraries directory into your Arduino envoronment's libraries directory.
   * An Arduino sketch, *badge-fs*, suitable for a NodeMCU or similar microcontroller board, using the esp8266 core and the above libraries.
   * The *pinout* file, which describes, more or less, how to hook the NodeMCU up to the display for writing images to it.
   * A Mathematica notebook, *image-convert.nb*, to make raw images for loading onto the epaper display.
   * An example raw image in the sketch data directory, generated using the notebook above.

Aside from the Arduino environment, you'll need the ESP8266 core to use your NodeMCU.  
See the insructions here: http://arduino.esp8266.com/Arduino/versions/2.0.0/doc/installing.html
   
You'll also want the SPIFFS data uploader, so that once you have a library of images, you can 
write them into the module.  
See the instructions here: https://github.com/esp8266/arduino-esp8266fs-plugin
   
If you'd like to do something else to produce raw images, note that they're written directly to the screen as a
stack (two deep) of 1-bit rasters, black first, for the same number of bits as there are pixels on the display,
and then red -- or possibly yellow, depending on your epaper module.  The image file should be twice the size in 
bits as the resolution of the display.  There is no other data in the file.  

