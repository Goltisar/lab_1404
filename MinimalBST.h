#pragma once
#include "BinaryTree.h"

TreeNode* CreateMinimalBST(int* arr, int start, int end)
{
	if (end < start)
		return nullptr;
	int midIndex = (start + end) / 2;
	TreeNode* node = new TreeNode(arr[midIndex]);
	node->set_left(CreateMinimalBST(arr, start, midIndex - 1));
	node->set_right(CreateMinimalBST(arr, midIndex + 1, end));
	return node;
}

