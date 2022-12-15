h = openfig('tape_plus_independent_power_source_version');
h = findobj(gca,'Type','line');
x = get(h,'Xdata');
y = get(h,'Ydata');
plot(x,y)