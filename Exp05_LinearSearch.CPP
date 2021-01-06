#include <conio.h>
#include <time.h>
#include <iostream.h>
#include <dos.h>

int linear_search(int sea, int n, int pos, int i, int arr[]);

int main()
{
	int i, sea, pos, size, l = 0;
	int arr[50];
	clock_t start, end;
	clrscr();
	cout << "\n Enter size of array : ";
	cin >> size;
	cout << "\n Elements of array are : ";
	for (i = 0; i < size; i++)
		cin >> arr[i];
	cout << "\n Enter element to be searched : ";
	cin >> sea;
	start = clock();
	l = linear_search(sea, size, pos, i, arr);
	end = clock();
	if (l == 0)
		cout << "\n Element not found ";
	else
		cout << "\n Element found at position : " << l;
	cout << "\n End : " << end;
	cout << "\n CLK_TCK : " << CLK_TCK;
	cout << "\n END - START : " << end - start;
	cout << "\n The time is : " << (end - start) / CLK_TCK;
	getch();
	return 0;
}

int linear_search(int sea, int n, int pos, int i, int arr[])
{
	for (i = 0; i < n; i++)
	{
		delay(1000);
		if (arr[i] == sea)
		{
			pos = i + 1;
			break;
		}
	}
	return pos;
}