#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

// Função que gera o conjunto de Mandelbrot e retorna os dados
int* generate_mandelbrot() {
    int *data = (int *)malloc(WIDTH * HEIGHT * sizeof(int)); // Alocar memória para os dados
    if (data == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return NULL; // Retorna NULL se a alocação falhar
    }

    // Percorrendo cada pixel da imagem
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = (x - WIDTH / 2.0) * 4.0 / WIDTH; // Mapeia x para o espaço complexo
            double imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT; // Mapeia y para o espaço complexo
            double z_real = real;
            double z_imag = imag;
            int iteration = 0;

            // Iteração de Mandelbrot
            while (z_real * z_real + z_imag * z_imag < 4 && iteration < MAX_ITER) {
                double z_real_temp = z_real * z_real - z_imag * z_imag + real;
                z_imag = 2 * z_real * z_imag + imag;
                z_real = z_real_temp;
                iteration++;
            }

            // Armazenar o número de iterações no array
            data[y * WIDTH + x] = iteration; // Armazenar em um array unidimensional
        }
    }

    return data; // Retorna o ponteiro para os dados
}

// Função para liberar a memória alocada
void free_mandelbrot(int* data) {
    free(data);
}
