#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE * arquivo;
    arquivo = fopen("arquivo.txt", "w");
    if (arquivo != NULL) {
        double ultimo = 1; double penultimo = 1;
        char total[500];
        fprintf(arquivo, "%.0lf\n", penultimo);
        fprintf(arquivo, "%.0lf\n", ultimo);
        for (int i = 0; i < 64; i++) {
            double novo = ultimo + penultimo;
            char texto[50];
            fprintf(arquivo, "%.0lf\n", novo);
            strcat(total, texto);
            penultimo = ultimo;
            ultimo = novo;
        }
        printf("Salvo com sucesso!");
    } else {
        printf("O arquivo nao existe!");
    }
    fclose(arquivo);
    return 0;
}
