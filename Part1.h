#pragma once  
class Part1
{
private:
    bool isRectangle; // True if the shape is a rectangle, false if it's a circle
    long double b, h, r, l, a, mp, M, I, ml; // Dimensions, mass, moment, inertia, etc.
    int type; // Material type index

public:
    Part1();

    // Setters with validation
    void setIsRectangle(bool isRectangle);
    void setB(long double b);
    void setH(long double h);
    void setR(long double r);
    void setL(long double L);
    void setType(int type);
    void setA(long double a);
    void setMp(long double mp);

    // Getters
    long double getB();
    long double getH();
    long double getR();
    long double getL();
    int getType(); // Returns the material type index
    long double getA();
    long double getMp();
    long double getMl();
    long double getM();
    long double getI();
    long double getDensity(int type);
    bool getIsRectangle();

    // Core calculations
    long double linkMass(bool isRectangle, long double b, long double h, long double r, long double L, int type);
    long double bendingMoment(long double L, long double a, long double ml, long double mp);
    long double computeInertia(bool isRectangle, long double r, long double h, long double b, long double M, int type);
    long double Stress(bool isRectangle, long double r, long double h, long double b, long double M, long double I, int type);
};