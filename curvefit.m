%initialize data
x = [1.01, 2.2, 2.9, 4.03, 5.32 ,6.22, 8.56, 9.09];
y = [18.5, 76.2, 150.5, 365, 780, 1265, 3250, 7099];
%create Vandermonde matrix
for j=drange(0:3)
    V(:,j+1) = (x.').^j;
end
%create transpose
Vt = V.';
%calculate coefficients
c = inv(Vt*V)*Vt*(y.');
%display coefficients
format long g
c
%create x and y regression value matrices for plot
x2 = (0:0.01:10);
y2 = c(4).*x2.^3+c(3).*x2.^2+c(2).*x2+c(1);
%display graph
figure
plot (x,y,'k.',x2,y2,'r--');