#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <time.h>
#define max 10

int main()
{
	clock_t start, end;
	int a[max];
	float p[max], c[max][max], r[max][max], sum, minval;
	int n, i, j, d, k, s;
	clrscr();
	cout << "\n Enter the length of array ";
	cin >> n;
	cout << "\n Enter the elements ";
	for (i = 1; i <= n; i++)
		cin >> a[i];
	cout << "\n Enter the probability ";
	for (i = 1; i <= n; i++)
		cin >> p[i];
	for (i = 1; i <= n + 1; i++)
		for (j = 0; j <= n; j++)
			c[i][j] = r[i][j] = 0;
	for (i = 1; i <= n; i++)
	{
		c[i][i] = p[i];
		r[i][i] = a[i];
	}
	for (i = 1; i <= n + 1; i++)
	{
		cout << "\n";
		for (j = 0; j <= n; j++)
			cout << c[i][j] << "\t";
	}
	for (i = 1; i <= n + 1; i++)
	{
		cout << "\n";
		for (j = 0; j <= n; j++)
		{
			cout << r[i][j] << "\t";
		}
	}
	start = clock();
	for (d = 1; d <= n - 1; d++)
	{
		for (i = 1; i <= n - d; i++)
		{
			j = i + d;
			minval = 3000;
			for (k = i; k <= j; k++)
			{
				delay(100);
				if ((c[i][k - 1] + c[k + 1][j]) < minval)
				{
					minval = (c[i][k - 1] + c[k + 1][j]);
					r[i][j] = k;
				}
			}
			sum = 0;
			for (s = i; s <= j; s++)
			{
				delay(100);
				sum = sum + p[s];
				c[i][j] = minval + sum;
			}
		}
	}
	end = clock();
	cout << "\n Answer : \n";
	for (i = 1; i <= n + 1; i++)
	{
		cout << "\n";
		for (j = 0; j <= n; j++)
		{
			cout << c[i][j] << "\t";
		}
	}
	for (i = 1; i <= n + 1; i++)
	{
		cout << "\n";
		for (j = 0; j <= n; j++)
		{
			cout << r[i][j] << "\t";
		}
	}
	cout << "\n Start : " << start;
	cout << "\n End : " << end;
	cout << "\n CLK_TCK : " << CLK_TCK;
	cout << "\n END - START : " << end - start;
	cout << "\n The time is : " << (end - start) / CLK_TCK;
	getch();
	return 0;
}
