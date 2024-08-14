# Trabalho de Integralização de Linguagens - Conceitos de Linguagens de Programação
Neste repositório está o desenvolvimento de um código que calcula e demonstra o fractal de Mendelbrot.
A ideia desse trabalho é focar e encontrar uma maneira de criar um programa que integre duas linguagens diferentes, no caso as escolhidas forma C e Python.

## Integrantes
  Bruno Martins Alexandre // bmalexandre@inf.ufpel.edu.br
  Gabriel Rosa de O. Silva // grosilva@inf.ufpel.edu.br

## Composição do repositório
O repositório é composto por 6 arquivos, sendo 5 deles para a execução do código e 1 em formato PDF com a descrição do que foi feito:

  -`main.py` -> Arquivo que contém a parte de implementação da interface do projeto;
  
  -`mandelbrot.c` -> Arquivo que contém a parte de cálculo do fractal de Mandelbrot necessário;
  
-`mandelbrot.dll` -> .dll gerado a partir de `mandelbrot.c` para a execução com python em Windows.

-`mandelbrot.so` -> .so gerado a partir de `mandelbrot.c` para a execução com python em Linux.

-`Makefile` -> Arquivo para ser utilizado através do utilitário make para compilar e executar o projeto.

-`Relatório.pdf` -> Arquivo contendo a documentação da implementação.

## Como utilizar

### Bibliotecas necessárias
 Numpy e Matplotlib
```
pip install numpy matplotlib
```
### Compilar e Executar
Windows com MinGW:
```
mingw32-make
```
```
mingw32-make run
```
Linux
```
make
```
```
make run
```
