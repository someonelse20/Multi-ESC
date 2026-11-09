#include "pid.h"

double loop_pid(pid_control_t *pid, double procces_value, double set_point) {
	double error = set_point - procces_value;

	double proportional = pid->kP * error;

	pid->integral = pid->integral + (pid->kI * error * pid->DT);

	double derivative = pid->kD * ((error - pid->previous_error) / pid->DT);

	pid->previous_error = error;

	double output = proportional + pid->integral + derivative;

	output *= pid->gain;

	pid->output = output;

	return output;
}

void reset_pid(pid_control_t *pid) {
	pid->integral = 0;
	pid->previous_error = 0;
}
