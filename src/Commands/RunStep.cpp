#include "RunStep.h"

RunStep::RunStep()
{
	iteration = 0;
	Requires(drive);
	Requires(gyro);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void RunStep::Initialize()
{
	step_size = SmartDashboard::GetNumber("step_size", 0);
	gyro->ResetGyro();
	anglePid = new NewPIDController(.05,0,0,0, false);
	printf("Rate Step Response for step_size=%f:\n", step_size);
}

// Called repeatedly when this Command is scheduled to run
void RunStep::Execute()
{
	drive->arcadeDrive(step_size, anglePid->Tick(gyro->GetAngle()));
	printf("%f\n", drive->GetRate());
}

// Make this return true when this Command no longer needs to run execute()
bool RunStep::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RunStep::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunStep::Interrupted()
{

}
