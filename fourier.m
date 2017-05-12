%intialize step function
x1 = -0.2:0.01:1.2;
y1 = zeros(length(x1));
y1(x1>0&x1<1) = 1;
%list of iterations
list = [5,10,20,40,80,160,320,640];
%blank figure
figure
for i = drange (1:8)
    %initial x and y values
    x = -0.2:0.01:1.2;
    y = 0.5;
    %display step function
    plot (x1,y1,'r')
    hold on
    %sum new fourier series terms
    for j = drange (1:list(i))
        y = y+(2/pi/(j*2-1))*sin(2*pi*(j*2-1)*x/2);
    end
    %display fourier series plot
    plot (x,y)
    %pause animation
    pause (1);
    hold off
end