#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ler_string (char *string, char *letra, int tamanho, int *contador){
    
    int i = 0;
    printf ("Insira uma string:\n");
    fgets (string, tamanho, stdin);
    
    printf("Insira a letra que deseja verificar\n");
    fgets (letra, 3, stdin);
    
    *contador = 0;
    
    for (i=0; string[i] != '\0'; i++){
        if (string [i] == *letra || string [i] == *letra - 32 || string [i] == *letra + 32){
            (*contador)++;
        }
        
    }
    
    printf("%d", *contador);
    
    return 1;
    
}

int main(){
    char string[250];
    char letra[3];
    int tamanho = 250;
    int contador;
    
        ler_string (string, letra, tamanho, &contador);
        
    return 0;
}
