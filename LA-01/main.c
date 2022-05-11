#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    double ultimo = 1; double penultimo = 1;
    char total[500];
    sprintf(total, "%.0lf\n%.0lf\n", penultimo, ultimo);
    for (int i = 0; i < 64; i++) {
        double novo = ultimo + penultimo;
        char texto[50];
        sprintf(texto, "%.0lf\n", novo);
        strcat(total, texto);
        penultimo = ultimo;
        ultimo = novo;
    }
    printf("%s", total);
    return 0;
}
