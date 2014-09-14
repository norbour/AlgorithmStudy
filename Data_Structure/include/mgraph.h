#ifndef _MGRAPH_H_
#define _MGRAPH_H_

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 9
#define INFINITY 65535

typedef struct {
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
} MGraph;

#endif