#include "Part1.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

// Constants
const long double PI = 3.14L; // Use 'L' for long double literals
const long double g = 9.81;   // Gravitational acceleration in m/s^2
using namespace std;

// Global vector to store material properties (yield strength, density)
vector<pair<int, long double>> materialspair;

// Constructor: Initialize Part1 object and material database
Part1::Part1() // Density in g/mm^3
    : isRectangle(false), b(0.0L), h(0.0L), r(0.0L), l(0.0L), a(0.0L), mp(0.0L), M(0.0L), I(0.0L), ml(0.0L), type(0)
{
    // Initialize material database with (yield strength in MPa, density in g/mm^3)
    materialspair.push_back(make_pair(130, .0000073L));  // Cast iron
    materialspair.push_back(make_pair(130, .00000894L)); // Copper nickel
    materialspair.push_back(make_pair(200, .00000873L)); // Brass
    materialspair.push_back(make_pair(241, .0000027L));  // Aluminum
    materialspair.push_back(make_pair(247, .00000758L)); // Steel
    materialspair.push_back(make_pair(72, .00000116L));  // Acrylic
    materialspair.push_back(make_pair(70, .00000892L));  // Copper
    materialspair.push_back(make_pair(275, .00000786L)); // Stainless steel
    materialspair.push_back(make_pair(941, .00001925L)); // Tungsten
}

// Setter methods with validation

// Set whether the cross-section is rectangular
void Part1::setIsRectangle(bool isRectangle)
{
    this->isRectangle = isRectangle;
}

// Set width for rectangular cross-section
void Part1::setB(long double b)
{
       this->b = b;    
}

// Set height for rectangular cross-section
void Part1::setH(long double h)
{
        this->h = h;
}

// Set radius for circular cross-section
void Part1::setR(long double r)
{
        this->r = r;    
}

// Set arm length
void Part1::setL(long double l)
{
        this->l = l;
}

// Set material type index
void Part1::setType(int type)
{
        this->type = type;
}

// Set angular acceleration (can be zero or negative)
void Part1::setA(long double a)
{
    this->a = a;
}

// Set point mass at end of arm
void Part1::setMp(long double mp)
{
        this->mp = mp;
}

// Getter methods
long double Part1::getB()
{
    return b;
}

long double Part1::getH()
{
    return h;
}

long double Part1::getR()
{
    return r;
}

long double Part1::getL()
{
    return l;
}

long double Part1::getA()
{
    return a;
}

long double Part1::getMp()
{
    return mp;
}

long double Part1::getMl()
{
    return ml;
}

long double Part1::getM()
{
    return M;
}

long double Part1::getI()
{
    return I;
}

// Get material density for given type index
long double Part1::getDensity(int type)
{
        return materialspair[type].second;
}

int Part1::getType()
{
    return type;
}

bool Part1::getIsRectangle()
{
    return isRectangle;
}

// Calculate link mass and initiate stress analysis chain
long double Part1::linkMass(bool isRectangle, long double b, long double h, long double r, long double L, int type)
{
    long double ml;
    if (isRectangle)
    {
        // Calculate mass for rectangular cross-section: Volume * Density
        ml = materialspair[type].second * (b * h * L);
    }
    else
    {
        // Calculate mass for circular cross-section: Volume * Density
        ml = materialspair[type].second * (PI * pow(r, 2) * L);
    }
    this->ml = ml; // Store link mass in grams

    // Continue to bending moment calculation
    return bendingMoment(L, this->a, ml, this->mp);
}

// Calculate bending moment due to gravitational and inertial loads
long double Part1::bendingMoment(long double L, long double a, long double ml, long double mp)
{
    // Validate inputs
    if ( ml <= 0)
    {
        cout << "Error: Invalid inputs for bending moment calculation.\n";
        return 0.0L;
    }

    // Calculate bending moment components:
    // 1. Gravitational load from link mass at center of mass (L/2)
    // 2. Gravitational load from point mass at end (L)
    // 3. Inertial load from link mass angular acceleration
    // 4. Inertial load from point mass angular acceleration
    long double M = ml * g * (L / 2) + (mp * g * L) + (ml * pow((L / 2), 2) * a + mp * pow(L, 2) * a);
    this->M = M; // Store bending moment in N*mm

    // Continue to moment of inertia calculation
    return computeInertia(this->isRectangle, this->r, this->h, this->b, M, this->type);
}

// Calculate second moment of area (moment of inertia) for cross-section
long double Part1::computeInertia(bool isRectangle, long double r, long double h, long double b, long double M, int type)
{
    // Validate bending moment
    if (M <= 0)
    {
        cout << "Error: Invalid bending moment for inertia calculation.\n";
        return 0.0L;
    }

    long double I;
    if (isRectangle == true)
    {
        // Second moment of area for rectangular cross-section about neutral axis
        I = (b * pow(h, 3)) / 12.0L;
    }
    else
    {
        // Second moment of area for circular cross-section about neutral axis
        I = (PI * pow(r, 4)) / 4.0L;
    }
    this->I = I; // Store moment of inertia in mm^4

    // Continue to stress calculation
    return Stress(this->isRectangle, this->M, this->r, this->h, this->b, this->I, this->type);
}

// Calculate maximum bending stress and optimize dimensions
long double Part1::Stress(bool isRectangle, long double M, long double r, long double h, long double b, long double I, int type)
{
    // Validate moment of inertia
    if (I <= 0)
    {
        cout << "Error: Invalid moment of inertia for stress calculation.\n";
        return 0.0L;
    }

    long double stress;
    if (isRectangle)
    {
        // Maximum bending stress for rectangular cross-section
        stress = (M * h) / (2.0L * I);
    }
    else
    {
        // Maximum bending stress for circular cross-section
        stress = (M * r) / I;
    }

    // Check if stress exceeds material yield strength
    if (stress > materialspair[type].first)
    {
        // Increase dimensions by 5% and recalculate
        this->b += (0.05L * this->b);
        this->h += (0.05L * this->h);
        this->r += (0.05L * this->r);

        return linkMass(this->isRectangle, this->b, this->h, this->r, this->l, this->type);
    }
    // Check if stress is much lower than yield strength (underutilized material)
    else if (stress < 0.98L * materialspair[type].first)
    {
        // Decrease dimensions by 1% to optimize material usage
        this->b -= (0.01L * this->b);
        this->h -= (0.01L * this->h);
        this->r -= (0.01L * this->r);

        return linkMass(this->isRectangle, this->b, this->h, this->r, this->l, this->type);
    }
    
    else
    {
        // Stress is within acceptable range
        return stress; // Return stress in MPa or N/mm^2
    }
}
