#include <stdio.h>
#include <stdlib.h>
#define MAX 10000000
int nums[MAX]= {0};
void mk_prime(void);
void count_prime(int, int);

int main(void)
{
    int a, b;
    mk_prime();
    while(scanf("%d %d",&a, &b)!=EOF)
    {
        count_prime(a,b);
    }
    return 0;
}

void mk_prime(void)
{
    int i, j;/*INDEX*/

    nums[0]=1;   /*0 is not a num. of prime.*/
    nums[1]=1;   /*1 is not a num. of prime*/
    for(i=3; i*i<=MAX; i+=2)	/*Generate a prime list.*/
    {
        if(nums[i] == 0)
        {
            for(j=i+i; j<MAX; j+=i) /*Eliminate all multiple of i.*/
            {
                nums[j] = 1;
            }
        }
    }
}

void count_prime(int a, int b)
{
    int i;
    int count=0;
    if(a<=2 && b>=2)
        count=1;
    if(a % 2 ==0)
        a++;
    for(i=a; i<=b; i+=2)
    {
        if(nums[i] == 0)
            count++;
    }
    printf("%d\n",count);
}
