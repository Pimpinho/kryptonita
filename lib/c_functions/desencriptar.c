#include <stdio.h>
#include <string.h>

// Função para calcular o modulo exponencial
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

// Função para descriptografar a mensagem
void descripascii(unsigned long long int crip[], char str[], int tam, unsigned long long int d, unsigned long long int n) {
    
    for (int i = 0; i < tam; i++) {
        unsigned long long int decrypted_val = modpow(crip[i], d, n);
        str[i] = (char)decrypted_val;
    }
}

// Função final para desencriptar a mensagem
void desencriptar(){

    // Abrir os arquivos
    FILE *desencriptada;
    FILE *encriptada;

    // Vetor para armazenar a mensagem criptografada
    unsigned long long int value[999];

    // Abrir o arquivo com a mensagem criptografada
    encriptada = fopen("mensagem_criptografada.txt", "r");

    /// Declaração de variáveis
    long long phi, e, p, q, n;

    // Inserir a chave privada
    printf("Insira p , q, e):\n");
    scanf("%lld %lld %lld", &p, &q, &e);

    // Calculo de n e phi
    phi = (p - 1) * (q - 1);
    n = p * q;

    // Calculo de d
    int d = 0, tam = 0;

    while ((d * e) % phi != 1) {
        d++;
    }

    // Descriptografar a mensagem
    while (fscanf(encriptada, "%lld", &value[tam]) != EOF) {
        tam++;
    }

    // Escrever a mensagem descriptografada no arquivo
    char str[tam];

    descripascii(value, str, tam, d, n);

    desencriptada = fopen("mensagem_descriptografada.txt", "w");
    fprintf(desencriptada, "%s", str);

    fclose(desencriptada);
    fclose(encriptada);
}

int main() {
    desencriptar();
    return 0;
}
