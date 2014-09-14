#include <stdio.h>
#include "../Data_Structure/include/queue.h"
#include "../Data_Structure/include/mgraph.h"

void BFSTraverse(MGraph G) {
	int i, j;
	Queue Q;
	int visited[MAXVEX];
	
	for (i = 0; i < G.numVertexes; i++) {
		visited[i] = FALSE;
	}
	
	InitQueue(&Q);
	
	for (i = 0; i < G.numVertexes; i++) {
		if(!visited[i]) {
			visited[i] = TURE;
			printf("%c ", G.vexs[i]);
			
			EnQueue(&Q, i);
			while (!QueueEmpty(&Q)) {
				DeQueue(&Q, &i);
				
				for (j = 0; j < G.numVertexes; j++) {
					if (G.arc[i][j] == 1 && !visited[j]) {
						visited[j] = TURE;
						
						printf("%c ", G.vexs[j]);
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	MGraph G;
	
	G.vexs[0] = 'a'; G.vexs[1] = 'b'; G.vexs[2] = 'c';
	G.vexs[3] = 'd'; G.vexs[4] = 'e'; G.vexs[5] = 'f';
	G.vexs[6] = 'g'; G.vexs[7] = 'h'; G.vexs[0] = 'i';
	G.arc[0] = { 0, 1, 0, 0, 0, 1, 0, 0, 0 };
	                   // { 1, 0, 1, 0, 0, 0, 1, 0, 1 },
	                   // { 0, 1, 0, 1, 0, 0, 0, 0, 1 },
	                   // { 0, 0, 1, 0, 1, 0, 1, 1, 1 },
	                   // { 0, 0, 0, 1, 0, 1, 0, 1, 0 },
	                   // { 1, 0, 0, 0, 1, 0, 1, 0, 0 },
	                   // { 0, 1, 0, 1, 0, 1, 0, 1, 0 },
	                   // { 0, 0, 0, 1, 1, 0, 1, 0, 0 },
	                   // { 0, 1, 1, 1, 0, 0, 0, 0, 0 } };

	G.numVertexes = 9;
	G.numEdges = 13;
	
	BFSTraverse(G);
}