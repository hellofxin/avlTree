#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef unsigned char bool;
#define false		0
#define true		1

#define null  		( (void*)0 )


typedef struct avlNode{
	unsigned int mData;
	struct avlNode* left;
	struct avlNode* right;
	char mHeight;
}AvlNode;

typedef struct avlTree{
	AvlNode* tree;
	char mError;
}AvlTree;

void avlTree_makeEmpty(AvlNode* head);
bool avlTree_isEmpty(AvlNode* head);
bool avlTree_isContaining(AvlNode* head, AvlNode* dataNode);

void avlTree_insertData(AvlNode** ppHead, unsigned int data, unsigned char* pError);
void avlTree_insert(AvlNode** ppHead, AvlNode* dataNode, unsigned char* pError);
void avlTree_remove(AvlNode** ppHead, AvlNode* dataNode, unsigned char* pError);
char avlTree_height(AvlNode* head);
void avlTree_balance(AvlNode** ppHead, unsigned char* pError);
void avlTree_rotateWithLeftChild(AvlNode** ppHead);
void avlTree_rotateWithRightChild(AvlNode** head);
void avlTree_doubleRotateWithLeftChild(AvlNode** ppHead);
void avlTree_doubleRotateWithRightChild(AvlNode** head);
AvlNode* avlTree_findMin(AvlNode* head);
AvlNode* avlTree_findMax(AvlNode* Head);
void avlTree_printInOrder(AvlNode* head);
void avlTree_printPreOrder(AvlNode* head);
void avlTree_printPostOrder(AvlNode* head);
char max(char x, char y);

#endif
