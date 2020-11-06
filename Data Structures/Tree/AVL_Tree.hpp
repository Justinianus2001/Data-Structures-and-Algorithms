#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>
using namespace std;

typedef struct AVLTree{
	int data, height;
	struct AVLTree *left, *right;
	
	AVLTree* InitRoot(){
		AVLTree *root = NULL;
		return root;
	}
	
	AVLTree* CreateNode(int val){
		AVLTree *q = new AVLTree;
		q->data = val, q->height = 1, q->left = q->right = NULL;
		return q;
	}
	
	int HeightNode(AVLTree *root){
		return root == NULL ? 0 : root->height;
	}
	
	int GetBalanceFactor(AVLTree *root){
		return root == NULL ? 0 : HeightNode(root->left) - HeightNode(root->right);
	}
	
	void LeftRotate(AVLTree *&x){
		AVLTree *y = x->right, *z = y->right;
		swap(x->data, y->data), x->right = z, y->right = y->left, y->left = x->left, x->left = y,
		x->height = max(HeightNode(x->left), HeightNode(x->right)) + 1,
		y->height = max(HeightNode(y->left), HeightNode(y->right)) + 1;
	}
	
	void RightRotate(AVLTree *&x){
		AVLTree *y = x->left, *z = y->left;
		swap(x->data, y->data), x->left = z, y->left = y->right, y->right = x->right, x->right = y,
		x->height = max(HeightNode(x->left), HeightNode(x->right)) + 1,
		y->height = max(HeightNode(y->left), HeightNode(y->right)) + 1;
	}
	
	void DeleteNode(AVLTree *root){
		if(root != NULL){
			DeleteNode(root->left),
			DeleteNode(root->right),
			delete root;
		}
	}
	
	bool IsLeftOfNode(AVLTree *root, int val){
		return val <= root->data;
	}
	
	bool IsRightOfNode(AVLTree *root, int val){
		return val > root->data;
	}
	
	void AddNode(AVLTree *&root, int val){
		if(root == NULL){
			root = CreateNode(val);
			return void();
		}
		else if(IsLeftOfNode(root, val))
			AddNode(root->left, val);
		else if(IsRightOfNode(root, val))
			AddNode(root->right, val);
		root->height = max(HeightNode(root->left), HeightNode(root->right)) + 1;
		int balance = GetBalanceFactor(root);
		if(balance < -1 && val > root->right->data)
			LeftRotate(root);
		if(balance > 1 && val < root->left->data)
			RightRotate(root);
		if(balance > 1 && val > root->left->data)
			LeftRotate(root->left), RightRotate(root);
		if(balance < -1 && val < root->right->data)
			RightRotate(root->right), LeftRotate(root);
	}
	
	bool Search(AVLTree *root, int val){
		if(root == NULL)
			return false;
		if(root->data == val)
			return true;
		if(IsLeftOfNode(root, val))
			return Search(root->left, val);
		if(IsRightOfNode(root, val))
			return Search(root->right, val);
	}
	
	int LeftMostValue(AVLTree *root){
		if(root->left != NULL)
			return LeftMostValue(root->left);
		return root->data;
	}
	
	int RightMostValue(AVLTree *root){
		if(root->right != NULL)
			return RightMostValue(root->right);
		return root->data;
	}
	
	void DeleteByValue(AVLTree *&root, int val){
		if(root != NULL){
			if(root->data == val){
				if(root->left == NULL){
					AVLTree *q = root;
					root = root->right;
					delete q;
				}
				else if(root->right == NULL){
					AVLTree *q = root;
					root = root->left;
					delete q;
				}
				else{
					root->data = RightMostValue(root->left),
					DeleteByValue(root->left, root->data);
				}
				return void();
			}
			if(IsLeftOfNode(root, val))
				DeleteByValue(root->left, val);
			if(IsRightOfNode(root, val))
				DeleteByValue(root->right, val);
			root->height = max(HeightNode(root->left), HeightNode(root->right)) + 1;
			int balance = GetBalanceFactor(root);
			if(balance < -1 && GetBalanceFactor(root->right) <= 0)
				LeftRotate(root);
			if(balance > 1 && GetBalanceFactor(root->left) >= 0)
				RightRotate(root);
			if(balance > 1 && GetBalanceFactor(root->left) < 0)
				LeftRotate(root->left), RightRotate(root);
			if(balance < -1 && GetBalanceFactor(root->right) > 0)
				RightRotate(root->right), LeftRotate(root);
		}
	}
	
	void PreOrder(AVLTree *root){
		if(root != NULL){
			cout << root->data << ' ';
			PreOrder(root->left),
			PreOrder(root->right);
		}
	}
	
	void InOrder(AVLTree *root){
		if(root != NULL){
			InOrder(root->left);
			cout << root->data << ' ';
			InOrder(root->right);
		}
	}
	
	void PostOrder(AVLTree *root){
		if(root != NULL){
			PostOrder(root->left),
			PostOrder(root->right);
			cout << root->data << ' ';
		}
	}
	
	void Input(AVLTree *&root){
		root = InitRoot();
		int n, val;
		cin >> n;
		for(int i = 0; i < n; i ++){
			cin >> val;
			AddNode(root, val);
		}
	}
}AVLNode;

#endif
