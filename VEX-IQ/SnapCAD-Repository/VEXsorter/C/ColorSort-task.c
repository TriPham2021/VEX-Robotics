#pragma config(Sensor, port3,  Color,          sensorVexIQ_Color12Color)
#pragma config(Sensor, port4,  Distance,       sensorVexIQ_Distance)
#pragma config(Sensor, port5,  ColorDisplay,   sensorVexIQ_LED)
#pragma config(Sensor, port9,  StartAgain,     sensorVexIQ_LED)
#pragma config(Motor,  motor1,          Belt,          tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor2,          ArmRotate,     tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          Gripper,       tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor8,          ArmLift,       tmotorVexIQ, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int ArmAngle;

void InitMotors(void)
{
  setMotorBrakeMode(ArmLift, motorCoast);
  setMotorCurrentLimit(ArmLift, 100);
  setMotorSpeed(ArmLift, 40);
  waitUntilMotorStop(ArmLift);
  setMotorSpeed(ArmLift, 0);
  wait1Msec(200);
  resetMotorEncoder(ArmLift);
  setMotorBrakeMode(ArmLift, motorHold);

  setMotorBrakeMode(ArmRotate, motorCoast);
  setMotorCurrentLimit(ArmRotate, 60);
  setMotorSpeed(ArmRotate, 40);
  waitUntilMotorStop(ArmRotate);
  setMotorSpeed(ArmRotate, 0);
  wait1Msec(200);
  resetMotorEncoder(ArmRotate);
  setMotorBrakeMode(ArmRotate, motorHold);

  setMotorBrakeMode(Gripper, motorCoast);
  setMotorCurrentLimit(Gripper, 100);
  setMotorSpeed(Gripper, 40);
  waitUntilMotorStop(Gripper);
  setMotorSpeed(Gripper, 0);
  wait1Msec(200);
  resetMotorEncoder(Gripper);
  setMotorBrakeMode(Gripper, motorHold);

  resetMotorEncoder(Belt);
  setMotorCurrentLimit(Gripper, 200);
  setMotorCurrentLimit(ArmRotate, 200);

}
void ResetArm(void)
{
  setMotorTarget(Gripper, -300, 40);
  waitUntilMotorStop(Gripper);
  setMotorTarget(ArmLift, -150, 40);
  setMotorTarget(ArmRotate, 0, 100);
  waitUntilMotorStop(ArmLift);
  waitUntilMotorStop(ArmRotate);
}

void PickBrick(void)
{
  // Pick Brick
  setMotorTarget(Gripper, -200, 40);
  waitUntilMotorStop(Gripper);
  // Raise Arm
  setMotorTarget(ArmLift, -80, 40);
  waitUntilMotorStop(ArmLift);
}

void MoveArm(int ArmRotAngle)
{
  // Turn Arm
  setMotorTarget(ArmRotate, ArmRotAngle, 100);
  waitUntilMotorStop(ArmRotate);
  // Lower Arm
  setMotorTarget(ArmLift, -150, 40);
  waitUntilMotorStop(ArmLift);
  // Drop Brick
  setMotorTarget(Gripper, -300, 40);
  waitUntilMotorStop(Gripper);
  // Raise Arm
  setMotorTarget(ArmLift, -80, 40);
  waitUntilMotorStop(ArmLift);
}

// Arm rotate range: 0 (on belt) to -600
// Arm lift range: 0 (fully up) to -150 (on belt)
// Gripper range: 0 (fully close) to -300 (fully open)

task Dispatch()
{
  int ArmRotAngle;
  while(true)
  {
    while(ArmAngle == 0) wait1Msec(100);
    PickBrick();
    ArmRotAngle = ArmAngle;
    ArmAngle = 0;
    MoveArm(ArmRotAngle);
    ResetArm();
  }
}

task main()
{
  int currentHueValue, detectedColor, dist;
  InitMotors();
  int ArmRotAngle;
  setColorMode(Color,colorTypeRGB_Hue_Reflected);
  ArmAngle=0;
  ResetArm();
  setMotorSpeed(Belt, 25);
  startTask(Dispatch);
  while(true)
  {
        while (dist=getDistanceStrongest(Distance)>40)
        {

          wait1Msec(20);
          if(getMotorEncoder(Belt)>1100)
          {
            setMotorSpeed(Belt, 0);
            setTouchLEDBlinkTime(StartAgain, 10, 10);
            setTouchLEDColor(StartAgain, colorGreen);
            while(getTouchLEDValue(StartAgain)==0)wait1Msec(100);
            setTouchLEDColor(StartAgain, colorNone);
            setMotorSpeed(Belt, 30);
            resetMotorEncoder(Belt);
          }
        }

      resetMotorEncoder(Belt);
      while (getMotorEncoder(Belt)<315) wait1Msec(10);
      currentHueValue = getColorValue(Color);
      if((currentHueValue <= 15)||(currentHueValue) > 250)
      {
        detectedColor = colorRed;
        ArmRotAngle = -215;
      }
      else if((currentHueValue > 15) && (currentHueValue <= 40))
      {
        detectedColor = colorOrange;
        ArmRotAngle = -275;
      }
      else if((currentHueValue > 40) && (currentHueValue <= 90))
      {
        detectedColor = colorYellow;
        ArmRotAngle = -365;
      }
      else if((currentHueValue > 90) && (currentHueValue <= 130))
      {
        detectedColor = colorGreen;
        ArmRotAngle = -480;
      }
      else if((currentHueValue > 131) && (currentHueValue <= 219))
      {
        detectedColor = colorBlue;
        ArmRotAngle = -550;
      }
      setTouchLEDColor(ColorDisplay, detectedColor);
      while (getMotorEncoder(Belt)<560) wait1Msec(10);
      setMotorSpeed(Belt, 0);
      wait1Msec(100);
      ArmAngle = ArmRotAngle;
      while(ArmAngle != 0) wait1Msec(100);
      setMotorSpeed(Belt, 25);
      setTouchLEDColor(ColorDisplay, colorNone);
      wait1Msec(100);
  }
}