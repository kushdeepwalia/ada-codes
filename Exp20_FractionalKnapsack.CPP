#include <iostream.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <time.h>

int sub[10];
float x[10];

void bubble_sort(float arr[], int n);
void frac_knapsack(int n, int cap, int wt[], int pro[]);

int main()
{
    int i, pro[10], wt[10], n, cap;
    float rat[10];
    clock_t start, end;
    clrscr();
    cout << "\n Enter the size : ";
    cin >> n;
    cout << "\n Enter profit values : ";
    for (i = 0; i < n; i++)
	cin >> pro[i];
    cout << "\n Enter weights : ";
    for (i = 0; i < n; i++)
	cin >> wt[i];
    cout << "\n Enter the capacity of knapsack : ";
    cin >> cap;
    for (i = 0; i < n; i++)
    {
        sub[i] = i;
        rat[i] = (float)pro[i] / wt[i];
    }
    bubble_sort(rat, n);
    start = clock();
    frac_knapsack(n, cap, wt, pro);
    end = clock();
    cout << "\n Start : " << start;
    cout << "\n End : " << end;
    cout << "\n CLK_TCK : " << CLK_TCK;
    cout << "\n END - START : " << end - start;
    cout << "\n The time is : " << (end - start) / CLK_TCK;
    getch();
    return 0;
}

void bubble_sort(float arr[], int n)
{
    int i, j, k, temp_sub;
    float temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                temp_sub = sub[j];
                sub[j] = sub[j + 1];
                sub[j + 1] = temp_sub;
            }
        }
    }
}

void frac_knapsack(int n, int cap, int wt[], int pro[])
{
    int i;
    float sum = 0.0;
    for (i = 0; i < n; i++)
        x[i] = 0;
    for (i = 0; i < n; i++)
    {
        delay(1000);
        if (cap == 0)
            break;
        else if (wt[sub[i]] <= cap)
        {
            delay(1000);
            x[sub[i]] = 1;
            cap -= wt[sub[i]];
            sum += pro[sub[i]];
        }
        else if (wt[sub[i]] > cap)
        {
            delay(1000);
            x[sub[i]] = (float)cap / wt[sub[i]];
            sum += x[sub[i]] * pro[sub[i]];
            cap = 0;
        }
    }
    cout << "\n Total Profit : " << sum;
}