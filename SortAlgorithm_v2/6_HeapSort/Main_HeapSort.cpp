/*
	EN IYI ALGOR�TMALARDAN B�R�D�R.
	LEFT : 2*�
	RIGHT : 2*I+1
	PARRENT : �/2

	SOL SAG VE UST (LARGEST) DUGUMLERDEN OLUSMAKTA. 
	EN TEPE DE K� [0]. 
	EN TEPEDEK� INDIS EN KUCUK DEGERE SAH�P OLACAK 

	BU ALGORT�TMA �LK OLARAK HEAP OLU�TURUR. BU HEAP ��ER�S�NDE DEGERLER RASTGELE DAGILMISTIR
	BU HEAP YAPILIRKEN SIRASIYLA 8. 7. 6. 5. 4. 3. 2. 1. 0. INDIS DEGERLER�  HEAP E KOYULMUSTUR
	
	hEAP OLUSTURULDUKTAN SONRA (HEAP ��ER�S�NDEN EXTRACT YAPILARAK VER�LER SIRALANIR)
	EN A�A�IDAN [8]. INDISTEN �T�BAREN, EN YUKSEK DEGER EN ALTTA OLUCAK �EK�LDE,
	7. 6. 5. ...0. INDISE KADAR YUKARI DOGRU CIKARKEN SWAP ��LEMLER� GERCEKLE�T�R�L�R

	BOYLECE EN YUKARIDA EN KUCUK EN A�A�IDA EN B�Y�K DEGERLER OLACAK SEK�LDE SIRALANMA YAPILMIS OLUR

	EXTRA:

	MAX VE MIN DEGER VARDIR
	MAX KUCULUR M�N BUYUR

	EKLEME VE SILME �SLEMLERI YAPILIR
	EKLENEN B�R UST DUGUMDEN KUCUK ISE SWAP YAPILIR B�R UST DUGUME GECER VE BU SEK�LDE DEAVM EDER
	SILME ISLEMINDE EN TEPE DUGUMDEK� DEGER S�L�N�R

	KARMASIKLIK N.LOGN D�R.
	*/

#include <iostream>
#include <time.h>

using namespace std;

void swap(int *val1, int  *val2);
void printBuffer(int *buffer, int len);

void HeapSort(int *buf, int len_buf);

void heapify(int *arr, int n, int i);

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

	HeapSort(Buffer, len_buffer);

	cout << endl << "After Sort Algorithm.. : ";
	printBuffer(Buffer, len_buffer);

	getchar();
	getchar();
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

void heapify(int *arr, int n, int i) //void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

void HeapSort(int *buf, int len_buf)
{
	// Build heap (rearrange array)
	for (int i = len_buf / 2 - 1; i >= 0; i--)
		heapify(buf, len_buf, i);

	// One by one extract an element from heap
	for (int i = len_buf - 1; i > 0; i--) {
		// Move current root to end
		swap(buf[0], buf[i]);

		// call max heapify on the reduced heap
		heapify(buf, i, 0);
	}
}

