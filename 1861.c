#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Assassino {
    char nome[11];
    int qtd;
    struct Assassino *esq;
    struct Assassino *dir;
};

struct Assassino *insere(struct Assassino *no, char nome[]) {
    if (no == NULL) {
        struct Assassino *novo = malloc(sizeof(struct Assassino));
        strcpy(novo->nome, nome);
        novo->qtd = 1;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    
    if (strcmp(nome, no->nome) < 0) {
        no->esq = insere(no->esq, nome);
    } else if (strcmp(nome, no->nome) > 0) {
        no->dir = insere(no->dir, nome);
    } else {
        no->qtd++;
    }
    return no;
}

struct Morto {
    char nome[11];
    struct Morto *esq;
    struct Morto *dir;
};

struct Morto *insere_morto(struct Morto *no, char nome[]) {
    if (no == NULL) {
        struct Morto *novo = malloc(sizeof(struct Morto));
        strcpy(novo->nome, nome);
        novo->esq = novo->dir = NULL;
        return novo;
    }
    
    if (strcmp(nome, no->nome) < 0) {
        no->esq = insere_morto(no->esq, nome);
    } else if (strcmp(nome, no->nome) > 0) {
        no->dir = insere_morto(no->dir, nome);
    }
    return no;
}

int busca_morto(struct Morto *no, char nome[]) {
    if (no == NULL) return 0;
    if (strcmp(nome, no->nome) == 0) return 1;
    if (strcmp(nome, no->nome) < 0) {
        return busca_morto(no->esq, nome);
    }
    return busca_morto(no->dir, nome);
}

void imprime(struct Assassino *no, struct Morto *mortos) {
    if (no != NULL) {
        imprime(no->esq, mortos);
        
        if (no->qtd > 0 && busca_morto(mortos, no->nome) == 0) {
            printf("%s %d\n", no->nome, no->qtd);
        }
        
        imprime(no->dir, mortos);
    }
}

int main() {
    char matador[11], vitima[11];
    struct Assassino *hall = NULL;
    struct Morto *lista_mortos = NULL;
    
    while (scanf("%s %s", matador, vitima) == 2) {
        hall = insere(hall, matador);
        lista_mortos = insere_morto(lista_mortos, vitima);
    }
    
    printf("HALL OF MURDERERS\n");
    imprime(hall, lista_mortos);
    
    return 0;
}
