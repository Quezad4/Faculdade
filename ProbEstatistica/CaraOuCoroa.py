import random
import matplotlib.pyplot as pl

def verif(jogadas):
    cara = coroa = 0
    for i in range (jogadas):
        flip = random.randint(0,1)
        if flip == 1:
            coroa += 1
    return coroa/jogadas


numJogadas = int(input("Quantas moedas serão jogadas: "))
abscissas = []
ordenadas = []
for i in range (1,numJogadas):
    abscissas.append(i)
    ordenadas.append(verif(i))
pl.plot(abscissas,ordenadas)
pl.title("Gráfico de Porcentagem")
pl.show()

            
    
