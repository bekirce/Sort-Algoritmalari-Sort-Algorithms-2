/*
	BUBBLE SORT ALG. 2 LI 2 LI G�DEREK TUM DIZIYE BAKAR. 
	HER �K�L� ADIMDA SWAP ISLEMI VARSA YAPILIR
	SWAP �SLEM� DEVAMLI YAPILARAK EN BUYUK DEGER EN SAGA ATILIR.
	SONRA EN BUYUK 2. DEGER SA�DAN 2. SIRAYA ATILIR...
	SONRA EN BUYUK 3. DEGER SA�DAN 3. SIRAYA ATILIR. VE B�YLE DEVAM EDER

	KARMASIKLIK N2
*/

#include <iostream>
#include <time.h>

using namespace std;

void swap(int *val1, int *val2);

void bubleSort(int *buf, int len_buf);
void bubleSort2(int buf[], int len_buf);

void printBuffer(int *buffer, int len);
void printBuffer2(int buffer[], int len);

int main()
{
	int buffer[100];
	int len_number;

	cout << "Sort elenan sayisini giriniz.. :";
	cin >> len_number; 	cout << endl;

	srand(time(0));

	//veriler buffer'a eklendi
	for (int i = 0; i < len_number; i++)
		buffer[i] = rand() % 100;

	cout << "Before sort algorithm : ";
	printBuffer(buffer, len_number); //Ekrana bas
	//printBuffer2(buffer, len_number);

	bubleSort(buffer, len_number);
	//bubleSort2(buffer, len_number);

	cout << endl << "After sort algorithm : ";
	printBuffer(buffer, len_number);
	//printBuffer2(buffer, len_number);

	getchar();
	getchar();
}

void bubleSort(int *buf, int len_buf) //burada direk buffer i�indeki deger ile okuma yap�l�r
{
	for (int counter1 = 0; counter1 < len_buf - 1; counter1++) //0 .. n-1
		for (int counter2 = 1; counter2 < len_buf - counter1; counter2++) //1... n-i; (i = 0 ... n-1-1)  //en son buffer dizisi 1 < 2 --> en son [0] dizi ve [1] dizi kars� last�r�l�r
			if (buf[counter2 - 1] > buf[counter2])
				swap(buf[counter2 - 1], buf[counter2]); //pointer ile cagr�ld��� i�in & kullanmad�m
}

void bubleSort2(int buf[], int len_buf) //burada buffer i�erisindeki adres ile okuma yap�l�r
{
	for (int counter1 = 0; counter1 < len_buf - 1; counter1++) //0 .. n-1
		for (int counter2 = 1; counter2 < len_buf - counter1; counter2++) //1... n-i; (i = 0 ... n-1-1)  //en son buffer dizisi 1 < 2 --> en son [0] dizi ve [1] dizi kars�last�r�l�r
			if (buf[counter2 - 1] > buf[counter2])
				swap(&buf[counter2 - 1], &buf[counter2]); //pointer ile �a�r�lmad��� i�in & kulland�m
}

void printBuffer(int *buffer, int len)
{
	for (int i = 0; i < len; i++)
		cout << *(buffer + i) << " "; 
		//cout << buffer[i] << " "; //buda olurdu
	cout << endl;
}

void printBuffer2(int buffer[], int len)
{
	for (int i = 0; i < len; i++)
		cout << buffer[i] << " ";
	cout << endl;
}

void swap(int *val1, int *val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
