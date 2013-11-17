
import servo_driver
import time

#pin info

SPINE_POS = 0
SPINE_NEG = 1

EYE_POS = 0
EYE_NEG = 1

LEFT_ARM_POS = 1
LEFT_ARM_NEG = 0
RIGHT_ARM_POS = 0
RIGHT_ARM_NEG = 1

#constants determined by experiment

SPINE_SPEED = 1
SPINE_CURLED = .4

EYE__SPEED = .1
EYES_CLOSED = 1

ARM_SPEED = .2 #anything you want between 0 and 1
ARM_CURLED = .2 #how far the arm closes (you probably shouldn't mess with this)

HEAD = 2 #pin for servo

def spine_curl():
    try:
        servo_driver.setMotorSpeed(SPINE_NEG,SPINE_POS,SPINE_SPEED)
    #    print 0
        time.sleep(SPINE_CURLED/SPINE_SPEED)
     #   print 1
        servo_driver.setMotorSpeed(SPINE_NEG,SPINE_POS,0)
        print "curled"
    except:
      #  print 10000
        servo_driver.setMotorSpeed(SPINE_NEG,SPINE_POS,0)



def spine_uncurl():
    try:
        servo_driver.setMotorSpeed(SPINE_NEG,SPINE_POS,-SPINE_SPEED)
        time.sleep(SPINE_CURLED/SPINE_SPEED)
        print SPINE_CURLED/SPINE_SPEED
        servo_driver.setMotorSpeed(SPINE_NEG,SPINE_POS,0)
        print "uncurled"
    except:
        servo_driver.setMotorSpeed(SPINE_NEG,SPINE_POS,0)
        print 10000

def close_eyes():
    try:
        servo_driver.setMotorSpeed(EYE_POS,EYE_NEG,EYE_SPEED)
        time.sleep(EYES_CLOSED/SPEED)
        servo_driver.setMotorSpeed(EYE_POS,EYE_NEG,0)
    except:
        servo_driver.setMotorSpeed(EYE_POS,EYE_NEG,0)


def open_eyes():
    try:
        servo_driver.setMotorSpeed(EYE_POS,EYE_NEG,-EYE_SPEED)
        time.sleep(EYES_CLOSED/SPEED)
        servo_driver.setMotorSpeed(EYE_POS,EYE_NEG,0)
    except:
        servo_driver.setMotorSpeed(EYE_POS,EYE_NEG,0)

def blink():
    close_eyes()
    time.sleep(.5)
    open_eyes()


def close_arms():
    try:
        servo_driver.setMotorSpeed(LEFT_ARM_POS,LEFT_ARM_NEG,-ARM_SPEED)
#        servo_driver.setMotorSpeed(RIGHT_ARM_POS,RIGHT_ARM_NEG,ARM_SPEED)
        time.sleep(ARM_CURLED/ARM_SPEED)
        servo_driver.setMotorSpeed(LEFT_ARM_POS,LEFT_ARM_NEG,0)
#        servo_driver.setMotorSpeed(RIGHT_ARM_POS,RIGHT_ARM_NEG,0)
    except:
        servo_driver.setMotorSpeed(LEFT_ARM_POS,LEFT_ARM_NEG,0)
#        servo_driver.setMotorSpeed(RIGHT_ARM_POS,RIGHT_ARM_NEG,0)

def open_arms():
    try:
        servo_driver.setMotorSpeed(LEFT_ARM_POS,LEFT_ARM_NEG,ARM_SPEED)
#        servo_driver.setMotorSpeed(RIGHT_ARM_POS,RIGHT_ARM_NEG,-ARM_SPEED)
        time.sleep(ARM_CURLED/ARM_SPEED)
        servo_driver.setMotorSpeed(LEFT_ARM_POS,LEFT_ARM_NEG,0)
#        servo_driver.setMotorSpeed(RIGHT_ARM_POS,RIGHT_ARM_NEG,0)
    except:
        print 10000
        servo_driver.setMotorSpeed(LEFT_ARM_POS,LEFT_ARM_NEG,0)
#        servo_driver.setMotorSpeed(RIGHT_ARM_POS,RIGHT_ARM_NEG,0)

def headtilt():
    servo_driver.setServoPosition(HEAD,60)
    time.sleep(2)
    servo_driver.setServoPosition(HEAD,120)


def hug():  #but you're so close to getting it right!
    spine_curl()
    close_arms()
    time.sleep(5)
    open_arms()
    spine_uncurl()



#spine_uncurl()
#time.sleep(5)
#print 1#
#spine_curl()

headtilt()

#servo_driver.setMotorSpeed(0,1,0)
#time.sleep(5)
#print 0
#ervo_driver.setMotorSpeed(0,1,1)
#ime.sleep(5)
#rint 1
#servo_driver.setMotorSpeed(0,1, .9)#
#time.sleep(5)
#print .9#
#servo_driver.setMotorSpeed(0,1, 0.8)
#time.sleep(5)
#print .8
#servo_driver.setMotorSpeed(0,1, 0.7)
#time.sleep(5)
#print .7
#servo_driver.setMotorSpeed(0,1,.5)
#time.sleep(5)
#print .5
#servo_driver.setMotorSpeed(0,1,.5)
#time.sleep(2)
#servo_driver.setMotorSpeed(0,1,0)
