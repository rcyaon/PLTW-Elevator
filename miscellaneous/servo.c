#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, dgt9,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgt8,  bumpSwitch2,     sensorTouch)
#pragma config(Sensor, dgt7,  bumpSwitch3,     sensorTouch)
#pragma config(Sensor, dgt5,  sonar,          sensorSONAR_inch)
#pragma config(Sensor, dgtl10, red,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, yellow,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, green,          sensorLEDtoVCC)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, openLoop)

/* Team Members: Lena Conde-Araujo and Marianne Smith
Section: Activity 3.1.7 Elevator 
Date: March 8, 2022 */

task main() {
  ClearTimer(T1); // Servos use a timer to determine detination
  while(1==1) {
      if(time10[T1] == 1000) { 
        turnLEDOff(green);
        turnLEDOff(red);
        turnLEDOff(yellow); 
        setServo(rightServo, 115); 
        setServo(leftServo, -115);
        turnLEDOn(green);
    }
    
    if(SensorValue(limitSwitch1)==1) { // Registering floors
      ClearTimer(T1);          
      turnLEDOff(green);
      turnLEDOff(red);
      turnLEDOff(yellow);   
      setServo(rightServo, 115); 
      setServo(leftServo, -115);
      turnLEDOn(green); 
    }
      
    if(SensorValue(bumpSwitch1)==1) { // Determening destination, the floor the servo will end up on.
      ClearTimer(T1); 
      turnLEDOff(green);
      turnLEDOff(red);
      turnLEDOff(yellow); 
      setServo(rightServo, 115); 
      setServo(leftServo, -115); 
      turnLEDOn(green);
    }
      
    if(SensorValue(limitSwitch2)==1) {
      ClearTimer(T1);         
      turnLEDOff(green);
      turnLEDOff(red);
      turnLEDOff(yellow);    
      setServo(rightServo, 0);   
      setServo(leftServo, 0);
      turnLEDOn(yellow);          
    }
      
    if(SensorValue(bumpSwitch2)==1) {
    ClearTimer(T1);                
    turnLEDOff(green);
    turnLEDOff(red);
    turnLEDOff(yellow); 
    setServo(rightServo, 0);     
    setServo(leftServo, 0);
    turnLEDOn(yellow);                     
    }
      
    if(SensorValue(limitSwitch3)==1) {
      ClearTimer(T1);    
      turnLEDOff(green);
      turnLEDOff(red);
      turnLEDOff(yellow);
      setServo(rightServo, -115);
      setServo(leftServo, 115);
      turnLEDOn(red); 
    }
      
    if(SensorValue(bumpSwitch3)==1) {
      ClearTimer(T1);        
      turnLEDOff(green);
      turnLEDOff(red);
      turnLEDOff(yellow);
      setServo(rightServo, -115);
      setServo(leftServo, 115);
      turnLEDOn(red);
    }
  }
}
