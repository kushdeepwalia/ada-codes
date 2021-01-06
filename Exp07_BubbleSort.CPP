#include <conio.h>
#include <time.h>
#include <iostream.h>
#include <dos.h>

void bubble_sort(int arr[], int n);

int main()
{
	int i, n, arr[50];
	clock_t start, end;
	clrscr();
	cout << "\n Enter size of array : ";
	cin >> n;
	cout << "\n Enter elements of array : ";
	for (i = 0; i < n; i++)
		cin >> arr[i];
	start = clock();
	bubble_sort(arr, n);
	end = clock();
	cout << "\n Elements of sorted array are :";
	for (i = 0; i < n; i++)
		cout << " " << arr[i];
	cout << "\n Start : " << start;
	cout << "\n End : " << end;
	cout << "\n CLK_TCK : " << CLK_TCK;
	cout << "\n END - START : " << (end - start);
	cout << "\n Total time : " << (end - start) / CLK_TCK;
	getch();
	return 0;
}

void bubble_sort(int arr[], int n)
{
	int temp, i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			delay(100);
			if (arr[j] > arr[j + 1])
			{
				delay(100);
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}