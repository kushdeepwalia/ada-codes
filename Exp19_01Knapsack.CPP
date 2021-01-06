#include <iostream.h>
#include <stdio.h>
#include <dos.h>
#include <time.h>
#include <conio.h>

int sub[10];
float x[10];

void bubble_sort(float arr[], int n);
void knapsack_01(int n, int cap, int wt[], int pro[]);

int main()
{
    int i, pro[10], wt[10], n, cap;
    clrscr();
    cout << "\n Enter the size : ";
    cin >> n;
    cout << "\n Enter profit values : ";
    for (i = 1; i <= n; i++)
        cin >> pro[i];
    cout << "\n Enter weights : ";
    for (i = 0; i < n; i++)
        cin >> wt[i];
    cout << "\n Enter the capacity of knapsack : ";
    cin >> cap;
    knapsack_01(n, cap, wt, pro);
    getch();
    return 0;
}

void knapsack_01(int n, int cap, int wt[], int pro[])
{
    int c[100][100];
    clock_t start, end;
    for (int i = 0; i <= cap; i++)
    {
        c[0][i] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        c[j][0] = 0;
    }
    start = clock();
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= cap; j++)
        {
            delay(100);
            if (wt[i] <= j)
            {
                delay(100);
                if ((pro[i] + c[i - 1][j - wt[i]]) > c[i - 1][j])
                {
                    c[i][j] = pro[i] + c[i - 1][j - wt[i]];
                }
                else
                {
                    c[i][j] = c[i - 1][j];
                }
            }
            else
                c[i][j] = c[i - 1][j];
        }
    }
    end = clock();
    j = cap;
    int sum = 0;
    for (i = n; i >= 1; i--)
    {
        if (c[i][j] != c[i - 1][j])
        {
            sum += pro[i];
            j -= wt[i];
        }
    }
    cout << "\n Total Profit : " << sum;
    cout << "\n Start : " << start;
    cout << "\n End : " << end;
    cout << "\n CLK_TCK : " << CLK_TCK;
    cout << "\n END - START : " << end - start;
    cout << "\n Total Time: " << (end - start) / CLK_TCK;
}
