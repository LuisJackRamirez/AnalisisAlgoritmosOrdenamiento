%%VALORES DE X
x=[100 1000 5000 10000 50000 100000 200000 400000 600000 800000 1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000];
 
%%VALORES DE Y = F(x)
y=[0.0001840591 0.0015859604 0.0057799816 0.0058469772 0.0372779369 0.0890529156 0.2155609131 0.5269420147 0.8651189804 1.2313659191 1.6114089489 3.7842280865 6.0932509899 9.5497939587 11.5260860920 14.8531279564 18.7284688950 20.0102200508 23.2158300877 26.2741379738];
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
