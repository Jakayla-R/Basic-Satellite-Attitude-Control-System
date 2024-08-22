% Define parameters
I = 10; % Moment of inertia (kg*m^2)
T = 20; % Initial torque (N*m)
dt = 0.01; % Time step (s)
t = 0:dt:10; % Time vector (10 seconds of simulation)
omega = zeros(size(t)); % Initialize angular velocity array

% Simulate the dynamics
for i = 2:length(t)
    % Euler integration
    omega(i) = omega(i-1) + (T/I) * dt;
end


% Plot results
figure;
plot(t, omega);
xlabel('Time (s)');
ylabel('Angular Velocity (rad/s)');
title('Satellite Pitch Axis Dynamics');
grid on;


model_name = 'satellite_pitch_control'; % Replace with your model name
open_system(model_name);
slbuild(model_name);



%In solver tab changed veriablestep to fixedstep 
%changed algorithm to ode4 Runge-Kutta 
%changed to fized step size 

%Code generation as grt.tlc for standard C code 
%saved and then rebuild