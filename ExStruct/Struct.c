#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Etapa 1
typedef struct{
    char nome[30];
    int idade;
    char telefone[10];
}Registro;


//Etapa 3
void quantidadeDeRegistros(Registro *registro3, int LIMITE){
    int j;
    for(j = 0; j < LIMITE; j++){
        
        while(getchar()!='\n');
        printf("Digite um nome para o registro %d:", j+1);
        fgets(registro3[j].nome,sizeof(registro3[j].nome),stdin);
        registro3[j].nome[strcspn(registro3[j].nome,"\n")] = '\0';
        printf("Digite uma idade para o registro %d:", j+1);
        scanf("%d", &registro3[j].idade);
        while(getchar()!='\n');
        printf("Digite um telefone para o registro %d:", j+1);
        scanf("%s", registro3[j].telefone);
        printf("\n");
    }
}
//Etapa 3
void imprimirRegistros(Registro *registro3, int LIMITE){
    int j;
    
    for(j = 0; j < LIMITE; j++){
        printf("Registro %d:\n", j+1);
        printf("Nome:%s\nIdade:%d\nTelefone:%s\n\n\n", registro3[j].nome, registro3[j].idade,registro3[j].telefone);
        
    }
}

//Etapa 4 
typedef struct{
  int dia;
  int mes;
  int ano;
}RgData;

//Etapa 4
typedef struct{
  char nome[35];
  float nota [4];
  RgData data;
  float media;
}RgAluno;

//Etapa 4 
void lerDados(RgAluno* aluno) {
    float soma = 0;

    printf("Nome do aluno: ");
    scanf(" %[^\n]", aluno->nome); 

    printf("Data Nascimento (digite dia mes ano): ");
    scanf("%d %d %d", &aluno->data.dia, &aluno->data.mes, &aluno->data.ano);

    printf("Digite as notas...\n");
    for (int i = 0; i < 4; i++) {
        printf("Nota[%d]: ", i + 1);
        scanf("%f", &aluno->nota[i]);
        soma += aluno->nota[i]; 
    }

    aluno->media = soma/4.0;
}
//Etapa 4 
void imprimirDados(RgAluno* aluno) {
    printf("\nNome do aluno: %s", aluno->nome);
    printf("\nData de Nascimento: %d/%d/%d", aluno->data.dia, aluno->data.mes, aluno->data.ano);
    for (int i = 0; i < 4; i++) {
        printf("\nNota[%d]: %.2f", i + 1, aluno->nota[i]);
    }
    printf("\nMédia do aluno: %.2f\n", aluno->media);
}
int main()
{
    //Etapa 1
    Registro registro1;
    printf("Exercício 1:\n");
    printf("Digite um nome para o registro 1:");
    fgets(registro1.nome,sizeof(registro1.nome),stdin);
    registro1.nome[strcspn(registro1.nome,"\n")] = '\0';
    printf("Digite uma idade para o registro 1:");
    scanf("%d", &registro1.idade);
    printf("Digite um telefone para o registro 1:");
    scanf("%s", registro1.telefone);
    printf("------------------------------------------------\n");
    printf("Registro 1:\n");
    printf("Nome:%s\nIdade:%d\nTelefone:%s\n", registro1.nome, registro1.idade,registro1.telefone);
    
    //Etapa 2
    Registro registro2[10];
    int i;
    printf("------------------------------------------------\n");
    printf("Exercício 2:\n");
    
    for(i = 0; i <10; i++){
        
        while(getchar()!='\n');
        printf("Digite um nome para o registro %d:", i+1);
        fgets(registro2[i].nome,sizeof(registro2[i].nome),stdin);
        registro2[i].nome[strcspn(registro2[i].nome,"\n")] = '\0';
        printf("Digite uma idade para o registro %d:", i+1);
        scanf("%d", &registro2[i].idade);
        while(getchar()!='\n');
        printf("Digite um telefone para o registro %d:", i+1);
        scanf("%s", registro2[i].telefone);
        printf("\n");
    }
        
    printf("------------------------------------------------\n");
    for(i = 0; i < 10; i++){
        printf("Registro %d:\n", i+1);
        printf("Nome:%s\nIdade:%d\nTelefone:%s\n\n\n", registro2[i].nome, registro2[i].idade,registro2[i].telefone);
        
    }
    
    
    //Etapa 3
        int LIMITE;
    printf("------------------------------------------------\n");
    printf("Exercício 3:\n");
    printf("Digite o valor máximo de registros:");
    scanf("%d", &LIMITE);
    printf("\n");
    Registro *registro3 = (Registro*)malloc(LIMITE * sizeof(Registro));
    if (registro3 == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }
    quantidadeDeRegistros(registro3,LIMITE);
    printf("------------------------------------------------\n");
    imprimirRegistros(registro3,LIMITE);
    
    
    
    
    //Etapa 4
    printf("------------------------------------------------\n");
    printf("Exercício 4:\n");
    int n = 5;  
    RgAluno** alunos = (RgAluno**)malloc(n * sizeof(RgAluno*));  

    for (int i = 0; i < n; i++) {
        alunos[i] = (RgAluno*)malloc(sizeof(RgAluno));
    }

    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        lerDados(alunos[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        imprimirDados(alunos[i]);
    }

    for (int i = 0; i < n; i++) {
        free(alunos[i]);
    }
    free(alunos);
    
    
    return 0;
}