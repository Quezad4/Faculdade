import matplotlib.pyplot as plt
import random

n = int(input("Digite o número de pontos"))

listx = []
listy = []
listans = []
somax = 0
somay = 0
somaxquad = 0
somaxy = 0
for i in range(n):
  listy.append(random.randint(1,10))
  listx.append(random.randint(1,10))
  somax = somax + listx[i]
  somay = somay + listy[i]
  somaxquad = somaxquad + listx[i]*listx[i]
  somaxy = somaxy + listx[i]*listy[i]
a = ((n*somaxy) - (somax*somay))/((n*somaxquad) - (somax*somax))
b = (somay/n) - (a*(somax/n))

for i in range(n):
  listans.append(b+a*listx[i])

plt.plot(listx,listy,'o')
plt.plot(listx,listans)
plt.title("Gráfico")
plt.show()






  

