#ifndef GEARBOX_H
#define GEARBOX_H

#define ld long double

class Gearbox
{
private:
	ld gearRatio, efficiency, mass, diameter, width, weight;

public:
	// Default constructor
	Gearbox() : gearRatio(0), efficiency(0), mass(0), diameter(0), width(0), weight(0) {}

	// Parameterized constructor
	Gearbox(ld ratio, ld efficiency, ld mass, ld diameter,ld weight, ld width) : gearRatio(ratio), efficiency(efficiency), mass(mass), diameter(diameter),weight(weight), width(width){}

	// Getter methods
	ld getGearRatio();
	ld getEfficiency();
	ld getMass();
	ld getDiameter();
	ld getWidth();
	ld getWeight();

	// Setter methods
	void setGearRatio(ld ratio);
	void setEfficiency(ld eff);
	void setMass(ld m);
	void setDiameter(ld d);
	void setWidth(ld w);
	void setWeight(ld w);
};

#endif // GEARBOX_H
