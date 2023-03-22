x=input('Enter the sequence');
N=input('Enter the number of points');
%Finding the DFT
X=dft(x,N);
disp(X)
mag=abs(X);
k=0:N-1;
subplot(2,1,1)
stem(k,mag);
ang=angle(X);
subplot(2,1,2);
stem(k,ang);
% Linear convolution using DFT
x=input("Enter the x sequence :");
h=input("Enter the h sequence :");
a=length(x);
b=length(h);
N=a+b-1;
X=dft(x,N);
H=dft(h,N);
y=X.*H;
Y=ifft(y,N);
disp('Linear Convolution ');
disp(real(Y));