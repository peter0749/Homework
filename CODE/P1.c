#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int city(char[]);
int conv_int(char[]);

int main(void)
{
	int conv[6] = {8,9,-4,-5,-6,0};
	//TW, JA, USE, USC, USW, UK

	char target[100];
	char src[100];
	int term;
	char temp[20];
	char hr[3], min[3];
	int time;
	int i;
	scanf("%d",&term);
	while(term--)
	{
		for(i=0;i<2;i++)
			scanf(" %c",&hr[i]);
		hr[i] = '\0';
		printf("--hr%s\n",hr);
		for(i=0;i<2;i++)
			scanf(" %c",&min[i]);
		min[i] = '\0';
		printf("--min%s\n",min);
		scanf(" %s %s",src,target);
		time = conv_int(hr);
		printf("--time: %d\n",time);
		time += conv[city(target)]-conv[city(src)];
		printf("--time: %d\n",time);
		if(time < 0)
		{
			time += 24;
		}
		printf("--mod time: %d\n",time);
		if(time<10)
			printf("0%d",time);
		else
			printf("%d",time);

		printf("%s",min);
		printf(" %s\n",target);
	}

	return 0;
}

int city(char conv[])
{
	if(strcmp(conv,"TW")==0)	return 0;
	if(strcmp(conv,"JA")==0)	return 1;
	if(strcmp(conv,"USE")==0)	return 2;
	if(strcmp(conv,"USC")==0)	return 3;
	if(strcmp(conv,"USW")==0)	return 4;
	if(strcmp(conv,"UK")==0)	return 5;
}

int conv_int(char data[])
{
	int i;
	int sum=0;
	int j;
	for(i=1,j=0;i>=0;i--,j++)
	{
		sum += (int)(data[i]-'0')*pow(10,j);
		printf("sum+= %d\n",sum);
	}
	printf("--%d\n",sum);
	return sum;
}

