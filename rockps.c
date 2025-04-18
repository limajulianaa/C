#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<locale.h>
#include<conio.h>
#include<ctype.h>

#define PEDRA 1
#define PAPEL 2
#define TESOURA 3

int main()
{
    setlocale(LC_ALL, "portuguese");

    srand(time(NULL));

    int escolha_do_jogador = 0;
    int escolha_do_computador = 0;
    int pontos_jogador = 0;
    int pontos_computador = 0;
    char jogar_novamente = "n";
    
    do (pontos_do_jogador)

    while (pontos_jogador < 3 && pontos_computador < 3)
    {
        printf("\nPlacar: Jogador %d x %d Computador\n", pontos_jogador, pontos_computador);
        printf("Insira sua escolha.\n");
        printf("1 PEDRA\n");
        printf("2 PAPEL\n");
        printf("3 TESOURA\n");
        printf("Jogador escolheu: ");
        scanf("%d", &escolha_do_jogador);

        escolha_do_computador = (rand() % 3) + 1;
        
        if (escolha_do_computador == PEDRA)
            printf("\nComputador escolheu PEDRA.\n");
        else if (escolha_do_computador == PAPEL)
            printf("\nComputador escolheu PAPEL.\n");
        else if (escolha_do_computador == TESOURA)
            printf("\nComputador escolheu TESOURA.\n");
        
        if (escolha_do_jogador == escolha_do_computador) {
            system("COLOR 3");
            printf("\nEMPATE! Jogue novamente.\n");
        } else {
            if (escolha_do_jogador == PEDRA && escolha_do_computador == TESOURA) {
                printf("\nPEDRA quebra TESOURA. VOCÊ VENCEU.\n\n");
                system("COLOR 2");
                pontos_jogador++;
            } else if (escolha_do_jogador == PEDRA && escolha_do_computador == PAPEL) {
                printf("\nPAPEL embrulha PEDRA. VOCÊ PERDEU.\n\n");
                system("COLOR 4");
                pontos_computador++;
            } else if (escolha_do_jogador == TESOURA && escolha_do_computador == PAPEL) {
                printf("\nTESOURA corta PAPEL. VOCÊ VENCEU.\n\n");
                system("COLOR 2");
                pontos_jogador++;
            } else if (escolha_do_jogador == TESOURA && escolha_do_computador == PEDRA) {
                printf("\nPEDRA quebra TESOURA. VOCÊ PERDEU.\n\n");
                system("COLOR 4");
                pontos_computador++;
            } else if (escolha_do_jogador == PAPEL && escolha_do_computador == PEDRA) {
                printf("\nPAPEL embrulha PEDRA. VOCÊ VENCEU.\n\n");
                system("COLOR 2");
                pontos_jogador++;
            } else if (escolha_do_jogador == PAPEL && escolha_do_computador == TESOURA) {
                printf("\nTESOURA corta PAPEL. VOCÊ PERDEU.\n\n");
                system("COLOR 4");
                pontos_computador++;
            }
        }
    }

    // Verificar quem atingiu 3 pontos primeiro
    if (pontos_jogador == 3) {
        printf("\nParabéns! Você ganhou o jogo com o placar de %d a %d.\n", pontos_jogador, pontos_computador);
    } else if (pontos_computador == 3) {
        printf("\nQue pena! O computador ganhou o jogo com o placar de %d a %d.\n", pontos_computador, pontos_jogador);
    }

    return 0;
}

