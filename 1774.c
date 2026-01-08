#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int source, destination, peso;
} Edge;

Edge grafo[250];
int pais[70];

int comparar_edges(Edge *a, Edge *b)
{
	return a->peso - b->peso;
}

int encontrar_component(int i)
{
	if (i == pais[i])
		return i;
	return encontrar_component(pais[i]);
}

int kruskal(int edges)
{
	int i, custoTot, componente_v, componente_u;
	custoTot = 0;
	for (i = 0; i < edges; ++i)
	{
		componente_v = encontrar_component(grafo[i].source);
		componente_u = encontrar_component(grafo[i].destination);

		if (componente_v != componente_u)
		{
			pais[componente_v] = pais[componente_u];
			custoTot += grafo[i].peso;
		}
	}

	return custoTot;
}
int main()
{
	int routers, edges, i;

	scanf("%d %d", &routers, &edges);

	for (i = 0; i < edges; ++i)
		scanf("%d %d %d", &grafo[i].source, &grafo[i].destination, &grafo[i].peso);

	qsort(grafo, edges, sizeof(Edge), comparar_edges);

	for (i = 1; i <= routers; ++i)
		pais[i] = i;

	printf("%d\n", kruskal(edges));

	return 0;
}
