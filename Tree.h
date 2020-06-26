#pragma once

#include <iostream>
#include <cstdlib>

template <typename T>
class Tree {
	struct Node {
		T value; // �������� ��������

		Node* left; // ��������� �� ����� ���������
		Node* right; // ��������� �� ������ ���������
	};

	Node* root; // ������ ������

	Node* Insert(Node* node, const T& value); // ������� � ������
	//Node* Remove(Node* node, const T& value); // �������� �� ������

	void Copy(Node* node, Node*& newNode); // ����������� ������
	void Clear(Node*& node); // ������� ������ (������������ ������)

	void preorderPrint(Node* tree); // ������
	void inorderPrint(Node* tree); // ������

	int GetSize(Node* node) const; // ���������� ��������� � ������
	//int GetHeight(Node* node) const; // ������ ������

	void Print(std::ostream& os, Node* node, int level) const; // ����� ������ � ���� ���������� ������ � �����

public:
	Tree(); // ����������� �� ���������
	Tree(const Tree& tree); // ����������� �����������

	//Tree& operator=(const Tree& tree); // �������� ������������

	void Insert(const T& value); // ������� �������� � ������
	//bool Remove(const T& value); // �������� �������� �� ������
	void Clear(); // �������� ���� ��������� �� ������

	void preorderPrint(); // ������
	void inorderPrint(); // ������

	bool Find(const T& value) const; // ����� �������� � ������

	int GetSize() const; // ���������� ��������� � ������
	//int GetHeight() const; // ������ ������

	~Tree(); // ���������� (������������ ������)

	template <typename T1>
	friend std::ostream& operator<<(std::ostream& os, const Tree<T1>& tree); // �������� ������ � �����
};