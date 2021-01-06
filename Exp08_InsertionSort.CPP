#include <conio.h>
#include <time.h>
#include <iostream.h>
#include <dos.h>

void insertion_sort(int arr[], int n);

int main()
{
	int i, n, arr[50];
	clock_t start, end;
	clrscr();
	cout << "\n Enter size of array : ";
	cin >> n;
	cout << "\n Elements of array are : ";
	for (i = 0; i < n; i++)
		cin >> arr[i];
	start = clock();
	insertion_sort(arr, n);
	end = clock();
	cout << "\n Elements of sorted array are :";
	for (i = 0; i < n; i++)
		cout << " " << arr[i];
	cout << "\n Start : " << start;
	cout << "\n End : " << end;
	cout << "\n CLK_TCK : " << CLK_TCK;
	cout << "\n END - START : " << end - start;
	cout << "\n Total time : " << (end - start) / CLK_TCK;
	getch();
	return 0;
}

void insertion_sort(int arr[], int n)
{
	int temp, i, j, k;
	for (i = 0; i < n; i++)
	{
		temp = arr[i];
		j = i - 1;
		while ((temp < arr[j]) && (j >= 0))
		{
			delay(1000);
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}