#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<locale.h>
#include<conio.h>
#include<ctype.h>
#ifdef _WIN32
    #include<windows.h>
#else
    #include<unistd.h>
#endif
#define PEDRA 1
#define PAPEL 2
#define TESOURA 3
//decidi fazer o desafio em linguagem C, pois estou aprendendo na faculdade. 
int main()
{
    setlocale(LC_ALL, "portuguese");

    srand(time(NULL));

    int escolha_do_jogador = 0;
    int escolha_do_computador = 0;
    int pontos_do_jogador = 0;
    int pontos_do_computador = 0;
    char jogar_novamente = 'n';

    do {
        pontos_do_jogador = 0;
        pontos_do_computador = 0;

        while (pontos_do_jogador < 3 && pontos_do_computador < 3) {
            printf("\nPlacar: Jogador %d x %d Computador\n", pontos_do_jogador, pontos_do_computador);
            printf("OLÁ, VAMOS JOGAR PEDRA, PAPEL E TESOURA. QUEM FIZER 3 PONTOS PRIMEIRO GANHA O JOGO.\n\nDigite uma das opções a seguir:\n\n");
            printf("1 PEDRA\n");
            printf("2 PAPEL\n");
            printf("3 TESOURA\n\n");
            printf("Jogador escolhe: ");
            scanf("%d", &escolha_do_jogador);

            escolha_do_computador = (rand() % 3) + 1;

            #ifdef _WIN32
                Sleep(1000); 
            #else
                sleep(1); 
            #endif
            
            if (escolha_do_computador == PEDRA)
                printf("\nComputador escolheu PEDRA.\n");
            else if (escolha_do_computador == PAPEL)
                printf("\nComputador escolheu PAPEL.\n");
            else if (escolha_do_computador == TESOURA)
                printf("\nComputador escolheu TESOURA.\n");

            #ifdef _WIN32
                Sleep(1000); 
            #else
                sleep(1);
            #endif

            if (escolha_do_jogador == escolha_do_computador) {
                system("COLOR 3");
                printf("\nEMPATE! Jogue novamente.\n");
            } else if (escolha_do_jogador == PEDRA && escolha_do_computador == TESOURA) {
                printf("\nPEDRA quebra TESOURA. VOCÊ VENCEU.\n\n");
                system("COLOR 2");
                pontos_do_jogador++;
            } else if (escolha_do_jogador == PEDRA && escolha_do_computador == PAPEL) {
                printf("\nPAPEL embrulha PEDRA. VOCÊ PERDEU.\n\n");
                system("COLOR 4");
                pontos_do_computador++;
            } else if (escolha_do_jogador == TESOURA && escolha_do_computador == PAPEL) {
                printf("\nTESOURA corta PAPEL. VOCÊ VENCEU.\n\n");
                system("COLOR 2");
                pontos_do_jogador++;
            } else if (escolha_do_jogador == TESOURA && escolha_do_computador == PEDRA) {
                printf("\nPEDRA quebra TESOURA. VOCÊ PERDEU.\n\n");
                system("COLOR 4");
                pontos_do_computador++;
            } else if (escolha_do_jogador == PAPEL && escolha_do_computador == PEDRA) {
                printf("\nPAPEL embrulha PEDRA. VOCÊ VENCEU.\n\n");
                system("COLOR 2");
                pontos_do_jogador++;
            } else if (escolha_do_jogador == PAPEL && escolha_do_computador == TESOURA) {
                printf("\nTESOURA corta PAPEL. VOCÊ PERDEU.\n\n");
                system("COLOR 4");
                pontos_do_computador++;
            }

            #ifdef _WIN32
                Sleep(1000); 
            #else
                sleep(1);
            #endif
        }

        if (pontos_do_jogador == 3) {
            printf("\nParabéns! Você ganhou o jogo com o placar de %d a %d.\n", pontos_do_jogador, pontos_do_computador);
        } else if (pontos_do_computador == 3) {
            printf("\nSinto muito, o computador ganhou o jogo com o placar de %d a %d.\n", pontos_do_computador, pontos_do_jogador);
        }

        printf("\nDeseja jogar novamente? (s/n): ");
        getchar(); 
        jogar_novamente = tolower(getchar());

    } while (jogar_novamente == 's');

    printf("\nObrigado por jogar!\n");

    return 0;
}

