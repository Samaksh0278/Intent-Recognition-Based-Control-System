delete(instrfind);
%plot(a(1:1644),b);
%c = sgolayfilt(b,1,101);
%f = fit(d,avg,"rat23");
f = polyfit(d(1:27),avg(1:27),1);
v = polyval(f,d(1:27));
semilogy(d(1:27),v);
p = polyfit(d(27:53),avg(27:53),1);
u = polyval(p,d(27:53));
hold on
semilogy(d(27:53),u);
hold off