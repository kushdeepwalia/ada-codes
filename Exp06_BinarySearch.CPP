#include <iostream.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <dos.h>

int binary_search(int arr[], int low, int high, int sea);

int main()
{
    int arr[50], size, i, sea;
    clock_t start, end;
    clrscr();
    cout << "\n Enter size of array : ";
	cin >> size;
    cout << "\n Enter elements of array : ";
	for (i = 0; i < size; i++)
        cin >> arr[i];
	cout << "\n Enter element to be searched : ";
    cin >> sea;
    start = clock();
    int isfound = binary_search(arr, 0, n - 1, sea);
    end = clock();
    cout << "\n Start : " << start;
    cout << "\n End : " << end;
    cout << "\n CLK_TCK : " << CLK_TCK;
    cout << "\n END - START : " << end - start;
    cout << "\n The time is : " << (end - start) / CLK_TCK;
    if (isfound == -1)
        cout << "\n Item Not Found";
    else
        cout << "\n Element found at position : " << isfound + 1;
    getch();
    return 0;
}

int binary_search(int arr[], int low, int high, int sea)
{
    delay(100);
    if (low == high)
    {
        if (arr[low] == sea)
            return low;
        else
            return -1;
    }
    else
    {
        int mid = low + (high - low) / 2;
        if (sea == arr[mid])
            return mid;
        else if (sea < arr[mid])
            return binary_search(arr, low, mid - 1, sea);
        else
            return binary_search(arr, mid + 1, high, sea);
    }
}