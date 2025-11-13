/* 
Simulamos uma situação que nos permita determinar qual o tempo médio que um
cliente aguarda numa fila de uma agência bancária para realizar uma transação no
caixa eletrônico.
Banco possui 3 caixas eletrônicos e uma fila única para acessar esses três caixas.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h> //recursos para gerar um número aleatório
#include "filaDinamica2.h" //incluir o recurso da fila implementada
#define fim 21600  // 6 horas de expediente no banco

/* Na simulação que vamos realizar, há dois eventos importantes:
 1) Um cliente chega à agência e entra na fila.
 2) Um guichê é liberado, alguém sai da fila e o utiliza-lo. */

int clienteChegou(void);
int transacao(void);

int main() // programa principal
{  int guiches[3], crono, n_cliente, i;
   float t_espera;   
   
   srand(time(NULL)); //Semente para gerar um número aleatório 
   crono = 0; n_cliente = 0; t_espera = 0.0;   
   
   for(i=0; i<3; i++) //inicializar os caixas eletrônicas
      guiches[i] = 0;
   
   // Enquanto não terminar o expediente ou tem alguém na fila
   while ((crono<fim)||(!FilaVazia()))
   {   if ((clienteChegou()) && (crono<fim)) // se um cliente chegou, entra na fila
           insereNoFila(crono);
       for(i=0; i<3; i++)
       // Se há guichê livre e a fila não está vazia, clientes saem da fila e vão serem atendidos
	      if ((guiches[i]==0)&&(!FilaVazia()))
          {   t_espera = t_espera + (crono - RemoveNoFila())/60 ;
              guiches[i] = transacao(); //realizar a operação de transação
              n_cliente++; }
       
       for(i=0;i<3;i++) //decrementar o tempo de uso de cada guichê ocupado
          if (guiches[i]>0)
              guiches[i]--; //decrementar o tempo
              
       crono++; // incrementar o cronômetro
    }
    printf("Total de clientes atendidos ..%d\n",n_cliente);
    printf("tempo media de espera na fila : %.2f mim.\n",(t_espera/n_cliente));
    printf("tempo extra de expediente...%.2f mim\n",(float)(crono-fim)/60);
    system("pause");
    
    return 0;
}
//subprograma como função : simular a chagada de um cliente
int clienteChegou(void)
{  int num;
   num = rand()%30; //gerar um número aleatório entre 0 a 29
   if (num == 0) // probabilidade de chagar um cliente é 1/30
     return 1;
   else 
     return 0;
}
//subprograma como função : simular a operação de transação
// 3 operações: Saque; depósito; Pagamento;
int transacao(void)
{  int num, trans;
   num = rand()%3; //gerar um número aleatório entre 0 a 2
   if (num == 0)
      trans = 60; //efetuar um saque 60s
   else if (num == 1)
           trans = 90; //efetuar um depósito 90s
        else if (num == 2)
                trans = 120; //efetuar um pagamento 120s
   return trans;
}             
         
   
 

            
   
