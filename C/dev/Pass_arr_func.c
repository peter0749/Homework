#include <stdio.h>
#if 0
void PrintA (int A[10]){
	int i;
	for(i=0;i<10;++i){
		printf("%d, ",A[i]);
	}
	printf("\n");
}

int main(void){
	int M[10]={0};
	int i;
	for(i=0;i<10;++i){
		M[i]=i;
	}
	PrintA(M);
	return 0;
}
#endif

#if 0
void PrintA(int A[],int n){
	int i;
	for(i=0;i<n;++i){
		printf("%d, ",A[i]);
	}
	printf("\n");
}

int main(void){
	int M[10]={0};
	int i;
	for(i=0;i<10;++i){
		M[i]=i;
	}
	PrintA(M,10);
	return 0;
}
#endif

#if 0
void PrintA(int(*A)[10]){
	int i;
	for(i=0;i<10;++i){
		printf("%d, ",(*A)[i]);
	}
	printf("\n");
}
int main(void){
	int M[10]={0};
	int i;
	for(i=0;i<10;++i){
		M[i]=i;
	}
	PrintA(&M);
	return 0;
}
#endif

#if 0
void PrintA(int *A,int n){
	int i;
	for(i=0;i<n;++i){
		printf("%d ",A[i]);
	}
	printf("\n");
}

int main(void){
	int i;
	const int n=10;
	int M[n];
	for(i=0;i<10;++i){
		M[i]=i;
	}
	PrintA(M,n);
}
#endif

#if 1
void PrintA(int *A,int n){
	int i;
	for(i=0;i<n;++i){
		printf("%d ",A[i]);
	}
	printf("\n");
}

int main(void){
	int i;
	int M[10]={0};
	for(i=0;i<10;++i){
		M[i]=i;
	}
	PrintA(M,10);
}
#endif
