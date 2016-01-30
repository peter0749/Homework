


int main_ui(void)
{
    char temp[MAX];
    int i = 0, j, k = 0;
    char ch;
    char itf[4][MAX] =
    {
        "1.Start!","2.Coop Mode","3.Watch Replay","4.Exit"
    };
    printf("->  ");
    puts(itf[0]);
    puts(itf[1]);
    puts(itf[2]);
    puts(itf[3]);
    puts("(SPACE:select\tW:UP\tS:DOWN)");

    while(1)
    {
        ch = getch();
        if(k>21)
        	k = 0;
        temp[k++] = ch;
        temp[k] = '\0';
        if(strcmp(temp,secretcode)==0)
        {
            gmod = 1;
            puts("== GodMode Enabled ==");
            _sleep(500);
        }
        clrscr();
        switch(ch)
        {
        case 'w':        //Arrow UP
            if(i>0) i--;
            break;
        case 's':    //Arrow DOWN
            if(i<3) i++;
            break;
        case ' ':
            return i;
        }
        for(j=0; j<4; j++)
        {
            if(i==j)
                printf("->  ");
            puts(itf[j]);
        }
        puts("(SPACE:select\tW:UP\tS:DOWN)");
    }

}

int game_ui(int arr[][MAX], int tar)         //Return the position    ,target
{
    int i;
    static int x=1, y=1;
    char ch;
    while(1)
    {
        prt_arr(arr, &x, &y, 0, 1);
        ch = getch();
        switch(ch)
        {
        case 'w':   //UP
            if(y > 1)
                y--;
            break;
        case 's':   //DOWN
            if(y < BD)
                y++;
            break;
        case 'a':   //LEFT
            if(x > 1)
                x--;
            break;
        case 'd':   //RIGHT
            if(x < BD)
                x++;
            break;
        case ' ':
            if(arr[y][x]==0)
            {
                arr[y][x] = tar;
                a_cont(y,x);
                return 1;
            }
            break;
        case 'u':
            if(c>1 && gmod==1)
            {
                for(i=0,--c; i<2; i++,--c)
                    arr[record[c][0]][record[c][1]] = 0;
                c++;
            }
            break;
        case 'm':
            if(gmod)
            {
                compute(tar,arr,1);
                return 1;
            }
            break;
        case 'q':
            x = y = 1;
            return 0;
            break;
        }
    }
    //Done
}

void prt_arr(int arr[][MAX], int *x, int *y, int rply, int selc)      //rply==1 replay mode  selc==1 select mode
{
    int i, j;

    clrscr();
    printf("   ");
    for(i=0; i<8; i++)
        printf("%c ",'A'+i);
    i += 1;
    for(; i<BD+1; i++)
        printf("%c ",'A'+i);

    printf("\n");
    for(i=1; i<=BD; i++)
    {
        printf("%2d",20-i);
        for(j=1; j<=BD; j++)
        {
            if(*y==i&&*x==j)
                printf("¡¹");
            else
            {
                if(arr[i][j]==1)
                    printf("¡³");
                else if(arr[i][j]==2)
                    printf("¡´");
                else
                {
                    if(j==1&&i==1)
                        printf("¢z");
                    else if(j==1&&i==19)
                        printf("¢|");
                    else if(j==19&&i==1)
                        printf("¢{");
                    else if(j==19&&i==19)
                        printf("¢}");
                    else if(j==1)
                        printf("¢u");
                    else if(j==19)
                        printf("¢t");
                    else if(i==1)
                        printf("¢s");
                    else if(i==19)
                        printf("¢r");
                    else
                        printf("¢q");
                }
            }
        }
        if(i==4)
            printf("\tCoordinates:");
        else if(i==5 || i==9)
            printf("\t===========");
        else if(i==6 || i==8)
            printf("\t#         #");
        else if(i==7)
        {
            if(selc)
            {
                printf("\t#( %2c", *x>=9 ? *x+'A':*x+'A'-1);
                printf(",%2d )#",20-*y);
            }
            else if(c==0)
                printf("\t#( __,__ )#");
            else if(rply)
            {
                //printf("\t#( %2c,%2d )#",record[k][1]+'A'-1,20-record[k][0]);
                printf("\t#( %2c", record[k][1]>=9 ? record[k][1]+'A':record[k][1]+'A'-1);
                printf(",%2d )#",20-record[k][0]);
                k++;
            }
            else
            {
                printf("\t#( %2c", record[c-1][1]>=9 ? record[c-1][1]+'A':record[c-1][1]+'A'-1);
                printf(",%2d )#",20-record[c-1][0]);
                //printf("\t#( %2c,%2d )#",record[c-1][1]+'A'-1,20-record[c-1][0]);
            }
        }

        printf("\n");
    }
    printf("SPACE:select   W:UP   S:DOWN   A:LEFT   D:RIGHT   Q:QUIT");
    if(gmod)
        printf("   U:UNDO    M:AUTO");
    printf("\n");
}

void clean_arr(int arr[][MAX])
{
    int i,j;
    for(i=0; i<MAX; i++)  for(j=0; j<MAX; j++)  arr[i][j] = -1;
    for(i=1; i<=BD; i++)  for(j=1; j<=BD; j++)  arr[i][j] = 0;
}
