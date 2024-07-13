// A C++ program to demonstrate serialization and
// deserialization of Binary Tree

#include <bits/stdc++.h>
using namespace std;

#define MARKER -1

// A binary tree Node has key, 
// pointer to left and right children
struct Node {
	int key;
	struct Node *left, *right;
};

// Helper function that allocates a new Node with the
// given key and NULL left and right pointers.
struct Node* newNode(int key)
{
	struct Node* temp = new Node();
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

// This function stores a tree in a file pointed by fp
void serialize(Node* root, FILE* fp)
{
	// If current node is NULL, store marker
	if (root == NULL) {
		fprintf(fp, "%d ", MARKER);
		return;
	}

	// Else, store current node and 
	// recur for its children
	fprintf(fp, "%d ", root->key);
	serialize(root->left, fp);
	serialize(root->right, fp);
}

// This function constructs a tree from 
// a file pointed by 'fp'
void deSerialize(Node*& root, FILE* fp)
{
	// Read next item from file. 
	// If there are no more items
	// or next item is marker, then return
	int val;
	if (!fscanf(fp, "%d ", &val) || val == MARKER)
		return;

	// Else create node with this item 
	// and recur for children
	root = newNode(val);
	deSerialize(root->left, fp);
	deSerialize(root->right, fp);
}

// A simple inorder traversal used for 
// testing the constructed tree
void inorder(Node* root)
{
	if (root) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

// Driver code
int main()
{
	// Construct a tree shown in the above figure
	struct Node* root = newNode(30);
	root->left = newNode(10);
	root->right = newNode(40);
	root->left->left = newNode(5);
	root->left->right = newNode(20);
	root->left->right->left = newNode(15);
	root->left->right->right = newNode(25);

	// Open a file and serialize the tree into the file
	FILE* fp = fopen("tree.txt", "w");
	if (fp == NULL) {
		puts("Could not open file");
		return 0;
	}
	serialize(root, fp);
	fclose(fp);

	// Deserialize the stored tree into root1
	Node* root1 = NULL;
	fp = fopen("tree.txt", "r");
	deSerialize(root1, fp);

	printf("Inorder Traversal of the tree constructed from "
		"file:\n");
	inorder(root1);

	return 0;
}
