clc;
delete(instrfind);
s1 = serial('COM5','BaudRate',9600,'DataBits',8);
b = [];
a = [];
d = [];
sum = 0;
counter = 0;
overall_count = 0;
avg = [];
temp = 1;
fopen(s1);
for i=1:1:50000
    s = fscanf(s1);
    c = strsplit(s,',');
    %%d = cell2mat(c);
    a = [a,str2num(cell2mat(c(2)))];
    b = [b,str2num(cell2mat(c(1)))];
    if  i > 1 && a(i) == a(i-1)
        if str2num(cell2mat(c(1)))
            sum = sum + b(i-1);
            counter = counter +1;
            avg(temp) = sum/counter;
        end
    end
            
    
    
   if  i>1 && a(i)~=a(i-1)
        d = [d,a(i-1)*0.1175];
                
        if a(i) == 0
            overall_count = overall_count+1;
        end
        
        if overall_count == 3
            break;
        end
        
        sum = 0;
        temp = temp +1;
        counter = 0;
        avg = [avg,0];
   end
end
semilogy(d,avg);
fclose(s1);