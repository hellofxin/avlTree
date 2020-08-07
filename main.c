#include "avlTree.h"
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

AvlTree gAvlTree;

int main(){
	avlTree_insertData(&gAvlTree.tree, 5, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 8, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 2, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 6, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 4, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 1, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 3, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 7, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 9, &gAvlTree.mError);

	avlTree_printInOrder(gAvlTree.tree);
	return 0;
}
