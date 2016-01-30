#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct SALE {
	char name[MAX];
	double price;
	double sold;
	double total;
}PRODUCT;

void swap(PRODUCT *a, PRODUCT *b)
{
	PRODUCT temp = *a;
	*a = *b;
	*b = temp;
}

void selec_sort(PRODUCT[], int, int);		//Array of structure "SALE"
void cal(FILE*, PRODUCT[],int);		//n cases
void w_back(FILE*, PRODUCT[], int);

int main(void)
{
	char temp[MAX];
	PRODUCT data[MAX];
	int i = 0;
	FILE *fin, *fout;
	fin = fopen("dat.txt","r");			//"r" for "read"
	fout = fopen("price.txt","w");		//"a" for "attach"
	if(fin==NULL)
	{
		printf("Open \"dat.txt\" failed! Does the file exist?\n");
		return -1;
	}
	if(fout==NULL)
	{
		printf("Open \"price.txt\" failed! Please check your permission!\n");
		return -2;
	}
	while((fgets(temp,MAX,fin))!=NULL)
	{
		//(data+i) = (PRODUCT*)malloc(sizeof(PRODUCT));
		sscanf(temp,"%s %lf %lf %lf",data[i].name,&(data[i].price),&(data[i].sold));
		//printf("%s %.2lf %.2lf %.2lf\n",data[i].name,data[i].price,data[i].sold);
		i++;
	}
	// Total i- cases
	cal(fout,data,i);

	puts("Please enter \'q\' to exit");
	while(getchar()!='q');

	fclose(fin);
	fclose(fout);

	return 0;
}

void selec_sort(PRODUCT struc_arr[], int n, int op)		//OP 0 for weight; OP 1 for total
{
	int i, j;
	int max = 0 ;
	if(op)
	{
		for(i=0;i<n-1;i++)
		{
			max = i;
			for(j=i+1;j<n;j++)
			{
				if((struc_arr+j)->total > (struc_arr+max)->total)
					max = j;
			}
			if(i!=max)
				swap((struc_arr+max),(struc_arr+i));
		}
	}
	else		//For op==0
	{
		for(i=0;i<n-1;i++)
		{
			max = i;
			for(j=i+1;j<n;j++)
			{
				if((struc_arr+j)->sold > (struc_arr+max)->sold)
					max = j;
			}
			if(i!=max)
				swap((struc_arr+max),(struc_arr+i));
		}
	}
}

void w_back(FILE *fptr, PRODUCT data[], int n)
{
    int i = 0;
	while(n--)
	{
	    fprintf(fptr,"%s %.2lf %.2lf %.2lf\n",(data+i)->name,(data+i)->price,(data+i)->sold,(data+i)->total);
		i++;
	}
	//RETURN;
}

void cal(FILE *fptr, PRODUCT arr[],int n)
{
	int i;
	double max_w = 0.0, max_sale = 0.0;
	double total_sale = 0.0;
	for(i=0;i<n;i++)
	{
		(arr+i)->total = (arr+i)->price * (arr+i)->sold;
		total_sale += (arr+i)->total;
		if((arr+i)->sold > max_w)	max_w = (arr+i)->sold;
	}
    fputs("# product name, unit price, unit sold, total money\n",fptr);
	selec_sort(arr,n,0);
	fputs("Sort by Weight:\n",fptr);
	w_back(fptr,arr,n);		//Write back the result

	printf("The total sale for a day is %.2lf\n",total_sale);
	printf("The largest weight sold is %s with %.2lf pound.\n",arr[0].name,arr[0].sold);

	selec_sort(arr,n,1);
	fputs("\nSort by Total:\n",fptr);
	w_back(fptr,arr,n);		//Write back the result

	printf("The product with the largest dollar amount sold is %s.\n",arr[0].name);

}
