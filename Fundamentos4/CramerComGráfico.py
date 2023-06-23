from numpy.core.function_base import linspace
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
a = np.arange(9,dtype = float).reshape(3,3)
b = []
print("Escreva os elementos da Matrix 3x3: ")
for i in range(3):
  for j in range(3):
    print("M[",i,"][",j,"] = ")
    valor = float(input())
    a[i][j] = valor
print("Escreva os valores que igualam as linhas: ")
for i in range(3):
  print("Valor",i+1,":")
  valor2 = float(input())
  b.append(valor2)

aux1 = np.copy(a)
aux1[:,0] = b
aux2 = np.copy(a)
aux2[:,1] = b
aux3 = np.copy(a)
aux3[:,2] = b

x1 = np.linalg.det(aux1)/np.linalg.det(a)
x2 = np.linalg.det(aux2)/np.linalg.det(a)
x3 = np.linalg.det(aux3)/np.linalg.det(a)

figura = plt.figure()
grafico = figura.gca(projection = '3d')

x11 = linspace(x1,x1)
y22 = linspace(x2,x2)
z33 = linspace(x3,x3)

xa = linspace(-30,-15,5)
xb = linspace(-30,-15,5)

r1 =(a[0][0]*(-1))*xa + (a[0][1]*(-1))*xb + (b[0]*(-1))/a[0][2]
r2 =(a[1][0]*(-1))*xa + (a[1][1]*(-1))*xb + (b[1]*(-1))/a[1][2]
r3 =(a[2][0]*(-1))*xa + (a[2][1]*(-1))*xb + (b[2]*(-1))/a[2][2]
grafico.plot(xa,xb,r1,color='green')
grafico.plot(xa,xb,r2)
grafico.plot(xa,xb,r3,color='blue')
grafico.plot(x11,y22,z33,'o')
plt.show()
