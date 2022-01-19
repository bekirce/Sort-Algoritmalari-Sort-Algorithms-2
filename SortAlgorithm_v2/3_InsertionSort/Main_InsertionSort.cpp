/*
	D�Z�N�N/ L�STEN�N 0. ELEMANINDAN DE��L 1. ELEMANINDAN BAKMAYA BASLANIR
	ARAMAYA BA�LAMADAN ONCE KAR�ILA�TIRMA YAPILACAK DE�ER B�R DE���KENE ATANIR
	ATANAN DE���KENDEN DAHA B�Y�K B�R DE�ER OLUP OLMADI�I KONTROL ED�L�R
	EGER DE���KEN�N DE�ER�NDEN DAHA B�Y�K B�R DE�ER �LE KAR�ILA�ILIRSA
	B�Y�K DE�ER B�R B�R�M SA�A KAYDIRILIR. VE �ND�S 1 AZALTILIR VE BU ��LEMLER TEKRARLANIR
	B�T�N DE�ERLER KONTROL ED�LD�KTEN SONRA AZALTILMIS OLAN SON INDISE DE���KEN DE�ER� EKLEN�R
*/
#include <iostream>
#include <time.h>

using namespace std;

void swap(int *val1, int  *val2);
void printBuffer(int *buffer, int len);

void InsertionSort(int *buf, int len_buf);
void InsertionSort2(int arr[], int n);

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

	InsertionSort(Buffer, len_buffer);

	cout << endl << "After Sort Algorithm.. : ";
	printBuffer(Buffer, len_buffer);

	getchar();
	getchar();
}

void InsertionSort(int *buf, int len_buf)
{
	int counter1, counter2, value;
	for (counter1 = 1; counter1 < len_buf; counter1++)
	{
		value = buf[counter1];
		counter2 = counter1 - 1;

		while (counter2 >= 0 && buf[counter2] > value)
		{
			buf[counter2 + 1] = buf[counter2];
			counter2 = counter2 - 1;
		}
		buf[counter2+1] = value;
	}
}

void InsertionSort2(int arr[], int n)
{
	int i, deger, j;
	for (i = 1; i < n; i++) //ilk secilen/bak�lan dizideki [1].dizi degeridir.
	{
		deger = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > deger) //bak�lan degerin solunda bir dizi degeri var m�? ve o dizi s�ras�ndaki deger bak�lan degerden b�y�k m�? evet ise, bak�lan deger sola kayd�r�l�r
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = deger;
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