#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Exponenciação modular
unsigned long long int modexp(unsigned long long int base, unsigned long long int exp, unsigned long long int mod) {
    
    unsigned long long int result = 1;
    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp = exp / 2;
    }

    return result;
}

// Função para criptografar a mensagem
void criptoasc(char str[], unsigned long long int nva_str[], unsigned long long int tam, unsigned long long int e, unsigned long long int n) {
   
    for (int i = 0; i < tam; i++) {
        int ascii_val = (int)str[i]; 
        nva_str[i] = modexp(ascii_val, e, n); 
    }
}

// Função final para encriptar a mensagem
void encriptar(){

    // Declaração de variáveis
    unsigned long long int e, n;
    FILE *destino;
    destino = fopen("mensagem_criptografada.txt", "w");
    char str[99999];

    // Inserir a mensagem e a chave pública
    printf("Insira a mensagem que deseja criptografar: \n");
    scanf(" %[^\n]", str);
    printf("Insira a chave pública 'e' e 'n': \n");
    scanf("%lld %lld", &e, &n);

    // Criptografar a mensagem
    int tam = strlen(str);
    unsigned long long int crip[tam];

    criptoasc(str, crip, tam, e, n);

    // Escrever a mensagem criptografada no arquivo
    for (int i = 0; i < tam; i++) {
        fprintf(destino, "%lld ", crip[i]);
    }
    fclose(destino);
}

int main() {
    encriptar();
    return 0;

}
