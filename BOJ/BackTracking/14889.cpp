#include	<iostream>
#include	<cstdlib>

int start[11];
int link[11];
bool visit[11];
int min = 20001;

void findFunnyGame(int soccer[][21], int N, int count, int pre){
	if(count == N/2){
		bool check[21] = {false, };
		for(int i=0 ; i<N/2 ; i++){
			check[start[i]] = true;
		}
		int idx = 0;
		for(int i=1 ; i<=N ; i++)
			if(!check[i])
				link[idx++] = i;

		int start_sum = 0;
		int link_sum = 0;
		for(int i=0 ; i<N/2 ; i++){
			for(int j=0 ; j<N/2 ; j++){
				if(i == j)
					continue;
				start_sum += soccer[start[i]][start[j]];
				link_sum += soccer[link[i]][link[j]];
			}
		}
		min = std::min(min, std::abs(start_sum - link_sum));
	}

	for(int i=1 ; i<=N ; i++){
		if(visit[i])
			continue;
		if(pre < i){
			visit[i] = true;
			start[count] = i;
			findFunnyGame(soccer, N, count+1, i);
			visit[i] = false;
		}
	}
}

int main(){
	int N;
	int soccer[21][21] = {0};

	std::cin >> N;

	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=N ; j++)
			std::cin >> soccer[i][j];

	findFunnyGame(soccer, N, 0, 0);

	std::cout << min << std::endl;
}
