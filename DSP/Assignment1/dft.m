function X=dft(x,N)
L=length(x);
if(N<L)
    disp("Not Valid");
end
x=[x,zeros(1,N-L)];
for k=0:N-1
    for n=0:N-1
        w(k+1,n+1)=exp(-j*2*pi*k*n/N);
    end
end
X=w*x.';

