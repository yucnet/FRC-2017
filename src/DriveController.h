#ifndef DRIVECONTROLLER_H_
#define DRIVECONTROLLER_H_

#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"
#include "DriveYMotorsPIDOutput.h"
#include "DriveRotateMotorsPIDOutput.h"
#include "DriveEncodersPIDSource.h"
#include "DashboardLogger.h"
#include "ini.h"
#include <iostream>

class PivotCommand;

class DriveController {
public:
	DriveController(RobotModel *myRobot, RemoteControl *myHumanControl);
	virtual ~DriveController();

	void Stop();
	void Update(double currTimeSec, double deltaTimeSec);
	void Reset();
	void ArcadeDrive(double myX, double myY, bool teleOp);
	void TankDrive(double myLeft, double myRight);
	  void RefreshIni();

	enum DriveState {
		kInitialize, kTeleopDrive
	};

	PIDOutput *driveXPIDOutput;
	PIDController *driveXPID;

	PIDOutput *driveYPIDOutput;
	PIDController *driveYPID;
	DriveEncodersPIDSource *driveEncodersPIDSource;

private:

  RobotModel *robot;
  RemoteControl *humanControl;
  double testVariable;
  double test2Variable;
  RobotDrive *driveTrain;
  uint32_t m_stateVal;
  uint32_t nextState;
};

#endif
