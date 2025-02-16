#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct lista{
       int info;
       struct lista * prox;       
};

typedef struct lista Lista;

Lista* inicializaLista(){
       return NULL;       
}

bool vazia(Lista * pL){
     if(pL->info == NULL)
        return true;             
     else
         return false;
}

Lista * inserir(Lista * pL, int valor){
      Lista * novo = (Lista *) malloc(sizeof(Lista));
      if(novo != NULL){
         novo->info = valor;
         novo->prox = pL;
         printf("Lista[%d] \n", novo->info);
         return novo;        
      } 
}

void imprimir(Lista * pL){
     
     while(pL != NULL){
             printf(" %d ", pL->info);
             pL = pL->prox;         
     }     
     printf("\n\nFim da Lista Encadeada! \n\n");
}

Lista * buscar(Lista *pL, int valor){
      while(pL != NULL){
            if(pL->info == valor)
               return pL;  
            else
                pL=pL->prox;
      }    
      return pL;  
}

Lista * remover(Lista * pL, int valor){
     Lista * p = pL;     /* ponteiro do tipo Lista para percorrer a lista*/
     Lista * ant = NULL; /* ponteiro do tipo Lista para elemento anterior */      
     
      /* procura elemento na lista, guardando anterior */
      while(p != NULL && p->info != valor){
           ant = p;
           p = p->prox;  
     }
     
     /* verifica se achou elemento */        
     if(p == NULL){ 
          return pL; /* n?o achou: retorna lista original */
     }
     
     /* retira elemento */        
     if(ant == NULL){      /*se entrar aqui ? porque ? o primeiro elemento da lista. Sen?o j? entrou pelo menos 1 vez no while acima */                                 
        pL = p->prox;      /* retira elemento do in?cio */    
     }
     else{
          ant->prox = p->prox; /* retira elemento do meio da lista */          
     }
     free(p);
     return pL;     
}

void libera(Lista * pL){
     
     Lista * p = pL;
     Lista * t;
     
     while(p != NULL){
           t = p->prox; /* guarda refer?ncia para o pr?ximo elemento */
           free(p);     /* libera a mem?ria apontada por p */
           p = t;       /* faz p apontar para o pr?ximo */   
     }
}

void main(){

     /* declara uma lista n?o inicializada */ 
     Lista * L;
     Lista * Q;
     
     /* inicializa lista como vazia */                 
     L = inicializaLista();     
     
     /* Checa se a lista est? vazia */
     if(vazia(&L)){
         printf("Lista Vazia! \n");                        
     }
     else{
          printf("Lista com elementos! \n");     
     }
     
     L = inserir(L, 1000);  /* insere na lista o elemento 1000 */
     L = inserir(L, 100);   /* insere na lista o elemento 100 */
     L = inserir(L, 10);    /* insere na lista o elemento 10 */
     L = inserir(L, 1);     /* insere na lista o elemento 1 */
     
     /* imprime os elementos da lista */
     printf("Imprimindo a Lista... \n\n");
     imprimir(L);
     
     /* verifica se o elemento est? na lista encadeada*/
     Q = buscar(L, 10);
     if(Q != NULL){
          printf("\nElemento %d encontrado! \n", Q->info);     
     }
     else{
          printf("\nElemento nao encontrado! \n\n");     
     }
     
     /* retira um elemento da lista encadeada */      
     printf("Removendo um valor da Lista! \n");
     L = remover(L, 10);
     
     /* imprime os elementos da lista */
     printf("Imprimindo a Lista... \n\n");
     imprimir(L);
     
     /* libera as listas da mem?ria */    
     libera(L);
     
     system("PAUSE");     
}