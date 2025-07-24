#include <iostream>
#include "Part1.h"
#include "Part2.h"
#include "Motor.h"
#include "UserInterface.h"
#include <algorithm>
using namespace std;

int main()
{
	// Create Part1 object to handle mechanical analysis
	Part1 part1;
    Part2 part2;
	int op = 0;

	// Get shape information from user (rectangle or circle)
	UserInterface::getShapeInfo(part1);

	// Get dimensions based on shape type
	UserInterface::getDimensions(part1, part1.getIsRectangle());

	// Get additional parameters (arm length, point mass, angular acceleration)
	UserInterface::getParameters(part1);

	// Get material type from predefined list
	UserInterface::getMaterialType(part1);

	// Calculate stress using link mass analysis
	long double stress = part1.linkMass(part1.getIsRectangle(),
		part1.getB(),
		part1.getH(), 
		part1.getR(),
		part1.getL(),
		part1.getType());

	// Display the mechanical analysis results
	UserInterface::displayResults(part1, stress);

	// Create Part2 object for motor and gearbox selection

	// Get torque and speed requirements from the user
	UserInterface::getTorqueAndSpeed(part2, part1);

	// Get optimization priority and select best motor-gearbox combination
	pair<Motor, Gearbox> motor_gearbox = UserInterface::getOptimzationPriority(part2,op);

	// Display the selected motor and gearbox information
	UserInterface::getMotorGearboxInfo(motor_gearbox, op);
}