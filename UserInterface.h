#pragma once
#include "Part1.h"
#include "Part2.h"
#include "Motor.h"
#include "Gearbox.h"
#include <utility>

using namespace std;

class UserInterface
{
private:
    static void printMaterials();
public:
    static void getShapeInfo(Part1& project);
    static void getDimensions(Part1& project, bool isRectangle);
    static void getParameters(Part1& project);
    static void getMaterialType(Part1& project);
    static void displayResults(Part1& project, long double stress);
    static void getTorqueAndSpeed(Part2& project, Part1& p1);
    static pair<Motor, Gearbox> getOptimzationPriority(Part2& project,int& op);
    static void getMotorGearboxInfo(pair<Motor, Gearbox> motor_gearbox, int op);
};

