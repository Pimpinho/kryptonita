#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Função para verificar se um número é primo
int check_primo(int n) {
    if (n < 2) return 0;
    int max_div = (int)sqrt(n);
    for (int i = 2; i <= max_div; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Função para gerar um número primo aleatório
int primo_aleat(int min, int max) {
    int num;
    do {
        num = rand() % (max - min + 1) + min;
    } while (!check_primo(num));
    return num;
}

void gerar_dois_primos() {

    // Inicializar o gerador de números aleatórios
    srand(time(NULL));

    // Gerar dois números primos aleatórios
    int primo1 = primo_aleat(500, 35000);
    int primo2 = primo_aleat(500, 35000);

    // Imprimir os números primos gerados
    printf("Número primo 1: %d\n", primo1);
    printf("Número primo 2: %d\n", primo2);
}
