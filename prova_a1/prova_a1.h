//Função de Limpar Buffer
void cleanBuffer(void){
    char c;
    while ((c = getchar()) != '\n' && c != EOF);    
}

//Struct da Questão 1
typedef struct{
    long code;
    char name[100];
    float grade1;
    float grade2;
    float grade3;
} Student;
