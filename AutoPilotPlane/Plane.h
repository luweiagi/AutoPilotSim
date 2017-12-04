#pragma once

#include "..\libraries\Scheduler\Scheduler.h"

class Plane
{
public:
	Plane(void) {};

	void setup(void);

	void loop(void);

	// Main loop - 400hz
	void fast_loop(void);

	// main loop scheduler
	Scheduler scheduler;

private:

	// main loop scheduler
	static const Scheduler::Task scheduler_tasks[];

};