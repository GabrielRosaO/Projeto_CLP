LIB_NAME = mandelbrot.so	# (Comando para execução no Linux)
#LIB_NAME = mandelbrot.dll (Comando para execução no Windows)

C_SRC = mandelbrot.c

PYTHON_SCRIPT = main.py

CC = gcc
CFLAGS = -shared  -fPIC

$(LIB_NAME): $(C_SRC)
	$(CC) $(CFLAGS) -o $(LIB_NAME) $(C_SRC)

# Regra para rodar o script Python (assumindo que a biblioteca foi compilada)
run: 
	python $(PYTHON_SCRIPT) 
