/*
	AVANTAJI RADÝX SORT ÝLE N2 OLAN KARMASIKLIGI N.LOGN E INDIRIR.
	ANCAK RADIX DE PEK KULLANILMAZ.

	ICI BOS BÝR DIZI TANIMLANIR. BU DIZIDE HER DEGERDEN KAC ADET DEGER VAR ONUN BÝLGÝSÝ GÝRÝLÝR. 1 0 0 2 .. COUNT 
	IKINCI BÝR DIZI TANIMLANIR. BU DÝZÝ DE SIRALI SEKÝKDE INDIS ATANIR. 0. 1. 2. 3... 

	0. INDISTEN BASLAYARAK ÝLK BUFFERDAN ALINAN DEGERELR OUTPUT ÝÇERÝSÝNE COUNT SIRASINA GÖRE YERLEÞTÝRÝLÝR
	OUTPUT A SIRALI YERLEÞMÝÞ DEGERLER ÝLK BUFFERA SIRASIYLA ÝLETÝLÝR.
*/
#include <iostream>
#include <time.h>

#define Length 100

using namespace std;

void swap(int *val1, int  *val2);
void printBuffer(int *buffer, int len);

void CountingSort(int *buf, int len_buf);


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

	CountingSort(Buffer, len_buffer);

	cout << endl << "After Sort Algorithm.. : ";
	printBuffer(Buffer, len_buffer);

	getchar();
	getchar();
}

void CountingSort(int *buf, int len_buf)
{
	int output[Length];

	// Find the largest element of the array
	int max = buf[0];
	for (int i = 1; i < len_buf; i++) {
		if (buf[i] > max)
			max = buf[i];
	}

	// The size of count must be at least (max+1) but
	// we cannot declare it as int count(max+1) in C as
	// it does not support dynamic memory allocation.
	// So, its size is provided statically.
	int count[Length];

	// Initialize count array with all zeros.
	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}

	// Store the count of each element
	for (int i = 0; i < len_buf; i++) {
		count[buf[i]]++;
	}

	// Store the cummulative count of each array
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	// Find the index of each element of the original array in count array, and
	// place the elements in output array
	for (int i = len_buf - 1; i >= 0; i--) {
		output[count[buf[i]] - 1] = buf[i];
		count[buf[i]]--;
	}

	// Copy the sorted elements into original array
	for (int i = 0; i < len_buf; i++) {
		buf[i] = output[i];
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