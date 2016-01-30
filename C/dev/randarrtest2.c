#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARR_SIZE 100000

int main(void){
	int rem=ARR_SIZE;
	int *arr=NULL;
	int *new_arr=NULL;
	arr=(int*)(malloc(sizeof(int)*ARR_SIZE)); 
	new_arr=(int*)(malloc(sizeof(int)*ARR_SIZE)); 
	int rand_index;
	int i,j;
	srand(time(NULL));
	for(i=0;i<ARR_SIZE;i++){
		*(arr+i)=i+1;
	}
	for(i=0;i<ARR_SIZE;i++){
		rand_index=rand()%rem;
		*(new_arr+i)=*(arr+rand_index);
		for(j=rand_index;j<rem-1;j++){
			arr[j]=arr[j+1];
		}
		rem--;
	}
	//for(i=0;i<ARR_SIZE;i++)	printf("%d\n",*(new_arr+i));
	//system("pause");
	return 0;
}
