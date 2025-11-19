#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inverter_n(char *n, int tam_max){
    
    printf("insira um numero a ser invertido\n");
    fgets (n, tam_max, stdin);
    
    int tamanho = strlen(n);
    
    int i = 0;
    int j = tamanho - 1;
    int temp;
        
        while (i < j){
            temp = n[i];
            n[i] = n[j];
            n[j] = temp;
            i++;
            j--;
            
                
        }
        
        for (i = 0; i < tamanho; i++){
            if (n[i]!= '0'){
                printf("%c", n[i]);
            }
        }
        
        return 1;
}

int main(){
    char n[500];
    
        inverter_n(n, 500);
    
}
