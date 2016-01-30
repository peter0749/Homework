#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARR_SIZE 100000

int main(void){
	int *arr=NULL;
	arr=(int*)(malloc(sizeof(int)*ARR_SIZE)); 
	int rand_index;
	int i;
	srand(time(NULL));
	for(i=0;i<ARR_SIZE;i++)	*(arr+i)=-1;
	for(i=0;i<ARR_SIZE;i++){
		rand_index=rand()%ARR_SIZE;
		if(arr[rand_index]==-1)	*(arr+rand_index)=i+1;
		else{
			i--;
		}
	}
	//for(i=0;i<ARR_SIZE;i++)	printf("%d\n",*(arr+i));
	//system("pause");
	return 0;
}
