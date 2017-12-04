#pragma once

#include <stdint.h>
#include "..\..\AutoPilotPlane\define.h"
#include "..\HAL\utility\functor.h"



class Scheduler
{
public:
	// constructor
	Scheduler(void) 
	{
		_loop_rate_hz = LOOP_RATE_HZ;
		current_task = -1;
	};

	//FUNCTOR_TYPEDEF(task_fn_t, void);
	typedef void(*task_fn_t)(void);

	struct Task
	{
		task_fn_t function;
		uint16_t rate_hz;
		uint16_t max_time_micros;
	};

	// initialise scheduler
	void init(const Task *tasks, uint8_t num_tasks);

	// one tick has passed
	void tick(void);

	// run the tasks. 
	void run(uint32_t time_available);

	// current running task, or -1 if none. Used to debug stuck tasks
	int8_t current_task;

private:
	// overall scheduling rate in Hz
	int16_t _loop_rate_hz; // The value of this variable can be changed with the non-initialization. (Ex. Tuning by GDB)


	// progmem list of tasks to run
	const struct Task *_tasks;

	// number of tasks in _tasks list
	uint8_t _num_tasks;

	// number of 'ticks' that have passed (number of times that
	// tick() has been called
	uint16_t _tick_counter;

	// tick counter at the time we last ran each task
	uint16_t* _last_run;

	// number of microseconds allowed for the current task
	uint32_t _task_time_allowed;

	// the time in microseconds when the task started
	uint32_t _task_time_started;
};
