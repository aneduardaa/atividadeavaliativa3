#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Produto{
    char descricao[50];
    int quantidade;
    int codigo;
    float valor;
    int id;
    struct Produto *prox;
}Produto;

Produto* criarListaVazia(){
    return NULL;
}

//funcao para criar um novo registro
Produto* criarProduto(){
    Produto *novoProduto = (Produto*)malloc(sizeof(Produto));
    if(novoProduto == NULL){
        printf("Erro de alocacao de memoria");
        exit(EXIT_FAILURE);
    }
    novoProduto->prox = NULL;
    return novoProduto;
}
Produto* cadastrar(Produto *lista){
    srand(time(NULL));
    Produto *novoProduto = criarProduto();
    novoProduto->id = rand() % 100;
    printf("Digite o codigo: ");
    scanf("%d", &novoProduto->codigo);
    fflush(stdin);
    printf("Digite a descricao: ");
    scanf("%s", novoProduto->descricao);
    printf("Digite a quantidade: ");
    scanf("%d", &novoProduto->quantidade);
    printf("Digite o valor: ");
    scanf("%f", &novoProduto->valor);

    //verificar se a lista é nula
    if(lista == NULL){
        return novoProduto;
    }else{
        Produto *atual = lista;
        while(atual->prox != NULL){
            atual = atual->prox;
            
        }
        atual->prox = novoProduto;
        return lista;
        //atualizar a lista 
    }
}
 void mostrarLista(Produto *lista){
        Produto *atual = lista;
        if(lista == NULL){
            printf("\nLista nula\n");
            return;
        }
        else{
            while(atual != NULL){
                printf("\nCodigo: %d", atual->codigo);
                printf("Descricao: %s", atual->descricao);
                printf("\nQuantidade: %d", atual->quantidade);
                printf("\nValor: %f", atual->valor);
                printf("\n");
                atual = atual->prox;
            }
        }
 }
 Produto* buscarProduto(Produto *lista, int idBusca){
    Produto *atual = lista;
        while(atual != NULL){
            if(atual->id == idBusca){
                printf("\nCodigo: %d", atual->codigo);
                printf("\nDescricao: %s", atual->descricao);
                printf("\nQuatidade: %d", atual->quantidade);
                printf("\nValor: %f", atual->valor);
                return atual;
            }
            atual = atual->prox;
        }
    printf("Pessoa nao encontrada");
    return NULL;
 }

void alterar(Produto *novoProduto){
    printf("Digite o novo codigo");
    fflush(stdin);
    fgets(novoProduto->codigo, sizeof(novoProduto->codigo), stdin);
    fflush(stdin);
    printf("Digite a nova descricao");
    fflush(stdin);
    scanf("%s", novoProduto->descricao);
}

Produto* excluir(Produto *lista, int idBusca){
    Produto *atual = lista;
    Produto *anterior = NULL;

    while(atual != NULL && atual->id != idBusca){
    	anterior = atual;
        atual = atual->prox;
        
    }
    if(atual != NULL){
        if(anterior != NULL){ 
            anterior->prox = atual->prox;
        }else{
            lista = atual->prox;
        }
        free(atual);
        printf("Removido com sucesso");
    }else{
        printf("Produto nao encontrado");
    }
    return lista;
}

void liberarLista(Produto *lista){
    Produto *atual = lista;
    Produto *prox;
    while(atual != NULL){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

int main(){
    int opcao;
    int idBusca;
    Produto *encontrada;
    Produto *lista = criarListaVazia();
    do{
        printf("\nDigite 1 para adicionar codigo");
        printf("\nDigite 2 para mostrar");
        printf("\nDigite 3 para buscar");
        printf("\nDigite 4 para alterar");
        printf("\nDigite 5 para excluir");
        printf("\nDigite 0 para sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                lista = cadastrar(lista);
            break;
            case 2:
                mostrarLista(lista);
            break;
            case 3:
                printf("Digite o id para busca");
                scanf("%d", &idBusca);
                encontrada = buscarProduto(lista, idBusca);
            break;
            case 4:
                printf("\nDigite o id para alteracao");
                scanf("%d", &idBusca);
                encontrada = buscarProduto(lista, idBusca);
                if(encontrada != NULL){
                    alterar(encontrada);
                }
            break;
            case 5:
                printf("\nDigite o id para exclusao");
                scanf("%d", &idBusca);
                lista = excluir(lista, idBusca);
            break;
        }
    }while(opcao != 0);

    liberarLista(lista);

return 0;
}