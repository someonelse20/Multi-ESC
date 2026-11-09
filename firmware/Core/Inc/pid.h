#ifndef PID_H
#define PID_H

typedef struct {
	// Public variables
	const double DT;
	const double kP, kI, kD;
	const double gain;

	double output;

	// Private internal variables
	double error;
	double previous_error;
	double proportional, integral, derivative;
} pid_control_t;

double loop_pid(pid_control_t *pid, double procces_value, double set_point);

void reset_pid(pid_control_t *pid);

#endif
