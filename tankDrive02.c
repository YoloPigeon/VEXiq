#pragma config(Sensor, port2,  touchLED,       sensorVexIQ_LED)
#pragma config(Sensor, port5,  bumper,         sensorVexIQ_Touch)
#pragma config(Sensor, port8,  gyro,           sensorVexIQ_Gyro)
#pragma config(Sensor, port11, lightSensor,    sensorVexIQ_ColorGrayscale)
#pragma config(Motor,  motor7,          leftMotor,     tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor12,         rightMotor,    tmotorVexIQ, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*------------------------------------------------------------------------------------------------
  This program will use the VEX IQ Wirless Controller to drive your Clawbot. This program will use
  "Tank Mode" to enable two joysticks to drive the two main motors of the Robot.

  The 4 joystick axis on the VEX IQ Wireless Controller return values from -127 to +127.

  Adding threshold to compensate for joystick not landign in 0 position

------------------------------------------------------------------------------------------------*/

task main()
{
	int threshold = 10;					// treshold valeu 10 - 15 is a good option
	while(true)
	{
		if(getJoystickValue(ChA) > threshold || getJoystickValue(ChA) < -threshold)
		{
			setMotorSpeed(leftMotor, getJoystickValue(ChA));
		}
		else  //If less than the threshold, we'll set the motor to zero.
		{
			setMotorSpeed(leftMotor, 0);
		}

		//If the ChannelD (right Y-Axis) is greater than the threshold value,
		//then we'll set the speed of the motor to vlaue from the joystick.
		if(getJoystickValue(ChD) > threshold || getJoystickValue(ChD) < -threshold)
		{
			setMotorSpeed(rightMotor, getJoystickValue(ChD));
		}
		else  //If less than the threshold, we'll set the motor to zero.
		{
			setMotorSpeed(rightMotor, 0);
		}
	}
}
