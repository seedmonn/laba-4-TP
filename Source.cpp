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
				cout << "\n������ ���������� �����: ";
			cout << "[" << i << "] ";
		}
	}
	if (!counter) {
		cout << "\n������ ����� � ������� ���!\n";
		return;
	}
	cout << "\n���������� ����������: " << counter << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int size = 29 + rand() % 71; int user_value;
	Massiv<int> array;
	int* arr = new int[size];
	cout << "������ ������� [" << size << "]" << endl << "Value\tIndex" << endl;
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
	cout << "\n������� �����, ������� ������ ����� � �������: "; cin >> user_value;
	search(user_value, array);
	system("PAUSE");
	delete[] arr;
	return 0;
}