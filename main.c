#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    int op = -1, alt;
    ArvBin *arvore = criarArvBin();

    do{
        puts("----- M E N U -----");
        puts("1) Inserir na arvore");
        puts("2) Remover da arvore");
        puts("3) Listar em Pre-Ordem");
        puts("4) Listar em In-Ordem");
        puts("5) Listar em Pos-Ordem");
        puts("6) Buscar na arvore");
        puts("7) Altura da arvore");
        puts("8) Numero de nos");
        puts("0) Sair");
        puts("");

        printf("Insira a opcao desejada: ");
        scanf("%d", &op);

        system(CLEAR);

        switch(op){
            case 1:
                insere_ArvBin(arvore);
                system(CLEAR);
                break;

            case 2:
                remover(arvore); //TERMINAR ESSE

                getchar();
                flush();
                system(CLEAR);
                break;

            case 3:
                printar(arvore, &op);
                getchar();
                flush();
                system(CLEAR);
                break;

            case 4:
                printar(arvore, &op);
                getchar();
                flush();
                system(CLEAR);
                break;

            case 5:
                printar(arvore, &op);
                getchar();
                flush();
                system(CLEAR);
                break;

            case 6:
                buscar(arvore);
                getchar();
                flush();
                system(CLEAR);
                break;

            case 7:
                alturaArvore(arvore);
                getchar();
                flush();
                system(CLEAR);
                break;

            case 8:
                numeroDeNos(arvore);
                getchar();
                flush();
                system(CLEAR);
                break;

            case 0:
                printf("Saindo...");
                break;

            default:
                system(CLEAR);
                printf("Valor inserido nao aceito...");
                getchar();
                flush();
                system(CLEAR);
        };
    } while(op != 0);

    libera_ArvBin(arvore);
    return 0;
}
