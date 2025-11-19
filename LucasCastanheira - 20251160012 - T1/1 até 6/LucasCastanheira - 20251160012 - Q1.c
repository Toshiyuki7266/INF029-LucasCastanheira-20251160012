
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int validar_data(char *data, int *dia, int *mes, int *ano) {
    printf("Insira uma data válida no formato dd/mm/aaaa\n");
    fgets(data, 11, stdin);

    if (sscanf(data, "%d/%d/%d", dia, mes, ano) != 3)
        return 0;

    if (*dia <= 0 || *mes <= 0 || *ano <= 0)
        return 0;

    switch (*mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return (*dia <= 31);

        case 4: case 6: case 9: case 11:
            return (*dia <= 30);

        case 2:
            if (ehBissexto(*ano))
                return (*dia <= 29);
            else
                return (*dia <= 28);

        default:
            return 0;
    }
}

int main() {
    char data[11];
    int dia, mes, ano;

    if (validar_data(data, &dia, &mes, &ano)) {
        printf("Dia: %d\nMes: %d\nAno: %d\n", dia, mes, ano);
        printf("Data válida");
    } else {
        printf("Formato inválido!\n");
    }

    return 0;
}
