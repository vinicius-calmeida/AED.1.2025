#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 1100

typedef struct Aresta {
    int origem, destino;
    double peso;
} Aresta;

int conjuntoPai[TAM_MAX];
Aresta grafo[TAM_MAX];

int qtdAeroportos;
double limitePeso;


int compararArestas(const void *a, const void *b) {
    double diferenca = ((Aresta *)a)->peso - ((Aresta *)b)->peso;

    if (diferenca == 0.0)
        return 0;
    else if (diferenca > 0.0)
        return 1;
    else
        return -1;
}

int encontrarRaiz(int vertice) {
    if (conjuntoPai[vertice] == vertice)
        return vertice;
    
    return encontrarRaiz(conjuntoPai[vertice]);
}

double calcularKruskal(int totalArestas, int totalVertices) {
    int i;
    double custoTotal = 0;

    for (i = 0; i <= totalVertices; ++i)
        conjuntoPai[i] = i;

    qtdAeroportos = 0;
    for (i = 0; i < totalArestas; ++i) {
        int raizOrigem = encontrarRaiz(grafo[i].origem);
        int raizDestino = encontrarRaiz(grafo[i].destino);

        if (raizOrigem != raizDestino) {
            conjuntoPai[raizOrigem] = conjuntoPai[raizDestino];

            if (grafo[i].peso > limitePeso) {
                custoTotal += grafo[i].peso + 2;
                ++qtdAeroportos;
            } else {
                custoTotal += grafo[i].peso;
            }
        }
    }

    return custoTotal;
}
int main() {
    int qtdVertices, qtdArestas, i;

    while (scanf("%d %d %lf", &qtdVertices, &qtdArestas, &limitePeso), 
           qtdVertices && qtdArestas && limitePeso) {
        
        for (i = 0; i < qtdArestas; ++i) {
            scanf("%d %d %lf", &grafo[i].origem, &grafo[i].destino, &grafo[i].peso);
        }

        qsort(grafo, qtdArestas, sizeof(Aresta), compararArestas);
        printf("%.2lf ", calcularKruskal(qtdArestas, qtdVertices));
        printf("%d\n", qtdAeroportos);
    }

    return 0;
}
