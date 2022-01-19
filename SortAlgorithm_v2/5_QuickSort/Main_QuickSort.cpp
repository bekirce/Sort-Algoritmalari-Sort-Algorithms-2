#include <iostream>
#include <time.h>

using namespace std;

void swap(int *val1, int  *val2);
void printBuffer(int *buffer, int len);

void QuickSort(int *buf, int indis_left, int indis_right);
int Partition(int *buf, int indis_left, int indis_right);

int main()
{
	int Buffer[100];
	int len_buffer;

	cout << "Eleman sayisini giriniz.. : ";
	cin >> len_buffer;
	cout << endl;

	srand(time(NULL));

	for (int buf_counter = 0; buf_counter < len_buffer; buf_counter++)
		Buffer[buf_counter] = rand() % 100;

	cout << "Before Sort Algorithm.. : ";
	printBuffer(Buffer, len_buffer);

	QuickSort(Buffer, 0, len_buffer - 1);

	cout << endl << "After Sort Algorithm.. : ";
	printBuffer(Buffer, len_buffer);

	getchar();
	getchar();
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int Partition(int *buf, int indis_left, int indis_right)
{
	int pivot = buf[indis_right];
	int i = indis_left - 1;

	for (int j = 0; j < indis_right; j++)
	{
		if (buf[j] < pivot)
		{
			i++;
			swap(buf[i], buf[j]); //swap(&buf[i], &buf[j]);
		}
	}

	swap(buf[i + 1], buf[indis_right]); //swap(&buf[i + 1], &buf[indis_right]);
	return i + 1;
}

void QuickSort(int *buf, int indis_left, int indis_right)
{
	/* pi is partitioning index, arr[p] is now
at right place */
	int pivot = Partition(buf, indis_left, indis_right);

	QuickSort(buf, indis_left, pivot-1);
	QuickSort(buf, pivot+1, indis_right);
}


void printBuffer(int *buffer, int len)
{
	for (int i = 0; i < len; i++)
		cout << *(buffer + i) << " ";
	//cout << buffer[i] << " "; //buda olurdu
	cout << endl;
}

void swap(int *val1, int *val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
