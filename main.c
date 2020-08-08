#include "avlTree.h"

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

	avlTree_insertData(&gAvlTree.tree, 10, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 11, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 12, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 15, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 14, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 13, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 19, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 17, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 18, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 18, &gAvlTree.mError);
	avlTree_insertData(&gAvlTree.tree, 18, &gAvlTree.mError);

	avlTree_printInOrder(gAvlTree.tree);
	system("pause");
	return 0;
}
