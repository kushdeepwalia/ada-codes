#include <conio.h>
#include <time.h>
#include <iostream.h>
#include <dos.h>

int fib(int x);

int main()
{
	int x, i = 0;
	clock_t start, end;
	clrscr();
	cout << "\n Enter a number : ";
	cin >> x;
	cout << "\n The fibonacci series :";
	start = clock();
	while (i < x)
	{
		cout << " " << fib(i);
		i++;
	}
	end = clock();
	cout << "\n End : " << end;
	cout << "\n CLK_TCK : " << CLK_TCK;
	cout << "\n END - START : " << end - start;
	cout << "\n The time is : " << (end - start) / CLK_TCK;
	getch();
	return 0;
}

int fib(int x)
{
	delay(1000);
	if ((x == 1) || (x == 0))
	{
		return (x);
	}
	else
	{
		return (fib(x - 1) + fib(x - 2));
	}
}