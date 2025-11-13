//Este programa mostre a implementação da Fila em alocação dinamica
#include<stdio.h>
#include<stdlib.h>//para usar comando system("pause")
#include<locale.h> //para usar acento em portugues
struct Nodo{
       int info;
       struct Nodo *prox;
};// definição uma caixinha (célula)
typedef struct Nodo celula;
celula *ifila = NULL; //um ponteiro para inicio da fila
celula *ffila = NULL; //um ponteiro para final da fila
//declaração de subprogramas
int filaVazia(void); //verificar se fila está vazia
void insereFila(int x);
void removeFila(void);
void mostraFila(void);
void menu(void);
void devolverFila(void);//coleta de lixo
//programa principal
int main(){
   int info;
   int opcao;   
   setlocale(LC_ALL,"portuguese"); //para usar acento em portugues
   menu();
   printf("Escolha uma opção!\n");
   scanf("%d",&opcao);
   while(opcao!=3){
      switch(opcao){
      case 1:
           printf("Digite um número a ser inserido na Fila !\n");
           scanf("%d",&info);
           insereFila(info);           
           mostraFila(); 
		   printf("\nUma célula inserida na Fila!\n");          
           break;                 
      case 2:           
           if (filaVazia())
              printf("\nA Fila está vazia e não tem nada fazer!\n");
           else {      
             removeFila();              
             mostraFila();
             printf("\nUma celula removida na Fila!\n");
             if (filaVazia()){
             	printf("A célula foi removida é última célula da fila\n");
			 }
           }
           break;
      default:
           printf("Escolha inválida!\n");           
           break;
       }
    printf("Escolha uma opção!\n");
    scanf("%d",&opcao);   
   }
   devolverFila(); // esvaziar a Fila para a mem. livre
   printf("Fim do programa!!!\n");
   system("pause");
   return 0;
}
//subprogramas
int filaVazia(){
	if (ifila == NULL){
		return 1; //verdadeiro
	}
	else{
		return 0; //falso
	}
}
void insereFila(int x){
	celula *ptr;
	ptr = (celula *)malloc(sizeof(celula));
	ptr->info = x;
	ptr->prox = NULL; 
	if (filaVazia()){//essa celula é primeira celula da fila
		ifila = ptr;
		ffila = ptr;
	}
	else{//temos uma fila
		ffila->prox = ptr;
		ffila = ptr;		
	}
	ptr = NULL;
}
void removeFila(){
	celula *aux;
	aux = ifila;
	ifila = ifila->prox; //andar uma celula para frente
	aux->prox = NULL;
	free(aux); //devolver a celula apontado pelo ponteiro aux para memória(RAM)
	aux = NULL; //por segurança
}
void devolverFila(){//coleta de lixo
	celula *aux; //ponteiro auxiliar    
    if (ifila) //se tem fila 
    {  aux = ifila;
       while (aux!=NULL) //percorrer a fila para devolver uma por uma
       {  ifila = ifila->prox;
          aux->prox = NULL;
          free(aux);
          aux = ifila;
       } 
    }
    aux = NULL;
    ifila = NULL; ffila = NULL; //inciarizar os ponteiros da fila
}
void menu(void)
{
     printf("Menu de opcao:\n"
     "       1 -- Inserir uma célula na Fila (no final da fila).\n"     
     "       2 -- Remover uma célula na Fila (no inicio da fila).\n"
     "       3 -- Finalizar. \n ");
}
void mostraFila(void){	
     celula *aux;
     aux = ifila;
     while (aux!=NULL){
           if (aux->prox == NULL)
             printf("%d->#",aux->info);
           else 
             printf("%d->",aux->info);
           aux = aux->prox; //percorrendo da fila 
	 }
     aux = NULL;
}

