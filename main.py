import ctypes
import numpy as np
import matplotlib.pyplot as plt

# Carregar a biblioteca C
#mandelbrot_lib = ctypes.CDLL('./mandelbrot.dll')
mandelbrot_lib = ctypes.CDLL('./mandelbrot.so')

# Definir o protótipo da função que gera o conjunto de Mandelbrot
mandelbrot_lib.generate_mandelbrot.restype = ctypes.POINTER(ctypes.c_int * (800 * 800))  # Define o tipo de retorno
mandelbrot_lib.generate_mandelbrot.argtypes = []  # Não há argumentos

# Chamar a função
data_ptr = mandelbrot_lib.generate_mandelbrot()  # Chamar a função para obter os dados

# Converter o ponteiro retornado para um numpy array
data_array = np.ctypeslib.as_array(data_ptr.contents)  # Converter o ponteiro em um array
data_array = data_array.reshape((800, 800))  # Ajustar a forma do array

# Visualizar os dados
plt.imshow(data_array, cmap='inferno', extent=(-2, 2, -2, 2))  # Ajuste o extent conforme a região
plt.colorbar()
plt.title("Conjunto de Mandelbrot")
plt.xlabel("Parte real")
plt.ylabel("Parte imaginária")

# Mostrar a imagem na tela
plt.show()

# Liberar a memória alocada na biblioteca C
mandelbrot_lib.free_mandelbrot(data_ptr)
