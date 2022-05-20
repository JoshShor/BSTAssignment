/*
* Name: Joshua Shor
* Student ID: 200968955
* Email: shor002@cougars.csusm.edu
Write a C++ program to implement a Binary Search Tree (BST). Your program must
be able to read a list of integers (separated by space) from keyboard input and create a BST
(e.g., by inserting these numbers into the BST one by one). At the end, please print the BST that
you have created using the last function below. The node structure of your BST is as follows
*/

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
//creating nodes
struct Node {
	int key;
	struct Node* left;
	struct Node* right;
};

Node* sNode(int data)
{
    Node* temp = new Node;
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

//Tree treversal
void preorder(Node* root) {
	
	if (root != NULL) {
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node* root) {

	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

void postorder(Node* root) {

	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		cout << root->key << " ";
	}
}

//Search
Node* search(Node* root, int key) {

	if (root == NULL || root->key == key) {return root;} //if only one element
	else if (root->key < key) {return search(root->right, key);} // search right
	return search(root->left, key);//search left
}

//insert
Node* insert(Node* node, int data) {
	if (node == NULL) { return sNode(data);}
	else if (node->key > data) { node->left = insert(node->left, data); }
	else if (data > node->key) { node->right = insert(node->right, data); }
	return node;
}

//delete
Node* rightmostNode(Node* node) {
	Node* current = node;
	//loop down to find the leftmost leaf
	while (current->left != NULL)
		current = current->left; //update pointing element to lower one
	return current; //return the lowest element
}

Node* remove(Node* node, int key) {
	if (node == NULL) {
		return node;
		if (key < node-> key) { 
			node->left = remove(node->left, key); 
		}
		else if (key > node->key) { node->right = remove(node->right, key); }
	}
	else {
		if (node->left == NULL) {
			Node* temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == NULL) {
			Node* temp = node->left;
			delete node;
			return temp;
		}
		Node* temp = rightmostNode(node->right);
		node->key = temp->key;
		node->right = remove(node->right, temp->key);
	}
	return node;
}

//print
void printTree(Node* node, int space) {

	int spacer = 10;
	int i = spacer;
	if (node == NULL)
		return;

	space = spacer + space;

	printTree(node->right, space);
	cout << endl;

	while (i < space) {
		//if (node->right) { cout << " \\"; }
		//if (node->left) { cout << "/ "; }
		cout << " ";
		i++;
	}
	cout << node->key << "\n";
	printTree(node->left, space);
}

int main() {


	string nnum;
	int digt, num, nSize, searchNum, removeNum, * arry;
	vector<int> theNumberList;


	// Title for funsies!
	cout << " __               ___         " << endl;
	cout << "(_  _  _  __ _ |_  |  __ _  _ " << endl;
	cout << "__)(/_(_| | (_ | | |  | (/_(/_" << endl;
	cout << endl << endl;
	cout << "Please enter in a set of numbers seperated by a space" << endl;
	cout << "Please enter in a set of numbers seperated by a space" << endl;
	cout << "Please enter in a set of numbers seperated by a space" << endl;
	cout << "ENTER NUMBERS : ";

	getline(cin, nnum);
	cout << endl << endl;

	//nnum = "50 12 17 66 2 5 1"; //just to test so I don't have to type something in each time while testing

	//iterate through string to get rid of non-digital non-white space characters
	for (int i = 0; i < nnum.length(); i++) {
		if (nnum[i] != ' ' && !isdigit(nnum[i]))
			nnum[i] = ' ';
	}
	//cout << "you have entered: " << nnum << endl;
	stringstream strm(nnum);
		nSize = theNumberList.size();

	//function to parse string and turn them into array of numbers goes here
	cout << "you have entered the following numbers: " << endl;
	while (strm >> digt) {
		theNumberList.push_back(digt);
		cout << digt << endl;
	}

	nSize = theNumberList.size();
	arry = new int[nSize];

	Node* ki = NULL;


	for (int j = 0; j < nSize; j++ ) {
		arry[j] = theNumberList[j];
	}

	for (int k = 0; k < nSize; k++ ) {
		num = arry[k];
		ki = (insert(ki, num));
	}
	cout << "Current Tree: ";
	printTree(ki, 0);
	cout << endl;
	cout << "Preorder traversal: ";
	preorder(ki);
	cout << endl;

	cout << "Inorder traversal: ";
	inorder(ki);
	cout << endl;

	cout << "Postorder traversal: ";
	postorder(ki);
	cout << endl;

	cout << "Please enter the number you wish to search for\n";
	cout << "Search Number: ";
	cin >> searchNum;
	if (search(ki, searchNum)) { cout << searchNum << " was found"; }
	else { cout << searchNum << " is not in the tree"; }
	cout << endl;

	cout << "Please enter the number you wish to remove\n";
	cout << "Remove Number: ";
	cin >> removeNum;
	//if (search(ki, removeNum)) { cout << removeNum << " was found and will be deleted"; }
	//else { cout << removeNum << " is not in the tree"; }
	cout << removeNum << "might be removed" << "\n";
	remove(ki, removeNum);
	cout << endl;

	return 0;

}