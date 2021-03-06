#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>

typedef struct _edge{
	int v1, v2, w;
}edge;

const int INF = 9999999;

class Graph{
	int N;
	int M;
	std::vector<edge>* g;

public:
	Graph(){}

	void init(){
		g = new std::vector<edge>[N];

		for(int i=0 ; i<M ; i++){
			int u, v, w;
			std::cin >> u >> v >> w;

			g[u].push_back(edge{u, v, w});
			g[v].push_back(edge{u, v, w});
		}
	}

	int getN(){
		return N;
	}

	int getM(){
		return M;
	}

	std::vector<edge>*& getGraph(){
		return g;
	}

	~Graph(){
		for(int i=0 ; i<N ; i++)
			std::vector<edge>().swap(g[i]);
	}
	
	friend std::istream& operator>>(std::istream& is, Graph& g);
};

std::istream& operator>>(std::istream& is, Graph& g){
	is >> g.N >> g.M;
	return is;
}

int prim(Graph& mst, int s){
	int N = mst.getN();
	int* p;
	int sum=0;
	std::vector<bool> added(N, false);
	std::vector<int> key(N, INF);

	std::vector<edge>* g = mst.getGraph();



	key[s] = 0;

	for(int i=0 ; i<N ; i++){
		int u = -1;
		for(int v=0 ; v<N ; v++){
			if(!added[v] && (u == -1 || key[u] > key[v]))
				u = v;
		}

		sum += key[u];
		added[u] = true;

		for(int j=0 ; j<g[u].size() ; j++){
			int v = g[u][j].v2;
			int w = g[u][j].w;

			if(!added[v] && key[v] > w){
				key[v] = w;
			}
		}
	}
/*
	while(!pq.empty()){
		int u = pq.top();
		pq.pop();

		for(std::vector<int>::size_type i=0 ; i<g[u].size() ; i++){
			int v = g[u][i].v2;
			
			if(g[u][i].w < key[v]){
				p[v] = u;
				key[v] = g[u][i].w;
			}
		}
	}

	for(int i=0 ; i<N ; i++){
		sum += key[i];
		std::cout << key[i] << " ";
	}
	std::cout << std::endl;
//		sum += key[i];
*/
	return sum;
}

int main(){
	Graph mst;
	int s;

	std::cin >> mst;
	std::cin >> s;
	mst.init();

	std::cout << prim(mst, s) << std::endl;

	return 0;
}
