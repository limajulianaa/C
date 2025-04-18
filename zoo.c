#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main (){
setlocale(LC_ALL, "portuguese");
float animal, consumo, custo, consumo_dia, custo_dia, consumo_mes, custo_mes;
char nome[30];

printf("Digite o tipo de animal: ");
gets(nome);
printf("Digite quantos animais deste tipo há no zoológico: ");
scanf("%f", &animal);
printf("Quantos kilogramas de comida esses animais consomem por dia individualmente? " );
scanf("%f", &consumo);
printf("Qual é o preço do kilo de comida? R$");
scanf("%f", &custo);
	
	consumo_dia = consumo * animal;
	custo_dia = consumo_dia * custo;
	consumo_mes = consumo_dia * 30;
	custo_mes = custo_dia * 30;

printf("Por dia, %.0f unidades de %s consomem %.1f kg de alimento gerando um custo diário de R$ %.2f\n", animal, nome, consumo_dia, custo_dia );
printf("Durante um mês, essas %.0f unidades de %s consumirão %.1f kg de alimento gerando um custo mensal de R$ %.2f\n", animal, nome, consumo_mes, custo_mes );
system("pause");
}
