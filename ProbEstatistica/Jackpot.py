import random
import matplotlib.pyplot as pl

def jackpot(jogadas,valorInicial):
    soma = valorInicial
    for i in range (jogadas):
        roleta = random.randint(0,1)
        if roleta == 1:
            soma+= 1
        else:
            soma-= 1
    return soma

valorInicial = int(input("Qual o seu investimento:" ))
numJogadas = int(input("Quantidade de jogadas na roleta: "))
abscissas = []
ordenadas = []
for i in range (numJogadas):
    abscissas.append(i)
    ordenadas.append(jackpot(i,valorInicial))
pl.plot(abscissas,ordenadas)
pl.title("Gráfico de Porcentagem")
pl.show()

            
    
