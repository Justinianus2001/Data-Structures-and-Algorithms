#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

typedef struct BinarySearchTree{
	int data;
	struct BinarySearchTree *left, *right;
}TreeNode;

TreeNode* InitRoot(){
	TreeNode *root = NULL;
	return root;
}

TreeNode* CreateNode(int val){
	TreeNode *q = new TreeNode;
	q->data = val, q->left = q->right = NULL;
	return q;
}

void DeleteNode(TreeNode *root){
	if(root != NULL){
		DeleteNode(root->left),
		DeleteNode(root->right),
		delete root;
	}
}

bool IsLeftOfNode(TreeNode *root, int val){
	return val <= root->data;
}

bool IsRightOfNode(TreeNode *root, int val){
	return val > root->data;
}

void AddNode(TreeNode *&root, int val){
	if(root == NULL)
		root = CreateNode(val);
	else if(IsLeftOfNode(root, val))
		AddNode(root->left, val);
	else if(IsRightOfNode(root, val))
		AddNode(root->right, val);
}

bool Search(TreeNode *root, int val){
	if(root == NULL)
		return false;
	if(root->data == val)
		return true;
	if(IsLeftOfNode(root, val))
		return Search(root->left, val);
	if(IsRightOfNode(root, val))
		return Search(root->right, val);
}

int LeftMostValue(TreeNode *root){
	if(root->left != NULL)
		return LeftMostValue(root->left);
	return root->data;
}

int RightMostValue(TreeNode *root){
	if(root->right != NULL)
		return RightMostValue(root->right);
	return root->data;
}

void DeleteByValue(TreeNode *&root, int val){
	if(root != NULL){
		if(root->data == val){
			if(root->left == NULL){
				TreeNode *q = root;
				root = root->right;
				delete q;
			}
			else if(root->right == NULL){
				TreeNode *q = root;
				root = root->left;
				delete q;
			}
			else{
				root->data = RightMostValue(root->left),
				DeleteByValue(root->left, root->data);
			}
		}
		if(IsLeftOfNode(root, val))
			DeleteByValue(root->left, val);
		if(IsRightOfNode(root, val))
			DeleteByValue(root->right, val);
	}
}

void PreOrder(TreeNode *root){
	if(root != NULL){
		cout << root->data << ' ';
		PreOrder(root->left),
		PreOrder(root->right);
	}
}

void InOrder(TreeNode *root){
	if(root != NULL){
		InOrder(root->left);
		cout << root->data << ' ';
		InOrder(root->right);
	}
}

void PostOrder(TreeNode *root){
	if(root != NULL){
		PostOrder(root->left),
		PostOrder(root->right);
		cout << root->data << ' ';
	}
}

int Depth(TreeNode *root){
	if(root == NULL)
		return 0;
	else
		return max(Depth(root->left), Depth(root->right)) + 1;
}

void Input(TreeNode *&root){
	root = InitRoot();
	int n, val;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> val;
		AddNode(root, val);
	}
}

#endif
