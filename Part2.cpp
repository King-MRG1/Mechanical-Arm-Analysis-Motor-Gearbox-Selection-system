#include "Part2.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include "Part1.h"
#include "Motor.h"
#include "Gearbox.h"
#define ld long double

// Constructor: Initialize Part2 object and populate motor/gearbox databases
Part2::Part2() : T_req(0), W_req(0), T_out(0), W_out(0)
{
	// Clear vectors to ensure clean state
	motors.clear();
	gearboxes.clear();
	motor_gearbox.clear();
	suitable_motor_gearbox.clear();

	// Initialize motor database with specifications (Torque, Speed, Mass, Diameter, Weight, Width)
    motors.push_back(Motor(322L, 696.4L, 2.995L, 50L, 29.38L, 22.01L));
    motors.push_back(Motor(1710L, 357.1L, 0.42L, 85L, 4.12L, 33L));
    motors.push_back(Motor(3710L, 291.12L, 2.995L, 70L, 29.38L ,193L));
    motors.push_back(Motor(3350L, 321L, 2.99L, 70L, 29.38L , 193L));
    motors.push_back(Motor(2840L, 201.7L, 0.7017L, 90L, 6.89L, 43L));
    motors.push_back(Motor(1600L, 390.6L, 2.295L, 70L, 22.514L , 156L));
    motors.push_back(Motor(1710L, 357L, 0.741, 85L, 7.27L , 33L));
    motors.push_back(Motor(1610L, 217.8L, 0.987L, 90L, 9.68L , 39.9L));
    motors.push_back(Motor(1560L, 217.8L, 0.987L, 90L, 9.68L , 39.9L));
    motors.push_back(Motor(1520L, 499L, 1.594L, 70L, 15.64L , 123L));

    // Initialize gearbox database with specifications (Ratio, Efficiency, mass, Diameter, Weight, Width)
    gearboxes.push_back(Gearbox(1296L, 0.64L, 0.56L, 42L, 5.5L , 42L));
    gearboxes.push_back(Gearbox(756L, 0.64L, 0.567L, 42L, 5.5L ,84.55L));
    gearboxes.push_back(Gearbox(20L, 0.38L, 0.061L, 16L, 0.6L ,102L));
    gearboxes.push_back(Gearbox(2623L, 0.50L, 0.258L, 32L, 2.531L , 56.5L));
    gearboxes.push_back(Gearbox(74L, 0.75L, 0.77L, 52L, 7.554L , 78.5L));
    gearboxes.push_back(Gearbox(103L, 0.7L, 0.194L, 32L, 1.903L , 43.1L));
    gearboxes.push_back(Gearbox(216L, 0.72L, 0.46L, 42L, 7.06L , 70L));
    gearboxes.push_back(Gearbox(531L, 0.60L, 0.226L, 32L, 5.87L ,49.8L));
    gearboxes.push_back(Gearbox(4.4L, 0.38L, 0.061L, 16L, 0.6L, 101L));
    gearboxes.push_back(Gearbox(1014L, 0.42L, 0.094L, 22L, 4.12L ,49.8L));

	// Create all possible motor-gearbox combinations
	for (auto &motor : motors)
	{
		for (auto &gearbox : gearboxes)
		{
			motor_gearbox.push_back(make_pair(motor, gearbox));
		}
	}
}

// Setter methods
void Part2::set_T_req(ld T)
{
	T_req = T;
}

void Part2::set_W_req(ld W)
{
	W_req = W;
}

// Getter methods
ld Part2::get_T_req()
{
	return T_req;
}

ld Part2::get_W_req()
{
	return W_req;
}

ld Part2::get_T_out()
{
	return T_out;
}

ld Part2::get_W_out()
{
	return W_out;
}

// Calculate output torque from motor through gearbox
ld Part2::Torque_out(ld T_motor, ld ratio, ld efficiency)
{
	T_out = T_motor * ratio * efficiency;
	return T_out;
}

// Calculate output speed from motor through gearbox
ld Part2::Speed_out(ld W_motor, ld ratio)
{
	W_out = W_motor / ratio;
	return W_out;
}

// Filter motor-gearbox combinations that meet torque and speed requirements
void Part2::choose_motor_gearbox(ld T_req)
{
	for (auto &pair : motor_gearbox)
	{
		Motor motor = pair.first;
		Gearbox gearbox = pair.second;

		// Get motor and gearbox specifications
		ld T_motor = motor.getTorque();
		ld W_motor = motor.getSpeed();
		ld ratio = gearbox.getGearRatio();
		ld efficiency = gearbox.getEfficiency();
		ld w_req = get_W_req();

		// Calculate output torque and speed
		ld T_output = Torque_out(T_motor, ratio, efficiency);
		ld W_output = Speed_out(W_motor, ratio);

		// Check if combination meets requirements
		if (T_output >= T_req && W_output >= W_req)
		{
			suitable_motor_gearbox.push_back(make_pair(motor, gearbox));
		}
	}
}

// Calculate cost based on part specifications
float Part2::partcost(float Diameter, float width, float mass)
{
	float cost = mass + Diameter / 100 + width / 100;
	return cost;
}

// Compute total cost of motor-gearbox combination
float Part2::compute_cost(float cost1, float cost2)
{
	float cost = cost1 + cost2;
	return cost;
}

// Find motor-gearbox combination with minimum weight
pair<Motor, Gearbox> Part2::Weight()
{
    // Clear previous results
    suitable_motor_gearbox.clear();
    
    // Filter suitable combinations
    choose_motor_gearbox(T_req);
    if (suitable_motor_gearbox.empty())
    {
        cout << "\nNo suitable motor-gearbox combination found for the given torque requirement.\n\n" << endl;
        return make_pair(Motor(), Gearbox());
    }

    // Find combination with minimum total weight
    float minweight = 99999999;
    int index = 0;

    for (int i = 0; i < suitable_motor_gearbox.size(); i++)
    {
        float motorweight = suitable_motor_gearbox[i].first.getWeight();
        float gearweight = suitable_motor_gearbox[i].second.getWeight();

        float totalweight = motorweight + gearweight;
        if (minweight > totalweight)
        {
            minweight = totalweight;
            index = i;
        }
    }
    return suitable_motor_gearbox[index];
}

// Find motor-gearbox combination with minimum cost
pair<Motor, Gearbox> Part2::Cost()
{
    // Clear previous results
    suitable_motor_gearbox.clear();
    
    // Filter suitable combinations
    choose_motor_gearbox(T_req);
    if (suitable_motor_gearbox.empty())
    {
        cout << "\nNo suitable motor-gearbox combination found for the given torque requirement.\n\n";
        return make_pair(Motor(), Gearbox());
    }

    // Find combination with minimum total cost
    float mincost = 99999999;
    int index = 0;

    for (int i = 0; i < suitable_motor_gearbox.size(); i++)
    {
        // Get motor specifications
        float motorDiameter = suitable_motor_gearbox[i].first.getDiameter();
        float motorWidth = suitable_motor_gearbox[i].first.getWidth();
        float motorMass = suitable_motor_gearbox[i].first.getMass();

        // Get gearbox specifications
        float gearDiameter = suitable_motor_gearbox[i].second.getDiameter();
        float gearWidth = suitable_motor_gearbox[i].second.getWidth();
        float gearMass = suitable_motor_gearbox[i].second.getMass();

        // Calculate total cost
        float cost = compute_cost(partcost(motorDiameter, motorWidth, motorMass),
								  partcost(gearDiameter, gearWidth, gearMass));

        if (mincost > cost)
        {
            mincost = cost;
            index = i;
        }
    }
    return suitable_motor_gearbox[index];
}