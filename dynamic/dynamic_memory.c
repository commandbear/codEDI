#include <stdio.h>
#include <stdlib.h> //necessário para usar as funções de alocação dinâmica
#define SIZE 10
int main(){
    int size;
    int *v; //sempre que usar malloc, é preciso usar ponteiro
    
    //forma errada de se fazer uma alocação dinâmica
    //printf("Tamanho do vetor: ");
    //scanf("%d", &size);
    //int vector[size]; // é DIFERENTE de se usar vector[SIZE], que está correto
    /*
        vector[0] -> endereço HEX EFAA00   
        vector[1] -> endereço HEX EFAA01
        vector[2] -> endereço HEX EFAA02
        vector[3] -> endereço HEX EFAA03
        ..........
    */
    
    //sizeof retorna o tamanho máximo do tipo de dado escolhido
    printf("Tamanho do int: %ld bytes\n", sizeof(int));
    printf("Tamanho do char: %ld bytes\n", sizeof(char));
    
    //malloc -> alocação dinâmica de memória
    printf("Escolha um tamanho do vetor:");
    scanf("%d", &size); //supondo que usuario escolheu 1000
    
    v = malloc (size * sizeof(int)); //alocação dinamica de uma vetor de tamanho definido pelo usuário
    //esse v é um vetor. Isso é igual a int v[1000], caso size seja 1000

    //printf("Tamanho do VETOR: %ld bytes", sizeof(v)); -> a descobrir

    //Se o usuário quiser mudar o tamanho do vetor alocado dinamicamente -> realloc
    printf("Escolha o novo tamanho do vetor:");
    scanf("%d", &size); //supondo que usuario escolheu 2000
    v = realloc(v, 2000 * sizeof(int)); //neste caso, o vetor passaria a ter 2000 posições
    
    free(v); //libera a memória alocada para o vetor v

    return 0;
}