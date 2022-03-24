#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, dgt9,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgt8,  bumpSwitch2,     sensorTouch)
#pragma config(Sensor, dgt7,  bumpSwitch3,     sensorTouch)
#pragma config(Sensor, dgt5,  sonar,          sensorSONAR_inch)
#pragma config(Sensor, dgtl10, red,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, yellow,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, green,          sensorLEDtoVCC)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, openLoop)

// only displays the first floor 
task main() {
	while (1 == 1) {
		if (SensorValue(lineFollower) == 3100 && SensorValue(bumpSwitch) == 1) { // on lvl 1 and called to lvl 1
			stopMotor(rightMotor);
		}
		if (SensorValue(lineFollower) == 3100 && SensorValue(bumpSwitch2) == 1) { // on lvl 1 and called to lvl 2
			startMotor(rightMotor, 127);
			untilLight(3000, lineFollower);
			stopMotor(rightMotor);
		}
		if (SensorValue(lineFollower) == 3100 && SensorValue(bumpSwitch3) == 1) { // on lvl 1 and called to lvl 3
			startMotor(rightMotor, 127);
			untilLight(2900, lineFollower);
			stopMotor(rightMotor);
		}
	}
}
