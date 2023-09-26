#include <stdio.h>
#include <string.h>

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

void descriptoasc(unsigned long long int crip[], char str[], int tam, unsigned long long int d, unsigned long long int n) {
    for (int i = 0; i < tam; i++) {
        unsigned long long int decrypted_val = modpow(crip[i], d, n);
        str[i] = (char)decrypted_val;
    }
}

void Desencriptar() {
    FILE *desencriptada;
    FILE *encriptada;

    unsigned long long int value[999];

    encriptada = fopen("mensagem_criptografada.txt", "r");

    long long phi, e, p, q, n;

    printf(">> Insira p , q, e):\n");
    scanf("%lld %lld %lld", &p, &q, &e);

    phi = (p - 1) * (q - 1);
    n = p * q;

    int d = 0, tam = 0;

    while ((d * e) % phi != 1) {
        d++;
    }

    while (fscanf(encriptada, "%lld", &value[tam]) != EOF) {
        tam++;
    }

    char str[tam];

    descriptoasc(value, str, tam, d, n);

    desencriptada = fopen("mensagem_descriptografada.txt", "w");
    fprintf(desencriptada, "%s", str);

    fclose(desencriptada);
    fclose(encriptada);
}

int main() {
    Desencriptar();
    return 0;
}
