/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int inorder_helper(struct node *root, int *arr, int ind){
	if (root->left != NULL)
		ind = inorder_helper(root->left, arr, ind);

	arr[ind++] = root->data;

	if(root->right != NULL)
		ind = inorder_helper(root->right, arr, ind);

	return ind;
}

void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;

	inorder_helper(root, arr, 0);
}

int preorder_helper(struct node *root, int *arr, int ind){
	
	arr[ind++] = root->data;

	if(root->left != NULL)
		ind = preorder_helper(root->left, arr, ind);

	if (root->right != NULL)
		ind = preorder_helper(root->right, arr, ind);

	return ind;
}

void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;

	preorder_helper(root, arr, 0);
}

int postorder_helper(struct node *root, int *arr, int ind){
	if (root->left != NULL)
		ind = postorder_helper(root->left, arr, ind);

	if (root->right != NULL)
		ind = postorder_helper(root->right, arr, ind);

	arr[ind++] = root->data;

	return ind;
}

void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;

	postorder_helper(root, arr, 0);
}

