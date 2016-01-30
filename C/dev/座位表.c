#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main(){
	int max_dim,p,searchNum,i,j,midNum=0,low=0,high,choise;
	char q=0;
	printf("座位表產生器\n最大到幾號?");
	scanf("%d",&max_dim);
	high=max_dim-1;
	int members[max_dim];
	for(i=0;i<max_dim;i++){
		members[i]=i+1;
	} 
	do{
		printf("\n去除第幾號(一次一名,按\"c\"退出)");
		scanf("%c",&q);
		if(q =='c' || q =='C') break;
		else{
			searchNum=(int)(q-'0');
			//binary searching;
			do{
				midNum=(low+high)/2;
				if(searchNum==members[midNum]){
					for(i=midNum;i<max_dim;i++){
						members[i]=members[i+1];
						max_dim--;
						low=0;
						high=max_dim-1;
						break;
					}
				}
				else if(searchNum>members[midNum]){
					low=midNum+1;
				}
				else{
					high=midNum-1;
				}
			}while(low<=high);
		}
		}while(1/*q !='c' || q !='C'*/);
		printf("\n有幾排?");
		scanf("%d",&p);
		printf("\n產生中......");
		srand((unsigned)time(NULL));
		int true_members[max_dim],max;
		max=max_dim;
		for(i=0;i<max;i++){
			choise=rand()%max_dim;
			true_members[i]=members[choise];
			for(j=choise;j<max_dim;j++){
				members[j]=members[j+1];
			}
			max_dim--;
		}
		printf("\n");
		for(i=0;i<p;i++){
			for(j=i*p;j<(i+1)*p;j++){
				printf("%4d",true_members[j]);
			}
			printf("\n");
		}
		system("pause");
		return 0;
		
	}

