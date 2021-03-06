
void cp_mtx(int des[][MAX], int src[][MAX])
{
    int i, j;
    for(i=0; i<MAX; i++)
    {
        for(j=0; j<MAX; j++)
            des[i][j] = src[i][j];
    }
}

void compute(int tar, int arr[][MAX], int difcult)      //difficulty 0:easy 1:hard
{
    int remain[500][2];
    //int bk[MAX][MAX];
    int i,j,k = 0;
    int cotar = (tar==1?2:1);
    int rnum;

    if(difcult)             //To adjust difficulty
    {
        //printf("##INCON.h## %d",difcult);
        //system("pause");
        for(i=4; i>=1; i--)
        {
            if(automode(tar,tar,arr,i,1))
            {
                return;   //Attack
            }
        }

        for(i=4; i>=1; i--)
        {
            if(automode(cotar,tar,arr,i,1))
            {
                //printf("i= %d\n",i);
                return;   //Defend
            }
        }
    }

    if(automode(tar,tar,arr,4,0))
    {
        return;   //Attack
    }
    if(automode(cotar,tar,arr,4,0))
    {
        //printf("i= %d\n",i);
        return;   //Defend
    }

    for(i=3; i>=2; i--)
    {
        if(automode(tar,tar,arr,i,0))
        {
            return;   //Attack
        }
    }

    for(i=3; i>=2; i--)
    {
        if(automode(cotar,tar,arr,i,0))
        {
            //printf("i= %d\n",i);
            return;   //Defend
        }
    }
    if(automode(tar,tar,arr,1,0))
    {
        return;   //Attack
    }

    if(automode(cotar,tar,arr,1,0))
    {
        //printf("i= %d\n",i);
        return;   //Defend
    }
    /*
        i = rand()%3+9;         //Computer first
        j = rand()%3+9;
        if(arr[i][j]==0)
        {
            arr[i][j] = tar;
            a_cont(i,j);
            return;
        }
    */
    for(i=1; i<=BD; i++)
    {
        for(j=1; j<=BD; j++)
        {
            if(arr[i][j]==0)
            {
                remain[k][0] = i;
                remain[k][1] = j;
                k++;
            }
        }
    }
    rnum = rand()%k;
    arr[remain[rnum][0]][remain[rnum][1]] = tar;
    a_cont(remain[rnum][0],remain[rnum][1]);
}

int is_tie(int arr[][MAX])          //IF TIE
{
    int i, j;
    for(i=1; i<=BD; i++)
    {
        for(j=1; j<=BD; j++)
            if(arr[i][j]==0)    return 0;
    }
    return 1;
}

int is_five(int tar,int arr[][MAX])
{
    int i, j;
    int len;
    int dir;
    for(i=1; i<=BD; i++)
    {
        for(j=1; j<=BD; j++)
            if(arr[i][j]==tar)
            {
                for(dir=0; dir<4; dir++)
                {
                    len = cter(dir,tar,&arr[i][j],arr);
                    if(len>5)
                        return -1;
                    if(len==5)
                        return 1;

                }
            }
    }
    return 0;
}
int automode(int tar,int cotar,int arr[][MAX], int n, int diflty)       //diflty 0:easy 1:hard
{
    int i, j, dir, k =0;
    int shifter;       //Shifter
    int bk[MAX][MAX];
    int valid[500][2];
    int rnum;

    for(i=1; i<=BD; i++)
    {
        for(j=1; j<=BD; j++)
            if(arr[i][j]==tar)
            {
                for(dir=0; dir<4; dir++)
                {
                    if(cter(dir,tar,&arr[i][j],arr)==n)
                    {
                        shifter = shi(dir);

                        if(*(&arr[i][j]-shifter)==0 )
                        {
                            valid[k][0] = (i*MAX+j-shifter)/MAX;
                            valid[k][1] = (i*MAX+j-shifter)%MAX;
                            k++;
                        }

                        if(*(&arr[i][j]+n*shifter)==0 )
                        {
                            valid[k][0] = (i*MAX+j+n*shifter)/MAX;
                            valid[k][1] = (i*MAX+j+n*shifter)%MAX;
                            k++;
                        }
                    }
                }
            }
    }
    if(k>0)
    {
        //printf("##INCONAUTO.h## diff = %d",diflty);
        //system("pause");
        for(i=0; i<k; i++)
        {
            cp_mtx(bk,arr);
            bk[valid[i][0]][valid[i][1]] = tar;
            if(diflty==1 && is_five(tar,bk)==1)
            {
                //printf("##INCONAUTO##");
                //system("pause");
                arr[valid[i][0]][valid[i][1]] = cotar;
                a_cont(valid[i][0], valid[i][1]);
                return 2;           //Win
            }
        }
        if(diflty==0)
        {
            rnum = rand()%k;
            arr[valid[rnum][0]][valid[rnum][1]] = cotar;
            a_cont(valid[rnum][0], valid[rnum][1]);
            return 1;       //Not sure
        }

    }

    return 0;       //Nothing
}
int cter(const int dir, const int tar, int *ptr, int arr[][MAX])
{
    int count = 0;
    while(tar==*ptr)
    {
        count++;
        ptr+=shi(dir);
    }
    /*The initial number of count MUST BE ZERO!!!*/
    //printf("count = %d\n",count);
    return count;
}

int shi(const int dir)
{
    int shift;
    if(dir==0)		//m = 0
    {
        shift = 1;
    }
    else if(dir==1)		//m = -1
    {
        shift = (MAX + 1);
    }
    else if(dir==2)		//m = undefine
    {
        shift = MAX;
    }
    else		//dir==4   m = 1
    {
        shift = (MAX - 1);
    }
    return shift;
}
