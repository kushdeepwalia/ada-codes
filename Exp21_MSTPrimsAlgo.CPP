#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <iostream.h>
#include <limits.h>
#include <malloc.h>

int extract_min(int key[], int mstSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int m = 0; m < V; m++)
    {
        delay(100);
        if (mstSet[m] == 0 && key[m] < min)
        {
            min = key[m];
            min_index = m;
            delay(100);
        }
    }
    return min_index;
}

void printMST(int parent[], int V, int *graph)
{
    cout << "\n Edge Weight";
    for (int i = 1; i < V; i++)
        cout << endl << parent[i] << " - " << i << "\t" << *(graph + i * V + parent[i]);
}

void primMST(int *graph, int V)
{
    int *parent = new int(V);
    int *key = new int(V);
    int *mstSet = new int(V);
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        delay(100);
        int u = extract_min(key, mstSet, V);
        mstSet[u] = 1;
        for (int m = 0; m < V; m++)
        {
            delay(100);
            if (*(graph + count * V + m) && mstSet[m] == 0 && *(graph + count * V + m) < key[m])
            {
                delay(100);
                parent[m] = u;
                key[m] = *(graph + count * V + m);
            }
        }
    }
    printMST(parent, V, graph);
}

int main()
{
    int n, V, *graph;
    clock_t start, end;
    clrscr();
    cout << "\n Enter the number of nodes in the graph:";
    cin >> V;
    graph = (int *)malloc(V * V * sizeof(int));
    cout << "\n Enter the weight matrix for graph with " << V << " nodes: \n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> *(graph + i * V + j);
    start = clock();
    primMST(graph, V);
    end = clock();
    cout << "\n Start : " << start;
    cout << "\n End : " << end;
    cout << "\n CLK_TCK : " << CLK_TCK;
    cout << "\n END - START : " << end - start;
    cout << "\n The time is : " << (end - start) / CLK_TCK;
    getch();
    return 0;
}
