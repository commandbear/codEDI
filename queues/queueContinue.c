//Menu de interação com Filas
//Autor: Yuri Pedro

#include<stdio.h>
#include "queues.h"

void menu(){
    int removed;
    int option, elem;
    Tqueue *q = NULL;

    do{
        printf("************** Menu de Gerenciamento de Fila **************\n");
        printf("1 - Criar uma fila vazia\n");
        printf("2 - Inserir um elemento na fila\n");
        printf("3 - Remover um elemento da fila\n");
        printf("4 - Verificar se a fila está vazia\n");
        printf("5 - Limpar e remover a fila\n");
        printf("6 - Sair\n");
        printf("Escolha uma das opcoes: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                if(!q){ //se não existir uma fila ainda
                    q = create();
                    printf("Fila criada com sucesso\n\n");
                }
                else{
                    printf("Uma fila ja foi criada\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 2:
                if(!q){
                    printf("A fila nao existe. Crie uma fila antes de inserir um elemento\n\n");
                }
                else{
                    printf("Digite um valor inteiro para o elemento a ser inserido na fila: ");
                    scanf("%d", &elem);
                    insert(q, elem);
                    printf("Elemento %d inserido com sucesso.\n\n", elem);
                }
                system("pause");
                system("cls");
                break;
            case 3:
                if(!q){
                    printf("Nao é possivel remover elementos de uma fila que nao existe\n\n");
                } else if (empty(q)){
                    printf("Nao eh possivel remover elementos de uma fila vazia.\n\n");
                } else {
                    printf("O elemento %d foi removido da fila\n\n", remove_node(q));
                }             
                system("pause");   
                system("cls");
                break;
            case 4:
                if(!q){
                    printf("Nao eh possivel verificar uma fila que nao existe. Crie uma primeiro\n\n");
                } else if (empty(q)){
                    printf("A fila esta vazia\n\n");
                } else {
                    printf("A fila nao esta vazia\n\n");
                }
                system("pause");   
                system("cls");
                break;
            /*case 5:
                if(!q){
                    printf("Não é possivel liberar a memoria de uma fila que não existe\n\n");
                } else {
                    clear(q);
                    printf("Memoria da fila foi liberada com sucesso\n\n");
                }
                system("pause");
                system("cls");
                break;*/
            case 5:
                /*if(q->start && q->end){
                    clear(q);
                }*/
                clear(q);                
                printf("Fechando o programa..\n\n");
                system("cls");
                system("pause");                
                break;
            default:
                printf("Escolha invalida. Tente novamente !\n\n");
                system("pause");
                system("cls");
                break;
        }
    }while (option != 5);    
}

int main(){
    menu();
    return 0;
}