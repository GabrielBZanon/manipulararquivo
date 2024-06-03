#include <stdio.h>
#include <stdlib.h>

#define CHAVE 3

int main() {
    FILE *arquivo_entrada, *arquivo_saida;
    char caractere;

    arquivo_entrada = fopen("teste5.txt", "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    arquivo_saida = fopen("teste5saida.txt", "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(arquivo_entrada);
        return 1;
    }

    while ((caractere = fgetc(arquivo_entrada))!= EOF) {
        caractere += CHAVE;
        fputc(caractere, arquivo_saida);
    }

    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Arquivo encriptado com sucesso.\n");

    return 0;
}
