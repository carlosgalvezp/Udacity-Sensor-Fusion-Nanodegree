% Doppler Velocity Calculation
c = 3*10^8;         %speed of light
frequency = 77 * 10^9;   %frequency in Hz

% Calculate the wavelength
lambda = c / frequency;

% Define the doppler shifts in Hz using the information from above 
fd = [3, 4.5, 11, -3] * 10^3;  % [Hz]

% Calculate the velocity of the targets  fd = 2*vr/lambda
vr = fd * lambda / 2;

% Display results
disp(vr)
