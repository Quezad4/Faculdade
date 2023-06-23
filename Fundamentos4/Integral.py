def calculoFx(x):
  return 0.2 + 25*x - 200*x*x + 675*x*x*x - 900*x*x*x*x + 400*x*x*x*x*x


  
N = int(input("Digite o valor de N: "))
A = float(input("Digite o valor inferior: "))
B = float(input("Digite o valor superior: "))
H = (B-A)/N


lista = []
soma = 0.0
lista.append(A)
for i in range(N):
  lista.append(lista[i]+H)
for i in range(1,N+1):
  soma = soma + calculoFx(lista[i-1]) + calculoFx(lista[i])
soma = soma*(B-A)
soma = soma/(N*2)
print("Valor Absoluto: 1,640533")
print("Valor do Cálculo da Soma dos Trapézios: ", soma )
valorErro = ((soma/1.640533)-1)*-100
print("Valor Erro Calculado: ", valorErro, "%")

