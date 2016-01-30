


void compute(int tar, int arr[][MAX])
{
    int remain[500][2];
    int i,j,k=0;
    int cotar = (tar==1?2:1);
    int rnum;

    if(automode(tar,tar,arr,4))
    {
        return;   //Attack
    }

    for(i=4; i>=3; i--)
    {
        if(automode(cotar,tar,arr,i))
        {
            //printf("i= %d\n",i);
            return;   //Defend
        }
    }

    for(i=3; i>=2; i--)
    {
        if(automode(tar,tar,arr,i))
        {
            return;   //Attack
        }
    }

    if(automode(cotar,tar,arr,2))
    {
        //printf("i= %d\n",i);
        return;   //Defend
    }
    if(automode(tar,tar,arr,1))
    {
        return;   //Attack
    }

    if(automode(cotar,tar,arr,1))
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
    int dir;
    for(i=1; i<=BD; i++)
    {
        for(j=1; j<=BD; j++)
            if(arr[i][j]==tar)
            {
                for(dir=0; dir<4; dir++)
                {
                    if(cter(dir,tar,&arr[i][j],arr)==5)
                        return 1;
                }
            }
    }
    return 0;
}
int automode(int tar,int cotar,int arr[][MAX], int n)
{
    int i, j, dir;
    int shifter;       //Shifter

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
                            *(&arr[i][j]-shifter) = cotar;
                            a_cont((i*MAX+j-shifter)/MAX, (i*MAX+j-shifter)%MAX);
                            return 1;
                        }

                        if(*(&arr[i][j]+n*shifter)==0 )
                        {
                            *(&arr[i][j]+n*shifter) = cotar;
                            a_cont((i*MAX+j+n*shifter)/MAX, (i*MAX+j+n*shifter)%MAX);
                            return 1;
                        }
                    }
                }
            }
    }
    return 0;
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
