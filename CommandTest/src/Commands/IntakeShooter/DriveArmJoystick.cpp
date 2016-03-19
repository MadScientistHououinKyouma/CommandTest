#include "DriveArmJoystick.h"

DriveArmJoystick::DriveArmJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooter);
	mode = t_intake;
}

// Called just before this Command runs the first time
void DriveArmJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveArmJoystick::Execute()
{
	SmartDashboard::PutNumber("Arm Angle", shooter->ArmAngle());
	SmartDashboard::PutNumber("Left Shooter Wheel Speed", shooter->LeftShooterSpeed());
	SmartDashboard::PutNumber("Right Shooter Wheel Speed", shooter->RightShooterSpeed());

	SmartDashboard::PutBoolean("Good To Shoot", shooter->ReadyToShoot());

	CommandBase::shooter->MoveThrottle(CommandBase::oi->operate->GetRawAxis(1));

	if(mode == t_spit){
		CommandBase::shooter->ManualLeftSpin(-oi->operate->GetRawAxis(2));
	}else{
		CommandBase::shooter->ManualLeftSpin(oi->operate->GetRawAxis(2));
	}

	if(mode == t_intake){
		CommandBase::shooter->ManualRightSpin(-oi->operate->GetRawAxis(3));
	}else{
		CommandBase::shooter->ManualRightSpin(oi->operate->GetRawAxis(3));
	}
}
// Make this return true when this Command no longer needs to run execute()
bool DriveArmJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveArmJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveArmJoystick::Interrupted()
{

}
