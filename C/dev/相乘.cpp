#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
	long int i,k,n,j;
	printf("n��Ƭۭ��A�п�Jn:");
	scanf("%d",&n);	//Ū�Jn 
	long int a[2][n],c[2*n+1];	//�}�@�Ӥ@���}�C�M�@�ӤG���}�C 
	for(j=2*n;j>=0;j--)		//�w�q�}�Cc����l�Ȭ�0 
	c[j]=0;
	printf("\n�п�J�Q����:");
	for(k=n-1;k>=0;k--)		//Ū�J�Q����a[0][k] �ѥ��ܥk(��Ƥj���Ƥp)
	a[0][k]=(long int)(getche()-'0');		//getche��char��int 
	//printf("\na[0][0]=%d\n",a[0][0]);//debug
	printf("\n�п�J����:");
	for(i=n-1;i>=0;i--)		//Ū�J�Q����a[1][i] �ѥ��ܥk(��Ƥj���Ƥp)
	a[1][i]=(long int)(getche()-'0');		//getche��char��int
	
	for(i=0;i<=n-1;i++){		//a[0][k],a[1][i]�ۭ� �A�ϥα_���j�� 
		for(k=0;k<=n-1;k++){
			c[k+i]+=(a[0][k]*a[1][i]);	//�N a[0][k],a[1][i]�ۭ����ȡA�֥[��c[k+i]�A�N��(10^a)*(10^b)=10^(a+b)
			while(c[k+i]>9){		//�ˬdc[k+i]�O�_�j��9�A���Y�i�� 
				c[k+i]-=10;
				c[k+i+1]++;
			}
		}
	}
	//printf("\nc[2]=%d\n",c[2]);//debug
	printf("\nThe answer is: ");
	for(j=2*n;j>=0;j--)		//�ѥ��ܥk(��Ƥj���Ƥp)�L�X���� 
	printf("%d",c[j]);
	system("pause");
	return 0;
}
