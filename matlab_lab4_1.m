t=-2*pi:0.001:2*pi;
ft=(0.5*(1+cos(t)).*(abs(t)>=0 & abs(t)<=pi));
subplot(411);
plot(t,ft);
xlabel('t');
ylabel('f(t)');
% 
% w=linspace(-2*pi,2*pi,500);
% 
% fwj=t*exp(-j*t'*w);
% subplot(312);
% plot(w,abs(fwj));
% xlabel('w');
% ylabel('|f(jw)|');
% 
% 
% subplot(313);
% plot(w,angle(fwj));
% xlabel('w');
% ylabel('ψ');


Tm1=1;
n1=-2*pi:Tm1:2*pi;
ftn1=(0.5*(1+cos(n1)).*(abs(n1)>=0 & abs(n1)<=pi));
subplot(412);
stem(n1,ftn1,'filled');

Tm2=1/pi;
n2=-2*pi:Tm2:2*pi;
ftn2=(0.5*(1+cos(n2)).*(abs(n2)>=0 & abs(n2)<=pi));
subplot(413);
stem(n2,ftn2,'filled');

Tm3=2;
n3=-2*pi:Tm3:2*pi;
ftn3=(0.5*(1+cos(n3)).*(abs(n3)>=0 & abs(n3)<=pi));
subplot(414);
stem(n3,ftn3,'filled');




