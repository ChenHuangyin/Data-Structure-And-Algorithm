% x(n)＝d(n＋3)＋2d(n－4)，(－5<n<5)
% n=-5:5;
% x=(n==-3)+2*(n==4);
% stem(n,x,'filled');

% x(n)＝u(n－2)＋u(n＋2)，(－5<n<5)
% n=-5:5;
% x=(n>=2)+(n>=-2);
% stem(n,x,'filled');

% 已知x(n)＝3cos(2pn/10)，试显示x(n－3)和x(n＋3)在0<n<20区间的波形。
% n=0:20;
% x1=3*cos(2*pi*(n-3)/10);
% x2=3*cos(2*pi*(n+3)/10);
% 
% subplot(211);
% stem(n,x1,'filled');
% subplot(212);
% stem(n,x2,'filled');

% 已知x1＝e－n/16，x2(n)＝5sin(2pn/10)，试显示x1(n)×x2(n)在0<n<24区间的波形。
% n=0:24;
% x1=exp(-n/16);
% x2=5*sin(2*pi*n/10);
% x=x1.*x2;
% stem(n,x,'filled');

% 已知信号x(n)＝n sin(n)，试显示在0<n<20区间的下列波形：
% y1(n)＝x(n－3)，y2(n)＝x(－n)，y3(n)＝－x(n)，y4(n)＝x(－n＋3)，y5(n)＝x(n/2)
% n=0:20;
% y1=(n-3).*sin(n-3);
% subplot(321);
% stem(n,y1,'filled');
% 
% y2=(-n).*sin(-n);
% subplot(322);
% stem(n,y2,'filled');
% 
% y3=-(n.*sin(n));
% subplot(323);
% stem(n,y3,'filled');
% 
% y4=(-n+3).*sin(-n+3);
% subplot(324);
% stem(n,y4,'filled');
% 
% y5=(n/2).*sin(n/2);
% subplot(325);
% stem(n,y5,'filled');


% 编写MATLAB程序，描绘下列信号序列的卷积波形：
% ①f1(n)＝d(n－1)，f2(n)＝u(n－2)，(0≤n<10)
n=0:10;
f1t=(n==1);
f2t=(n>=2);
f1=ones(1,10);
f1( find((n>=0) & (n<=10)) )=f1t;
f2=ones(1,10);
f2( find((n>=0) & (n<=10)) )=f2t;
f=conv(f1,f2);
subplot(221);
stem(f,'filled');

% ②f1(n)＝u(n)，f2(n)＝e0.2nu(n)，(0≤n<10)
n=0:9;
f1t=(n>=0);
f1=ones(1,9);
f1( find( (n>=0)&(n<=9)))=f1t;

f2t=exp(0.2*n).*(n>=0);
f2=ones(1,9);
f2( find( (n>=0)&(n<=9)))=f2t;

f=conv(f1,f2);
subplot(222);
stem(f,'filled');

% ③x(n)＝sin	n/2，h(n)＝(0.5)n，(－3≤n≤4pi)

n=-3:4*pi;
f1t=sin(n/2);
f1=ones(1,length(n));
f1( find( (n>=min(n)&(n<=max(n))))) =f1t;

f2t=0.5.^n;
f2=ones(1,length(n));
f2( find( (n>=min(n)&(n<=max(n)))))=f2t;

f=conv(f1,f2);
subplot(223);
stem(f,'filled');







