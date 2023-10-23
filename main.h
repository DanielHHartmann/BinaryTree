#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#ifdef _WIN32
#define CLEAR "cls"
#include <Windows.h>
#else
#define CLEAR "clear"
#include <unistd.h>
#endif

void flush()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

struct No{
    int num;
    struct No *esq;
    struct No *dir;
};
typedef struct No no;
typedef no *ArvBin;

ArvBin* criarArvBin(){
    ArvBin *raiz = (ArvBin*) malloc (sizeof(ArvBin));
    if (raiz != NULL){
        *raiz = NULL;
    }else{
        printf("Erro na alocação...\n");
        exit(0);
    }
    return raiz;
}

int insere_ArvBin(ArvBin* raiz){
    no *novo = (no *) malloc(sizeof(no));

    if(novo == NULL){
        printf("Sem memoria disponivel!\n");
        exit(0);
    }

    printf("Novo elemento: ");
    scanf("%d", &novo->num);

    novo->dir = NULL;
    novo->esq = NULL;


    if(*raiz == NULL){
        *raiz = novo;
    }else{
        no *atual = *raiz;
        no *ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(novo->num == atual->num){
                printf("Elemento ja existe...");
                getchar();
                flush();
                free(novo);
                return;
            }
            if(novo->num > atual->num){
                atual = atual->dir;
            }else{
                atual = atual ->esq;
            }
        }
        if (novo->num > ant->num){
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
}

void libera_NO(no *raiz){
    if(raiz == NULL){
        return;
    }else{
        libera_NO(raiz->esq);
        libera_NO(raiz->dir);
        free(raiz);
    }
}
int libera_ArvBin(ArvBin* raiz){
    if(raiz ==NULL){
        return 0;
    }else{
        libera_NO(*raiz);
    }
    free(raiz);
}

void printarInOrdem(no *raiz){
    if(raiz == NULL){
        return;
    }else{
        printarInOrdem(raiz->esq);
        printf("%5d", raiz->num);
        printarInOrdem(raiz->dir);
    }
}


void printarPreOrdem(no *raiz){
    if(raiz == NULL){
        return;
    }else{
        printf("%5d", raiz->num);
        printarPreOrdem(raiz->esq);
        printarPreOrdem(raiz->dir);
    }
}


void printarPosOrdem(no *raiz){
    if(raiz == NULL){
        return;
    }else{
        printarPosOrdem(raiz->esq);
        printarPosOrdem(raiz->dir);
        printf("%5d", raiz->num);
    }
}

void printar(ArvBin *raiz, int *op){
    if (*raiz == NULL){
        printf("Arvore vazia...\n");
        return;
    }else {
        switch(*op){
            case 3:
                printarPreOrdem(*raiz);
                break;
            case 4:
                printarInOrdem(*raiz);
                break;
            case 5:
                printarPosOrdem(*raiz);
                break;
        }
    }
}

void contarNo(no *raiz, int *c){
    if(raiz == NULL){
        return;
    }else{
        *c = 1 + *c;
        contarNo(raiz->esq, c);
        contarNo(raiz->dir, c);
    }
}

void numeroDeNos(ArvBin *raiz){
    int contador = 0;
    if (*raiz == NULL){
        printf("Arvore vazia...\n");
        return;
    }else {
        contarNo(*raiz, &contador);
        printf("A arvore possui %d nos...", contador);
    }
}

void buscar(ArvBin *raiz){
    int valor = 0, achou = 0;
    printf("Insira valor para buscar na arvore: ");
    scanf("%d", &valor);
    if (*raiz == NULL){
        printf("Arvore vazia...\n");
        return;
    }else {
        buscarNaArvore(*raiz, &valor, &achou);
        if (achou)
            printf("\nA arvore possui %d", valor);
        else
            printf("\nA arvore nao possui %d", valor);
    }

};

void buscarNaArvore(no *raiz, int *valor, int *achou){
    if(raiz == NULL){
        return;
    }else{
        if (raiz->num == *valor){
            *achou = 1;
            return;

        }
        if (*valor < raiz->num)
            buscarNaArvore(raiz->esq, valor, achou);
        else
            buscarNaArvore(raiz->dir, valor, achou);
    }
};


void alturaArvore(ArvBin *raiz){
    int altura;
    if (*raiz == NULL){
        printf("Arvore vazia...\n");
        return;
    }else {
        altura = calcularAltura(*raiz);
        printf("Altura da arvore: %d", altura);;
    }
};

int calcularAltura(no *raiz){
    if(raiz == NULL){
        return;
    }else{
        int esqAltura = calcularAltura(raiz->esq);
        int dirAltura = calcularAltura(raiz->dir);
        return max(esqAltura,dirAltura) + 1;
    }
};

void remover(ArvBin *raiz){
    int valor = 0, achou = 0;
    printf("Insira valor para retirar da arvore: ");
    scanf("%d", &valor);
    if (*raiz == NULL){
        printf("Arvore vazia...\n");
        return;
    }else {
        removerDaArvore(*raiz, &valor, &achou);
        if (achou)
            printf("\nValor %d excluido com sucesso", valor);
        else
            printf("\nA arvore nao possui %d", valor);
    }
};

void removerDaArvore(no *raiz, int *valor, int *achou){
    if(raiz == NULL){
        return;
    }
}

#endif // MAIN_H_INCLUDED
