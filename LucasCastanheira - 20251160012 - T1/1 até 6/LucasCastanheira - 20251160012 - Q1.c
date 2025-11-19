
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int transformar_data (char *data, int *dia, int *mes, int *ano){
    printf ("Insira uma data válida no formato dd/mm/aaaa\n");
    fgets (data, 11, stdin);
    
        if (sscanf(data, "%d/%d/%d", dia, mes, ano) == 3){
            if (dia > 0 && mes > 0 && ano > 0){
                switch (*mes){
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        if (*dia > 31){
                            return 0;
                        }
                        else {
                            return 1;
                        }
                    break;
                    
                    case 4: case 6: case 9: case 11:
                        if (*dia > 30){
                            return 0;
                        }
                        else {
                            return 1;
                        }
                    break;
                    
                    case 2:
                        if (*ano % 4 == 0 && *ano % 100 != 0 || *ano % 400 == 0){
                            if (*dia > 29){
                                return 0;
                            }
                            
                            else {
                                return 1;
                            }
                        }
                        else{
                            if (*dia > 28){
                                return 0;
                            }
                            
                            else {
                                return 1;
                            }
                        }
                    break;
                    
                    default:
                        return 0;
                }
                
            }
            return 1;
        }
        else {
            return 0;
        }
}

int main() {
    char data[11];
    int dia, mes, ano;

    if (transformar_data(data, &dia, &mes, &ano)) {
        printf("Dia: %d\nMes: %d\nAno: %d\n", dia, mes, ano);
        printf("Data válida");
    } else {
        printf("Formato inválido!\n");
    }

    return 0;
}
