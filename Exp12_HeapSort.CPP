#include <conio.h>
#include <time.h>
#include <iostream.h>
#include <dos.h>
#include <stdio.h>

void heapup(int *heap, int index);
void heapdown(int *heap, int index, int n);
void heap_sort(int *heap, int n);

int main()
{
    int i, n;
    clock_t start, end;
    clrscr();
    cout << "\n Enter size of array : ";
    cin >> n;
    int *heap = new int(n + 1);
    cout << "\n Enter values: ";
    for (i = 1; i <= n; i++)
        cin >> *(heap + i);
    start = clock();
    heap_sort(heap, n);
    end = clock();
    cout << "\n Elements of sorted array are :";
    for (i = 1; i <= n; i++)
        cout << " " << heap[i];
    cout << "\n Start : " << start;
    cout << "\n End : " << end;
    cout << "\n CLK_TCK : " << CLK_TCK;
    cout << "\n END - START : " << end - start;
    cout << "\n The time is : " << (end - start) / CLK_TCK;
    getch();
    return 0;
}

void heap_sort(int *heap, int n)
{
    for (int i = 1; i <= n; i++)
    {
        delay(100);
        heapup(heap, i);
    }
    int j = n;
    for (i = 1; i <= n; i++)
    {
        int temp = heap[1];
        heap[1] = heap[j];
        heap[j] = temp;
        j--;
        heapdown(heap, 1, j);
    }
}

void heapup(int *heap, int index)
{
    int val = heap[index];
    while ((index > 1) && (heap[index / 2] < val))
    {
        heap[index] = heap[index / 2];
        index /= 2;
    }
    heap[index] = val;
}

void heapdown(int *heap, int index, int n)
{
    int val = heap[index], j = index * 2;
    while (j <= n)
    {
        delay(100);
        if ((j < n) && (heap[j] < heap[j + 1]))
            j++;
        if (heap[j] < heap[j / 2])
            break;
        heap[j / 2] = heap[j];
        j *= 2;
    }
    heap[j / 2] = val;
}