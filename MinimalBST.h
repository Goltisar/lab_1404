#pragma once
#include "BinaryTree.h"

template<typename T>
void CreateMinimalBST(T* arr, int start, int end)
{
	BinaryTree<T> tree = BinaryTree<T>(arr[(start + end) / 2]);
	CreateNodes(arr, start, end, &tree);
	std::cout << "MinimalBST: " << std::endl;
	tree.printTree(tree.get_root());
	std::cout << std::endl;
}

template<typename T>
void CreateNodes(T* arr, int start, int end, BinaryTree<T>* tree)
{
	if (end < start)
		return;
	int midIndex = (start + end) / 2;
	tree->insert(arr[midIndex]);
	CreateNodes(arr, start, midIndex - 1, tree);
	CreateNodes(arr, midIndex + 1, end, tree);
}
