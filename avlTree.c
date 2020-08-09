#include "avlTree.h"
#include "stdio.h"
#include "stdlib.h"

static const unsigned char allowedImbalance = 1;

void avlTree_insertByData(AvlNode** ppHead, unsigned int data, unsigned char* pError){
	if( !(ppHead) ){
		(*pError)++;
		return;
	}
	AvlNode* pNode = (AvlNode*)malloc( sizeof(AvlNode) );
	if( !pNode ){
		(*pError)++;
		return;
	}
	pNode->mData = data;
	pNode->left = null;
	pNode->right = null;
	pNode->mHeight = 0;
	avlTree_insertByNode(ppHead, pNode, pError);
}

void avlTree_removeByData(AvlNode** ppHead, unsigned int data, unsigned char* pError) {
	if (!(*ppHead) ) {
		(*pError)++;
		return;
	}
	if (data < (*ppHead)->mData) {
		avlTree_removeByData(&(*ppHead)->left, data, pError);
	}
	else if (data > (*ppHead)->mData) {
		avlTree_removeByData(&(*ppHead)->right, data, pError);
	}
	else {
		avlTree_removeByNode(ppHead, *ppHead, pError);
	}
	avlTree_balance(ppHead, pError);
}

AvlNode* avlTree_findByData(AvlNode* head, unsigned int data) {
	if (!head) {
		return null;
	}
	if (data < head->mData) {
		return avlTree_findByData(head->left, data);
	}
	else if (data > head->mData) {
		return avlTree_findByData(head->right, data);
	}
	else {
		return head;
	}
}

void avlTree_insertByNode(AvlNode** ppHead, AvlNode* dataNode, unsigned char* pError) {
	if (!dataNode || !ppHead) {
		(*pError)++;
		return;
	}
	if (!(*ppHead)) {
		*ppHead = dataNode;
	}
	else if (dataNode->mData < (*ppHead)->mData) {
		avlTree_insertByNode(&(*ppHead)->left, dataNode, pError);
	}
	else if (dataNode->mData > (*ppHead)->mData) {
		avlTree_insertByNode(&(*ppHead)->right, dataNode, pError);
	}
	else {
		// node with same id found.
	}
	avlTree_balance(ppHead, pError);
}

void avlTree_removeByNode(AvlNode** ppHead, AvlNode* dataNode, unsigned char* pError){
	if( !(*ppHead) || !dataNode ){
		(*pError)++;
		return;
	}
	if( dataNode->mData < (*ppHead)->mData ){
		avlTree_removeByNode( &(*ppHead)->left, dataNode, pError);
	}
	else if( dataNode->mData > (*ppHead)->mData ){
		avlTree_removeByNode( &(*ppHead)->right, dataNode, pError);
	}
	else{
		if( (*ppHead)->left && (*ppHead)->right ){
			AvlNode* pNodeMin = avlTree_findMin( (*ppHead)->right );
			(*ppHead)->mData = pNodeMin->mData;
			avlTree_removeByNode( &(*ppHead)->right, pNodeMin, pError);
		}
		else{
			// one child or no child.
			AvlNode* pNodeToBeRemoved = (*ppHead);
			//ppHead = &( (*ppHead)->left? (*ppHead)->left:(*ppHead)->right );
			if( (*ppHead)->left ){
				*ppHead = (*ppHead)->left;
			}
			else{
				*ppHead = (*ppHead)->right;
			}
			free(pNodeToBeRemoved);
		}
	}
	avlTree_balance(ppHead, pError);
}

char avlTree_height(AvlNode* head){
	if( !head ){
		return -1;
	}
	return head->mHeight;
}

void avlTree_balance(AvlNode** ppHead, unsigned char* pError){
	if( !ppHead || !(*ppHead) ){
		(*pError)++;
		return;
	}
	if( avlTree_height((*ppHead)->left) - avlTree_height((*ppHead)->right) > allowedImbalance ){
		if( avlTree_height((*ppHead)->left->left) >= avlTree_height((*ppHead)->left->right) ){
			avlTree_rotateWithLeftChild( ppHead );
		}
		else{
			avlTree_doubleRotateWithLeftChild( ppHead );
		}
	}
	else if( avlTree_height((*ppHead)->right) - avlTree_height((*ppHead)->left) > allowedImbalance ){
		if( avlTree_height((*ppHead)->right->right) >= avlTree_height((*ppHead)->right->left) ){
			avlTree_rotateWithRightChild( ppHead );
		}
		else{
			avlTree_doubleRotateWithRightChild( ppHead );
		}
	}
	(*ppHead)->mHeight = avlTree_max( avlTree_height((*ppHead)->left), avlTree_height((*ppHead)->right) ) + 1;
}

void avlTree_rotateWithLeftChild(AvlNode** ppHead){
	if( !ppHead || !(*ppHead) ){
		return;
	}
	AvlNode* newHead = (*ppHead)->left;
	(*ppHead)->left = newHead->right;
	newHead->right = (*ppHead);
	(*ppHead)->mHeight = 1 + avlTree_max( avlTree_height((*ppHead)->left), avlTree_height((*ppHead)->right) );
	newHead->mHeight = 1 + avlTree_max( avlTree_height(newHead->left), avlTree_height(newHead->right) );
	*ppHead = newHead;
}

void avlTree_rotateWithRightChild(AvlNode** ppHead){
	if( !ppHead || !(*ppHead) ){
		return;
	}
	AvlNode* newHead = (*ppHead)->right;
	(*ppHead)->right = newHead->left;
	newHead->left = (*ppHead);
	// update mHeight here.
	(*ppHead)->mHeight = 1 + avlTree_max( avlTree_height((*ppHead)->left), avlTree_height((*ppHead)->right) );
	newHead->mHeight = 1 + avlTree_max( avlTree_height(newHead->left), avlTree_height(newHead->right) );
	*ppHead = newHead;
}

void avlTree_doubleRotateWithLeftChild(AvlNode** ppHead){
	avlTree_rotateWithRightChild( &(*ppHead)->left );
	avlTree_rotateWithLeftChild( ppHead );
}

void avlTree_doubleRotateWithRightChild(AvlNode** ppHead){
	avlTree_rotateWithLeftChild( &(*ppHead)->right );
	avlTree_rotateWithRightChild( ppHead );
}

AvlNode* avlTree_findMin(AvlNode* head){
	if( !head ){
		return null;
	}
	AvlNode* tempHead = head;
	while( tempHead->left ){
		tempHead = tempHead->left;
	}
	return tempHead;
}

AvlNode* avlTree_findMax(AvlNode* head){
	if( !head ){
		return null;
	}
	AvlNode* tempHead = head;
	while( tempHead->right ){
		tempHead = tempHead->right;
	}
	return tempHead;
}

bool avlTree_findByNode(AvlNode* head, AvlNode* dataNode) {
	if (!head || !dataNode) {
		return false;
	}
	if (dataNode->mData < head->mData) {
		return avlTree_findByNode(head->left, dataNode);
	}
	else if (dataNode->mData > head->mData) {
		return avlTree_findByNode(head->right, dataNode);
	}
	else {
		return true;
	}
}

void avlTree_makeEmpty(AvlNode** ppHead) {

}

bool avlTree_isEmpty(AvlNode* head) {
	return head ? false : true;
}

void avlTree_printInOrder(AvlNode* head){
	if( !head ){
		return;
	}
	avlTree_printInOrder( head->left );
	printf("%d->", head->mData);
	avlTree_printInOrder( head->right );
}

void avlTree_printPreOrder(AvlNode* head){
	if( !head ){
		return;
	}
	printf("%d->", head->mData);
	avlTree_printInOrder( head->left );
	avlTree_printInOrder( head->right );
}

void avlTree_printPostOrder(AvlNode* head){
	if( !head ){
		return;
	}
	avlTree_printInOrder( head->left );
	avlTree_printInOrder( head->right );
	printf("%d->", head->mData);
}

char avlTree_max(char x, char y) {
	return x >= y ? x : y;
}

