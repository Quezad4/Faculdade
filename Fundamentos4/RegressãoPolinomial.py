import random 
import numpy as np
import matplotlib.pyplot as plt


def LU(matrixa,vetorb,n):
  a = np.arange(n*n,dtype = float).reshape(n,n)
  a =matrixa
  u = np.arange(n*n,dtype = float).reshape(n,n)
  l = np.arange(n*n,dtype = float).reshape(n,n)
  print("Valores da Matriz A: \n")
  queue = []
  for i in range(n):
      for j in range(n):
          valor = float(input())
          a[i][j] = valor
          u[i][j] = a[i][j]
  b = []
  b = vetorb
  for i in range(n):
      for j in  range(n):
          if(i>j):
              save = u[i][j]/u[j][j]
              queue.append(u[i][j]/u[j][j])
              for k in range(j,n): 
                  u[i][k] = u[i][k]-u[j][k]*save
  for i in range(n):
      for j in range(n):
          if(i==j):
              l[i][j] = 1
          else:
              if(i<j):
                  l[i][j] = 0
              else:   
                  l[i][j] = queue.pop(0)
  x = []
  y =[]
  y.append(b[0])
  for i in range(1,n): #comecar o i de 1
      soma = 0
      for j in range(i):
          soma = soma+ (l[i][j]*y[j])
      y.append(b[i]-soma)
          
  x.append(y[n-1]/u[n-1][n-1])
  for i in range(n-2,-1,-1): #olhar como fazer tbm
      soma = 0
      aux = 0
      for j in range(n-1,-1,-1):
          if(j==i):
              x.append((y[j]-soma)/u[i][j])
          elif(j>i):
              soma+= u[i][j]*x[aux]
              aux = aux+1
  print("Valores de X: \n")
  print(x)
  return x

x = []
y = []
somax = 0 #ok
somay = 0.0 #ok
somaxquad = 0 #ok
somaxcubo = 0 #ok
somaxquar = 0 #ok
somaxy = 0.0 #ok
somaxquady = 0.0 #ok

matrix = np.arange(3*3,dtype = float).reshape(3,3)


n = int(input("Digite o número de elementos: "))
m = int(input("Digite o grau do polinômio: "))
for i in range(n):
  x.append(i)
  somax = somax + i
  somaxquad = somaxquad + i*i
  somaxcubo = somaxcubo + i*i*i
  somaxquar = somaxquar + i*i*i*i
  #valor = random.uniform(1.0,70.0)
  print("Digite os valores de y: ")
  valor = float(input())
  somaxy = somaxy + i*valor
  somaxquady = somaxquady + i*i*valor
  somay = somay + valor
  y.append(valor)

y.sort()
vet = []
vet.append(somay)
vet.append(somaxy)
vet.append(somaxquady)
X = []
X = LU(matrix,vet,m+1)

plt.plot(x,y,'o')
eq=[]
for i in range(n):
  eq.append(X[2]+X[1]*x[i]+X[0]*x[i]*x[i])
plt.plot(x,eq)
plt.show()
print(eq)
