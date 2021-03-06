#include	<iostream>

bool has_couple[10] = {false, };

bool can_find_couple(int* couple[], int m, int num){
	if(has_couple[num])
		return false;
	for(int j=0 ; j<m ; j++){
		for(int i=0 ; i<2 ; i++){
			if(couple[i][j] == num && !has_couple[num] && !has_couple[couple[(i+1)%2][j]])
				return true;
		}
	}
	return false;
}

int find_couple(int* couple[], int n, int m, int num){
	int i;
	int sum=0;
	for(i=0 ; i<n ; i++){
		if(!has_couple[i])
			break;
	}
	if(i==n)
		return 1;
	if(!can_find_couple(couple, m, num))
		return 0;


	for(int j=0 ; j<m ; j++){
		if(couple[0][j] == num || couple[1][j] == num){
			has_couple[couple[0][j]] = true;
			has_couple[couple[1][j]] = true;
			sum += find_couple(couple, n, m, num+1);
		}
	}
	return sum;
}

int main(){
	int T;
	int n, m;

	std::cin >> T;

	for(int i=0 ; i<T ; i++){
		int* couple[2];

		std::cin >> n >> m;

		couple[0] = new int[m];
		couple[1] = new int[m];

		for(int i=0 ; i<m ; i++)
			std::cin >> couple[0][i] >> couple[1][i];

		std::cout << find_couple(couple, n, m, 0) << std::endl;
		for(int j=0 ; j<10 ; j++)
			has_couple[i] = false;
//		for(int i=0 ; i<m ; i++){
//			std::cout << couple[0][i] << couple[1][i] << std::endl << std::endl;
//		}
	}
}
