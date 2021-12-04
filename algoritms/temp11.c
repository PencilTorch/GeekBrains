#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1==1
#define false 1!=1
#define __max(a,b)  (((a) > (b)) ? (a) : (b))
typedef int bool;
FILE *file;

typedef struct Node {
	int key;
	struct Node *left;
	struct Node *right;
} TreeNode;

TreeNode* addNode(TreeNode *t, int data) {
	TreeNode *newNode = (TreeNode*) malloc(sizeof(TreeNode));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	TreeNode *pCurrent = t;
	TreeNode *pParent = t;
	if(t == NULL){
		t = newNode;
	} else {
		while(pCurrent->key != data){
			pParent = pCurrent;
			if(pCurrent->key > data){
				pCurrent = pCurrent->left;
				if(pCurrent == NULL){
					pParent->left = newNode;
					return t;
				}
			} else{
				pCurrent = pCurrent->right;
				if(pCurrent == NULL){
					pParent->right = newNode;
					return t;
				}
			}
		}
	}
	return t;
}

TreeNode* getSuccesor(TreeNode *node) {
	TreeNode *pThis = node->right;
	TreeNode *pParent = node;
	TreeNode *pBest = node;
	while(pThis != NULL){
		pParent = pBest;
		pBest = pThis;
		pThis = pThis->left;
	}
	if(pBest != node->right){
		pParent->left = pBest->right;
		pBest->right = node->right;
	}
	return pBest;
}

bool treeDel(TreeNode *root, int key) {
	TreeNode *pCurrent = root;
	TreeNode *pParent = root;
	bool leftChild = true;
	while(pCurrent->key != key){
		pParent = pCurrent;
		if(key <pCurrent->key){
			pCurrent = pCurrent->left;
			leftChild = true;
		} else{
			pCurrent = pCurrent->right;
			leftChild = false;
		}
		if(pCurrent == NULL)
			return false;
	}
	if(pCurrent->left == NULL && pCurrent->right == NULL){
		if(pCurrent == root)
			root == NULL;
		else if(leftChild)
			pParent->left = NULL;
		else
			pParent->right = NULL;
	}
	else if(pCurrent->right == NULL){
		if(leftChild)
			pParent->left = pCurrent->left;
		else
			pParent->right = pCurrent->left;
	}
	else if(pCurrent->left == NULL){
		if(leftChild)
			pParent->left = pCurrent->right;
		else
			pParent->right = pCurrent->right;
	}
	else{
		TreeNode *pSuccessor = getSuccesor(pCurrent);
		if(pCurrent == root)
			root = pSuccessor;
		else if(leftChild)
			pParent->left = pSuccessor;
		else
			pParent->right = pSuccessor;
	pSuccessor->left = pCurrent->left;
	}
	return true;
}

TreeNode* balancedTree(int n) {
	TreeNode *newNode;
	int x;
	int nL;
	int nR;
	if(n == 0){
		newNode = NULL;
		return newNode;
	} else {
		fscanf(file, "%d", &x);
		nL = n/2;
		nR = n - nL - 1;
		newNode = (TreeNode*) malloc(sizeof(TreeNode));
		newNode->key = x;
		newNode->left = balancedTree(nL);
		newNode->right = balancedTree(nR);
	}
	return newNode;
}

bool binSearch(TreeNode *root, int value) {
	if(root == NULL)
		return false;
	if(root->key == value)
		return true;
	TreeNode *pCurrent = root;
	while(pCurrent->key != value){
		if(value < pCurrent->key)
			pCurrent = pCurrent->left;
		else
			pCurrent = pCurrent->right;
		
		if(pCurrent == NULL)
			return false;
	}
}

int checkTreeDeep(TreeNode *tree) {
	if(tree== NULL)
		return 0;
	int deepLeft = checkTreeDeep(tree->left);
	if(deepLeft == -1)
		return -1;
	int deepRight = checkTreeDeep(tree->right);
	if(deepRight == -1)
		return -1;
	int deepDif = abs(deepLeft - deepRight);
	if(deepDif > 1)
		return -1;
	else
		return __max(deepLeft, deepRight) + 1;
		
}

bool checkBalanceTree(TreeNode *tree) {
	if(checkTreeDeep(tree) == -1)
		return false;
	else
		return true;
}

void printTree(TreeNode *root) {
	if(root){
		printf("%d", root->key);
		if(root->left || root->right){
			printf("(");
			if(root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");
			if(root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

int main() {
    
    TreeNode *tree = NULL;
    /*
    file = fopen("balance.txt", "r");
    if(file == NULL){
    	printf("%s \n", "Can not open file");
    	return 1;
	}
    const int count = 15;
    tree = balancedTree(count);
    fclose(file);
    printTree(tree);
    */
    
	tree = addNode(tree, 7);
	addNode(tree, 3);
	addNode(tree, 2);
	addNode(tree, 1);
	addNode(tree, 9);
	addNode(tree, 5);
	addNode(tree, 4);
	addNode(tree, 6);
	addNode(tree, 8);
	//addNode(tree, 0);
	
	printTree(tree);
	printf(" \n");
	
	printf("8 in tree = %s \n", binSearch(tree, 8)? "true" : "false");
	printf("15 in tree = %s \n", binSearch(tree, 15)? "true" : "false");
	printf(" \n");
	printf("tree balanced = %s \n", checkBalanceTree(tree)? "true" : "false");
	printf(" \n");
	

	

    return 0;
}
