#include "Gearbox.h"

// Getter methods for Gearbox class

// Returns the gear ratio (output speed / input speed)
ld Gearbox::getGearRatio()
{
	return gearRatio;
}

// Returns the gearbox efficiency (typically 0.4 to 0.75)
ld Gearbox::getEfficiency()
{
	return efficiency;
}

// Returns the gearbox mass in kg
ld Gearbox::getMass()
{
	return mass;
}

// Returns the gearbox diameter in mm
ld Gearbox::getDiameter()
{
	return diameter;
}

// Returns the gearbox width in mm
ld Gearbox::getWidth()
{
	return width;
}

// Returns the gearbox weight in N
ld Gearbox::getWeight()
{
	return weight;
}

// Setter methods for Gearbox class

// Sets the gear ratio
void Gearbox::setGearRatio(ld ratio)
{
	gearRatio = ratio;
}

// Sets the gearbox efficiency
void Gearbox::setEfficiency(ld eff)
{
	efficiency = eff;
}

// Sets the gearbox mass
void Gearbox::setMass(ld m)
{
	mass = m;
}

// Sets the gearbox diameter
void Gearbox::setDiameter(ld d)
{
	diameter = d;
}

// Sets the gearbox width
void Gearbox::setWidth(ld w)
{
	width = w;
}

// Sets the gearbox weight
void Gearbox::setWeight(ld w)
{
	weight = w;
}
