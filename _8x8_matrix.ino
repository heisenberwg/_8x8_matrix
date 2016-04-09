#include <LedControl.h>
#include <stdio.h>

LedControl lc = LedControl(12, 11, 10);

#define DISP_ADDR 0
#define DIG_PIN 7
#define DELAY_MS 1000
#define INTENSITY 2
//int transistorPin = 13;

int led = 1, ledX = 0, ledY = 0;

void setup()
{
  Serial.begin(9600);
  while (!Serial);

  //wake up the MAX72XX from power-saving mode, enables display
  lc.shutdown(DISP_ADDR, false);
  //set a medium brightness for the Leds, range is 0-15
  lc.setIntensity(DISP_ADDR, INTENSITY);
  //clear screen
  lc.clearDisplay(0);
  led = Serial.read();
  ledX = led % 8;
  ledY = (led - ledX) / 8;
  Serial.println(led);
  Serial.print('X');
  Serial.print('\t');
  Serial.println(ledX);
  Serial.print('Y');
  Serial.print('\t');
  Serial.println(ledY);
}

void loop()
{
  lc.setLed(0, ledY, ledX, true);
  delay(100);
  /*for(int i = 0; i<8; i++)
    {
    for(int j = 0; j<8; j++)
    {
      lc.setLed(0, i, j, true);
      lc.clearDisplay(0);
    }
    }*/
}

