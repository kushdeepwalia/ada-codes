#include <iostream.h>
#include <limits.h>
#include <conio.h>
#include <dos.h>
#include <time.h>

int m[10][10], bracket[10][10];

void mcm_memoized(int p[], int n);
int lookupchain(int p[], int i, int j);
void printParenthesis(int i, int j, int n, char &name);

int main()
{
	int p[10],i, j, q, n;
	clock_t start, end;
	clrscr();
	cout << "\n Enter Size : ";
	cin >> n;
	cout << "\n Enter Array " << n + 1 << " : ";
	for (i = 0; i <= n; i++)
		cin >> p[i];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			m[i][j] = INT_MAX;
			bracket[i][j] = 0;
		}
	start = clock();
	mcm_memoized(p, n);
	end = clock();
	for (i = 0; i < n; i++)
	{
		cout << endl;
		for (j = 0; j < n; j++)
			if (m[i][j] == INT_MAX)
				cout << "0" << "\t";
			else
				cout << m[i][j] << "\t";
	}
	for (i = 0; i < n; i++)
	{
		cout << endl;
		for (j = 0; j < n; j++)
			if (i < j)
				cout << bracket[i][j] + 1 << "\t";
			else
				cout << bracket[i][j] << "\t";
	}
	char name = 'A';
	printParenthesis(0, n - 1, n, name);
	cout << "\n End:" << end;
	cout << "\n CLK_TCK:" << CLK_TCK;
	cout << "\n End-start:" << (end - start);
	cout << "\n The time is:" << (end - start) / CLK_TCK;
	getch();
	return 0;
}

void printParenthesis(int i, int j, int n, char &name)
{
	if (i == j)
	{
		cout << name++;
		return;
	}
	else
	{
		cout << "(";
		printParenthesis(i, bracket[i][j], n, name);
		printParenthesis(bracket[i][j] + 1, j, n, name);
		cout << ")";
	}
}

void mcm_memoized(int p[], int n)
{
	for (int d = 1; d < n; d++)
	{
		for (int i = 0; i < n - d; i++)
		{
			delay(100);
			int j = i + d;
			m[i][j] = lookupchain(p, i, j);
		}
	}
}

int lookupchain(int p[], int i, int j)
{
	int q;
	if (m[i][j] < INT_MAX)
		return m[i][j];
	else if (i == j)
		return 0;
	else
	{
		for (int k = i; k < j; k++)
		{
			delay(100);
			q = lookupchain(p, i, k) + lookupchain(p, k + 1, j) + (p[i] * p[k + 1] * p[j + 1]);
			if (q < m[i][j])
			{
				delay(100);
				m[i][j] = q;
				bracket[i][j] = k;
			}
		}
		return m[i][j];
	}
}
