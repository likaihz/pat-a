#include<stdio.h>
int isPrime(int n){
	int i;
	if(n<2) return 0;
	for(i=2;i*i<=n;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int change(int n,int d){
	int i,j,b[100],cnt=0;
	while(n){
		b[cnt]=n%d;
		cnt++;
		n=n/d;
	}
	int ans=0;
	for(i=cnt-1;i>=0;i--){
		int tmp=1;
		for(j=0;j<cnt-1-i;j++){
			tmp=tmp*d;
		}
		ans=ans+b[i]*tmp;
	}
	return ans;		
}
int main(){
	int i,j,n,d;
	while(scanf("%d",&n)){
		if(n<0) break;
		scanf("%d",&d);
		int rn=change(n,d);
		if(isPrime(n)&&isPrime(rn))
			printf("Yes\n");
		else
			printf("No\n");
		
	}
	return 0;
}
