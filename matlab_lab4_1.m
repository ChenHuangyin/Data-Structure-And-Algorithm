t=-2*pi:0.001:2*pi;
ft=(0.5*(1+cos(t)).*(abs(t)>=0 & abs(t)<=pi));
subplot(311);
plot(t,ft);
xlabel('t');
ylabel('f(t)');

w=linspace(-2*pi,2*pi,500);

fwj=t*exp(-j*t'*w);
subplot(312);
plot(w,abs(fwj));
xlabel('w');
ylabel('|f(jw)|');

fwj=t*exp(-j*t'*w);
subplot(313);
plot(w,angle(fwj));
xlabel('w');
ylabel('ψ');

