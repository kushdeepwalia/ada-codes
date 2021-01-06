#include <conio.h>
#include <time.h>
#include <iostream.h>
#include <dos.h>

void fib(int num);

int main()
{
	int num;
	clock_t start, end;
	clrscr();
	cout << "\n Enter a number : ";
	cin >> num;
	cout << "\n The fibonacci series :";
	start = clock();
	fib(num);
	end = clock();
	cout << "\n End : " << end;
	cout << "\n CLK_TCK : " << CLK_TCK;
	cout << "\n END - START : " << end - start;
	cout << "\n The time is : " << (end - start) / CLK_TCK;
	getch();
	return 0;
}

void fib(int num)
{
	int x = 0, y = 1, z = 0;
	for (int i = 0; i < num; i++)
	{
		cout << " " << x;
		z = x + y;
		x = y;
		y = z;
		delay(1000);
	}
}