/*Este programa é para mostrar um subprogrma que funciona como um procedimento*/
#include<stdio.h>//biblioteca padrão para entrada e saída para funcionar print f e scan f 
void mensagem(); //declaração de subprograma 
//programa principal
int main(){
	
	mensagem(); //chamado subprograma mensagem()
	return 0;
} 
//subprograma 
void mensagem(){
	printf("Seja bem vindo(a) a linguagem C avancada !!\n"); 
}

