% t=0:0.05:4;
% f=4*exp(1)-2*t;
% subplot(2,2,1);
% plot(t,f);
% title('f(t)-t函数');
% xlabel('t');
% ylabel('f(t)');
% 
% subplot(2,2,2);
% t1=0:0.05:3;
% f1=exp(1)-t1.*cos(2.*t1.*pi);
% plot(t1,f1);
% title('f1(t)-t1函数');
% xlabel('t1');
% ylabel('f1(t)');
% 
% subplot(2,2,3);
% k=0:0.05:10;
% f2=k;
% plot(k,f2);
% title('f2(t)-k函数');
% xlabel('k');
% ylabel('f2(t)');
% 
% subplot(2,2,4);
% k1=-20:0.05:20;
% f3=k1.*sin(k1);
% plot(k1,f3);
% title('f3(t)-k1函数');
% xlabel('k1');
% ylabel('f3(t)');

a=zeros(1,20);
a(1,1)=1;
a(1,2)=1;
for n=3:20
a(1,n)=a(1,n-1)+a(1,n-2);
end
   
