#include <stdio.h>

int main(void)
{
    int is_prime;
    int i=0;
    int input=0;
    while(scanf("%d",&input)!=EOF)
    {
        is_prime=1;
        if(input < 2)
            is_prime=0;
        else if(input % 2 == 0 && input != 2 )
        {
            is_prime=0;
        }
        else
        {
            /*printf("\*\*Entering loop\*\*\n");*/
            for(i=3; i*i<=input; i+=2)
            {
                if(input % i == 0)
                {
                    is_prime=0;
                    break;
                }
            }
        }
        printf(is_prime ? "It's a prime!!!\n":"It's not a prime!!!\n");
    }
    return 0;
}
