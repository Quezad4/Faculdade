import numpy as np
import matplotlib.pyplot as plt

n = int(input("Digite quantos valore de X: "))
x = []
y = []
x1 = []
x2 = []

for i in range(n):
  x.append(i+1)
  y.append((1.75*np.log10(i+1)) - 0.3)
  x1.append(np.log10(x[i]))
  x2.append(pow(10,y[i]))
fig, (ax1, ax2) = plt.subplots(1, 2)
ax1.plot(x, x2)
ax1.set_title('X e Y')
ax2.plot(x1, y)
ax2.set_title('Log(X) e Log(Y)')
