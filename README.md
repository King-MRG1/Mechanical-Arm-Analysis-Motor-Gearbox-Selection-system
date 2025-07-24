# 🤖 Mechanical Arm Analysis & Motor-Gearbox Selection

A modular C++ project developed for **CSE232s - Fundamentals of Computer Programming**, designed to perform mechanical stress analysis on a robotic arm and assist in selecting the most suitable **motor–gearbox combination** based on user-defined requirements. The system supports material property validation, dimensional optimization, and cost/weight minimization strategies.

---

## 📌 Overview

The application is divided into two major modules:
- **Part1**: Performs mechanical analysis on a robotic arm segment using user-defined dimensions, material properties, and motion parameters.
- **Part2**: Selects the most suitable motor and gearbox combination based on torque and speed requirements, optimizing for either **minimum cost** or **minimum weight**.

It features a complete command-line interface and is structured for clarity, reusability, and performance.

---

## 🧠 Key Features

- 🧮 **Mechanical Stress Calculations**
- 🧾 **Material database with auto-optimization**
- ⚙️ **Dynamic Motor & Gearbox Filtering**
- 📈 **Cost or Weight Optimization**
- 🔧 **Auto-correction for over/under stress**
- 💡 **Full error handling (input, logical, runtime)**
- 📊 **Test cases and validation for robustness**

---

## 🗂 Project Structure

/Team24-Project
│
├── main.cpp # Entry point, coordinates parts and UI
├── Part1.cpp/.h # Stress analysis logic
├── Part2.cpp/.h # Motor-gearbox selection logic
├── Motor.cpp/.h # Motor model and attributes
├── Gearbox.cpp/.h # Gearbox model and attributes
├── UserInterface.cpp/.h # User input, display, validation

---

## 🛠 Technologies

- **Language**: C++
- **Concepts**: OOP, Vectors, Structs, Error Handling
- **Development Environment**: Visual Studio Code / GCC / Clang

---

## ⚙️ How It Works

### 🧾 Inputs Collected:
1. **Cross-section shape** (Rectangle or Circle)
2. **Dimensions** (width, height, or radius)
3. **Length of arm** (mm)
4. **Point mass at arm end** (kg)
5. **Angular acceleration** (rad/s²)
6. **Material selection**
7. **Desired speed** (rad/s)
8. **Optimization target**: cost or weight

---

### 🔄 Program Flow

1. `main.cpp` initializes **Part1** and **Part2**
2. `UserInterface` gathers and validates user inputs
3. `Part1` calculates:
   - Mass
   - Bending Moment
   - Moment of Inertia
   - Stress (with auto-optimization if needed)
4. `Part2`:
   - Generates all motor–gearbox pairs
   - Filters based on torque and speed requirements
   - Returns the **optimal combination** based on user preference
5. Results (including stress and motor/gearbox specs) are displayed

---

## 🛡 Error Handling & Validation

- **Binary choice validation** (`cin.fail`, `cin.clear`, `cin.ignore`)
- **Open/closed range checks**
- **Auto-retry until valid input**
- **Exception handling with `try-catch`**
- **Logical checks** (e.g., stress limits, no valid combos)

---

## 🔍 Testing Strategy

Includes:
- ✅ Valid input tests
- 🚫 Invalid input tests (negative values, unknown materials)
- 📐 Edge cases (extreme sizes, zero dimensions)
- 💣 Calculation edge cases (division by zero, stress overflow)

---

## 🧪 Example Interaction (CLI)

