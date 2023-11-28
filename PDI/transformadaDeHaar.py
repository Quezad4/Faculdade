import numpy as np
import matplotlib.pyplot as plt

# Função para realizar a Transformada de Haar 1D
def haar_1d(signal):
    length = len(signal)
    output = np.zeros(length)
    even_index = 0
    odd_index = length // 2

    for i in range(length // 2):
        output[i] = (signal[2 * i] + signal[2 * i + 1]) / np.sqrt(2)
        output[i + odd_index] = (signal[2 * i] - signal[2 * i + 1]) / np.sqrt(2)

    return output

# Função para realizar a Transformada de Haar 2D em uma imagem
def haar_2d(image):
    rows, cols = image.shape
    temp = np.copy(image)

    # Transformada nas linhas
    for i in range(rows):
        temp[i, :] = haar_1d(temp[i, :])

    # Transformada nas colunas
    for i in range(cols):
        temp[:, i] = haar_1d(temp[:, i])

    return temp

# Carregando a imagem
imagem = plt.imread('C:/Users/20211002800150/Desktop/imagem.png')

# Convertendo para escala de cinza se for uma imagem colorida
if len(imagem.shape) > 2:
    imagem = np.mean(imagem, axis=2)

# Aplicando a transformada de Haar na imagem
imagem_transformada = haar_2d(imagem)

# Mostrando a imagem original e a imagem após a transformada de Haar
plt.subplot(1, 2, 1)
plt.title('Imagem Original')
plt.imshow(imagem, cmap='gray')

plt.subplot(1, 2, 2)
plt.title('Imagem Transformada')
plt.imshow(imagem_transformada, cmap='gray')

plt.tight_layout()
plt.show()
