#pragma once

#include <iostream>
using namespace std;

class BinaryTree
{
private:
	class Node {
	private:
		int id;
		int value;
		Node* left;
		Node* right;

	public:
		Node(int id, int value, Node* left, Node* right) {
			this->id = id;
			this->value = value;
			this->left = left;
			this->right = right;
		}
		Node(int id, int value) : Node(id, value, nullptr, nullptr) {}

		void addNode(int id, int value) {
			if (value >= this->value) {
				if (right == nullptr)
					right = new Node(id, value);
				else
					right->addNode(id, value);
			}
			else { 
				if (left == nullptr)
					left = new Node(id, value);
				else
					left->addNode(id, value);
			}
		}
		int findMax(Node* root)

		{


			if (root == NULL)

				return INT_MIN;

			int res = root->value;

			int left_res = findMax(root->left);

			int right_res = findMax(root->right);

			if (left_res > res)

				res = left_res;

			if (right_res > res)

				res = right_res;

			return res;

		}
		int findMin(Node* root)

		{


			if (root == NULL)

				return INT_MAX;

			int res = root->value;

			int left_res = findMin(root->left);

			int right_res = findMin(root->right);

			if (left_res < res)

				res = left_res;

			if (right_res < res)

				res = right_res;

			return res;

		}
		void print(int level) {
			for (int i = 0; i < level; i++)
				cout << '\t';
			cout << "(id = " << id << ", value = " << value << endl;

			if (right != nullptr)
				right->print(level + 1);
			else {
				for (int i = 0; i < level + 1; i++)
					cout << '\t';
				cout << "(nullptr)" << endl;
			}

			if (left != nullptr)
				left->print(level + 1);
			else {
				for (int i = 0; i < level + 1; i++)
					cout << '\t';
				cout << "(nullptr)" << endl;
			}

			for (int i = 0; i < level; i++)
				cout << '\t';
			cout << ")" << endl;
		}
	};

private:
	Node* root;
	int nodeCount;

public:
	int FindMax() {
		return root->findMax(root);
	}
	int FindMin() {
		return root->findMin(root);
	}
	BinaryTree() {
		root = nullptr;
		nodeCount = 0;
	}

	void addNode(int value){
		if (root == nullptr)
			root = new Node(nodeCount++, value);
		else
			root->addNode(nodeCount++, value);
	}

	
	void print() {
		if (root == nullptr)
			cout << "empty tree" << endl;
		else
			root->print(0);
	}
};