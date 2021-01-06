#include <iostream.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

int binomialCoeff(int n, int k);

int main()
{
    int n, k;
    clock_t start, end;
    clrscr();
    cout << "\n Enter value of n : ";
    cin >> n;
    cout << "\n Enter value of k : ";
    cin >> k;
    start = clock();
    cout << "\n Value of C(" << n << ", " << k << ") is : " << binomialCoeff(n, k);
    end = clock();
    cout << "\n Start : " << start;
    cout << "\n End : " << end;
    cout << "\n CLK_TCK : " << CLK_TCK;
    cout << "\n END - START : " << end - start;
    cout << "\n Total Time: " << (end - start) / CLK_TCK;
    getch();
    return 0;
}

int binomialCoeff(int n, int k)
{
    delay(100);
    if (k > n)
        return 0;
    else if (k == 0 || k == n)
        return 1;
    else
        return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}