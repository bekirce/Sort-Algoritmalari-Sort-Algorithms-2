/*
	LÝSTENIN TAMAMINDAN GEÇEREK EN KÜÇÜK OLAN DEÐERÝ BULUR.
	BU DEÐERÝ ÝLK SIRAYA KOYAR.
	LÝSTENÝN EN KÜÇÜK 2. DEÐERÝNÝ BULUR VE LÝSTTENÝN 2. SIRASINA KOYAR
	LÝSTENÝN EN KÜÇÜK 3. DEÐERÝNÝ BULUR VE LÝSTENÝN 3. SIRASINA KOYAR
	BÖYLECE SORT ÝÞLEMÝ TAMAMLANIR

	KARMAÞIKLIK N2 DÝR. EN YAVAÞ ALGORÝTMADIR
*/

#include <iostream>
#include <time.h>

using namespace std;

void swap(int *val1, int  *val2);
void printBuffer(int *buffer, int len);

void SelectionSort(int *buf, int len_buf);
void SelectionSort2(int buf[], int len_buf);

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

	SelectionSort2(Buffer, len_buffer);

	cout << endl << "After Sort Algorithm.. : ";
	printBuffer(Buffer, len_buffer);

	getchar();
	getchar();
}

void SelectionSort(int *buf, int len_buf)
{
	int min; int counter1; int counter2;
	// One by one move boundary of unsorted subarray
	for (counter1 = 0; counter1 < len_buf - 1; counter1++)
	{
		// Find the minimum element in unsorted array
		min = counter1;
		for (counter2 = counter1 + 1; counter2 < len_buf; counter2++)
		{
			if (buf[counter2] < buf[min])
				min = counter2;
		}
		// Swap the found minimum element with the first element
		swap(buf[min], buf[counter1]);
	}
}

void SelectionSort2(int buf[], int len_buf)
{
	int min; int counter1; int counter2;
	for (counter1 = 0; counter1 < len_buf - 1; counter1++)
	{
		min = counter1;
		for (counter2 = counter1 + 1; counter2 < len_buf; counter2++)
		{
			if (buf[counter2] < buf[min])
				min = counter2;
		}
		swap(&buf[min], &buf[counter1]);
		//swap(buf[min], buf[counter1]);//BU DA OLURDU
	}
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