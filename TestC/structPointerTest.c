#include <stdio.h>

typedef struct Node {
	int value;
	struct Node *ptr;
};

void ChangeNode(struct Node *node){
	node->value++;
}

int main(int argc, char *argv[]) {
	struct Node node1;
	struct Node node2;
	
	node1.value = 11;
	node2.value = 12;
	
	node1.ptr = &node2;
	node2.ptr = &node1;
	
	printf("node1 : %d, %d\n", node1.value, node1.ptr->value);
	
	ChangeNode(node2.ptr);
	printf("node1 : %d, %d\n", node1.value, node1.ptr->value);
}