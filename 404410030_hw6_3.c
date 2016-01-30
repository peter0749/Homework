#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(void)
{
    //freopen("testinput.txt","r",stdin);
    //freopen("testoutput.txt","w+",stdout);
    int first_run = 1;
    int even[MAX];
    int odd[MAX];
    int count_odd;
    int count_even;
    int input_num;
    int n;
    int i; /*INDEX of for loop*/
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)
            exit(0);
        count_even = count_odd = 0;

        for(i=0; i<n; i++)
        {
            scanf("%d",&input_num);
            if(input_num % 2)
            {
                odd[count_odd++] = input_num;
            }
            else
            {
                even[count_even++] = input_num;
            }
        }

        for(i=0; i<count_odd; i++)
        {
            if(i > 0)
                printf(" ");
            else
            {
                if(first_run)
                    first_run = 0;
                else
                    printf("\n");
            }
            printf("%d",odd[i]);
        }

        for(i=0; i<count_even; i++)
        {
            if(i > 0)
                printf(" ");
            else
            {
                if(first_run)
                    first_run = 0;
                else
                    printf("\n");
            }
            printf("%d",even[i]);
        }
        printf("\n");

    }

    return 0;
}
