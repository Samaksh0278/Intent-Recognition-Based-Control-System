clc;
delete(instrfind);
s1 = serial('COM5','BaudRate',9600,'DataBits',8);
b = [];
fopen(s1);
for i=1:1:5000
    s = fscanf(s1);
    b = [b,str2num(s)];
        
end
%c = sgolayfilt(b,3,7);
%plot(c);
plot(b);
fclose(s1);