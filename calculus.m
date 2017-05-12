%prompt for user input
c = input('Enter 1 for integral, 2 for derivative ');
syms x
%select user choice
if (c==1)
    %prompt for function
    f = input('Enter function ');
    %calculate symbolic integral
    disp (int(f,x));
elseif (c==2)
    %prompt for function
    f = input('Enter function ');
    %calculate symbolic derivative
    disp (diff(f+0*x));
end
    