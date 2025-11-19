#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ler_string (char *string, char *numero,int tam_max1, int tam_max2){
    
    int i = 0;
    int j = 0;
    int contador = 0;
    printf ("Insira um numero:\n");
    fgets (string, tam_max1, stdin);
    if (string[strlen(string) - 1] == '\n'){
            string[strlen(string) - 1] = '\0';
    }
    
    printf("Insira o numero que deseja verificar\n");
    fgets (numero, tam_max2, stdin);
    if (numero[strlen(numero) - 1] == '\n'){
            numero[strlen(numero) - 1] = '\0';  
    }
    
    for (i = 0; string[i] != '\0'; i++){
        if (string[i] == numero[j]){
            j++;
                if (numero[j] == '\0'){
                    j=0;
                    contador++;
                }
        }
    }
    
    
    printf("%d", contador);
    
    return 1;
    
}

int main(){
    char string[250];
    char numero[250];
    
        ler_string (string, numero,250,250);
        
    return 0;
}
