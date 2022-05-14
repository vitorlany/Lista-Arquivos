#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ex01();
void ex02();

void ex04();

int main()
{
    // Falta fazer o 3
    ex04();
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

void ex04() {
    FILE * fibonacci;
    fibonacci = fopen("fibonacci.txt", "r");
    
    double vetor[64];
    for(int counter = 0; counter <= 64; counter++) {
        char buffer[50]; char *ptr[50];
        fgets(buffer, sizeof(buffer), fibonacci);
        double num = strtod(buffer, ptr);
        vetor[counter] = num;
    }

    int inserido;
    do {
        printf("Insira um numero: ");
        scanf("%i", &inserido);
        if (inserido != -1) {
            int igual = 0;
            int arraySize = sizeof(vetor) / sizeof(vetor[0]);
            for (int i = 0; i <= arraySize; i++) {
                if (vetor[i] == inserido) {
                    printf("Valor igual = [%i] %i\n", i+1, inserido);
                    igual = 1;
                }
            }
            if (!(igual)) {
                for (int i = 0; i <= arraySize; i++) {
                    if (inserido < vetor[i]) {
                        printf("O numero esta entre [%i] %.0lf e [%i] %.0lf\n", i, vetor[i-1], i+1, vetor[i]);
                        break;
                    }
                }
            }
        }
    }while(inserido != -1);


    fclose(fibonacci);
}