#include <iostream>
#include <locale>
#include <ctime>
#include "Massiv.h"
#include "Massiv.cpp"

using namespace std;

template<typename T>
void search(T user_value, Massiv<int>& array) {
	int counter = 0;
	for (int i = 0; i < array.GetSize(); i++)
	{
		if (array[i] == user_value) {
			counter++;
			if (counter == 1)
				cout << "\nИндекс введенного числа: ";
			cout << "[" << i << "] ";
		}
	}
	if (!counter) {
		cout << "\nТакого числа в массиве нет!\n";
		return;
	}
	cout << "\nКоличество совпадений: " << counter << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int size = 29 + rand() % 71; int user_value;
	Massiv<int> array;
	int* arr = new int[size];
	cout << "Размер массива [" << size << "]" << endl << "Value\tIndex" << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100; if (arr[i] < 10)
			cout << " ";
		cout << " ["; cout << arr[i] << "] - [" << i << "]" << endl;
	}
	for (int i = 0; i < size; i++)
	{
		array.push_back(arr[i]);
	}
	cout << "\nВведите число, которое хотите найти в массиве: "; cin >> user_value;
	search(user_value, array);
	system("PAUSE");
	delete[] arr;
	return 0;
}