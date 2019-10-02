


#include <SPI.h>
#include "e-ink-2.13.h"
#include "e-ink-display.h"


#include "FS.h"


#define COLORED     0
#define UNCOLORED   1

#define WIDTH   104
#define HEIGHT  212

/* 212x104, 1 bit per component. */
  unsigned char black[(WIDTH*HEIGHT)/8];
  unsigned char red[(WIDTH*HEIGHT)/8];
  Paint blackFrame(black, 0, 0);
  Paint redFrame(red,0,0);
  Epd epd;

volatile char updating = 0;

volatile char next = 0;
volatile char updates = 0;


char *root = "/";
Dir images;

int startUpdate() {
  if (!updating) {
     updating = 1;
     epd.ClearFrame();
     return updating;
  }
  return 0;
}
int stopUpdate() {
  epd.DisplayFrame(black,red);
  delay(1000);
  updating = 0;
}

void clearScreen() {
    redFrame.Clear(UNCOLORED);
    blackFrame.Clear(UNCOLORED);
}

void message(char *message, char line = 0) {
    blackFrame.DrawStringAt(10, 10+(line*12), message, &Font12, COLORED);
    updates++;
}

void advance() {
  File badgepic;
  if (next == 0) return;
  updates++;
  clearScreen();
  if (!images.next()) {
    images = SPIFFS.openDir(root);  //Reset to beginning
    if (!images.next()) {
      message("No files.");
      next = 0;
      return;
    }
  }

  message("File: ");
  message((char *)images.fileName().c_str(),1);
  //message(images.fileSize(),2);

  badgepic = images.openFile("r");
  badgepic.readBytes((char *)black,sizeof(black));
  badgepic.readBytes((char *)red,sizeof(red));
  badgepic.close();
    
  next = 0;
  return;
}

void flashButton() {
  if (!next) next = 1;
}
  
void setup() {
  char count = 0;
  char msg[256];
/* Use the "flash" button on the board.
 *  Button is at pin 0.  Pin is low on press.
 */
pinMode(0,INPUT_PULLUP);

/* Set up the canvas for dynamic handling of the display when not just blitting out images. */
  redFrame.SetWidth(WIDTH);
  redFrame.SetHeight(HEIGHT);
  redFrame.SetRotate(ROTATE_180);
  blackFrame.SetWidth(WIDTH);
  blackFrame.SetHeight(HEIGHT);
  blackFrame.SetRotate(ROTATE_180);

  epd.Init();

  /* Boot message */
  clearScreen();
  message("Init...");
  SPIFFS.begin();
  images = SPIFFS.openDir(root);
  while (images.next()) {
    count++;
  }
  images = SPIFFS.openDir(root);
  snprintf(msg,256,"%d images.",count);
  
  attachInterrupt(digitalPinToInterrupt(0),flashButton,RISING);
  message("OK.",1);
  message("Available:",3);
  message(msg,4);
  message("Hit FLASH key.",6);

}

void loop() {
  if (updates > 0) {
    updates = 0;
    epd.ClearFrame();
    epd.DisplayFrame(black,red);
  }
  advance();  //... if the button has been pressed.
  
}
