#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Tree.h"
#include "Tree.cpp"

using namespace std;

void Print(Tree<int>& tree) {
	if (tree.GetSize() == 0) {
		cout << "Дерево пусто!" << endl;
	}
	else {
		cout << tree;
	}
}

void Insert(Tree<int>& tree) {
	int value;

	cout << "Enter value for insert: ";
	cin >> value;

	tree.Insert(value);
	cout << "Inserted!" << endl;
}

void Find(Tree<int>& tree) {
	int value;

	cout << "Введите значение для поиска ";
	cin >> value;

	if (tree.Find(value)) {
		cout << "Найдено!" << endl;
	}
	else {
		cout << "Числа " << value << " нет в дереве!" << endl;
	}
}

void preorderPrint(Tree<int>& tree) {
	tree.preorderPrint();
}

void inorderPrint(Tree<int>& tree) {
	tree.inorderPrint();
}

int main() {
	setlocale(LC_ALL, "rus");
	char item; // выбираемый пункт меню
	Tree<int> tree; // создаём дерево
	do
	{
		system("cls");
		Print(tree);
		cout << "\n[1] Добавить элемент в дерево.";
		cout << "\n[2] Прохождение по дереву в нисходящем порядке.";
		cout << "\n[3] Прохождение по дереву в восходящем порядке.";
		cout << "\n[4] Поиск по дереву.";
		cout << "\n[0] Выход.\n";
		cout << "=> "; cin >> item;
		switch (item)
		{
		case '1':
			Insert(tree); cout << "\n";
			system("pause");
			break;
		case '2':
			cout << "Прохождение по дереву в нисходящем порядке: ";
			preorderPrint(tree); cout << "\n";
			system("pause");
			break;
		case '3':
			cout << "Прохождение по дереву в восходящем порядке: ";
			inorderPrint(tree); cout << "\n";
			system("pause");
			break;
		case '4':
			Find(tree); cout << "\n";
			system("pause");
			break;
		case '0':
			break;
		}
	} while (item != '0');
	return 0;
}

//void Remove(Tree<int>& tree) {
//	int value;
//
//	cout << "Enter value for remove: ";
//	cin >> value;
//
//	if (tree.Remove(value)) {
//		cout << "Removed!" << endl;
//	}
//	else {
//		cout << "No value " << value << " in tree" << endl;
//	}
//}
//
//void GetHeight(Tree<int>& tree) {
//	cout << "Height: " << tree.GetHeight() << endl;
//}
//
//void GetSize(Tree<int>& tree) {
//	cout << "Size: " << tree.GetSize() << endl;
//}