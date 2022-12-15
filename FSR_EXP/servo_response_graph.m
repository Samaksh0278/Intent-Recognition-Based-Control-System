                                                                                                                     %%to extract data from previous plot
h = openfig('hysterisis_moving_avg_3_plots');
h = findobj(gca,'Type','line');
x = get(h,'Xdata');
y = get(h,'Ydata');
y = [0,y];
x = [x(1),x];
avg = zeros(1,28);
dist = x(1:28);
new = [];
for i=1:length(y)
    b = rem(i,54);
    
    if(b>27)
        break
    end
    b = b+1;
    avg(b) = avg(b) + (y(i))/3; 
end
low = avg(length(avg));
for i = 1:length(avg)
    %new =[new,((low/avg(i))^1)*90];
    new =[new,(1-avg(i)/10000000)*90];
end
     plot(dist,new);
