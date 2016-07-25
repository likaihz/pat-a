#include <cstdio>
int main(){
	int m, n, x, times = 0, candidate;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n*m; ++i){
			scanf("%d", &x);
			if (times == 0){
				candidate = x;
				++times;
			}
			else{
				if (x == candidate)
					++times;
				else
					--times;
			}
		}

	printf("%d\n", candidate);
	return 0;
}

//算法真是牛逼。。源自网络
    
