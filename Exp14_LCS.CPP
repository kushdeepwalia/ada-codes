#include <iostream.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

int main()
{
	char x[10], y[10], z[10];
	int m, n, c[10][10], b[10][10], i, j, k;
	clock_t start, end;
	clrscr();
	cout << "\n Enter 1st string : ";
	gets(x);
	cout << "\n Enter 2nd string : ";
	gets(y);
	m = strlen(x);
	n = strlen(y);
	for (i = 0; i <= m; i++)
		c[i][0] = b[i][0] = 0;
	for (j = 0; j <= n; j++)
		c[0][j] = b[0][j] = 0;
	start = clock();
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = -1;
				delay(100);
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
				delay(100);
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 0;
				delay(100);
			}
	i = m, j = n, k = 0;
	while (i >= 0 && j >= 0)
	{
		delay(100);
		if (b[i][j] == -1)
		{
			i--;
			j--;
			z[k++] = x[i];
		}
		else if (b[i][j] == 1)
			i--;
		else
			j--;
	}
	end = clock();
	int len = k;
	cout << "\n Longest Common Sequence is : ";
	for (k = len - 1; k >= 0; k--)
		cout << z[k];
	cout << "\n Start : " << start;
	cout << "\n End : " << end;
	cout << "\n CLK_TCK : " << CLK_TCK;
	cout << "\n END - START : " << end - start;
	cout << "\n The time is : " << (end - start) / CLK_TCK;
	getch();
	return 0;
}
