#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>
#include<fstream>
#include<string>
#include <vector>
#include <iterator>

using namespace std;

class mass {
public:
	string author;
	string nameauthor;
	string bookname;
	int year;
	int page;

	bool operator < (mass a)
	{
		return page < a.page;
	}

	bool operator > (mass a)
	{
		return page > a.page;
	}

	bool operator <= (mass a)
	{
		return page <= a.page;
	}

	bool operator  >= (mass a)
	{
		return page >= a.page;
	}

	bool operator == (mass a)
	{
		return page == a.page;
	}

	bool operator  != (mass a)
	{
		return page != a.page;
	}
};

template <typename T>
vector<T> selection(vector<T> ar, int*analyze);
template<typename T>
vector<T> cocktailsort(vector<T> vector, int*analyze);
template<typename T>
vector<T> quick_sort(vector<T> vector, int first, int last, int*analyze);
template <typename T>
vector<T> heapSort(vector<T> numbers, int array_size, int*analyze);
template<typename T>
vector<T> shellSort(vector<T> a, long size, int*analyze);


int main() {
	setlocale(LC_ALL, "Russian");
	FILE* ffout = fopen("fout.csv", "w");
	cout << "Введите тип данных \n1 - массив записей\n2 - массив чисел " << endl;
	int s; cin >> s;
	cout << " Введите тип сортировки\n1 - Шейкерная сортировка \n2 - Пирамидальная сортировка\n3 - Сортировка Шелла\n4 - Быстрая сортировка" << endl;
	int sort; cin >> sort;
	int* analyze = new int[2]{ 0, 0 };
	switch (s) {
	case 1:
	{
		vector<mass> info;
		vector<mass> info2;
		mass aa;
		char sm[50];
		int n = -1;
		ifstream file("saod.csv");
		while (!file.eof()) {


			n++;
			file.getline(sm, 50, ';');
			aa.author = sm;
			file.getline(sm, 50, ';');
			aa.nameauthor = sm;
			file.getline(sm, 50, ';');
			aa.year = atoi(sm);
			file.getline(sm, 50, ';');
			aa.bookname = sm;
			file.getline(sm, 50, ';');
			aa.page = atoi(sm);
			info.insert(info.end(), aa);

			if (n % 30 == 0)
			{
				switch (sort)
				{
					analyze[0] = 0;
					analyze[1] = 0;
				case 1:
				{
					clock_t start = clock();
					info2 = cocktailsort(info, analyze);
					clock_t end = clock();
					double seconds = (double)(end - start) / CLOCKS_PER_SEC;
					printf("cocktailsort library time %.8f\nchanges %.d\ncomparing %.d\ncount %.d\n", seconds, analyze[0], analyze[1], n);
					fprintf(ffout, "cocktailsort library;%.8f;%.d;%.d;%.d;\n", seconds, analyze[0], analyze[1], n);
					//	for (int i = 0; i < 10; i++) cout << info2[i].author << "  " << info2[i].nameauthor << "  " << info2[i].year << "  " << info2[i].bookname << "  " << info2[i].page << endl;
					break;
				}
				case 2:
				{
					clock_t start = clock();
					info2 = heapSort(info, info.size() - 1, analyze);
					clock_t end = clock();
					double seconds = (double)(end - start) / CLOCKS_PER_SEC;
					printf("heapsort library  time %.8f\nchanges %.d\ncomparing %.d\ncount %.d\n", seconds, analyze[0], analyze[1], n);
					fprintf(ffout, "heapsort library time;%.8f;%.d;%.d;%.d;\n", seconds, analyze[0], analyze[1], n);
					//		for (int i = 0; i < 10; i++) cout << info2[i].author << "  " << info2[i].nameauthor << "  " << info2[i].year << "  " << info2[i].bookname << "  " << info2[i].page << endl;
					break;
				}
				case 3:
				{
					clock_t start = clock();
					info2 = shellSort(info, info.size(), analyze);
					clock_t end = clock();
					double seconds = (double)(end - start) / CLOCKS_PER_SEC;
					printf("shellsort library time %.8f\nchanges %.d\ncomparing %.d\ncount %.d\n", seconds, analyze[0], analyze[1], n);
					fprintf(ffout, "shellsort library time;%.8f;%.d;%.d;%.d;\n", seconds, analyze[0], analyze[1], n);
					//		for (int i = 0; i < 10; i++) cout << info2[i].author << "  " << info2[i].nameauthor << "  " << info2[i].year << "  " << info2[i].bookname << "  " << info2[i].page << endl;
					break;
				}
				case 4:
				{
					clock_t start = clock();
					info2 = quick_sort(info, 0, info.size() - 1, analyze);
					clock_t end = clock();
					double seconds = (double)(end - start) / CLOCKS_PER_SEC;
					printf("quicksort library  time %.8f\nchanges %.d\ncomparing %.d\ncount %.d\n", seconds, analyze[0], analyze[1], n);
					fprintf(ffout, "quicksort library   time;%.8f;%.d;%.d;%.d;\n", seconds, analyze[0], analyze[1], n);
					// 	for (int i = 0; i < 10; i++) cout << info2[i].author << "  " << info2[i].nameauthor << "  " << info2[i].year << "  " << info2[i].bookname << "  " << info2[i].page << endl;
					break;
				}
				default: cout << "Данные введены неверно" << endl; break;
				}
			}

		}

		file.close();
		break;
	}
	case 2:
	{
		vector<int> info;
		vector<int> info2;
		ifstream file("f.csv");
		int n = -1;
		int m;
		char *sm = new char[50];
		while (!file.eof()) {

			n++;
			file >> m;
			info.insert(info.end(), m);


			if (n % 150 == 0) {
				switch (sort)
				{
					analyze[0] = 0;
					analyze[1] = 0;
				case 1:
				{
					clock_t start = clock();
					info2 = cocktailsort(info, analyze);
					clock_t end = clock();
					double seconds = (double)(end - start) / CLOCKS_PER_SEC;
					printf("cocktailsort number time %.8f\nchanges %.d\ncomparing %.d\ncount %.d\n", seconds, analyze[0], analyze[1], n);
					fprintf(ffout, "cocktailsort number time;%.8f;%.d;%.d;%.d;\n", seconds, analyze[0], analyze[1], n);
					//	for (int i = 0; i < 10; i++) cout << info2[i] << endl;
					break;
				}
				case 2:
				{
					clock_t start = clock();
					info2 = heapSort(info, info.size() - 1, analyze);
					clock_t end = clock();
					double seconds = (double)(end - start) / CLOCKS_PER_SEC;
					printf("heapsort number  time %.8f\nchanges %.d\ncomparing %.d\ncount %.d\n", seconds, analyze[0], analyze[1], n);
					fprintf(ffout, "heapsort number  time;%.8f;%.d;%.d;%.d;\n", seconds, analyze[0], analyze[1], n);
					//	for (int i = 0; i < 10; i++) cout << info2[i] << endl;
					break;
				}
				case 3:
				{
					clock_t start = clock();
					info2 = shellSort(info, info.size(), analyze);
					clock_t end = clock();
					double seconds = (double)(end - start) / CLOCKS_PER_SEC;
					printf("shellsort number  time %.8f\nchanges %.d\ncomparing %.d\ncount %.d\n", seconds, analyze[0], analyze[1], n);
					fprintf(ffout, "shellsort number  time;%.8f;%.d;%.d;%.d;\n", seconds, analyze[0], analyze[1], n);
					//	for (int i = 0; i < 10; i++) cout << info2[i] << endl;
					break;
				}
				case 4:
				{
					clock_t start = clock();
					info2 = quick_sort(info, 0, info.size() - 1, analyze);
					clock_t end = clock();
					double seconds = (double)(end - start) / CLOCKS_PER_SEC;
					printf("quicksort number  time %.8f\nchanges %.d\ncomparing %.d\ncount %.d\n", seconds, analyze[0], analyze[1], n);
					fprintf(ffout, "quicksort number  time;%.8f;%.d;%.d;%.d;\n", seconds, analyze[0], analyze[1], n);
					//	for (int i = 0; i < 10; i++) cout << info2[i] << endl;
					break;
				}
				default: cout << "Данные введены неверно" << endl; break;
				}

			}
		}
		file.close();
		break;
	}

	default: cout << "Неверный ввод данных " << endl; break;
	}
	fclose(ffout);
	system("pause");
	return 0;
}

template <typename T>
vector<T> selection(vector<T> ar, int *analyze)
{
	int i, j, nmx;
	T mx;

	for (i = 0; i < ar.size() - 1; i++)
	{
		mx = ar[i];
		nmx = i;
		for (j = i + 1; j < ar.size(); j++)
		{
			if (ar[j]<mx)
			{
				mx = ar[j];
				nmx = j;
			}
		}
		ar[nmx] = ar[i];
		ar[i] = mx;
	}
	return ar;
}

template<typename T>
vector<T> cocktailsort(vector<T> vector, int *analyze)
{
	int left, right, i;
	T tmp;

	for (left = 0, right = vector.size() - 1; left < right;)
	{
		for (i = left; i < right; i++)
		{
			analyze[0]++;
			if (vector[i + 1] < vector[i])
			{
				tmp = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = tmp;
				analyze[1]++;
			}
		}
		right--;

		for (i = right; i > left; i--)
		{
			analyze[0]++;
			if (vector[i - 1] > vector[i])
			{
				tmp = vector[i - 1];
				vector[i - 1] = vector[i];
				vector[i] = tmp;
				analyze[1]++;
			}
		}
		left++;
	}
	return vector;
}

template<typename T>
vector<T> quick_sort(vector<T> vector, int first, int last, int *analyze)
{
	int left, right;
	analyze[0]++;
	if (first < last)
	{
		left = first, right = last;
		T middle = (vector)[(left + right) / 2];
		do
		{
			while ((vector)[left] < middle)
			{
				left++;
			}

			while ((vector)[right] > middle)
			{
				right--;
			}
			analyze[0]++;
			if (left <= right)
			{
				T tmp = (vector)[left];
				(vector)[left] = (vector)[right];
				(vector)[right] = tmp;
				left++;
				right--;
				analyze[1]++;
			}

		} while (left <= right);

		vector = quick_sort(vector, first, right, analyze);
		vector = quick_sort(vector, left, last, analyze);
	}
	return vector;
}

template <typename T>
vector<T> siftDown(vector<T> numbers, int root, int bottom, int *analyze)
{
	int maxChild;
	int done = 0;

	while ((root * 2 <= bottom) && (!done))
	{
		analyze[0]++;
		if (root * 2 == bottom)
			maxChild = root * 2;

		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		analyze[0]++;
		if (numbers[root] < numbers[maxChild])
		{
			T temp = numbers[root];
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
			analyze[1]++;
		}
		else
			done = 1;
	}
	return numbers;
}
template <typename T>
vector<T> heapSort(vector<T> numbers, int array_size, int *analyze)
{
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		numbers = siftDown(numbers, i, array_size, analyze);
	for (int i = array_size - 1; i >= 1; i--)
	{
		T temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		numbers = siftDown(numbers, 0, i - 1, analyze);
		analyze[1]++;
	}
	return numbers;
}


int increment(long *inc, long size, int *analyze) {
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do {

		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;
}

template<typename T>
vector<T> shellSort(vector<T> a, long size, int *analyze) {
	long inc, i, j, seq[40];
	int s;

	s = increment(seq, size, analyze);
	while (s >= 0) {
		inc = seq[s--];
		for (i = inc; i < size; i++) {
			T temp = a[i];
			for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
				a[j + inc] = a[j];
			a[j + inc] = temp;
			analyze[1]++;
		}
	}
	return a;
}