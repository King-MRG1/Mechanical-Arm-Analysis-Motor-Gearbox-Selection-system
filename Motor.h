#pragma once
#define ld long double

class Motor
{
private:
    ld torque, speed, Mass, diameter, width, weight;

public:
    // Default constructor
    Motor() : torque(0), speed(0), Mass(0), diameter(0), width(0), weight(0) {}
    
    // Parameterized constructor
    Motor(ld t, ld s, ld m, ld d,ld we, ld wi) : torque(t), speed(s), Mass(m), diameter(d),weight(we), width(wi) {}

    // Getter methods
    ld getTorque();
    ld getSpeed();
    ld getMass();
    ld getDiameter();
    ld getWidth();
    ld getWeight();

    // Setter methods
    void setTorque(ld t);
    void setSpeed(ld s);
    void setMass(ld m);
    void setDiameter(ld d);
    void setWidth(ld w);
    void setWeight(ld w);
};

