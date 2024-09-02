#include <stdio.h>
#include <stdlib.h>
//  Biblioteca que tem o comando para deixar letras maiusculas
#include <ctype.h>

/*Faça um programa em C que preencha um vetor com letras minúsculas e, através
de um vetor de ponteiros, altere as letras para maiúsculas. (Para alterar as
letras do vetor de caracteres, você deve utilizar o vetor de ponteiros) */

int main() {  
    
     char letrasMinusculas[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
    char *pont;
    pont = &letrasMinusculas;
    printf("Colocando as letras em maiusculas\n");
   for( int i=0 ; i <= 6 ; i++){
        
        printf("%c", toupper(pont[i]));

   }
    printf("\nColocando as letras em minusculas\n");
   for( int i=0 ; i <= 6 ; i++){
       
        printf("%c", tolower(pont[i]));

   }
   
    return 0;
}