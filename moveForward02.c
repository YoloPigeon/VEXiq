#pragma config(Sensor, port2,  touchLED,       sensorVexIQ_LED)
#pragma config(Sensor, port5,  bumper,         sensorVexIQ_Touch)
#pragma config(Sensor, port8,  gyro,           sensorVexIQ_Gyro)
#pragma config(Sensor, port11, lightSensor,    sensorVexIQ_ColorGrayscale)
#pragma config(Motor,  motor7,          leftMotor,     tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor12,         rightMotor,    tmotorVexIQ, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*------------------------------------------------------------------------------------------------
This program will drive your robot forward for a lnown distance based on motor encoder
------------------------------------------------------------------------------------------------*/

task main()
{
	while(true)
	{
		//Reset the current position in the motor encoder to zero.
		resetMotorEncoder(leftMotor);
		resetMotorEncoder(rightMotor);
		//Set motor to run 5000 counts at power level 75.
		moveMotorTarget(leftMotor, 5000, 75);
		moveMotorTarget(rightMotor, 5000, 75);
		//Blocking command prevents program from continuing until movement is complete.
		waitUntilMotorStop(leftMotor);
		waitUntilMotorStop(rightMotor);
	}
}
