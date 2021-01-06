#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <iostream.h>
#include <limits.h>
#include <malloc.h>

int minDistance(int dist[], int sptSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void printSolution(int dist[], int V)
{
    cout << "Vertex \t\t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << "\n";
}

void dijkstra(int *graph, int src, int V)
{
    int *dist = new int(V);
    int *sptSet = new int(V);
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && *(graph + u * V + v) && dist[u] != INT_MAX && dist[u] + *(graph + u * V + v) < dist[v])
                dist[v] = dist[u] + *(graph + u * V + v);
    }
    printSolution(dist, V);
}

int main()
{
    int V, *graph;
    clock_t start, end;
    clrscr();
    cout << "\n Enter the number of nodes in the graph: ";
    cin >> V;
    clrscr();
    graph = (int *)malloc(V * V * sizeof(int));
    cout << "\n Enter the weight matrix for graph with " << V << " nodes: \n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> *(graph + i * V + j);
    start = clock();
    dijkstra(graph, 0, V);
    end = clock();
    cout << "\n Start : " << start;
    cout << "\n End : " << end;
    cout << "\n CLK_TCK : " << CLK_TCK;
    cout << "\n END - START : " << end - start;
    cout << "\n The time is : " << (end - start) / CLK_TCK;
    getch();
    return 0;
}
