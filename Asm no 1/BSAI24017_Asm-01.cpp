#include<iostream>
#include<fstream>
using namespace std;
#define capacity 100
// Initializing an array 
void Printanarray(int A[], int size,const char Msg[])
{
	cout << Msg << "{ ";
	for (int i = 0;i < size;i++)
	{
		cout << A[i] << " , ";
	}
	cout << "\b\b }";
}
void Randominitialization(int A[],int size,int s,int r)
{
	srand(time(0));
	for (int i = 0;i < size;i++)
	{
		A[i] = rand() % r + s;
	}
}
int main1()
{
	int s, r,size;
	cout << " Enter the range: ";
	cin >> s >> r;
	cout << " Enter the size : ";
	cin >> size;
	int A[capacity];
	Randominitialization(A, size,s,r);
	Printanarray(A, size," Random Initialized array is : ");
	return 0;
}
//Reading and writing in files
void Readfromfile(ifstream& rd, int A[], int& size)
{
	size = 0;
	if (!rd)
	{
		cout << "File not exist...";
		exit(1);
	}
	else
	{
		int a;
		rd >> a;
		for (int i = 0;a != -1;i++)
		{
			A[size++] = a;
			rd >> a;
		}
	}
}
int main2()
{
	int A[capacity],size=0;
	int choice;
	cout << " Choose an option: " << endl;
	cout << "1. Saved array " << endl;
	cout << "2.Read from New one" << endl;
	cin >> choice;
	if (choice == 1)
	{
		ifstream rd("Out.txt");
		Readfromfile(rd, A, size);
		Printanarray(A, size, "Saved Array : ");
	}
	else
	{
		ifstream Srd("Int.txt");
		Readfromfile(Srd, A, size);
		Printanarray(A, size, "Loaded Array : ");
	}
	ofstream wr("Out.txt");
	for (int i = 0;i < size;i++)
	{
		wr << A[i] << " ";
	}
	wr << -1;
	return 0;
}
//Part 2
//Question 1
int FirstOcurrance(int A[], int size, int n)
{
	for (int i = 0;i < size;i++)
	{
		if (A[i] == n)
			return i;
	}
}
int LastOcurrance(int A[], int size, int n)
{
	for (int i = size-1;i >=0;i--)
	{
		if (A[i] == n)
			return i;
	}
}
int KthOccurance(int A[], int size, int n,int k)
{
	int c = 0;
	for (int i = 0;i < size;i++)
	{
		if (A[i] == n)
		{
			c++;
			if (c == k)
				return i;
		}
	}
}
void AllOcurrance(int A[], int size, int B[], int &Bsize, int n)
{
	Bsize = 0;
	for (int i = 0;i < size;i++)
	{
		if (A[i] == n)
		{
			B[Bsize++] = i;
		}
	}
}
int main5()
{
	int A[] = { 1,5,8,7,5,9,8,9,5,7,9,5,7,6};
	int size = sizeof(A) / sizeof(int);
	Printanarray(A, size, " Array : ");
	int n;
	cout << " \nEnter the number which occurance you want to know: ";
	cin >> n;
	int f = FirstOcurrance(A, size, n);
	cout << "\n First Occurance: " << f << endl;
	int l = LastOcurrance(A, size, n);
	cout << " Last Occurance: " << l << endl;
	int k;
	cout << " Enter the value of k for kth Ocurrane : ";
	cin >> k;
	int j=KthOccurance(A, size, n, k);
	cout << "\n Kth Occurance is at index: " << j;
	int B[capacity]{}, Bsize = 0;
	cout << endl;
	AllOcurrance(A, size, B, Bsize, n);
	Printanarray(B, Bsize, "All Occurance Index: ");
	return 0;

}
//Question 2
int Binarysearch(int A[],int size,int n)
{
	int s=0, e=0;
	if (A[size / 2] == n)
		return size / 2;
	else if (A[size / 2] < n)
		s = (size / 2) + 1, e = size;
	else
		s = 0, e = size / 2;
	for (int i = s;i < e;i++)
	{
		if (A[i] == n)
			return i;
	}
}
int mainb2()
{
	int A[] = { 1,5,6,7,8,9 };
	int size = sizeof(A) / sizeof(int);
	Printanarray(A, size, " Array : ");
	int n;
	cout << " \nEnter the searching number ";
	cin >> n;
	int k = Binarysearch(A, size, n);
	cout << " Number is on index: "<<k;
	return 0;
}
int BinarysearchOccurance(int A[], int size, int n)
{
	int s = 0, e = 0,c=0;
	if (A[size / 2] == n)
	{
		for (int i = 0;i < size;i++)
		{
			if (A[i] == n)
			{
				s = i;
				e = size;
				break;
			}
		}
	}
	else if (A[size / 2] < n)
		s = (size / 2) + 1, e = size;
	else
		s = 0, e = size / 2;
	for (int i = s;i < e;i++)
	{
		if (A[i] == n)
			c++;
	}
	return c;
}
int mainb3()
{
	int A[] = { 1,5,6,6,6,7,7,7,8,8,9 };
	int size = sizeof(A) / sizeof(int);
	Printanarray(A, size, " Array : ");
	int n;
	cout << " \nEnter the searching number ";
	cin >> n;
	int k = BinarysearchOccurance(A, size, n);
	cout << " Number Occurance in Sorted array : " << k;
	return 0;
}
//Question 3
bool Prime(int n)
{
	if (n == 2)
		return true;
	if (n % 2 == 0 or n<2)
		return false;
	for (int i = 3;i * i <= n;i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
void Leftshifting(int A[], int start, int end)
{
	int temp = A[end-1];
	for (int i = start;i < end;i++)
	{
		swap(A[i], temp);
	}
	A[end] = temp;
}
void SegregationOV(int A[], int size)
{
	int ei = 0, oi = size - 1;
	while (ei < oi)
	{
		while (ei < oi and A[ei] % 2 == 0)
			ei++;
		while (ei < oi and A[oi] % 2 == 1)
			oi--;
		if (ei < oi)
			Leftshifting(A,ei,oi);
	}
}
void SegregationOZ(int A[], int size)
{
	int ei = 0, oi = size - 1;
	while (ei < oi)
	{
		while (ei < oi and A[ei] == 0)
			ei++;
		while (ei < oi and A[oi] == 1)
			oi--;
		if (ei < oi)
			Leftshifting(A, ei, oi);
	}
}
void SegregationPC(int A[], int size)
{
	int ei = 0, oi = size - 1;
	while (ei < oi)
	{
		while (ei < oi and Prime(A[ei]))
			ei++;
		while (ei < oi and !Prime(A[oi]))
			oi--;
		if (ei < oi)
			Leftshifting(A, ei, oi);
	}
}
int mainS()
{
	int A[] = { 1,5,6,6,6,7,7,7,8,8,9 };
	int size = sizeof(A) / sizeof(int);
	Printanarray(A, size, " Loaded  Array    : ");
	SegregationOV(A, size);
	cout << "\nOdd and Even segregator" << endl;
	Printanarray(A, size, "Segregtaed Array : ");
	int Z[] = {0,1,0,1,1,1,0,0,1,0,1,0};
	int Zsize = sizeof(Z) / sizeof(int);
	Printanarray(Z, Zsize, "\n\n Loaded  Array    : ");
	SegregationOZ(Z, Zsize);
	cout << "\nZeros and Ones segregator" << endl;
	Printanarray(Z, Zsize, "Segregtaed Array : ");
	int P[] = { 1,5,8,2,4,9,6,7,10,7 };
	int Psize = sizeof(P) / sizeof(int);
	Printanarray(P, Psize, "\n\n Loaded  Array    : ");
	SegregationPC(P, Psize);
	cout << "\nPrimes and Compodite Number segregator" << endl;
	Printanarray(P, Psize, "Segregtaed Array : ");
	return 0;
}
//Part 3 Sorters 
void arrayfromcin(int A[], int& size, int n)
{
	size = 0;
	for (int i = 0;n != -1;i++)
	{
		A[i] = n;
		cin >> n;
		size++;
	}
}
//Bubblesort
bool Ascbubblesort(int A[], int size, int st)
{
	int t = 1;
	bool repeat;
	do
	{
		repeat = false;
		for (int i = st;i + 1 <= size - t;i++)
		{
			if (A[i] > A[i + 1])
				swap(A[i], A[i + 1]),
				repeat = true;
		}
		t++;
	} while (repeat);
	return repeat;
}
bool Desbubblesort(int A[], int size, int st)
{
	int t = 1;
	bool repeat;
	do
	{
		repeat = false;
		for (int i = st;i + 1 <= size - t;i++)
		{
			if (A[i] < A[i + 1])
				swap(A[i], A[i + 1]),
				repeat = true;
		}
		t++;
	} while (repeat);
	return repeat;
}
int mainBs()
{
	int A[capacity];
	cout << "Enter the array ending on -1: ";
	int n, size;
	cin >> n;
	arrayfromcin(A, size, n);
	Printanarray(A, size,"Given Array : ");
	Ascbubblesort(A, size, 0);
	Printanarray(A, size, "\nAss Sorted Array : ");
	Desbubblesort(A, size, 0);
	Printanarray(A, size, "\nDes Sorted Array : ");
	return 0;
}
//Selectionsort
bool selectionsortasc(int A[], int size)
{
	bool CO = false;
	do
	{
		for (int i = 0;i < size;i++)
		{
			int min = i;
			CO = false;
			for (int j = i + 1;j < size;j++)
			{
				if (A[j] < A[min])
					min = j,
					CO = true;
			}
			swap(A[i], A[min]);
		}
	} while (CO);
	return CO;
}
bool selectionsortdes(int A[], int size)
{
	bool CO = false;
	do
	{
		for (int i = 0;i < size;i++)
		{
			int max = i;
			CO = false;
			for (int j = i + 1;j < size;j++)
			{
				if (A[j] > A[max])
					max = j,
					CO = true;
			}
			swap(A[max], A[i]);
		}
	} while (CO);
	return CO;
}
int mainSS()
{
	int A[capacity];
	cout << "Enter the array ending on -1: ";
	int n, size;
	cin >> n;
	arrayfromcin(A, size, n);
	Printanarray(A, size, "Given Array : ");
	selectionsortasc(A, size);
	Printanarray(A, size, "\nAss Sorted Array : ");
	selectionsortdes(A, size);
	Printanarray(A, size, "\nDes Sorted Array : ");
	return 0;
}
//Insertion sort
void insertsortasc(int A[], int size, int n)
{
	for (int j = 0;j < size - 1;j++)
	{
		if (A[j] > n)
			swap(A[j], A[size - 1]);

	}

}
void insertsortdes(int N[], int Nsize, int n)
{
	for (int j = 0;j < Nsize - 1;j++)
	{
		if (N[j] < n)
			swap(N[j], N[Nsize - 1]);

	}
}
void insertionsortingascdes(int A[], int& size)
{
	int Nsize = 0;
	int n, N[capacity];
	cin >> n;
	A[size++] = n;
	N[Nsize++] = n;
	for (int i = 1;n != -1;i++)
	{
		cin >> n;
		if (n == -1)
			break;
		A[size++] = n;
		N[Nsize++] = n;
		insertsortasc(A, size, n);
		insertsortdes(N, Nsize, n);
	}
	Printanarray(A, size, "Ascending array : ");
	cout  << endl;
	Printanarray(N, Nsize, "Desending array : ");
}
int maininsert()
{
	int A[capacity], size = 0;
	cout << "Enter the array ending on -1: ";
	insertionsortingascdes(A, size);
	return 0;
}
// Part 3 section b
bool bubblesortinRange(int A[], int size, int st,int end)
{
	int t = 1;
	bool repeat;
	do
	{
		repeat = false;
		for (int i = st;i + 1 <= end - t;i++)
		{
			if (A[i] > A[i + 1])
				swap(A[i], A[i + 1]),
				repeat = true;
		}
		t++;
	} while (repeat);
	return repeat;
}
int mainv()
{
	int A[capacity];
	cout << "Enter the array ending on -1: ";
	int n, size;
	cin >> n;
	arrayfromcin(A, size, n);
	cout << "Enter the range for sorting : ";
	int st, end;
	cin >> st >> end;
	Printanarray(A, size, "Given Array : ");
	bubblesortinRange(A, size, st,end);
	Printanarray(A, size, "\nAss Sorted Array in given range: ");
	return 0;
}
//Part3 Question no 2
int freqcount(int A[], int size, int n)
{
	int c = 0;
	for (int i = 0;i < size;i++)
	{
		if (A[i] == n)
			c++;
	}
	return c;
}
int mean(int A[], int size)
{
	int sum = 0;
	for (int i = 0;i < size;i++)
	{
		sum += A[i];
	}
	return sum / size;
}
int mode(int A[], int size)
{
	int max = -1;
	for (int i = 0;i < size;i++)
	{
		if (freqcount(A, size, A[i]) > max)
			max = freqcount(A, size, A[i]);
	}
	return max;
}
int median(int A[], int size)
{
	Ascbubblesort(A, size, 0);
	if (size % 2 == 1)
	{
		return A[size / 2];
	}
	else
	{
		return ((A[size/2])+A[(size/2)-1]) / 2;
	}

}
int mainmmm()
{
	int A[capacity];
	cout << "Enter the array ending on -1: ";
	int n, size;
	cin >> n;
	arrayfromcin(A, size, n);
	int m=mean(A, size);
	cout << " Mean of the array is : "<<m <<endl;
	int mo=mode(A, size);
	cout << " Mode of the array is : " << mo << endl;
	int me = median(A, size);
	cout << " Median of the array is : " << me << endl;
	return 0;
}
// Part 3 Question no 3
void UniqueElements(int A[], int size, int D[], int &Dsize)
{
	Dsize = 0;
	for (int i = 0;i < size;i++)
	{
		if (freqcount(A, size, A[i]) == 1)
			D[Dsize++] = A[i];
	}
}
void DistinctElements(int A[], int size,int D[],int &Dsize)
{
	Dsize = 0;
	D[Dsize++] = A[0];
	for (int i = 1;i < size;i++)
	{
		if (freqcount(D, Dsize, A[i]) == 0)
			D[Dsize++] = A[i];
	}
}
int maindu()
{
	int A[capacity];
	cout << "Enter the array ending on -1: ";
	int n, size;
	cin >> n;
	arrayfromcin(A, size, n);
	Printanarray(A, size, "Given Array : ");
	int U[capacity], Usize = 0;
	UniqueElements(A, size, U, Usize);
	cout << endl;
	Printanarray(U, Usize, "Unique element Array : ");
	int D[capacity], Dsize = 0;
	DistinctElements(A, size, D, Dsize);
	cout << endl;
	Printanarray(D, Dsize, "Distinct element Array : ");
	return 0;
}
//Part 3 Question no 2 section b
void Freqsorter(int A[], int size,int F[],int &Fsize)
{
	int D[capacity], Dsize = 0;
	DistinctElements(A, size, D, Dsize);
	int U[capacity]{}, Usize = 0;
	for (int i = 0;i < Dsize;i++)
	{
		U[Usize++] = freqcount(A, size, D[i]);
	}
	selectionsortdes(U, Usize);
	int j;
	Fsize = 0;
	for (int i = 0;i < Usize;i++)
	{
		for ( j = 0;j < Dsize;j++)
		{
			if (freqcount(A, size, D[j]) == U[i])
			{
				F[Fsize++] = D[j];
				swap(D[j], D[Dsize - 1]);
				Dsize--;
			}

		}
	}
}
int main()
{
	int A[capacity];
	cout << "Enter the array ending on -1: ";
	int n, size;
	cin >> n;
	arrayfromcin(A, size, n);
	Printanarray(A, size, " Given Array : ");
	int U[capacity], Usize = 0;
	Freqsorter(A, size, U, Usize);
	Printanarray(U, Usize, "\nFreq Sort Array : ");
	return 0;
}


