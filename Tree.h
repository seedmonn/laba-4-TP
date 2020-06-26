#pragma once

#include <iostream>
#include <cstdlib>

template <typename T>
class Tree {
	struct Node {
		T value; // значение элемента

		Node* left; // указатель на левое поддерево
		Node* right; // указатель на правое поддерево
	};

	Node* root; // корень дерева

	Node* Insert(Node* node, const T& value); // вставка в дерево
	//Node* Remove(Node* node, const T& value); // удаление из дерева

	void Copy(Node* node, Node*& newNode); // копирование дерева
	void Clear(Node*& node); // очистка дерева (освобождение памяти)

	void preorderPrint(Node* tree); // восход
	void inorderPrint(Node* tree); // нисход

	int GetSize(Node* node) const; // количество элементов в дереве
	//int GetHeight(Node* node) const; // высота дерева

	void Print(std::ostream& os, Node* node, int level) const; // вывод дерева в виде повёрнутого дерева в поток

public:
	Tree(); // конструктор по умолчанию
	Tree(const Tree& tree); // конструктор копирования

	//Tree& operator=(const Tree& tree); // оператор присваивания

	void Insert(const T& value); // вставка элемента в дерево
	//bool Remove(const T& value); // удаление элемента из дерева
	void Clear(); // удаление всех элементов из дерева

	void preorderPrint(); // восход
	void inorderPrint(); // нисход

	bool Find(const T& value) const; // поиск элемента в дереве

	int GetSize() const; // количество элементов в дереве
	//int GetHeight() const; // высота дерева

	~Tree(); // деструктор (освобождение памяти)

	template <typename T1>
	friend std::ostream& operator<<(std::ostream& os, const Tree<T1>& tree); // оператор вывода в поток
};