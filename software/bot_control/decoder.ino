const uint8_t NUM_CHANNELS = 6;

volatile unsigned long lastTime = 0;

volatile uint8_t channelNum = 0;

volatile uint16_t channelVals[NUM_CHANNELS] = {0};


/*
Notes:

Channel 0: Aileron
Channel 1: Elevator
Channel 2: Throttle
Channel 3: Rudder
Channel 4: Gear
Channel 5: Unresponsive (Should be flap)
*/

void pulseISR()
{
  unsigned long currentTime = micros(); // The nature of unsigned arithmetic guards against the issue of the timer eventually overflowing
  unsigned long deltaTime = currentTime - lastTime;
  lastTime = currentTime;

  // A sync pulse is about 13 milliseconds
  if(deltaTime > 5000)
  {
    channelNum = 0; // A long time between pulses indicates a sync pulse. Start measuring channel values from here
  }else
  {
    if(channelNum < NUM_CHANNELS)
    {
      channelVals[channelNum] = deltaTime;
      channelNum++;
    }else
    {
      Serial.println("Critical error - pulses exceed channel number");
      digitalWrite(13, HIGH);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW); // 13 to high indicates critical error
  attachInterrupt(digitalPinToInterrupt(2), pulseISR, RISING);
}

void loop()
{
  for(int i = 0; i < NUM_CHANNELS; i++)
  {
    Serial.print("Channel "); Serial.print(i); Serial.print(" "); Serial.print(channelVals[i]); Serial.print(" ");
  }
  Serial.println();
  delay(200);
}



