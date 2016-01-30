#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
	long int i,k,n,j;
	printf("n位數相乘，請輸入n:");
	scanf("%d",&n);	//讀入n 
	long int a[2][n],c[2*n+1];	//開一個一維陣列和一個二維陣列 
	for(j=2*n;j>=0;j--)		//定義陣列c的初始值為0 
	c[j]=0;
	printf("\n請輸入被乘數:");
	for(k=n-1;k>=0;k--)		//讀入被乘數a[0][k] 由左至右(位數大到位數小)
	a[0][k]=(long int)(getche()-'0');		//getche之char轉int 
	//printf("\na[0][0]=%d\n",a[0][0]);//debug
	printf("\n請輸入乘數:");
	for(i=n-1;i>=0;i--)		//讀入被乘數a[1][i] 由左至右(位數大到位數小)
	a[1][i]=(long int)(getche()-'0');		//getche之char轉int
	
	for(i=0;i<=n-1;i++){		//a[0][k],a[1][i]相乘 ，使用巢狀迴圈 
		for(k=0;k<=n-1;k++){
			c[k+i]+=(a[0][k]*a[1][i]);	//將 a[0][k],a[1][i]相乘的值，累加至c[k+i]，就像(10^a)*(10^b)=10^(a+b)
			while(c[k+i]>9){		//檢查c[k+i]是否大於9，有即進位 
				c[k+i]-=10;
				c[k+i+1]++;
			}
		}
	}
	//printf("\nc[2]=%d\n",c[2]);//debug
	printf("\nThe answer is: ");
	for(j=2*n;j>=0;j--)		//由左至右(位數大到位數小)印出答案 
	printf("%d",c[j]);
	system("pause");
	return 0;
}
