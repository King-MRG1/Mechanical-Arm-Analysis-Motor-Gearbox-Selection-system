#ifndef PART2_H
#define PART2_H

#include <vector>
#include <utility>
#include "Part1.h"
#include "Motor.h"
#include "Gearbox.h"
#define ld long double
using namespace std;

class Part2
{
private:
    ld T_req, W_req, T_out, W_out;
    
    // Move global vectors to class members
    vector<Motor> motors;
    vector<Gearbox> gearboxes;
    vector<pair<Motor, Gearbox>> motor_gearbox;
    vector<pair<Motor, Gearbox>> suitable_motor_gearbox;

public:
    Part2();

    void set_T_req(ld T);
    void set_W_req(ld W);

    ld get_T_req();
    ld get_W_req();
    ld get_T_out();
    ld get_W_out();

    ld Torque_out(ld T_motor, ld ratio, ld efficiency);
    ld Speed_out(ld W_motor, ld ratio);

    void choose_motor_gearbox(ld T_req);

    pair<Motor, Gearbox> Cost();
    float partcost(float Diameter, float width, float mass);
    float compute_cost(float cost1, float cost2);
    pair<Motor, Gearbox> Weight();
};

#endif // PART2_H
