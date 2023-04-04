#include <stdio.h>
#include <stdlib.h>


//estrutura nó
typedef struct no
{
    int informacao;
    struct no *esquerda,*direita;
    /* data */
}No;


//estrutura arvore,com ponteiro para no
typedef struct 
{   
    No *raiz;
    int tam;
    /* data */
}Arvore;

//assinatura do procedimento inserir direita(necessário pois sera utilizado para inserir esquerda)

void inserirDireita(No* no, int valor);

//procedimento para inserir no subno esquerdo
void inserirEsquerda(No* no, int valor){
    if(no->esquerda == NULL){
        //Ao dar o malloc, separamos uma posição de memória para esse novo no, semelhante a No novo = new No(), em java
        No *novo = ((No*) malloc(sizeof(No)));
        novo->informacao = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    else{
        if( valor < no->esquerda -> informacao){
            inserirEsquerda(no-> esquerda,valor);
        }else{
            inserirDireita(no-> esquerda,valor);
        }
    }
}

//procedimento para inserir no sub no direito
void inserirDireita(No* no, int valor){
    if(no->direita == NULL){
        No* novo = ((No*)malloc(sizeof(No)));
        novo->informacao = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    if(valor > no ->direita->informacao){
        inserirDireita(no -> direita,valor);
    }else{
        inserirEsquerda(no ->direita,valor);
    }
}

//funcao que gerencia qual procesdimento utilizar, além de verificar se a raiz é NULL, se sim, cria-se um novo no e dá-se o nome de raiz
void inserir(Arvore *arvore, int valor){
    if(arvore ->raiz == NULL){
        No *novo = ((No*)malloc(sizeof(No)));
        novo ->informacao = valor;
        novo ->esquerda = NULL;
        novo ->direita = NULL;
        arvore ->raiz = novo;
    }else{
        if (valor < arvore->raiz->informacao)
        {
            inserirEsquerda(arvore->raiz,valor);
                    /* code */
        }else{
            inserirDireita(arvore->raiz,valor);
        }
    }
}


//funcao de inserir, recursiva
No* novo_inserir(No* raiz, int valor){
    if(raiz == NULL){
        No *novo = ((No*) malloc (sizeof(No)));
        novo->informacao = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    if(valor < raiz->informacao) raiz->esquerda =  novo_inserir(raiz->esquerda,valor);
    else raiz ->direita = novo_inserir(raiz->direita,valor);

    return raiz;
}
int tamanho(No* raiz){
    if(raiz == NULL)return 0;
    return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

int buscar(No* raiz, int chave){
    if(raiz == NULL) return 0;
    else{
        if(raiz->informacao == chave)return 1;
        if(chave < raiz -> informacao) return buscar(raiz->esquerda,chave);
        return buscar(raiz->direita,chave);
    }
}



void print(No* raiz){
    if(raiz != NULL){
        print(raiz->esquerda);
        printf("%d\n",raiz->informacao);
        print(raiz->direita);
    }
}

No* remover(No* raiz, int chave){
    if(raiz == NULL)  {
          perror("Arvore vazia");
          return NULL;
    }else{
        if(raiz -> informacao == chave){
            if(raiz ->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                return NULL;}
                else{
                    if(raiz ->esquerda == NULL || raiz->direita == NULL){
                        No *aux;
                        if(raiz -> esquerda != NULL) aux = raiz -> esquerda;
                        else aux = raiz ->direita;
                        free(raiz);
                        return aux;
                    }
                    No *aux = raiz ->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz -> informacao = aux -> informacao;
                    aux->informacao = chave;
                    raiz -> esquerda = remover(raiz->esquerda,chave);
                    return raiz;

                }
        }else{
            if( chave < raiz -> informacao){
                raiz->esquerda = remover(raiz->esquerda,chave);
            }else{
                raiz->direita = remover(raiz->direita , chave);
            }
            return raiz;
            
        }
    }


}

int main(int argc, char const *argv[])
{
    int op, valor;
    Arvore arv_1;
    arv_1.raiz == NULL;

    No* raiz = NULL;
    do{
        printf("\n0-Sair - 1-Inserir - 2-Imprimir - 3-Excluir - 4-Buscar\n\n");
        scanf("%d",&op);

        switch (op)
        {
        case 0:
            printf("\nSaindo...\n");
            break;
        case 1:
            printf("\nDigite um valor:\n");
            scanf("%d",&valor);
            raiz = novo_inserir(raiz,valor);
            break;
        case 2:
            printf("\nImpressao da Arvore binaria\n");
            print(raiz);
            printf("\n");
            printf("\nTamanho:%d\n",tamanho(raiz));
            break;
        case 3:
            printf("\nDigite o valor a ser removido: ");
            scanf("%d",&valor);
            raiz = remover(raiz,valor);
            break;
        case 4:
            printf("\nQual valor deseja buscar?\n");
            scanf("%d",&valor);
            printf("\nResultado da Busca: %d",buscar(raiz,valor));
            break;
        default:
            printf("\nOpcao invalida");
            break;
        }

    }while(op !=0);
    return 0;
}









