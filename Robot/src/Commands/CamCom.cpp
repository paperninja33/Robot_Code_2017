/*
 * CamCom.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: Robot Mafia
 */

#include "CamCom.h"

//Servo *bottomServo = new Servo(7);
//Servo *sideServo = new Servo(8);


// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "CamCom.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

CamCom::CamCom(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::CamSub.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	DPadLeft = false;
	DPadRight = false;

}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void CamCom::Initialize() {
	DPadLeft = false;
	DPadRight = false;
}

// Called repeatedly when this Command is scheduled to run
void CamCom::Execute() {
		DPadRight = Robot::oi->getDriverJoystick()->GetPOV(3);
		DPadLeft = Robot::oi->getDriverJoystick()->GetPOV(7);
		if(DPadRight){
			Robot::CamSub->CamTurn(180);
		}
		else if(DPadLeft){
			Robot::CamSub->CamTurn(0);
		}

}

// Make this return true when this Command no longer needs to run execute()
bool CamCom::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void CamCom::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CamCom::Interrupted() {

}