#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerTwo, sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerThree, sensorLineFollower)
#pragma config(Sensor, dgtl1,  bumpSwitchTwo,  sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl3,  bumpSwitchThree, sensorTouch)
#pragma config(Sensor, dgtl9,  red2,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, red,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, yellow,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, green,          sensorLEDtoVCC)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, openLoop)
void Safety(); 
task main() {
	clearTimer(T1);
	while (1 == 1) {
		Safety(); 
		// FLOOR ONE
		if (SensorValue(lineFollowerTwo) < 200 && SensorValue(bumpSwitch) == 1) {
			turnLEDOff(red);
			turnLEDOff(red2);
			turnLEDOff(yellow);
			turnLEDOn(green);
			startMotor(rightMotor, 17);
			untilLight(300, lineFollower);
			stopMotor(rightMotor); 
			clearTimer(T1);
		}
		if (SensorValue(lineFollowerThree) < 1500 && SensorValue(bumpSwitch) == 1) {
			turnLEDOff(red);
			turnLEDOff(red2);
			turnLEDOff(yellow);
			turnLEDOn(green);
			startMotor(rightMotor, 17);
			untilLight(300, lineFollower);
			stopMotor(rightMotor); 
			clearTimer(T1);
		}
		if (SensorValue(lineFollower) < 200 && SensorValue(bumpSwitch) == 1) {
			turnLEDOff(red);
			turnLEDOff(red2);
			turnLEDOff(yellow);
			turnLEDOn(green);
			stopMotor(rightMotor); 
		}
		// FLOOR TWO
		if (SensorValue(lineFollowerThree) <1500  && SensorValue(bumpSwitchTwo) == 1) {
			turnLEDOff(green);
			turnLEDOff(red);
			turnLEDOff(red2);
			turnLEDOn(yellow);
			startMotor(rightMotor, 17);
			untilLight(300, lineFollowerTwo);
			stopMotor(rightMotor);
			clearTimer(T1);
		}
		if (SensorValue(lineFollower) < 200 && SensorValue(bumpSwitchTwo) == 1) {
			turnLEDOff(green);
			turnLEDOff(red);
			turnLEDOff(red2);
			turnLEDOn(yellow);
			startMotor(rightMotor, -17);
			untilLight(300, lineFollowerTwo);
			stopMotor(rightMotor);
			clearTimer(T1);
		} 
		if (SensorValue(lineFollowerTwo) < 200 && SensorValue(bumpSwitchTwo) == 1) {
			turnLEDOff(green);
			turnLEDOff(red);
			turnLEDOff(red2);
			turnLEDOn(yellow);
			stopMotor(rightMotor); 
		}
		// FLOOR THREE
		if (SensorValue(lineFollowerTwo) < 200 && SensorValue(bumpSwitchThree) == 1) {
			turnLEDOff(yellow);
			turnLEDOff(green);
			turnLEDOn(red);
			turnLEDOn(red2);
			startMotor(rightMotor, -17);
			untilLight(1000, lineFollowerThree);
			stopMotor(rightMotor);
			clearTimer(T1);
		}
		if (SensorValue(lineFollower) < 200 && SensorValue(bumpSwitchThree) == 1) {
			turnLEDOff(yellow);
			turnLEDOff(green);
			turnLEDOn(red);
			turnLEDOn(red2);
			startMotor(rightMotor, -17);
			untilLight(1000, lineFollowerThree);
			stopMotor(rightMotor);
			clearTimer(T1);
		}
		if (SensorValue(lineFollowerThree) < 1500 && SensorValue(bumpSwitchThree) == 1) {
			turnLEDOff(yellow);
			turnLEDOff(green);
			turnLEDOn(red);
			turnLEDOn(red2);
			stopMotor(rightMotor); 
		} 
	}
}
void Safety() {
	if(time1[T1] == 10000) {
		startMotor(rightMotor, 17);
		untilLight(300, lineFollower);
		stopMotor(rightMotor);
	}
}