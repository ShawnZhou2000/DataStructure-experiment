#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MaxVertexNum 100
using namespace std;
typedef struct {
	char vexs[MaxVertexNum];
	int edges[MaxVertexNum][MaxVertexNum];
	int n, e;
}MGraph;

void CreateMGrpah(MGraph* g) {
	char a;
	cout << "Input VertexNum(n) and EdgesNum(e):";
	cin >> g->n >> g->e;
	cout << "Input Vertex String:";
	for (int i = 0; i < g->n; i++) {
		cin >> a;
		g->vexs[i] = a;
	}
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			g->edges[i][j] = 0;
		}
	}
	cout << "Input edges, Creat Adjacency Matrix." << endl;
	for (int k = 0; k < g->e; k++) {
		int i, j;
		cin >> i >> j;
		g->edges[i][j] = 1;
		g->edges[j][i] = 1;
	}
}

bool visited[MaxVertexNum];

void dfsm(MGraph* g, int i) {
	cout << g->vexs[i];
	visited[i] = true;
	for (int j = 0; j < g->n; j++) {
		if (g->edges[i][j] && !visited[j])
			dfsm(g, j);
	}
}

void dfs(MGraph* g) {
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < g->n; i++) {
		//cout << "----debug " <<i << endl;
		if (!visited[i])
			dfsm(g, i);
	}
}

void bfs(MGraph* g, int k) {
	int f = 0, r = 0;
	int i;
	int cq[MaxVertexNum];
	memset(visited, 0, sizeof(visited));
	for (i = 0; i <= g->n; i++) {
		cq[i] = -1;
	}
	cout << g->vexs[k];
	visited[k] = true;
	cq[r] = k;
	while (cq[f] != -1) {
		i = cq[f];
		f++;
		for (int j = 0; j < g->n; j++) {
			if (g->edges[i][j] && !visited[j]) {
				cout << g->vexs[j];
				visited[j] = true;
				r++;
				cq[r] = j;
			}
		}
	}
}

int main() {
	MGraph* g;
	g = (MGraph*)malloc(sizeof(MGraph));
	CreateMGrpah(g);
	cout << "Print Graph DFS:";
	dfs(g);
	cout << "\nPrint Graph BFS:";
	bfs(g, 3);
	cout << endl;
	system("pause");
	return 0;
	
}