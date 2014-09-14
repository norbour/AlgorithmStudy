#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MAXSIZE 100

#define TURE 1
#define FALSE 0
#define ERROR -1

typedef int QElemType;

typedef struct {
	QElemType data[MAXSIZE];
	int front;
	int rear;
} Queue;

int InitQueue(Queue *Q) {
	Q->front = 0;
	Q->rear = 0;
	return TURE;
}

int QueueLength(Queue Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

int QueueEmpty(const Queue *Q) {
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return TURE;
	return FALSE;
}

int EnQueue(Queue *Q, QElemType e) {
	if (QueueEmpty(Q))
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	
	return TURE;
}

int DeQueue(Queue *Q, QElemType *e) {
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	
	return TURE;
}

#endif