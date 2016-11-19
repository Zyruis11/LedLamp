/**
 * Code By Travis Leeden
 * Code for controlling an LED based desk light
 */

//Variables for led pin numbers
int leds[12] = {13,12,11,10,9,8,7,6,5,4,3,2};
int ledCount = 12;
int blueLeds[4] = {13,12,11,10};
int redLeds[4] = {9,8,7,6};
int whiteLeds[4] = {5,4,3,2};

int button = 1;
//Button state for remembering if the button is HIGH or LOW
int buttonState = 0;

//Current selected animation
int currentMode = 0;

//Function Signitures
void Train(long delaySeconds);
void OneByOne(long delaySeconds);
void Flash(long delaySeconds);
void AllOn(void);
void SetMode(int mode);
void ButtonController();

//the setup routine runs once when you press reset:
void setup()
{
  Serial.begin(9600);
  while (! Serial); // Wait until Serial is ready
  Serial.println("Type A Command Number 1 - 4");
  pinMode(button,INPUT);
  for(int i = 0; i <= ledCount; i++)
  {
	  pinMode(leds[i],OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop()
{
  buttonState = digitalRead(button);
  SerialReader();
}

/**
 *  Lights the leds from left to right from top left to bottom right then turns them off in the same order.
 *  long delaySeconds = delay between each action
 */
void Train(long delaySeconds)
{
  for(int i = 0; i < ledCount; i++)
  {
    delay(delaySeconds);
    digitalWrite(leds[i],HIGH);
  }
  delay(delaySeconds);
  for(int i = 0; i < ledCount; i++)
  {
    delay(delaySeconds);
    digitalWrite(leds[i],LOW);
  }
}

/**
 *  Lights the leds one by one(In Order) and turns them off before lighting the next one.
 * delaySeconds = milliseconds between each action
 */
void OneByOne(long delaySeconds)
{
  for(int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i],HIGH);
    delay(delaySeconds);
    digitalWrite(leds[i],LOW);
  }
}

/**
 * Flashes all of the leds on then off
 * delaySeconds = milliseconds between each flash.
*/
void Flash(long delaySeconds)
{
  for(int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i],HIGH);
  }
  delay(delaySeconds);
  for(int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i],LOW);
  }
  delay(delaySeconds);
}

/**
 * Turns all connected leds on
*/
void AllOn(void)
{
  for(int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i],HIGH);
  }
}

/**
 * Turns all connected leds off
*/
void ClearLeds(void)
{
  for(int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i],LOW);
  }
}

/**
 * Serial Reader for getting commands from serial console.
 * Only used for debugging
*/
void SerialReader(void)
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch >= '0' && ch <= '7')
    {
      currentMode = ch - '0';
      SetMode(currentMode);
      Serial.print("Activated ");
      Serial.println(currentMode);
    }
    if (ch == 'x')
    {
      currentMode = 0;
      ClearLeds();
      Serial.println("Cleared");
    }
  }
}

/**
 * Sets the mode for lamp
*/
void SetMode(int mode)
{
  switch(mode)
  {
    case 1:
      Train(500);
      break;
    case 2:
      OneByOne(500);
      break;
    case 3:
      Flash(500);
      break;
    case 4:
      AllOn();
      break;
    default:
      ClearLeds();
      break;
  }
}

//TODO: Add button to control the animations
void ButtonController(void)
{
}
