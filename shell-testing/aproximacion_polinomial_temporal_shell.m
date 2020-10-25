%%VALORES DE X
x=[100 1000 5000 10000 50000 100000 200000 400000 600000 800000 1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000];
 
%%VALORES DE Y = F(x)
y=[0.0000119209 0.0001921654 0.0013630390 0.0031859875 0.0170681477 0.0386910439 0.0840148926 0.1872608662 0.2848520279 0.4157049656 0.5094668865 1.1705238819 1.9059309959 2.6567611694 3.5743601322 4.3076448441 5.1210191250 6.1237020493 6.7596480846 8.2133541107];
format long;
%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
n=8; 				%%GRADO DEL POLINOMIO DE AJUSTE
p1=polyfit(x,y,1);
p2=polyfit(x,y,2);
p3=polyfit(x,y,3);
p4=polyfit(x,y,4);
p8=polyfit(x,y,8);%%FUNCION QUE REALIZA EL AJUSTE POLINOMIAL

xi=linspace(0,10000000,60000);	%%ESPACIO DE PUNTOS PARA Xi

figure;
y1=polyval(p1,xi);
y2=polyval(p2,xi);
y3=polyval(p3,xi);
y4=polyval(p4,xi);
y8=polyval(p8,xi);%%EVALUACION DEL POLINOMIO P EN EL ESPACIO Xi


plot(x,y,'o',xi,y1,'-',xi,y2,'-',xi,y3,'-',xi,y4,'-',xi,y8,'-'),grid;
%%plot(x,y,'o',xi,y1,'-'),grid;
ylabel('Tiempo (segundos)');
xlabel('Tamaño del problema (n)');
title('Aproximación polinomial grados 1, 2, 3, 4, 8 del comportamiento temporal');
