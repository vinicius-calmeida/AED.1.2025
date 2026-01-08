#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_MAX 40050
#define TAMANHO_MAX_P 40000

typedef struct {
	int origem, destino, peso;
} aresta;

aresta grafo[TAMANHO_MAX];
int pais[TAMANHO_MAX_P];

int comparar(aresta *a, aresta *b)
{
	return a->peso - b->peso;
}

int encontrar_componente(int i)
{
	if (i == pais[i])
		return i;
	return encontrar_componente(pais[i]);
}

int kruskal(int arestas)
{
	int i, custo_total, v, u;

	custo_total = 0;

	for (i = 0; i < arestas; ++i)
	{
		v = encontrar_componente(grafo[i].origem);
		u = encontrar_componente(grafo[i].destino);

		if (v != u)
		{
			pais[v] = pais[u];
			custo_total += grafo[i].peso;
		}
	}

	return custo_total;
}

int main(){
	int roteadores, arestas, i;

	while (scanf("%d %d", &roteadores, &arestas), roteadores && arestas)
	{
		memset(grafo, 0, sizeof(grafo));
		memset(pais, 0, sizeof(pais));

		for (i = 0; i < arestas; ++i)
			scanf("%d %d %d", &grafo[i].origem, &grafo[i].destino, &grafo[i].peso);
		qsort(grafo, arestas, sizeof(aresta), comparar); // pra por em ordem

		for (i = 1; i <= roteadores; ++i)
			pais[i] = i;
		printf("%d\n", kruskal(arestas));
	}

	return 0;
}
