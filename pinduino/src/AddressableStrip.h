/*
  RGBStrip.h - Library for pinduino shield for Arduinos.
  Created by Eric Lyons and Wes Sparks, 2015.
  Released into the public domain.
  Play more pinball!
*/
#ifndef AddressableStrip_h
#define AddressableStrip_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class AddressableStrip
{
  public:
    //Constructor
    //initialize strip for appropriate data pin
    AddressableStrip(int num, int pin);

    void setNumLEDs(int num);
    int getNumLEDs();

    // Adafruit_NeoPixel (# of LEDs, Signal Pin, Refresh Rate)
    Adafruit_NeoPixel* strip();

    //functions for controlling 5V Addressable RGB strips
    void color2RGB(String color, int &r, int &g, int &b);
    //color the entire strip some color
    //valid colors are (case insensitive):  red, green, blue, yellow, cyan, purple, white, orange, lime, sky, mint, magenta, lavender
    void color(String color, int brightness);
    //If you want to specify by R, G, B values between 0-255
    void colorRGB(int r, int g, int b, int brightness);

    void clear();
    void fadeIn(String color, float time);
    void fadeInRGB(int r, int g, int b, float time);
    void fadeOut(float steps);

    //Note: to write
    void fadeRGB2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float time);
    void fadeColor2Color(String color1, String Color2, float time);

    void RGBBand(int pos, int r, int g, int b, int span);
    void chase2RGB(float r1, float g1, float b1, float r2, float g2, float b2, float span, int time, int dir);
    void chase2Color(String color1, String color2, float span, int time, int dir);
    void chaseRGB(int r, int g, int b, int span, int time, int dir);
    void chase(String color, float span, int time, int dir);
    void spreadInFromPoint2RGB (int pos, float r1, float g1, float b1, float r2, float g2, float b2, int time);
    void spreadInFromPoint2Color (int pos, String color1, String color2, int time);
    void spreadInFromPointRGB (int pos, float r, float g, float b, int time);
    void spreadInFromPoint (int pos, String color, int time);
    void spreadOutFromPoint (int pos, float time);
    void spreadOutToPoint (int pos, float time);
    void explosionRGB(int pos, int r, int g, int b, int span);
    void explosion(int pos, String color, int span);

    //Rainbow effect
    void rainbow(int wait);
    void rainbowCycle(int wait);
    int Wheel(int WheelPos);
    

  private:
    int _pin; //data pin 
    int _numLEDs = 0; // number of LEDs in strip;
    Adafruit_NeoPixel* _strip; 
};

#endif
