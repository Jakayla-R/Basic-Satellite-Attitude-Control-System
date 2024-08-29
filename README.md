# Satellite Attitude Control System
Objective:
To understand the basics of satellite attitude control by modeling and simulating a control system using MATLAB/Simulink.

Workflow Steps:
1. Basic System Modeling
\
 a. Simple Dynamics:
      Model a basic satellite with 3-DOF (pitch, yaw, roll) using simple equations of motion.
      Use a single reaction wheel or torque rod for control.
   \
  b. Simulink Setup:
      Create a straightforward Simulink model with blocks representing the satellite and control mechanism.
2. Basic Control Design
\
  a. PID Control:
      Implement a basic PID controller in Simulink to stabilize one axis of the satellite.
   \
  b. Initial Testing:
      Run the simulation to observe how the PID controller adjusts the satellite's orientation.
4. Code Generation
\
  a. MATLAB Autocoder:
      Generate C code from the PID controller model using MATLAB Coder.
   \
  b. Review the Code:
      Look at the generated code to understand how the MATLAB/Simulink model translates into C.
6. Simple Validation
\
  a. Run on MATLAB:
      Validate the generated code by running it within MATLAB or on a simple microcontroller.

   
Project Deliverables:
\
-Simulink Model: Basic model of the satellite control system.
\
-Simulation Results: Basic plots showing the system's behavior.
\
-Generated Code: Simple C code for the PID controller.
\
-Documentation: A brief summary of what you’ve learned and how the system works.


Tools and Resources:
Software: MATLAB, Simulink, MATLAB Coder.

