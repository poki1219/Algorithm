#include	<iostream>
#include	<vector>
#include	<algorithm>

class Edge{
public:
	int u;
	int v;
	int w;

	Edge(int u, int v, int w)
		:u(u), v(v), w(w) {}
};


bool compare(Edge& a, Edge& b){
	return a.w < b.w;
}

int findSet(int*& parent, int node){
	while(node != parent[node])
		node = parent[node];
	return node;
}

void unionParent(int*& parent, int u, int v){
	int x = findSet(parent, u);
	int y = findSet(parent, v);
	parent[x] = y;
}

void weightedUnion(int*& parent, int u, int v, int*& size){
	int x = findSet(parent, u);
	int y = findSet(parent, v);

	if(size[x] > size[y]){
		parent[y] = x;
		size[x] += size[y];
	}
	else{
		parent[x] = y;
		size[y] += size[x];
	}
}

int kruskal(std::vector<Edge> e, int N, int M){
	int* parent;
	int* size;
	int sum =0;

	parent = new int[N];
	size = new int[N];
	for(int i=0 ; i<N ; i++){
		parent[i] = i;
		size[i] = 1;
	}

	std::sort(e.begin(), e.end(), compare);
	
	for(int i=0 ; i<e.size() ; i++){
		if(findSet(parent, e[i].u) != findSet(parent, e[i].v)){
			sum += e[i].w;
			//////////////방문
//			unionParent(parent, e[i].u, e[i].v);
			weightedUnion(parent, e[i].u, e[i].v, size);
		}
	}
	return sum;
}

int main(){
	int N;
	int M;
	std::vector<Edge> e;
//edge의 집합이 필요함
//전체적인 graph에 대한 자료구조는 필요한지 잘 모르겠다

	std::cin >> N >> M;

	for(int i=0 ; i<M ; i++){
		int u, v, w;

		std::cin >> u >> v >> w;
		e.push_back(Edge(u, v, w));
	}

	std::cout << kruskal(e, N, M) << std::endl;

	return 0;
}
