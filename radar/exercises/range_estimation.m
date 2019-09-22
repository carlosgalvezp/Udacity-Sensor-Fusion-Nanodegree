% Given parameters
c = 3 * 10^8;          % [m/s]
max_range = 300;       % [m]
range_resolution = 1;  % [m]

% Find the Bsweep of chirp for 1 m resolution
B_sweep = c / (2 * range_resolution);

% Calculate the chirp time based on the Radar's Max Range
Ts = 5.5 * 2 * max_range / c;

% TODO : define the frequency shifts 
fb = [0, 1.1, 13, 24] * 10^6;  % [MHz]

R = (c * Ts * fb) / (2 * B_sweep);

% Display the calculated range
disp(R);
