def fat(N):
  if(N<2):
    return 1
  return N*fat(N-1)
 
a = int(input("Digite o valor de N:"))
c = float(input("Digite o valor para ser elevado:"))
b = 1
count = 0;
vet2 = []
veterro = []
 
for i in range(1,a+2):
  vet2.append(b)
  b = b + (c**i/fat(i))
print(vet2[a-1])
print(vet2)
print("Cálculo do Erro: ")
for i in range(a):
  veterro.append((vet2[i+1] - vet2[i])/vet2[i+1] * 100)
print(veterro)

