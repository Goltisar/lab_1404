#include <iostream>
#include "BinaryTree.h"
#include "MinimalBST.h"

using namespace std;

void TestMinimalBinaryTree()
{
    const int n = 9;
    int arr[n] = { -5, -2, 0, 5, 9, 14, 20, 23, 90 };
    BinaryTree tree = BinaryTree();
    tree.set_root(CreateMinimalBST(arr, 0, n-1));
    cout << "MinimalBinaryTree: " << endl;
    tree.printTree(tree.get_root());
}

void TestBinaryTree()
{
    BinaryTree tree = BinaryTree(4);
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
    // First task
    TestBinaryTree();
    // Second task
    TestMinimalBinaryTree();
}


