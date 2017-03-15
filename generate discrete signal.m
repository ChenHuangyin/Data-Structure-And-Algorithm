subplot(321);
n1=-3;
n2=4;
n0=0;
n=n1:n2;
x= (n==n0);
stem(n,x,'filled');

subplot(322);
n1=-5;
n2=5;
n=n1:n2;
x=(n>=0);
stem(n,x,'filled');

subplot(323);
n = 0:16;
x = exp((0.1+pi*1j*1.6)*n);
stem(n,x,'filled');

subplot(324);
n = 0:20;
x = 3*sin((n*pi)/4);
stem(n,x,'filled');

subplot(325);
n=-20:20;
x=sinc((n/5)/pi);
stem(n,x,'filled');

