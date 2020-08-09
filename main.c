#include "avlTree.h"
#include "stdio.h"
#include "math.h"
#include "Windows.h"

void task1();
void task2();

AvlTree gAvlTree;

static unsigned int counter = 0;
int gStateMachine = 0;
char cmd[10];
int data = 0;

int main(){
	for (;;) {
		if (gStateMachine == -1) {
			break;
		}
		task1();
	}
	system("pause");
	return 0;
}

void task1() {
	scanf_s("%d", &data);
	if (data == -1 ) {
		gStateMachine = -1;
	}
	else if (100<data ) {
		avlTree_insertByData(&gAvlTree.tree, data % 100, &gAvlTree.mError);
		avlTree_printInOrder(gAvlTree.tree);
	}
	else if (-100 > data ) {
		avlTree_removeByData(&gAvlTree.tree, (-data)%100, &gAvlTree.mError);
		avlTree_printInOrder(gAvlTree.tree);
	}
	else if (1 == data ) {
		avlTree_printInOrder(gAvlTree.tree);
	}
	else if (2 == data) {
		printf("%d\n", avlTree_isEmpty(gAvlTree.tree) );
	}
}

void task2() {
	avlTree_insertByData(&gAvlTree.tree, 5, &gAvlTree.mError);
	avlTree_insertByData(&gAvlTree.tree, 8, &gAvlTree.mError);
	avlTree_insertByData(&gAvlTree.tree, 2, &gAvlTree.mError);
	avlTree_insertByData(&gAvlTree.tree, 7, &gAvlTree.mError);
	avlTree_insertByData(&gAvlTree.tree, 9, &gAvlTree.mError);
	avlTree_removeByData(&gAvlTree.tree, 8, &gAvlTree.mError);
	avlTree_printInOrder(gAvlTree.tree);
}
