// 学apm翘课挂科被导员批的大二学生
// AutoPilotPlane.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;
#include "AutoPilotPlane.h"
#include <stdint.h>
#include <stdio.h>
#include "..\libraries\HAL\HAL.h"
#include "..\libraries\HAL\timer.h"
#include "..\libraries\Maths\Maths.h"
#include "..\libraries\CopterAttitudeControl\CopterAttitudeControl.h"
#include "define.h"
#include "..\libraries\Scheduler\Scheduler.h"
#include "Plane.h"
#include <windows.h>

Plane plane;
CopterAttitudeControl att_control;


const Scheduler::Task Plane::scheduler_tasks[] =
{
	// funcName,      Hz, maxTimeMicros
	{ outputNumTest , 1,  500 },
  //{ outputNumTest , 1,  500 },
};


void Plane::setup()
{
	cout << "AutoPilotSim initting..." << endl;

	scheduler.init(&scheduler_tasks[0], uint8_t(sizeof(scheduler_tasks)/sizeof(Scheduler::Task)));

	cout << "size scheduler_tasks = " << sizeof(scheduler_tasks) << endl;
	cout << "size Task = " << sizeof(Scheduler::Task) << endl;

	cout << "AutoPilotSim init complete!" << endl << endl;
}


void Plane::loop()
{
	uint32_t timer = micros();

	// Execute the fast loop
	// ---------------------
	fast_loop();

	// tell the scheduler one tick has passed
	scheduler.tick();

	uint32_t time_available = (timer + LOOP_DELTA_T_MICROS) - micros();

	scheduler.run(time_available > LOOP_DELTA_T_MICROS ? 0u : time_available);

	while (micros() < timer + LOOP_DELTA_T_MICROS);
}


// Main loop - 400hz
void Plane::fast_loop()
{
	;
}


void outputNumTest(void)
{
	uint32_t startT = micros();
	for (int i = 0; i < 7000; i++)
	{
		sinf(i);
	}
	uint32_t lastT = micros();
	printf("duringTime of test function is: %d\n", lastT - startT);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
	plane.setup();
	for (;;) plane.loop();
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
