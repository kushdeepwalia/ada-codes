#include <conio.h>
#include <time.h>
#include <iostream.h>
#include <dos.h>

float factorial(int n);

int main()
{
    int n;
    clock_t start, end;
    clrscr();
    cout << "\n Enter a positive integer : ";
    cin >> n;
    start = clock();
    cout << "\n Factorial of " << n << " : " << factorial(n);
    end = clock();
    cout << "\n Start : " << start;
    cout << "\n End : " << end;
    cout << "\n CLK_TCK : " << CLK_TCK;
    cout << "\n END - START : " << end - start;
    cout << "\n Total time : " << (end - start) / CLK_TCK;
    getch();
    return 0;
}

float factorial(int n)
{
    delay(1000);
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}