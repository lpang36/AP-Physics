t = 0:0.01:1;
x = 2+4*t;
y = 1-t;
tf = t(end);
xv = 4;
yv = -1;
xa = 0;
ya = 0;
figure
plot(x,y);
hold on
quiver(x(end),y(end),xv,yv);
quiver(x(end),y(end),xa,ya);
hold off
