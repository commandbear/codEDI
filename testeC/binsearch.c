//Exemplos de busca binária
//Fonte: https://www.youtube.com/watch?v=CXUtxmwy1RU&t=584s&ab_channel=Programeseufuturo

#include <stdio.h>

//Busca Binária Recursiva
int recursiveBinSearch (int *vector, int key, int low, int high){
    int mid;
    if(low <= high){
        mid = (low + high) / 2;
        if(key == vector[mid]){
            return mid;
        } else {
            if(key < vector[mid]){
                return recursiveBinSearch(vector, key, low, mid-1);
            } else {
                return recursiveBinSearch(vector, key, mid+1, high);
            }
        }
    }
    return -1; //elemento não encontrado
}

//Busca Binária Iterativa
int iteractiveBinSearch(int *vector, int key, int high){
    int low = 0;
    int mid = (low + high) / 2;

    while(low <= high){
        if(key == vector[mid]){
            return mid;
        } else {
            if(key < vector[mid]){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        mid = (low + high) / 2;
    }
    return -1;
}

int main (){
    int vet[10] = {13, 14, 19, 43, 47, 52, 65, 82, 89, 91};
    int value, op;
    char choose;

    do{
        printf("Digite o valor a ser buscado: ");
        scanf("%d", &value);
        setbuf(stdin, NULL);
        printf("Busca Binaria >> {r}=Recursiva : {i}=Iterativa\n    ");
        scanf("%c", &choose);

        switch (choose){
            case 'r':
                printf("Valor do index por Recursividade >> %d", recursiveBinSearch(vet, value, 0, 9)); break;                            
            case 'i':
                printf("Valor do index por Iteratividade >> %d", iteractiveBinSearch(vet, value, 9)); break;        
            default:
                printf("Escolha Novamente");
                break;
        }
        //printf("Valor do index >> %d", recursiveBinSearch(vet, value, 0, 9));
        //printf("Valor do index >> %d", iteractiveBinSearch(vet, value, 9));

        printf("\n{0} - Sair\n{1} - Nova Busca\n");
        scanf("%d", &op);
    } while(op != 0);
    return 0;
}