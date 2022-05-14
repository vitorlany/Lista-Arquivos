#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ex01();
void ex02();

int main()
{
    FILE * fibonacci;
    fibonacci = fopen("fibonacci.txt", "r");
    
    double vetor[64];
    for(int counter = 0; counter <= 64; counter++) {
        char buffer[50]; char *ptr[50];
        fgets(buffer, sizeof(buffer), fibonacci);
        double num = strtod(buffer, ptr);
        vetor[counter] = num;
    }
    int i = 34;
    printf("[%i] = %lf", i, vetor[i]);

    fclose(fibonacci);
    return 0;
}

void ex01() {
    FILE * arquivo;
    arquivo = fopen("fibonacci.txt", "w");
    if (arquivo != NULL) {
        double ultimo = 1; double penultimo = 1;
        fprintf(arquivo, "%.0lf\n", penultimo);
        fprintf(arquivo, "%.0lf\n", ultimo);
        for (int i = 0; i < 64; i++) {
            double novo = ultimo + penultimo;
            fprintf(arquivo, "%.0lf\n", novo);
            penultimo = ultimo;
            ultimo = novo;
        }
        printf("Salvo com sucesso!");
    } else {
        printf("O arquivo nao existe!");
    }
    fclose(arquivo);
}

void ex02() {
    FILE * fibonacci;
    fibonacci = fopen("fibonacci.txt", "r");

    FILE * pares;
    pares = fopen("pares.txt", "w");

    FILE * impares;
    impares = fopen("impares.txt", "w");

    char line[50];

    for(int counter = 0; counter <= 64; counter++) {
        char buffer[50]; char *ptr[50];
        fgets(buffer, sizeof(buffer), fibonacci);
        double num = strtod(buffer, ptr);
        
        if (fmod(num, 2) == 0) {// Par
            fprintf(pares, "%.0lf\n", num);
        } else { // Impar
            fprintf(impares, "%.0lf\n", num);
        }
    }

    printf("Salvo com sucesso!");
    
    fclose(fibonacci);
    fclose(pares);
    fclose(impares);
}
