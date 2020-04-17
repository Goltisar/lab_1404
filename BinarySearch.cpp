#include <iostream>
#include "BinaryTree.h"
#include "MinimalBST.h"

using namespace std;

void TestMinimalBinaryTree()
{
    const int n = 9;
    int arr[n] = { -5, -2, 0, 5, 9, 14, 20, 23, 90 };
    CreateMinimalBST(arr, 0, n-1);
}

void TestBinaryTree()
{
    BinaryTree<int> tree = BinaryTree<int>(4);
    tree.insert(2);
    tree.insert(11);
    tree.insert(5);
    tree.insert(-2);
    tree.insert(-5);
    cout << "Binary tree ordered print: " << endl;
    tree.printTree(tree.get_root());
    cout << endl;
}

int main()
{
    TestBinaryTree();
    TestMinimalBinaryTree();
}


