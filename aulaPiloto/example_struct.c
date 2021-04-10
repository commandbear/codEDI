#include <stdio.h>
//#include "struct.h" //as aspas incluem uma biblioteca não padrão (criada pelo user)

//Global - antes do main
typedef struct {
    float weigth;
    int age;
    float heigth;
}Person;
void criar(){ //função auxiliar

}

int main(){
    Person P1, P2;
    
    printf("Insira a idade de P1: ");
    scanf("%d", &P1.age);
    printf ("Insira a altura de P1: ");
    scanf("%f", &P1.heigth);

    printf("Insira a idade de P2: ");
    scanf("%d", &P2.age);
    printf ("Insira a altura de P2: ");
    scanf("%f", &P2.heigth);
    
    
    if (P1.age > P2.age && P1.heigth < P2.heigth){
        printf ("P1 is mais velho que P2, porem, P2 is mais alto que P1");
    } else if (P1.age == P2.age){
        printf ("P1 e P2 possuem a mesma idade");
    } else {
        printf("P2 is mais velho");
    }


    return 0;
}