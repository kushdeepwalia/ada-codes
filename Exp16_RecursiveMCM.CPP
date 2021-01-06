#include <iostream.h>
#include <malloc.h>
#include <limits.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

void printParenthesis(int i, int j, int n, char &name, int *C);
int rec_chain_mul(int *p, int i, int j, int n, int *M, int *C);

int main()
{
	int p[20], i, j, *M, *C, n;
	clock_t start, end;
	clrscr();
	cout << "\n Enter Size : ";
	cin >> n;
	cout << "\n Enter Array " << n + 1 << " : ";
	for (i = 0; i <= n; i++)
		cin >> p[i];
	M = (int *)malloc(n * n * sizeof(int));
	C = (int *)malloc(n * n * sizeof(int));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			*(M + i * n + j) = 0;
			*(C + i * n + j) = 0;
		}
	start = clock();
	for (int d = 1; d < n; d++)
		for (i = 0; i < n - d; i++)
		{
			int j = i + d;
			*(M + i * n + j) = rec_chain_mul(p, i, j, n, M, C);
		}
	for (int x = 0; x < n; x++)
	{
		cout << endl;
		for (int y = 0; y < n; y++)
			cout << *(M + x * n + y) << "\t";
	}
	char name = 'A';
	printParenthesis(0, n - 1, n, name, C);
	end = clock();
	cout << "\n End:" << end;
	cout << "\n CLK_TCK:" << CLK_TCK;
	cout << "\n End-start:" << (end - start);
	cout << "\n The time is:" << (end - start) / CLK_TCK;
	getch();
	return 0;
}

int rec_chain_mul(int *p, int i, int j, int n, int *M, int *C)
{
	if (i == j)
		return 0;
	*(M + i * n + j) = INT_MAX;
	for (int k = i; k < j; k++)
	{
		int q = rec_chain_mul(p, i, k, M, C) + rec_chain_mul(p, k + 1, j, M, C) + p[i] * p[k + 1] * p[j + 1];
		if (q < *(M + i * n + j))
		{
			delay(100);
			*(M + i * n + j) = q;
			*(C + i * n + j) = k;
		}
	}
	return *(M + i * n + j);
}

void printParenthesis(int i, int j, int n, char &name, int *C)
{
	delay(100);
	if (i == j)
	{
		cout << name++;
		return;
	}
	else
	{
		cout << "(";
		printParenthesis(i, *(C + i * n + j), n, name, C);
		printParenthesis(*(C + i * n + j) + 1, j, n, name, C);
		cout << ")";
	}
}