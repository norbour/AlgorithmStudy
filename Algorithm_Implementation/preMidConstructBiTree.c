#include <stdio.h>
#include "../Data_Structure/include/binarytree.h"

int main(int argc, char *argv[]) {
	int preOrder[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int midOrder[] = {4, 7, 2, 1, 5, 3, 8 ,6};
	
	BinaryTreeNode *T = PreMidConstruct(preOrder, midOrder, 8);
	
	PreOrderTraverse(T); printf("\n");
	MidOrderTraverse(T); printf("\n");
	PostOrderTraverse(T);
}