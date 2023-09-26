#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned long long int modpow(unsigned long long int base, unsigned long long int exponent, unsigned long long int mod) {
    unsigned long long int result = 1;
    base = base % mod;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exponent = exponent / 2;
    }

    return result;
}

void criptoasc(char str[], unsigned long long int new[], unsigned long long int tam, unsigned long long int e, unsigned long long int n) {
    for (int i = 0; i < tam; i++) {
        int ascii_val = (int)str[i]; 
        new[i] = modpow(ascii_val, e, n); 
    }
}

int main() {
    unsigned long long int e, n;
    FILE *destino;
    destino = fopen("mensagem_criptografada.txt", "w");
    char str[99999];

    printf(">> Insira a mensagem que deseja criptografar: \n");
    scanf(" %[^\n]", str);
    printf(">> Insira a chave pública ('e' e 'n'): \n");
    scanf("%lld %lld", &e, &n);

    int tam = strlen(str);
    unsigned long long int crip[tam];

    criptoasc(str, crip, tam, e, n);

    for (int i = 0; i < tam; i++) {
        fprintf(destino, "%lld ", crip[i]);
    }
    fclose(destino);
    return 0;
}
