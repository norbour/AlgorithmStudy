#ifndef SORT_H
#define SORT_H

#define LH +1
#define EH 0
#define RH -1

typedef struct BiTNode{
	int data;
	int bf;
	struct BiTNode *lchild, *rchild;
} BiTNode, *AVLTree;

void R_Rotate(AVLTree *P) {
	AVLTree L;
	L = (*P)->lchild;
	(*P)->lchild = L->rchild;
	L->rchild = (*P);
	*P =  L;
}

void L_Rotate(AVLTree *P) {
	AVLTree R;
	R = (*P)->rchild;
	(*P)->rchild = R->lchild;
	R->lchild = (*P);
	*P = R;
}

void LeftBalance(AVLTree *T) {
	AVLTree L, Lr;
	L = (*T)->lchild;
	
	switch (L->bf) {
		case LH:
			(*T)->bf = L->bf = EH;
			R_Rotate(T);
			break;
		case RH:
			Lr = L->rchild;
			switch (Lr->bf) {
				case LH: (*T)->bf = RH;
					L->bf = EH;
					break;
				case EH: (*T)->bf = L->bf = EH;
					break;
				case RH: (*T)->bf = EH;
					L->bf = LH;
					break;
				default:
					break;
			}
			Lr->bf = EH;
			L_Rotate(&(*T)->lchild);
			R_Rotate(T);
		default:
			break;
	}
}

void RightBalance(AVLTree *T) {
	AVLTree R, Rl;
	R = (*T)->rchild;
	
	switch (R->bf) {
		case RH:
			(*T)->bf = R->bf = EH;
			L_Rotate(T);
			break;
		case LH:
			Rl = R->lchid;
			switch (Rl-bf) {
				case RH: (*T)->bf = LH;
					R->br = EH;
					break;
				case EH: (*T)->bf = R->bf = EH;
					break;
				case LH: (*T)->bf = EH;
					R->bf = RH;
					break;
				default:
					break;
			}
			Rl->bf = EH;
			R_Rotate(&(*T)->rchild);
			L_Rotate(T);
		default:
			break;
	}
}

#endif