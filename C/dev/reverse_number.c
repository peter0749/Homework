#include"stdio.h"

#include"string.h"

int main()

{

	char a[20];

	int i,k,m;

	gets(a);

	int sum = 0;

	for(i = 0;i < strlen(a);i ++)

	{

		if(a[i] == '0')

		{

			sum = sum + 1;

		}

	}

	if(sum == strlen(a))

	{

		printf("0");

	}

	if((a[0] == '0') && (a[1] == '\0'))

	{

		printf("0\n");

	}

	else if(a[0] == '0')

	{

		i = 0;

		while(a[i] == '0')

		{

			i ++;

		}

		k = i;

		i = strlen(a);

		while(a[i - 1] == '0')

		{

			i --;

		}

		for(m = i - 1;m >= k;m --)

		{

			printf("%c",a[m]);

		}

		printf("\n");

	}

	else

	{

		i = strlen(a);

		while(a[i - 1] == '0')

		{

			i --;

		}

		for(k = i - 1;k >= 0;k --)

		{

			printf("%c",a[k]);

		}

		printf("\n");

	}

	return 0;

} 
