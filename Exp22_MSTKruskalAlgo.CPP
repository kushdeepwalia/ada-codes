#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <dos.h>
#include <time.h>
#include <limits.h>

int find(int i, int parent[])
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j, int parent[])
{
    int a = find(i, parent);
    int b = find(j, parent);
    parent[a] = b;
}

void kruskalMST(int *graph, int V)
{
    int *parent = new int(V);
    int mincost = 0;
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int edge_count = 0;
    while (edge_count < V - 1)
    {
        delay(100);
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
            {
                delay(100);
                if (find(i, parent) != find(j, parent) && *(graph + i * V + j) < min)
                {
                    delay(100);
                    min = *(graph + i * V + j);
                    a = i;
                    b = j;
                }
            }
        union1(a, b, parent);
        edge_count++;
        cout << "\n Edge " << edge_count << " : (" << a << ", " << b << ") cost : " << min;
        mincost += min;
    }
    cout << "\n Minimum cost : " << mincost;
}

int main()
{
    int n, V, *graph;
    clock_t start, end;
    clrscr();
    cout << "\n Enter the number of nodes in the graph:";
    cin >> V;
    graph = (int *)malloc(V * V * sizeof(int));
    cout << "\n Enter the weight matrix for graph with " << V << " nodes :\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> *(graph + i * V + j);
    start = clock();
    kruskalMST(graph, V);
    end = clock();
    cout << "\n End : " << end;
    cout << "\n CLK_TCK : " << CLK_TCK;
    cout << "\n END - START : " << end - start;
    cout << "\n The time is : " << (end - start) / CLK_TCK;
    getch();
    return 0;
}