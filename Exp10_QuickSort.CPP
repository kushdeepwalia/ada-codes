#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>

int partition(int arr[], int l, int h);
void quickSort(int arr[], int l, int h);

int main()
{
    int i, n, arr[50];
    clock_t start, end;
    clrscr();
    cout << "\n Enter size of array : ";
    cin >> n;
    cout << "\n Elements of array are : ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    start = clock();
    quickSort(arr, 0, n);
    end = clock();
    cout << "\n Elements of sorted array are :";
    for (i = 0; i < n; i++)
        cout << " " << arr[i];

    cout << "\n Start: " << start;
    cout << "\n End : " << end;
    cout << "\n CLK_TCK : " << CLK_TCK;
    cout << "\n END - START : " << end - start;
    cout << "\n The time is : " << (end - start) / CLK_TCK;

    getch();
    return 0;
}
int partition(int arr[], int p, int q)
{
    int x = arr[p], temp;
    int i = p;
    for (int j = p + 1; j < q; j++)
    {
        delay(100);
        if (arr[j] <= x)
        {
            i += 1;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[p];
    arr[p] = arr[i];
    arr[i] = temp;
    return i;
}
void quickSort(int arr[], int p, int q)
{
    int m;
    if (p == q)
    {
        return;
    }
    else
    {
        m = partition(arr, p, q);
        quickSort(arr, p, m);
        quickSort(arr, m + 1, q);
    }
}