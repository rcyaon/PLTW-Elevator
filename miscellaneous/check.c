#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, dgt9,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgt8,  bumpSwitch2,     sensorTouch)
#pragma config(Sensor, dgt7,  bumpSwitch3,     sensorTouch)
#pragma config(Sensor, dgt5,  sonar,          sensorSONAR_inch)
#pragma config(Sensor, dgtl10, red,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, yellow,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, green,          sensorLEDtoVCC)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, openLoop)

task main(){
	while (1==1){
		stopMotor(rightMotor);
		untilLight(2900, lineFollower);
		startMotor(rightMotor, 127);
	}
} 