#include <iostream.h>
#include <dos.h>
#include <time.h>
#include <conio.h>

void mergesort(int a[], int i, int j);
void merge(int a[], int i1, int j1, int i2, int j2);

void main()
{
	int a[60], n, i;
	clock_t start, end;
	clrscr();
	cout << "\n Enter size of array : ";
	cin >> n;
	cout << "\n Enter elements of array : ";
	for (i = 0; i < n; i++)
		cin >> a[i];
	start = clock();
	mergesort(a, 0, n - 1);
	end = clock();
	cout << "\n Elements of sorted array is :";
	for (i = 0; i < n; i++)
		cout << " " << a[i];
	cout << "\n Start : " << start;
	cout << "\n End : " << end;
	cout << "\n CLK_TCK : " << CLK_TCK;
	cout << "\n END - START : " << end - start;
	cout << "\n The time is : " << (end - start) / CLK_TCK;
	getch();
}

void mergesort(int a[], int i, int j)
{
	int mid;
	if (i < j)
	{
		delay(100);
		mid = (i + j) / 2;
		mergesort(a, i, mid);
		mergesort(a, mid + 1, j);
		merge(a, i, mid, mid + 1, j);
	}
}

void merge(int a[], int i1, int j1, int i2, int j2)
{
	int temp[70], i = i1, j = i2, k = 0;
	while (i <= j1 && j <= j2)
	{
		delay(100);
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= j1)
	{
		temp[k++] = a[i++];
		delay(100);
	}
	while (j <= j2)
	{
		temp[k++] = a[j++];
		delay(100);
	}
	for (i = i1, j = 0; i <= j2; i++, j++)
	{
		a[i] = temp[j];
		delay(100);
	}
}
