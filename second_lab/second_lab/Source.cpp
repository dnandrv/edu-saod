#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>

using namespace std;

//Описание функции сортировки простым слиянием
void Simple_Merging_Sort(const char *name) {
	int a1, a2, k, i, j, kol, tmp;
	FILE *f, *f1, *f2;
	kol = 0;
	if ((f = fopen(name, "r")) == NULL)
		printf("\nИсходный файл не может быть прочитан...");
	else {
		while (!feof(f)) {
			fscanf(f, "%d\n", &a1);
			kol++;
		}
		fclose(f);
	}
	k = 1;
	while (k < kol) {
		f = fopen(name, "r");
		f1 = fopen("smsort_1", "w");
		f2 = fopen("smsort_2", "w");
		if (!feof(f)) fscanf(f, "%d", &a1);
		while (!feof(f)) {
			for (i = 0; i < k && !feof(f); i++) {
				fprintf(f1, "%d ", a1);
				fscanf(f, "%d\n", &a1);
			}
			for (j = 0; j < k && !feof(f); j++) {
				fprintf(f2, "%d ", a1);
				fscanf(f, "%d\n", &a1);
			}
		}
		fclose(f2);
		fclose(f1);
		fclose(f);

		f = fopen(name, "w");
		f1 = fopen("smsort_1", "r");
		f2 = fopen("smsort_2", "r");
		if (!feof(f1)) fscanf(f1, "%d", &a1);
		if (!feof(f2)) fscanf(f2, "%d", &a2);
		while (!feof(f1) && !feof(f2)) {
			i = 0;
			j = 0;
			while (i < k && j < k && !feof(f1) && !feof(f2)) {
				if (a1 < a2) {
					fprintf(f, "%d\n ", a1);
					fscanf(f1, "%d", &a1);
					i++;
				}
				else {
					fprintf(f, "%d\n ", a2);
					fscanf(f2, "%d", &a2);
					j++;
				}
			}
			while (i < k && !feof(f1)) {
				fprintf(f, "%d\n ", a1);
				fscanf(f1, "%d", &a1);
				i++;
			}
			while (j < k && !feof(f2)) {
				fprintf(f, "%d\n ", a2);
				fscanf(f2, "%d", &a2);
				j++;
			}
		}
		while (!feof(f1)) {
			fprintf(f, "%d\n ", a1);
			fscanf(f1, "%d", &a1);
		}
		while (!feof(f2)) {
			fprintf(f, "%d\n ", a2);
			fscanf(f2, "%d", &a2);
		}
		fclose(f2);
		fclose(f1);
		fclose(f);
		k *= 2;
	}
	remove("smsort_1");
	remove("smsort_2");
}

//определение конца блока
bool End_Range(FILE * f) {
	int tmp;
	tmp = fgetc(f);
	tmp = fgetc(f);
	if (tmp != '\'') fseek(f, -2, 1);
	else fseek(f, 1, 1);
	return tmp == '\'' ? true : false;
}

//Описание функции сортировки естественным слиянием
void Natural_Merging_Sort(const char *name) {
	int s1, s2, a1, a2, mark;
	FILE *f, *f1, *f2;
	s1 = s2 = 1;
	while (s1 > 0 && s2 > 0) {
		mark = 1;
		s1 = 0;
		s2 = 0;
		f = fopen(name, "r");
		f1 = fopen("nmsort_1", "w");
		f2 = fopen("nmsort_2", "w");
		fscanf(f, "%d", &a1);
		if (!feof(f)) {
			fprintf(f1, "%d ", a1);
		}
		if (!feof(f)) fscanf(f, "%d\n", &a2);
		while (!feof(f)) {
			if (a2 < a1) {
				switch (mark) {
				case 1: {fprintf(f1, "' "); mark = 2; s1++; break; }
				case 2: {fprintf(f2, "' "); mark = 1; s2++; break; }
				}
			}
			if (mark == 1) { fprintf(f1, "%d ", a2); s1++; }
			else { fprintf(f2, "%d ", a2); s2++; }
			a1 = a2;
			fscanf(f, "%d", &a2);
		}
		if (s2 > 0 && mark == 2) { fprintf(f2, "'"); }
		if (s1 > 0 && mark == 1) { fprintf(f1, "'"); }
		fclose(f2);
		fclose(f1);
		fclose(f);

		f = fopen(name, "w");
		f1 = fopen("nmsort_1", "r");
		f2 = fopen("nmsort_2", "r");
		if (!feof(f1)) fscanf(f1, "%d", &a1);
		if (!feof(f2)) fscanf(f2, "%d", &a2);
		bool file1, file2;
		while (!feof(f1) && !feof(f2)) {
			file1 = file2 = false;
			while (!file1 && !file2) {
				if (a1 <= a2) {
					fprintf(f, "%d\n ", a1);
					file1 = End_Range(f1);
					fscanf(f1, "%d", &a1);
				}
				else {
					fprintf(f, "%d\n ", a2);
					file2 = End_Range(f2);
					fscanf(f2, "%d", &a2);
				}
			}
			while (!file1) {
				fprintf(f, "%d\n ", a1);
				file1 = End_Range(f1);
				fscanf(f1, "%d", &a1);
			}
			while (!file2) {
				fprintf(f, "%d\n ", a2);
				file2 = End_Range(f2);
				fscanf(f2, "%d", &a2);
			}
		}
		file1 = file2 = false;
		while (!file1 && !feof(f1)) {
			fprintf(f, "%d\n ", a1);
			file1 = End_Range(f1);
			fscanf(f1, "%d", &a1);
		}
		while (!file2 && !feof(f2)) {
			fprintf(f, "%d\n ", a2);
			file2 = End_Range(f2);
			fscanf(f2, "%d", &a2);
		}
		fclose(f2);
		fclose(f1);
		fclose(f);
	}
	remove("nmsort_1");
	remove("nmsort_2");
}


int main() {
	setlocale(LC_ALL, "Russian");

	cout << "Введите тип данных\n1 - массив чисел\n2 - массив записей" << endl;
	int inputtype; cin >> inputtype;

	cout << "Введите тип сортировки\n1 - Простая внешняя сортировка\n2 - Естественная сортировка слиянием\n3 - Фибоначчиевая сортировка" << endl;
	int sorttype; cin >> sorttype;

	if (sorttype > 3 || inputtype > 2) { cout << "Неверный ввод данных "; }
	else {
		switch (inputtype)
		{
		case 1: {
			ifstream file("f.csv");
			const char* s = new char;
			s = "f.csv";
			switch (sorttype) {
			case 1:
			{
				Simple_Merging_Sort(s);
				break;
			}
			case 2:
			{
				Natural_Merging_Sort(s);
				break;
			}
			case 3:
			{

				break;
			}
			}
			file.close();
			break;
		}
		case 2: {
			ifstream file("saod.csv");
			switch (sorttype) {
			case 1:
			{
				break;
			}
			case 2:
			{
				break;
			}
			case 3:
			{
				break;
			}
			}



			file.close();
			break;
		}
		}
	}

	system("pause");
	return 0;
}