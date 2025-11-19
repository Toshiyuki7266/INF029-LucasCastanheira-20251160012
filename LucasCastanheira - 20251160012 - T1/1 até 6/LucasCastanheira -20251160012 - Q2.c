#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int diasDoMes(int mes, int ano) {
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return ehBissexto(ano) ? 29: 28;
        default:
            return 0;
    }
}

int validar_data(char *data, int *dia, int *mes, int *ano) {
    fgets(data, 22, stdin);

    if (sscanf(data, "%d/%d/%d", dia, mes, ano) != 3){
        return 0;
    }
    else if (*dia <= 0 || *mes <= 0 || *ano <= 0){
        return 0;
    }
    else if (*dia > diasDoMes(*mes, *ano)){
        return 0;
    }
    
    else{
        return 1;
    }
    
}

void diferencaDatas(int d1, int m1, int a1,
                    int d2, int m2, int a2,
                    int *anos, int *meses, int *dias) {

    if (d2 < d1) {
        m2--;
        if (m2 == 0) {
            m2 = 12;
            a2--;
        }
        d2 += diasDoMes(m2, a2);
    }

    if (m2 < m1) {
        m2 += 12;
        a2--;
    }

    *dias  = d2 - d1;
    *meses = m2 - m1;
    *anos  = a2 - a1;
}

int main() {
    char data[22];
    int d1, m1, a1;
    int d2, m2, a2;
    int anos, meses, dias;

    printf("Insira a primeira data (dd/mm/aaaa):\n");
    if (!validar_data(data, &d1, &m1, &a1)) {
        printf("Data inválida!\n");
        return 0;
    }

    printf("Insira a segunda data (dd/mm/aaaa):\n");
    if (!validar_data(data, &d2, &m2, &a2)) {
        fflush(stdin);
        printf("Data inválida!\n");
        return 0;
    }

    diferencaDatas(d1, m1, a1, d2, m2, a2, &anos, &meses, &dias);
    

    printf("\nDiferença entre as datas:\n");
    printf("%d anos, %d meses e %d dias\n", anos, meses, dias);

    return 0;
}
