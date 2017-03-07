/*
 zzb * DriveForwardRoutine.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: peter
 */

#include "DriveForwardRoutine.h"

DriveForwardRoutine::DriveForwardRoutine(DriveController* kDrive) {

	this->kDrive = kDrive;
}

void DriveForwardRoutine::Routine() {
	// TODO Auto-generated constructor stub
	SmartDashboard::PutBoolean("reacheddriveroutine", true);
	DriveIntervalAction(kDrive, 1.0, 1.0, 0);
}

void DriveForwardRoutine::Prestart() {

}

