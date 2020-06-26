#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Tree.h"
#include "Tree.cpp"

using namespace std;

void Print(Tree<int>& tree) {
	if (tree.GetSize() == 0) {
		cout << "������ �����!" << endl;
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

	cout << "������� �������� ��� ������ ";
	cin >> value;

	if (tree.Find(value)) {
		cout << "�������!" << endl;
	}
	else {
		cout << "����� " << value << " ��� � ������!" << endl;
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
	char item; // ���������� ����� ����
	Tree<int> tree; // ������ ������
	do
	{
		system("cls");
		Print(tree);
		cout << "\n[1] �������� ������� � ������.";
		cout << "\n[2] ����������� �� ������ � ���������� �������.";
		cout << "\n[3] ����������� �� ������ � ���������� �������.";
		cout << "\n[4] ����� �� ������.";
		cout << "\n[0] �����.\n";
		cout << "=> "; cin >> item;
		switch (item)
		{
		case '1':
			Insert(tree); cout << "\n";
			system("pause");
			break;
		case '2':
			cout << "����������� �� ������ � ���������� �������: ";
			preorderPrint(tree); cout << "\n";
			system("pause");
			break;
		case '3':
			cout << "����������� �� ������ � ���������� �������: ";
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