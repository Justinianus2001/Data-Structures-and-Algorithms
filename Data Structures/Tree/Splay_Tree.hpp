#ifndef SPLAY_TREE_HPP
#define SPLAY_TREE_HPP

#include <iostream>
using namespace std;

typedef struct SplayTree{
	int data;
	struct SplayTree *left, *right, *parent;
	
	SplayTree* InitRoot(){
		SplayTree *root = NULL;
		return root;
	}
	
	SplayTree* CreateNode(int val){
		SplayTree *q = new SplayTree;
		q->data = val, q->left = q->right = q->parent = NULL;
		return q;
	}
	
	void DeleteNode(SplayTree *root){
		if(root != NULL){
			DeleteNode(root->left),
			DeleteNode(root->right),
			delete root;
		}
	}
	
	bool IsLeftOfNode(SplayTree *root, int val){
		return val <= root->data;
	}
	
	bool IsRightOfNode(SplayTree *root, int val){
		return val > root->data;
	}
	
	int LeftMostValue(SplayTree *root){
		if(root->left != NULL)
			return LeftMostValue(root->left);
		return root->data;
	}
	
	int RightMostValue(SplayTree *root){
		if(root->right != NULL)
			return RightMostValue(root->right);
		return root->data;
	}
	
	void LeftRotate(SplayTree *&x){
		SplayTree *w = x->parent, *y = x->right, *z = y->left;
		if(w != NULL){
			if(w->left != NULL)
				w->left = y;
			else
				w->right = y;
		}
		if(z != NULL)	z->parent = x;
		x->right = z, y->left = x, y->parent = w, x->parent = y;
	}
	
	void RightRotate(SplayTree *&y){
		SplayTree *w = y->parent, *x = y->left, *z = x->right;
		if(w != NULL){
			if(w->left != NULL)
				w->left = x;
			else
				w->right = x;
		}
		if(z != NULL)	z->parent = y;
		y->left = z, x->parent = w, x->right = y, y->parent = x;
	}
	
	void LeftZigZag(SplayTree *&z){
		SplayTree *y = z->left;
		LeftRotate(y), RightRotate(z);
	}
	
	void RightZigZag(SplayTree *&z){
		SplayTree *y = z->right;
		RightRotate(y), LeftRotate(z);
	}
	
	void LeftRollerCoaster(SplayTree *&x){
		SplayTree *y = x->right;
		LeftRotate(x), LeftRotate(y);
	}
	
	void RightRollerCoaster(SplayTree *&z){
		SplayTree *y = z->left;
		RightRotate(z), RightRotate(y);
	}
	
	void Splay(SplayTree *&x){
		if(x->parent != NULL){
			SplayTree *y = x->parent, *z = y->parent;
			if(z == NULL){
				if(y->right != NULL)
					LeftRotate(y);
				else
					RightRotate(y);
			}
			else{
				if(z->left != NULL){
					if(y->left != NULL)
						RightRollerCoaster(z);
					else
						LeftZigZag(z);
				}
				else{
					if(y->right != NULL)
						LeftRollerCoaster(z);
					else
						RightZigZag(z);
				}
			}
			Splay(x);
		}
	}
	
	bool Search(SplayTree *&root, int val){
		if(root != NULL){
			SplayTree *x = SearchNotSplay(root, val);
			Splay(x), root = x;
			return root->data == val;
		}
		return false;
	}
	
	SplayTree* SearchNotSplay(SplayTree *root, int val){
		if(root != NULL){
			if(root->data == val)
				return root;
			else if(root->data < val){
				if(root->right == NULL)
					return root;
				else
					return SearchNotSplay(root->right, val);
			}
			else{
				if(root->left == NULL)
					return root;
				else
					return SearchNotSplay(root->left, val);
			}
		}
		return NULL;
	}
	
	void Insert(SplayTree *&root, int val){
		if(root != NULL){
			SplayTree *x = InsertNotSplay(root, val);
			Splay(x), root = x;
		}
		else
			root = CreateNode(val);
	}
	
	SplayTree* InsertNotSplay(SplayTree *&root, int val){
		if(root->data < val){
			if(root->right == NULL){
				SplayTree *x = CreateNode(val);
				root->right = x, x->parent = root;
				return x;
			}
			else
				return InsertNotSplay(root->right, val);
		}
		else{
			if(root->left == NULL){
				SplayTree *x = CreateNode(val);
				root->left = x, x->parent = root;
				return x;
			}
			else
				return InsertNotSplay(root->left, val);
		}
	}
	
	void DeleteByValue(SplayTree *&root, int val){
		while(Search(root, val)){
			SplayTree *x = root->left, *q = root;
			if(x != NULL){
				x->parent = NULL;
				if(x->right != NULL){
					SplayTree *y = x->right;
					while(y->right != NULL)		y = y->right;
					Splay(y), y->right = root->right;
					if(root->right != NULL)		root->right->parent = y;
					q = root, root = y;
				}
				else{
					x->right = root->right;
					if(root->right != NULL)		root->right->parent = x;
					q = root, root = x;
				}
			}
			else
				root = root->right, root->parent = NULL;
			delete q;
		}
	}
	
	void PreOrder(SplayTree *root){
		if(root != NULL){
			cout << root->data << ' ';
			PreOrder(root->left),
			PreOrder(root->right);
		}
	}
	
	void InOrder(SplayTree *root){
		if(root != NULL){
			InOrder(root->left);
			cout << root->data << ' ';
			InOrder(root->right);
		}
	}
	
	void PostOrder(SplayTree *root){
		if(root != NULL){
			PostOrder(root->left),
			PostOrder(root->right);
			cout << root->data << ' ';
		}
	}
	
	void Input(SplayTree *&root){
		root = InitRoot();
		int n, val;
		cin >> n;
		for(int i = 0; i < n; i ++){
			cin >> val;
			Insert(root, val);
		}
	}
}SplayNode;

#endif
