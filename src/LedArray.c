#include <Arduino.h>

/**
 * Code By Travis Leeden
 * Code for controlling an LED based desk light
 */
int leds[6] = {13,12,11,10,9,8};

int button = 7;
int buttonState = 0;

int currentMode = 0;

void Train(long delaySeconds);

//the setup routine runs once when you press reset:
void setup()
{
  pinMode(button,INPUT);
  for(int i = 0; i <= 6; i++)
  {
	  pinMode(leds[i],OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop()
{
  buttonState = digitalRead(button);

  //if(buttonState == HIGH)
//  {
    Train(1000);
  //}

}

/**
 *  Lights the leds from left to right from top left to bottom right then turns them off in the same order.
 *  long delaySeconds = delay between each action
 */
void Train(long delaySeconds)
{
  for(int i = 0; i < 6; i++)
  {
    delay(delaySeconds);
    digitalWrite(leds[i],HIGH);
  }
  delay(delaySeconds);
  for(int i = 0; i < 6; i++)
  {
    delay(delaySeconds);
    digitalWrite(leds[i],LOW);
  }
}

void ButtonController()
{

}
