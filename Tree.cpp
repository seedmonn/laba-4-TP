#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Tree.h"
// ������� � ������
template <typename T>
typename Tree<T>::Node* Tree<T>::Insert(Node* node, const T& value) {
	if (node == nullptr) {
		node = new Node; // ������ ����� �������

		node->value = value; // ��������� ��������
		node->left = nullptr;
		node->right = nullptr;

		return node; // ���������� ���
	}

	// ���� �������� ������ �������� ����
	if (value < node->value) {
		node->left = Insert(node->left, value); // ��������� � ����� ���������
	}
	else {
		node->right = Insert(node->right, value); // ����� ��������� � ������ ���������
	}

	return node; // ���������� ����������� ���������
}

//// �������� �� ������
//template <typename T>
//typename Tree<T>::Node* Tree<T>::Remove(Node* node, const T& value) {
//	if (node == nullptr)
//		return nullptr;
//
//	if (value < node->value) {
//		node->left = Remove(node->left, value); // ���� �������� ������ ����, ������� �� ������ ���������
//	}
//	else if (value > node->value) {
//		node->right = Remove(node->right, value); // ���� �������� ������ ����, ������� �� ������� ���������
//	}
//	else {
//		// ���� ���� ������ ��� �� ������
//		if (node->left == nullptr || node->right == nullptr) {
//			Node* tmp = node->left ? node->left : node->right;
//			delete node;
//
//			return tmp;
//		}
//
//		Node* parent = node->right;
//		Node* tmp = node->right;
//
//		while (tmp->left) {
//			parent = tmp;
//			tmp = tmp->left;
//		}
//
//		if (parent != tmp) {
//			parent->left = tmp->right;
//		}
//		else {
//			node->right = tmp->right;
//		}
//
//		node->value = tmp->value;
//
//		delete tmp;
//	}
//
//	return node;
//}
//����������� ������
template <typename T>
void Tree<T>::Copy(Node* node, Node*& newNode) {
	if (node == nullptr)
		return;

	newNode = new Node;

	newNode->value = node->value;
	newNode->left = nullptr;
	newNode->right = nullptr;

	Copy(node->left, newNode->left); // �������� ����� ���������
	Copy(node->right, newNode->right); // �������� ������ ���������
}

// �������� ��������� �� ������ � ������������ ������
template <typename T>
void Tree<T>::Clear(Node*& node) {
	if (node == nullptr)
		return;

	Clear(node->left); // ������� ����� ���������
	Clear(node->right); // ������� ������ ���������

	delete node; // ������� �������
	node = nullptr; // �������� �������� ��������
}

// ���������� ��������� � ������
template <typename T>
int Tree<T>::GetSize(Node* node) const {
	if (node == nullptr)
		return 0; // ���� �� ��������� �� �������

	int leftSize = GetSize(node->left); // ������� ����� ��������� � ����� ���������
	int rightSize = GetSize(node->right); // ������� ����� ��������� � ������ ���������

	return 1 + leftSize + rightSize; // �������� ����� ��������� - ����� ����� ��������� � ����������� + 1
}

//// ������ ������
//template <typename T>
//int Tree<T>::GetHeight(Node* node) const {
//	if (node == nullptr)
//		return 0; // ������ ����� ����� 0
//
//	int leftHeight = GetHeight(node->left); // �������� ������ ������ ���������
//	int rightHeight = GetHeight(node->right); //  �������� ������ ������� ���������
//
//	return 1 + std::max(leftHeight, rightHeight); // ������ ���� �� 1 ������, ��� ������������ �� ����� �����������
//}

// ����� ������ � ���� ���������� ������ � �����
template <typename T>
void Tree<T>::Print(std::ostream& os, Node* node, int level) const {
	if (node == nullptr)
		return;

	Print(os, node->right, level + 1);

	for (int i = 0; i < level; i++)
		os << "    ";

	os << node->value << std::endl;

	Print(os, node->left, level + 1);
}

// ����������� �� ���������
template <typename T>
Tree<T>::Tree() {
	root = nullptr; // ���������� ������ ���
}

// ����������� �����������
template <typename T>
Tree<T>::Tree(const Tree& tree) {
	Copy(tree.root, root);
}

//// �������� ������������
//template <typename T>
//Tree<T>& Tree<T>::operator=(const Tree& tree) {
//	if (this == &tree)
//		return *this;
//
//	Clear(root); // ������� ������� ������
//	Copy(tree.root, root); // �������� ������ ������
//
//	return *this;
//}

template <typename T>
void Tree<T>::Insert(const T& value) {
	root = Insert(root, value);
}

//template <typename T>
//bool Tree<T>::Remove(const T& value) {
//	if (!Find(value))
//		return false;
//
//	root = Remove(root, value);
//
//	return true;
//}

// �������� ���� ��������� �� ������
template <typename T>
void Tree<T>::Clear() {
	Clear(root); // �������� ����������� ������� ������� �� ������
}

template<typename T>
void Tree<T>::preorderPrint()
{
	return preorderPrint(root);
}

template<typename T>
void Tree<T>::preorderPrint(Node* tree)
{
	if (tree == nullptr)
		return;
	std::cout << tree->value << " ";
	preorderPrint(tree->left);
	preorderPrint(tree->right);
}

template<typename T>
void Tree<T>::inorderPrint()
{
	return inorderPrint(root);
}

template<typename T>
void Tree<T>::inorderPrint(Node* tree)
{
	if (tree == nullptr)
		return;
	inorderPrint(tree->left);
	std::cout << tree->value << " ";
	inorderPrint(tree->right);
}

// ����� �������� � ������
template <typename T>
bool Tree<T>::Find(const T& value) const {
	Node* node = root;

	while (node) {
		if (node->value == value)
			return true;

		if (value < node->value) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}

	return false;
}

// ���������� ��������� � ������
template <typename T>
int Tree<T>::GetSize() const {
	return GetSize(root); // �������� ����������� ������ ��������� �������
}

//// ������ ������
//template <typename T>
//int Tree<T>::GetHeight() const {
//	return GetHeight(root); // �������� ����������� ������ ��������� ������
//}

// ���������� (������������ ������)
template <typename T>
Tree<T>::~Tree() {
	Clear(root);
}

// �������� ������ � �����
template <typename T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& tree) {
	tree.Print(os, tree.root, 0);

	return os;
}