/*Este programa é para mostrar um subprograma que funciona como uma função ( que retorna um valor ) */ 
#include<stdio.h>//biblioteca de subprograma 
//programa principal 
int get_idade(); //delarção  do subprogrma
//programa principal
int main(){
	int idade;
	idade = get_idade();
	printf("A sua idade: %d anos", idade);
	return 0;
}
//subprograma funciona como um valor
//int é um tipo de dado a ser retornado plo subprograma

int get_idade(){
	int idade; 
	printf("Informe a sua idade: idade = ");
	scanf("%d", &idade); 
	return idade; //retornar o valor idade 
}
