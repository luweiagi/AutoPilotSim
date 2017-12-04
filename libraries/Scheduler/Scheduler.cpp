#include "Scheduler.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "..\HAL\timer.h"
#include "..\..\AutoPilotPlane\define.h"


// initialise scheduler
void Scheduler::init(const Scheduler::Task *tasks, uint8_t num_tasks)
{
	_tasks = tasks;
	_num_tasks = num_tasks;
	_last_run = new uint16_t[_num_tasks];
	memset(_last_run, 0, sizeof(_last_run[0]) * _num_tasks);
	_tick_counter = 0;
}


// one tick has passed
void Scheduler::tick(void)
{
	_tick_counter++;
}


void Scheduler::run(uint32_t time_available)
{
	uint32_t run_started_usec = micros();
	uint32_t now = run_started_usec;

	for (uint8_t i = 0; i < _num_tasks; i++)
	{
		uint16_t dt_ticks = _tick_counter - _last_run[i];
		uint16_t interval_ticks = _loop_rate_hz / _tasks[i].rate_hz;
		if (interval_ticks < 1)
		{
			interval_ticks = 1;
		}
		if (dt_ticks >= interval_ticks)
		{
			// this task is due to run. Do we have enough time to run it?
			_task_time_allowed = _tasks[i].max_time_micros;

			if (_task_time_allowed <= time_available)
			{
				// run it
				_task_time_started = now;
				current_task = i;
				_tasks[i].function();
				current_task = -1;
				// record the tick counter when we ran. This drives
				// when we next run the event
				_last_run[i] = _tick_counter;
				// work out how long the event actually took
				now = micros();
				uint32_t time_taken = now - _task_time_started;
				if (time_taken > _task_time_allowed)
				{
					// the event overran!
					printf("Scheduler overrun task[%u], time taken:%u, task time allowed:%u\n", (unsigned)i, (unsigned)time_taken, (unsigned)_task_time_allowed);
				}
				if (time_taken >= time_available)
				{
					break;
				}
				time_available -= time_taken;
			}
		}
	}
}
