#include<iostream>
#include <string>

#include <Windows.h>

#include "BinaryTree.h"

BinaryTree NewTree() {
	BinaryTree tree;
	int arr[10]{};
	for (int i = 0; i < 10; i++)
		arr[i] = rand() % 100 + 1;
	for (int i = 0; i < 10; i++)
		tree.addNode(arr[i]);
	return tree;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	BinaryTree tree = NewTree();
	tree.print(); 
	cout << "Max: " << tree.FindMax() << endl;
	cout << "Min: " << tree.FindMin() << endl;
	return 0;
}
