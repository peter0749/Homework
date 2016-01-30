#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define S MAX/2

void conv_to_int(char*);
void prt_rome(int);
int switch_rome(char);
int sum_up(int []);

int main(void)
{
	int testval;
	int i;
	char rome[MAX];
	char *ptr;
	while(1)
	{
		gets(rome);
		if(rome[0]=='#')	break;
		ptr=rome;
		
		#if 0
		printf("%c\n",*ptr);
		#endif
		
		conv_to_int(ptr);
	}
	return 0;
	
} 

void conv_to_int(char* ptr)
{
	int num_to_minus;
	int i=0;
	int r_one=0,r_two=0;
	int n_one[S]={0},n_two[S]={0};
	
	#if 0
	printf("%c\n",*ptr);
	#endif
	
	while(*ptr!=' ')
	{
		n_one[i]=switch_rome(*ptr);
		i++;
		ptr++;
	}
	ptr++;
	i=0;
	while(*ptr!='\0')
	{
		n_two[i]=switch_rome(*ptr);
		i++;
		ptr++;
	}
	r_one=sum_up(n_one);
	r_two=sum_up(n_two);
	if(r_one>r_two)	prt_rome(r_one-r_two);
	else if(r_one<r_two)	prt_rome(r_two-r_one);
	else printf("ZERO\n");
}

void prt_rome(int n)
{
	printf("In Prt_rome n = %d\n",n);
	int i,j;
	int deg[7]={0};
	for(i=0;n>=1000;deg[i]++)
	{
		n-=1000;
	}
	for(++i;n>=500;deg[i]++)
	{
		n-=500;
	}
	for(++i;n>=100;deg[i]++)
	{
		n-=100;
	}
	for(++i;n>=50;deg[i]++)
	{
		n-=50;
	}
	for(++i;n>=10;deg[i]++)
	{
		n-=10;
	}
	for(++i;n>=5;deg[i]++)
	{
		n-=5;
	}
	for(++i;n>=1;deg[i]++)
	{
		n--;
	}
	printf("now n = %d\n",n);
	printf("M\tD\tC\tL\tX\tV\tI\n");
	for(i=0;i<7;i++)
	{
		printf("%d\t",deg[i]);
	}
	printf("\n");
	
	
	for(i=0;i<7;i++)
	{
		if(deg[i]<4)
		{
			for(j=0;j<deg[i];j++)
			{
				switch(i)
				{
					case 0:
						printf("M");
						break;
					case 1:
						printf("D");
						break;
					case 2:
						printf("C");
						break;
					case 3:
						printf("L");
						break;
					case 4:
						printf("X");
						break;
					case 5:
						printf("V");
						break;
					case 6:
						printf("I");
						break;
				} 
			}
		}
		else
		{
			switch(i)
				{
					case 2:
						printf("CD");
						break;
					case 4:
						printf("XL");
						break;
					case 6:
						printf("IV");
						break;
				}
		}
	}
	printf("\n");
}

int switch_rome(char ch)
{
	switch(ch)
		{
			case 'I':
				return 1;
			case 'V':
				return 5;
			case 'X':
				return 10;
			case 'L':
				return 50;
			case 'C':
				return 100;
			case 'D':
				return 500;
			case 'M':
				return 1000;
		}
}

int sum_up(int n_one[S])
{
	int i;
	int r_one=0;
	int num_to_minus=0;
	
	for(i=S-1;i>=1;i--)
	{
		if(n_one[i]<=n_one[i-1])
		{
			r_one+=n_one[i];
			if(i==1)
			{
				r_one+=n_one[0];
			}
		}
		else
		{
			r_one+=n_one[i];
			i--;
			num_to_minus=n_one[i];
			while(n_one[i]<=num_to_minus && i>=0)
			{
				r_one-=num_to_minus;
				i--;
			}
		}
	}
	
	#if 1
	printf("r_one = %d\n",r_one);
	#endif
	return r_one;
}
