import numpy as np
import matplotlib.pyplot as plt
x1 = [4,7,11/2]
y1 = [5,5,9]

x2 = [4,7,11/2,4]
y2 = [5,5,9,5]


dx = int(input("Digite o valor da distância X: "))
dy = int(input("Digite o valor da distância y: "))
plt.plot(x2,y2)
matrix_translacao = np.array([[1,0,dx],[0,1,dy],[0,0,1]])
matrix_triangulo = np.vstack((x1, y1, np.ones_like(x1)))
matrix_Pronta = matrix_translacao @ matrix_triangulo

x3 = []
for i in range(3):
  x3.append(matrix_Pronta[0][i])
x3.append(matrix_Pronta[0][0])

y3 = []
for i in range(3):
  y3.append(matrix_Pronta[1][i])
y3.append(matrix_Pronta[1][0])

for i in range(3):
  plt.plot(x1[i], y1[i], 'b.')

for i in range(3):
  plt.plot(matrix_Pronta[0][i], matrix_Pronta[1][i], 'b.')

plt.plot(x3,y3)

plt.xlim(0,10)
plt.ylim(0,10)
plt.xlabel('Eixo X')
plt.ylabel('Eixo Y')
plt.show()
