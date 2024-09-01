#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Implemente uma função que calcule a área da superfície e o volume de uma
esfera de raio r. E a função deve obedecer ao protótipo:
void esfera (float r, float* area, float* volume);
A área da superfície e o volume são dados, respectivamente por 4pir^2 e 4pir^3
/ 3. */

// Função chamada esfera que vai calcular a area e o volume da esfera
void esfera(float r, float* area, float* volume) {
    //raio
    r = 2.0;
    // pi
    float pi = 3.14159;
    // calculo da area  
    *area = 4 * pi * pow(r,2.0);
    // calculo do volume  
    *volume = (4.0 / 3.0) * pi *pow(r,3.0); 

    // mostrando os resultados do calculo
    printf("area da superficie da esfera = %f\n", *area);
    printf("volume da esfera de raio r = %f\n", *volume);
}
// função principal
int main() {  
    float area, volume;

// chamando a função esfera aqui 
    esfera(2, &area, &volume);

    return 0;
}