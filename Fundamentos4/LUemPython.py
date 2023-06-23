import numpy as np
n = int(input("Insira o tamanho da Matriz A: \n"))
a = np.arange(n*n,dtype = float).reshape(n,n)
u = np.arange(n*n,dtype = float).reshape(n,n)
l = np.arange(n*n,dtype = float).reshape(n,n)
print("Valores da Matriz A: \n")
queue = []
for i in range(n):
    for j in range(n):
        valor = float(input())
        a[i][j] = valor
        u[i][j] = a[i][j]
print("Valores da Matriz B: \n")
b = []
for i in range(n):
    valor = float(input())
    b.append(valor)
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
print("Valores de Y: \n")
print(y)
print("Valores de X: \n")
print(x)
print("Matriz L: \n")
print(l)
print("Matriz U: \n")
print(u)
    








        
