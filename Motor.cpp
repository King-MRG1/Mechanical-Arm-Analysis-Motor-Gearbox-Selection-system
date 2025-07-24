#include "Motor.h"

// Getter methods for Motor class

// Returns the motor's torque output in N.mm
ld Motor::getTorque()
{
	return torque;
}

// Returns the motor's rotational speed in rad/s
ld Motor::getSpeed()
{
	return speed;
}

// Returns the motor's mass in kg
ld Motor::getMass()
{
	return Mass;
}

// Returns the motor's diameter in mm
ld Motor::getDiameter()
{
	return diameter;
}

// Returns the motor's width in mm
ld Motor::getWidth()
{
	return width;
}

// Returns the motor's weight in N
ld Motor::getWeight()
{
	return weight;
}

// Setter methods for Motor class

// Sets the motor's torque output
void Motor::setTorque(ld t)
{
	torque = t;
}

// Sets the motor's rotational speed
void Motor::setSpeed(ld s)
{
	speed = s;
}

// Sets the motor's mass
void Motor::setMass(ld m)
{
	Mass = m;
}

// Sets the motor's diameter
void Motor::setDiameter(ld d)
{
	diameter = d;
}

// Sets the motor's weight
void Motor::setWeight(ld w)
{
	weight = w;
}

// Sets the motor's width
void Motor::setWidth(ld w)
{
	width = w;
}
