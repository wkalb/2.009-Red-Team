#!/usr/bin/python

from Adafruit_PWM_Servo_Driver import PWM

# Initialise the PWM device using the default address
pwm = PWM(0x40, debug=True)

# Edit these values to correspond to your brand of servo.
servoMin = 104  # Min pulse length out of 4096, 0 degrees.
servoMax = 521  # Max pulse length out of 4096, 180 degrees.
servoSpan = servoMax - servoMin
pwm.setPWMFreq(50) # Sets PWM frequency to 50 Hz

def setPosition(channel, position):
  if position > 180:
    position = 180
  if position < 0:
    position = 0
  pulse = position * servoSpan/180 + servoMin
  pwm.setPWM(channel, 0, pulse)

