/*
	ONCE BUFFER LEFT VE RÝGHT OLMAK ÜZERE ÝKÝYE AYRILIR
	RECURSÝVE FONKSÝYONU YARDIMIYLA, LEFT VE RÝGHT BUFFER KENDÝ ÝÇERÝSÝNDE SÜREKLÝ OLARAK LEFT VE RÝGHT OLARAK ÝKÝYE BÖLÜNÜR
	CALISMA SIRASIYLA 
	ÝLK OLARAK LEFT BUFFER ÝÇÝN 0. VE 1. ÝNDÝS BAKILIR. KARSILASTIRMA YAPILIR GEREKÝYORSA SWAP ÝÞLEMÝ YAPILIR
	2. VE 3. ÝNDÝS E BAKILIR. AYNI ÝÞLEM YÝNE YAPILIR
	0. 1. VE 2. 3. INDIS ÝÇÝN AYNI ÝÞLEM YAPILIR.
	BU  ÝÞLEMLER RÝGTH BUFFER ÝÇÝNDE YAPILIR
	SON OLARAK SIRALI LEFT VE SIRALI RÝGHT BUFFER KENDÝ ARALARINDA KARSILASTIRMA GEREKÝRSE SWAP ÝÞLEMÝ YAPILIR

	KARMASIKLIK N.LOGN DÝR.
	*/

#include <iostream>
#include <time.h>

using namespace std;

void swap(int *val1, int  *val2);
void printBuffer(int *buffer, int len);

void MergeSort(int *buf, int indis_left, int indis_right);
void Merge_Sort(int *buf, int indis_left, int indis_med, int indis_right);

int main()
{
	int Buffer[100];
	int len_buffer;
	int len_left, len_right;

	cout << "Eleman sayisini giriniz.. : ";
	cin >> len_buffer;
	cout << endl;

	srand(time(NULL));

	for (int buf_counter = 0; buf_counter < len_buffer; buf_counter++)
		Buffer[buf_counter] = rand() % 100;

	cout << "Before Sort Algorithm.. : ";
	printBuffer(Buffer, len_buffer);

	MergeSort(Buffer, 0, len_buffer-1);

	cout << endl << "After Sort Algorithm.. : ";
	printBuffer(Buffer, len_buffer);

	getchar();
	getchar();
}

void MergeSort(int *buf, int indis_left, int indis_right)
{
	if (indis_left < indis_right)
	{
		int indis_med = indis_left + (indis_right - indis_left) / 2;

		MergeSort(buf, indis_left, indis_med);
		MergeSort(buf, indis_med + 1, indis_right);

		Merge_Sort(buf, indis_left, indis_med, indis_right);
	}
}

void Merge_Sort(int *buf, int indis_left, int indis_med, int indis_right)
{
	int temp_left_indis, temp_right_indis, all_indis;
	int len_left = indis_med - indis_left + 1;
	int len_right = indis_right - indis_med;

	/* Create temp arrays */
	int left_buffer[100];
	int right_buffer[100];


	/* Copy data to temp arrays */
	for (temp_left_indis = 0; temp_left_indis < len_left; temp_left_indis++)
		left_buffer[temp_left_indis] = buf[temp_left_indis+ indis_left];
	for (temp_right_indis = 0; temp_right_indis < len_right; temp_right_indis++)
		right_buffer[temp_right_indis] = buf[indis_med + 1 + temp_right_indis];


	temp_left_indis = 0;
	temp_right_indis = 0;
	all_indis = indis_left;


	while (temp_left_indis < len_left && temp_right_indis < len_right)
	{
		if (left_buffer[temp_left_indis] < right_buffer[temp_right_indis])
		{
			buf[all_indis] = left_buffer[temp_left_indis];
			temp_left_indis++;
		}

		else {
			buf[all_indis] = right_buffer[temp_right_indis];
			temp_right_indis++;
		}
		all_indis++;
	}

	while (temp_left_indis < len_left)
	{
		buf[all_indis] = left_buffer[temp_left_indis];
		temp_left_indis++;
		all_indis++;
	}

	while (temp_right_indis<len_right)
	{
		buf[all_indis] = right_buffer[temp_right_indis];
		temp_right_indis++;
		all_indis++;
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