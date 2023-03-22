function X = dif_fft(x)
% FFT_DIF - Computes the discrete Fourier transform (DFT) of a sequence using the decimation-in-frequency (DIF) FFT algorithm
% Usage:
%   X = dit_fft(x)
% Inputs:
%   x = input sequence
% Outputs:
%   X = DFT of x

N = length(x);
if N == 1
    % Base case: X(1) = x(1)
    X = x;
else
    x_even = x(1:2:N);
    x_odd = x(2:2:N);

    % Compute the DFT of the even and odd components using recursion
    X_even = dif_fft(x_even);
    X_odd = dif_fft(x_odd);

    % Combine the even and odd DFTs using the butterfly operation
    W_N = exp(-1j*2*pi/N);
    W = 1;
    X = zeros(1, N);
    for k = 1:N/2
        X(k) = X_even(k) + W*X_odd(k);
        X(k+N/2) = X_even(k) - W*X_odd(k);
        W = W*W_N;
    end
end
end
