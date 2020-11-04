%%VALORES DE X
x=[100 1000 5000 10000 50000 100000 200000 400000 500000 600000 800000 1000000 2000000];
 
%%VALORES DE Y = F(x)
y=[0.0000109673 0.0008299351 0.0221178532 0.0817580223 1.9679861069 7.7774341106 30.8597199917 122.8389940262 192.0878720284 441.6973760128 492.6336579323 770.9300370216 3226.6533091068];
        %1          %2              %3          %4          %5                          %7                      %9                         
%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
p1=polyfit(x,y,1);	%%FUNCION QUE REALIZA EL AJUSTE POLINOMIAL
p2=polyfit(x,y,2);	
p3=polyfit(x,y,3);	
p4=polyfit(x,y,4);	
p8=polyfit(x,y,8);	

%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
x1=linspace(0,2000000,600);	%%ESPACIO DE PUNTOS PARA Xi
z1=polyval(p1,x1);				%%EVALUACION DEL POLINOMIO P EN EL ESPACIO Xi
x2=linspace(0,2000000,600);
z2=polyval(p2,x2);
x3=linspace(0,2000000,600);
z3=polyval(p3,x3);
x4=linspace(0,2000000,600);
z4=polyval(p4,x4);
x8=linspace(0,2000000,600);
z8=polyval(p8,x8);

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
plot(x,y,'o',x1,z1,'-',x2,z2,'-',x3,z3,'-',x4,z4,'-'),grid;
ylabel('Tiempo (segundos)');
xlabel('Tamaño del problema (n)');
title('Comparación de aproximaciones polinomiales para Inserción');
legend('Tiempo real','Grado 1','Grado 2','Grado 3','Grado 4','Grado 8','Location','northwest');