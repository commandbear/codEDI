/*
Preencher uma lista encadeada com 10 elementos usando valores pseudo-aleatórios,
entre 0 – 20, gerados pela própria máquina. Em seguida, o programa deve buscar
valores também aleatórios, e verificar se eles estão contidos na lista.
O programa só pode encerrar após encontrar pelo menos três valores. 

Explicação: Eu tenho 10 valores pseudo-aleatórios contidos nessa lista.
Depois o programa vai gerar novos valores aleatórios, e a cada geração 
ele vai buscar se o elemento gerado se encontra na lista. E isso repete-se
até que três elementos sejam encontrados.

Essa função deve seguir a assinatura: void random_draw()
*/

#include<stdio.h>
#include"single_list.h"
#include<stdlib.h>

int main(){

    random_draw();

    return 0;
}