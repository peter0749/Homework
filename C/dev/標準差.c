#include <stdio.h>
#include <math.h>
#define N 5


float alpha(int (**A)[N]);
float sigma(int (*A)[N]);


int main(void){
	int A[N];
	scanf("%d %d %d %d %d",&A[0],&A[1],&A[2],&A[3],&A[4]);
	printf("%f\n",sigma(&A));
	return 0;
}

float alpha(int (**A)[N]){
	int i;
	float alph=0;
	for(i=0;i<N;i++)	alph+=(**A)[i];
	//printf("%f",alph);
	return alph/N;
}

float sigma(int (*A)[N]){
	int i;
	float sig;
	float a=alpha(&A);
	for(i=0;i<N;i++){
		sig+=(pow(((*A)[i]-a),2));
	}
	sig/=N;
	sig=sqrt(sig);
	return sig;
	
}
