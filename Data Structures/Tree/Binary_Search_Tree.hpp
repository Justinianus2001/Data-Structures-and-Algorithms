#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
using namespace std;

typedef struct BinarySearchTree{
	int data;
	struct BinarySearchTree *left, *right;
	
	BinarySearchTree* InitRoot(){
		BinarySearchTree *root = NULL;
		return root;
	}
	
	BinarySearchTree* CreateNode(int val){
		BinarySearchTree *q = new BinarySearchTree;
		q->data = val, q->left = q->right = NULL;
		return q;
	}
	
	void DeleteNode(BinarySearchTree *root){
		if(root != NULL){
			DeleteNode(root->left),
			DeleteNode(root->right),
			delete root;
		}
	}
	
	bool IsLeftOfNode(BinarySearchTree *root, int val){
		return val <= root->data;
	}
	
	bool IsRightOfNode(BinarySearchTree *root, int val){
		return val > root->data;
	}
	
	void AddNode(BinarySearchTree *&root, int val){
		if(root == NULL)
			root = CreateNode(val);
		else if(IsLeftOfNode(root, val))
			AddNode(root->left, val);
		else if(IsRightOfNode(root, val))
			AddNode(root->right, val);
	}
	
	bool Search(BinarySearchTree *root, int val){
		if(root == NULL)
			return false;
		if(root->data == val)
			return true;
		if(IsLeftOfNode(root, val))
			return Search(root->left, val);
		if(IsRightOfNode(root, val))
			return Search(root->right, val);
	}
	
	int LeftMostValue(BinarySearchTree *root){
		if(root->left != NULL)
			return LeftMostValue(root->left);
		return root->data;
	}
	
	int RightMostValue(BinarySearchTree *root){
		if(root->right != NULL)
			return RightMostValue(root->right);
		return root->data;
	}
	
	void DeleteByValue(BinarySearchTree *&root, int val){
		if(root != NULL){
			if(root->data == val){
				if(root->left == NULL){
					BinarySearchTree *q = root;
					root = root->right;
					delete q;
				}
				else if(root->right == NULL){
					BinarySearchTree *q = root;
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
	
	void PreOrder(BinarySearchTree *root){
		if(root != NULL){
			cout << root->data << ' ';
			PreOrder(root->left),
			PreOrder(root->right);
		}
	}
	
	void InOrder(BinarySearchTree *root){
		if(root != NULL){
			InOrder(root->left);
			cout << root->data << ' ';
			InOrder(root->right);
		}
	}
	
	void PostOrder(BinarySearchTree *root){
		if(root != NULL){
			PostOrder(root->left),
			PostOrder(root->right);
			cout << root->data << ' ';
		}
	}
	
	int Depth(BinarySearchTree *root){
		if(root == NULL)
			return 0;
		else
			return max(Depth(root->left), Depth(root->right)) + 1;
	}
	
	void Input(BinarySearchTree *&root){
		root = InitRoot();
		int n, val;
		cin >> n;
		for(int i = 0; i < n; i ++){
			cin >> val;
			AddNode(root, val);
		}
	}
}BSNode;

#endif
