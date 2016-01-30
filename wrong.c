#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define SIZE 3

/*Size of square matries.*/



int main(void)

{

	/*Permission check.*/

	FILE *fin = NULL;

	FILE *fout = NULL;

	fin = fopen("testinput.txt","r");

	fout = fopen("testoutput.txt","w+");

	if(fout == NULL )

	{

		printf("Failed to create testoutput.txt.\nPlease check your permission setting.\n");

		exit(-1);

	}

	if(fin == NULL )

	{

		printf("Failed to open testinput.txt.\nIs \"testinput.txt\" exist?\n");

		exit(-2);

	}

	fclose(fin);

	fclose(fout);

	/*End of permission check.*/



	/*Redirect stdout to the file.*/

	freopen("testoutput.txt","w+",stdout);

	freopen("testinput.txt","r",stdin);	

	int first_run = 1;	/*If fir--- == 0, printout \n*/

	int i,j,k;

	int mtx[3][SIZE][SIZE]={{0}};	/*m0 = m1 * m2 */

	while(1)

	{

		for(k=1;k<3;k++)	/*data_in*/

		{

			for(i=0;i<SIZE;i++)

			{

				for(j=0;j<SIZE;j++)

				{

					if(scanf("%d",&mtx[k][i][j]) == EOF)

						exit(0);

				}

			}

		}

		first_run ? first_run = 0 : printf("\n");    /*在每筆測資的開頭空行，隔開測資，但在第一筆前不輸出*/

		/*If fir--- == 0, printout \n*/

		for(k=0;k<SIZE;k++)

		{

			for(i=0;i<SIZE;i++)

			{

				for(j=0;j<SIZE;j++)

					mtx[0][i][j] += mtx[1][i][k] * mtx[2][k][j];

				/*Cij = Aim * Bmj*/

			}

		}

		for(i=0;i<3;i++)

		{

			for(j=0;j<3;j++)

				printf("%4d",mtx[0][i][j]);

			printf("\n");    /*這就是換行*/

		}

		memset(mtx,0x00,sizeof(int)*3*SIZE*SIZE);	/*Reset arrays*/

	}

	return 0;

}
