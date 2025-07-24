#include "UserInterface.h"
#include <iostream>
#include <string>
#include <utility>
#include <limits>
#include "Part1.h"
#include "Part2.h"
using namespace std;

// Display available materials with their properties
void UserInterface::printMaterials()
{
    cout << "\n------ MATERIALS ------\n";
    cout << "(1)-(Cast iron) yield = 130 \t Density = 7.3\n";
    cout << "(2)-(Copper nickel) yield = 130 \t Density = 8.94\n";
    cout << "(3)-(Brass) yield = 200 \t Density = 8.73\n";
    cout << "(4)-(Aluminum) yield = 241 \t Density = 2.7\n";
    cout << "(5)-(Steel) yield = 247 \t Density = 7.58\n";
    cout << "(6)-(Acrylic) yield = 72 \t Density = 1.16\n";
    cout << "(7)-(Copper)  yield = 70 \t Density = 8.92\n";
    cout << "(8)-(Stainless steel) yield = 275 \t Density = 7.86\n";
    cout << "(9)-(Tungsten) yield = 941 \t Density = 19.25\n";
    cout << "-----------------------\n";
    cout << "Choose a material type:\n";
}

// Get shape information from user and validate input
void UserInterface::getShapeInfo(Part1 &project)
{
    int shape;
    cout << "Enter shape type ((1)rectangle or (2)circle): ";

    // Input validation loop
    while (true)
    {
        cin >> shape;

        // Check for input stream failure
        if (cin.fail())
        {
            cin.clear();                                         // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number (1 or 2): ";
            continue;
        }

        if (shape == 1 || shape == 2)
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please enter '(1)rectangle' or '(2)circle': ";
        }
    }

    // Set the shape type in the project object
    bool isRectangle = (shape == 1);
    project.setIsRectangle(isRectangle);
}

// Get dimensions based on shape type
void UserInterface::getDimensions(Part1 &project, bool isRectangle)
{
    long double b = 0.0L, h = 0.0L, r = 0.0L;

    if (isRectangle)
    {
        // Get width for rectangular cross-section with validation
        cout << "Enter width (b in mm): ";
        while (true)
        {
            cin >> b;

            // Check for input stream failure
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a positive number for width: ";
                continue;
            }

            if (b > 0)
            {
                project.setB(b);
                break;
            }
            else
            {
                cout << "Width must be positive. Please enter a valid width (mm): ";
            }
        }

        // Get height for rectangular cross-section with validation
        cout << "Enter height (h in mm): ";
        while (true)
        {
            cin >> h;

            // Check for input stream failure
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a positive number for height: ";
                continue;
            }

            if (h > 0)
            {
                project.setH(h);
                break;
            }
            else
            {
                cout << "Height must be positive. Please enter a valid height (mm): ";
            }
        }
    }
    else
    {
        // Get radius for circular cross-section with validation
        cout << "Enter radius (r in mm): ";
        while (true)
        {
            cin >> r;

            // Check for input stream failure
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a positive number for radius: ";
                continue;
            }

            if (r > 0)
            {
                project.setR(r);
                break;
            }
            else
            {
                cout << "Radius must be positive. Please enter a valid radius (mm): ";
            }
        }
    }
}

// Get mechanical parameters from user with validation
void UserInterface::getParameters(Part1 &project)
{
    long double L = 0.0L, mp = 0.0L, alpha = 0.0L;

    // Get arm length with validation
    cout << "Enter arm length (L in mm): ";
    while (true)
    {
        cin >> L;

        // Check for input stream failure
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number for arm length: ";
            continue;
        }

        if (L > 0)
        {
            project.setL(L);
            break;
        }
        else
        {
            cout << "Arm length must be positive. Please enter a valid length (mm): ";
        }
    }

    // Get point mass with validation
    cout << "Enter point mass (mp in kg): ";
    while (true)
    {
        cin >> mp;

        // Check for input stream failure
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive number for point mass: ";
            continue;
        }

        if (mp >= 0) // Point mass can be zero
        {
            project.setMp(mp);
            break;
        }
        else
        {
            cout << "Point mass cannot be negative. Please enter a valid mass (kg): ";
        }
    }

    // Get angular acceleration with validation (can be negative)
    cout << "Enter angular acceleration (alpha in rad/s^2): ";
    while (true)
    {
        cin >> alpha;

        // Check for input stream failure
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number for angular acceleration: ";
            continue;
        }

        // Angular acceleration can be any real number
        project.setA(alpha);
        break;
    }
}

// Get material type selection from user with validation
void UserInterface::getMaterialType(Part1 &project)
{
    int materialType = 0;
    printMaterials();
    cout << "Enter material index: ";

    while (true)
    {
        cin >> materialType;

        // Check for input stream failure
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 9: ";
            continue;
        }

        if (materialType >= 1 && materialType <= 9)
        {
            // Convert to 0-based index
            project.setType(materialType - 1);
            break;
        }
        else
        {
            cout << "Invalid material index. Please enter a number between 1 and 9: ";
        }
    }
}

// Display the calculated results
void UserInterface::displayResults(Part1 &project, long double stress)
{
    try
    {
        cout << "\n------ RESULTS ------\n";
        cout << "Width = " << project.getB() << " mm\n";
        cout << "Height = " << project.getH() << " mm\n";
        cout << "Length = " << project.getL() << " mm\n";
        cout << "Radius = " << project.getR() << " mm\n";
        cout << "Bending Moment = " << project.getM() << " N.mm\n";
        cout << "Moment of Inertia = " << project.getI() << " mm^4\n";
        cout << "Maximum Stress = " << stress << " MPa\n";
        cout << "Density = " << project.getDensity(project.getType()) << " g/mm^3\n";
    }
    catch (const exception &e)
    {
        cerr << "Error displaying results: " << e.what() << endl;
    }
}

// Get torque and speed requirements for motor selection with validation
void UserInterface::getTorqueAndSpeed(Part2 &project, Part1 &p1)
{
    try
    {
        // Set required torque from Part1 bending moment
        project.set_T_req(p1.getM());
        long double W_req;
        cout << "====================================================\n";
        cout << "The required Torque is : " << project.get_T_req() << " N.mm " << endl;
        cout << "Please enter the omega required (rad/s): ";

        while (true)
        {
            cin >> W_req;

            // Check for input stream failure
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a positive number for omega: ";
                continue;
            }

            if (W_req > 0)
            {
                project.set_W_req(W_req);
                break;
            }
            else
            {
                cout << "Omega must be positive. Please enter a valid speed (rad/s): ";
            }
        }
    }
    catch (const exception &e)
    {
        cerr << "Error getting torque and speed requirements: " << e.what() << endl;
    }
}

// Get optimization priority and return best motor-gearbox combination with validation
pair<Motor, Gearbox> UserInterface::getOptimzationPriority(Part2 &project,int& op)
{
    pair<Motor, Gearbox> motor_gearbox;

    // Get user preference for optimization criteria with validation
    while (true)
    {
        cout << "Choose the combination's optimization priority according to minimum (1)'cost' or (2)'weight' : ";
        cin >> op;

        // Check for input stream failure
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 1 for cost or 2 for weight: ";
            continue;
        }

        if (op == 1)
        {
            try
            {
                // Optimize for minimum cost
                motor_gearbox = project.Cost();
                break;
            }
            catch (const exception &e)
            {
                cerr << "Error optimizing for cost: " << e.what() << endl;
                cout << "Please try again.\n";
                continue;
            }
        }
        else if (op == 2)
        {
            try
            {
                // Optimize for minimum weight
                motor_gearbox = project.Weight();
                break;
            }
            catch (const exception &e)
            {
                cerr << "Error optimizing for weight: " << e.what() << endl;
                cout << "Please try again.\n";
                continue;
            }
        }
        else
        {
            cout << "Invalid choice. Please enter 1 for cost or 2 for weight: ";
        }
    }
    return motor_gearbox;
}

// Display selected motor and gearbox information with error handling
void UserInterface::getMotorGearboxInfo(pair<Motor, Gearbox> motor_gearbox, int op)
{
    try
    {
        Motor motor = motor_gearbox.first;
        Gearbox gearbox = motor_gearbox.second;

        // Display header based on optimization criteria
        op == 1 ? cout << "\nSelected Motor-Gearbox Combination based on Cost:\n" : cout << "Selected Motor-Gearbox Combination based on Weight:\n";

        // Display motor specifications
        cout << "====================================================\n";
        cout << "Selected Motor: " << endl;
        cout << "Torque: " << motor.getTorque() << " N.mm" << endl;
        cout << "Speed: " << motor.getSpeed() << " rad/s" << endl;
        cout << "Diameter: " << motor.getDiameter() << " mm" << endl;
        cout << "Width: " << motor.getWidth() << " mm" << endl;
        cout << "Mass: " << motor.getMass() << " kg" << endl;
        cout << "Weight: " << motor.getWeight() << " N" << endl;

        // Display gearbox specifications
        cout << "====================================================\n";
        cout << "Selected Gearbox: " << endl;
        cout << "Gear Ratio: " << gearbox.getGearRatio() << endl;
        cout << "Efficiency: " << gearbox.getEfficiency() << endl;
        cout << "Width: " << gearbox.getWidth() << " mm" << endl;
        cout << "Diameter: " << gearbox.getDiameter() << " mm" << endl;
        cout << "Mass: " << gearbox.getMass() << " kg" << endl;
        cout << "Weight: " << gearbox.getWeight() << " N" << endl;
        cout << "====================================================\n";
    }
    catch (const exception &e)
    {
        cerr << "Error displaying motor-gearbox information: " << e.what() << endl;
    }
}
