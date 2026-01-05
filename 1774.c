#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int source, destination, weight;
} Edge;

Edge graph[250];
int parent[70];

int compare_edges(Edge *a, Edge *b)
{
	return a->weight - b->weight;
}

int find_component(int i)
{
	if (i == parent[i])
		return i;
	return find_component(parent[i]);
}

int kruskal(int edges)
{
	int i, total_cost, component_v, component_u;
	total_cost = 0;

	for (i = 0; i < edges; ++i)
	{
		component_v = find_component(graph[i].source);
		component_u = find_component(graph[i].destination);

		if (component_v != component_u)
		{
			parent[component_v] = parent[component_u];
			total_cost += graph[i].weight;
		}
	}

	return total_cost;
}
int main()
{
	int routers, edges, i;

	scanf("%d %d", &routers, &edges);

	for (i = 0; i < edges; ++i)
		scanf("%d %d %d", &graph[i].source, &graph[i].destination, &graph[i].weight);

	qsort(graph, edges, sizeof(Edge), compare_edges);

	for (i = 1; i <= routers; ++i)
		parent[i] = i;

	printf("%d\n", kruskal(edges));

	return 0;
}
