% Define input sequence
x = [1, 2, 3, 4];

% Compute DFT of sequence using DIF-FFT
X = dif_fft(x);

% Print result
disp(X);
