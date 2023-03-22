clc;
clear;
close all;
x = [1,2];
h = [1,2,4];
m1 = length(x);
m2 = length(h);
subplot(2, 2, 1);
stem(x);
xlabel('n values');
ylabel('Amplitude');
title('x(n');

subplot(2, 2, 2);
stem(h);
xlabel('n values');
ylabel('Amplitude');
title('h(n)');

X =  [x, zeros(1, m1)];
H = [h, zeros(1, m2)];
for i=1:(m1+m2-1)
    y(i) = 0;
    for j=1:m1
        if(i-j+1)>0
            y(i) = y(i) + X(j)*H(i-j+1);
        end
    end
end
subplot(2,2,3);
stem(y);
xlabel('n values');
ylabel('Amplitude');
title('y output(n)');
