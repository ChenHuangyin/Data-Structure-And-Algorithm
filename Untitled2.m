f = 0:0.00125:0.04;
y = 1+sawtooth(2*pi*50*f);
subplot(221);
stem(f,y);
subplot(222);
plot(f,y);


n = 0:0.00025:0.01;
y = square(2*pi*200*n);
subplot(223);
stem(n,y);
subplot(224);
plot(n,y);