#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para calcular o MDC
unsigned long long mdc(unsigned long long a, unsigned long long b) {
    while (b) {
        unsigned long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Funções para verificar se um número é primo
unsigned long int findprimo(unsigned long int n, unsigned long int divisor)
{
    if (divisor == 1) return 1;
    if (n % divisor == 0) return 0;     
    return findprimo(n, divisor - 1); 
}

unsigned long int checkprimo(unsigned long int n)
{
    if (n < 2) return 0;                 
    unsigned long int maiordiv = sqrt(n);         
    return findprimo(n, maiordiv);
}

void gerar_chave(unsigned long int p, unsigned long int q, unsigned long long int e) {
    
    // Declaração de variáveis
    unsigned long long int n, phi;

    // calculo de n
    n = (unsigned long long int)p * (unsigned long long int)q;
    
    //calculo de phi
    phi = (p - 1) * (q - 1);

    // Verifica se o expoente e é relativamente primo a phi
    if (mdc((int)e, phi) != 1) {
        printf("O expoente 'e' não é relativamente primo a (p-1)(q-1).\n");
        return;
    }

    // Cria o arquivo com a chave pública
    FILE *file;
    file = fopen("chave_publica.txt", "w");

    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(file, "Chave Pública:\n");
    fprintf(file, "e: %llu\n", e);
    fprintf(file, "n: %llu\n", n);

    fclose(file);
}
