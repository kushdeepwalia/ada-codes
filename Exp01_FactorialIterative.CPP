#include <conio.h>
#include <time.h>
#include <iostream.h>
#include <dos.h>
int main()
{
	int n, i;
	float fact = 1;
	clock_t start, end;
	clrscr();
	cout << "\n Enter a positive integer : ";
	cin >> n;
	start = clock();
	for (i = 1; i <= n; i++)
	{
		delay(1000);
		fact = fact * i;
	}
	end = clock();
	cout << "\n Factorial of " << n << " : " << fact;
	cout << "\n Start : " << start;
	cout << "\n End : " << end;
	cout << "\n CLK_TCK : " << CLK_TCK;
	cout << "\n END - START : " << end - start;
	cout << "\n Total Time: " << (end - start) / CLK_TCK;
	getch();
	return 0;
}
