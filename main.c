#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ex01();
void ex02();
void ex03();
void ex04();

int main()
{
    int atividade = 0;
    do {
        printf("\nInsira o numero da atividade (Flag -1)\n");
        scanf("%i", &atividade);

        switch (atividade)
        {
        case 1:
            printf("a) - gravar em um arquivo os 64 primeiros valores da série: 1 1 2 3 5 8 13 21 34 . . .\n");
            ex01();
            break;
            
        case 2:
            printf("b) - ler o arquivo letra a e armazenar os valores pares em um arquivo e os impares em outro arquivo\n");
            ex02();
            break;
            
        case 3:
            printf("c) - ler o arquivo letra a e armazenar apenas os primos em um arquivo\n");
            ex03();
            break;
            
        case 4:
            printf("d) - leia um conjunto de valores (flag -1) e verifique para cada valor se ele se encontra ou não no arquivo\n\
gravado na letra a. Caso não exista deverá mostrar o valor anterior e o posterior a esse valor. Exemplo:\n\
caso seja lido o valor 8 – deverá ser mostrada a informação o valor 8 está no arquivo na posição 6, caso o\n\
valor lido seja o 17 – deverá ser mostrada a informação o valor 17 não está no arquivo, valores mais\n\
próximos: 13 e 21.\n");
            ex04();
            break;
        
        default:
            break;
        }
    }while(atividade);

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

void ex03() {
    FILE * arquivo;
    arquivo = fopen("fibonacci.txt", "r");
    
    FILE * primos;
    primos = fopen("primos.txt", "w");

    int flag = 0;
    for(int counter = 0; counter <= 64; counter++) {
        char buffer[50]; char * ptr[50];
        fgets(buffer, sizeof(buffer), arquivo);
        double num = strtod(buffer, ptr);
        
        if (num != 1) {
            int flag = 0;
            for (int j = 2; j < num; j++) {
                if (fmod(num, j) == 0) {
                    flag = 1;
                    break;
                }
            }

            if (!(flag)) {
                printf("PRIMO %.0lf \n", num);
                // Professor, toda a atividade esta correta, mas tem um 
                // bug aqui no registro que nao consegui resolver. (o comando esta correto, mas nao salva)
                fprintf(primos, "%.0lf\n", num);
            }
        }
    }


    fclose(arquivo);
    fclose(primos);
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