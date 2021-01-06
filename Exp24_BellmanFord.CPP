#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <iostream.h>
#include <limits.h>
#include <malloc.h>

void BellmanFord(int *graph, int V, int E, int src)
{
	int *dis = new int(V), i;
	for (i = 0; i < V; i++)
		dis[i] = INT_MAX;

	dis[src] = 0;
	for (i = 0; i < V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			delay(100);
			if (dis[*(graph + j * E)] != INT_MAX && dis[*(graph + j * E)] + *(graph + j * E + 2) < dis[*(graph + j * E + 1)])
			{
				delay(100);
				dis[*(graph + j * E + 1)] = dis[*(graph + j * E)] + *(graph + j * E + 2);
			}
		}
	}
	for (i = 0; i < E; i++)
	{
		delay(100);
		int x = *(graph + i * E);
		int y = *(graph + i * E + 1);
		int weight = *(graph + i * E + 2);
		if (dis[x] != INT_MAX && dis[x] + weight < dis[y])
			cout << "Graph contains negative  weight cycle\n";
	}
	cout << "Vertex Distance from Source" << endl;
	for (i = 0; i < V; i++)
		cout << i << "\t\t" << dis[i] << endl;
}

int main()
{
	int V = 5;
	int E = 8;
	int graph[][3] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {3, 2, 5}, {3, 1, 1}, {1, 4, 2}, {4, 3, -3}};
	int *g, i;
	clock_t start, end;
	clrscr();
	g = (int *)malloc(E * 3 * sizeof(int));
	for (i = 0; i < E; i++)
		for (int j = 0; j < 3; j++)
		{
			*(g + i * E + j) = graph[i][j];
		}
	start = clock();
	BellmanFord(g, V, E, 0);
	end = clock();
	cout << "\n Start : " << start;
	cout << "\n End : " << end;
	cout << "\n CLK_TCK : " << CLK_TCK;
	cout << "\n END - START : " << end - start;
	cout << "\n Total time : " << (end - start) / CLK_TCK;
	getch();
	return 0;
}
