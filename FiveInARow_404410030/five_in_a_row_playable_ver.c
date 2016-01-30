#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define clrscr() system("cls");
#define MAX 30
#define BD 19

int record[500][2] = {{0}};
int c = 0;
int gmod = 0;
char *secretcode = "iloveraspberry";

void clean_arr(int arr[][MAX])
{
    int i,j;
    for(i=0; i<MAX; i++)  for(j=0; j<MAX; j++)  arr[i][j] = -1;
    for(i=1; i<=BD; i++)  for(j=1; j<=BD; j++)  arr[i][j] = 0;
}

void a_cont(int i, int j)
{
    record[c][0] = i;
    record[c][1] = j;
    c++;
}

void compute(int tar, int arr[][MAX])
{
    int remain[500][2];
    int i,j,k=0;
    int cotar = (tar==1?2:1);
    int rnum;
    for(i=4; i>=2; i--)
    {
        if(automode(cotar,tar,arr,i))
        {
            //printf("i= %d\n",i);
            return;   //Defend
        }
    }

    for(i=4; i>=1; i--)
    {
        if(automode(tar,tar,arr,i))
        {
            return;   //Attack
        }
    }

    if(automode(cotar,tar,arr,1))
    {
        //puts("ME");
        return;   //Defend
    }

    i = rand()%3+9;         //Computer first
    j = rand()%3+9;
    if(arr[i][j]==0)
    {
        arr[i][j] = tar;
        a_cont(i,j);
        return;
    }
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

void prt_arr(int arr[][MAX], int *x, int *y, int rply)      //rply==1 replay mode
{
    int i, j;
    static int k = 0;
    clrscr();
    printf("  ");
    for(i=0; i<BD; i++)
        printf("%c ",'A'+i);
    printf("\n");
    for(i=1; i<=BD; i++)
    {
        printf("%c",'A'+i-1);
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
            if(c==0)
                printf("\t#( __,__ )#");
            else if(rply)
            {
                printf("\t#( %2c,%2c )#",record[k][0]+'A'-1,record[k][1]+'A'-1);
                k++;
            }
            else
                printf("\t#( %2c,%2c )#",record[c-1][0]+'A'-1,record[c-1][1]+'A'-1);
        }

        printf("\n");
    }
    printf("SPACE:select   W:UP   S:DOWN   A:LEFT   D:RIGHT   Q:QUIT");
    if(gmod)
        printf("   U:UNDO    M:AUTO");
    printf("\n");
}

void main_menu(void)
{
    int status = 0;
    int pn = -1;
    char *mess = "The game: FIVE IN A ROW\n";
    puts(mess);
    _sleep(2000);
    while(1)
    {
        clrscr();
        status = main_ui();
        switch(status)
        {
        case 0:
            game(&pn);
            break;
        case 1:
            replay(&pn);
            break;
        case 2:
            clrscr();
            puts("Bye!");
            _sleep(900);
            return;
        }
    }
}

int game_ui(int arr[][MAX])         //Return the position
{
    int i;
    static int x=1, y=1;
    char ch;
    while(1)
    {
        prt_arr(arr, &x, &y, 0);
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
                arr[y][x] = 1;
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
                compute(1,arr);
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

void game(int *pn)
{
    int fakeptr = -1;
    int arr[MAX][MAX];
    clean_arr(arr);
    c = 0;
    clrscr();

    puts("Flipping a coin...");
    _sleep(3000);

    *pn = rand()%2;
    if(*pn == 1)
    {
        puts("Computer first\n");
        compute(2,arr);     //ZERO for USER, ONE for COMPUTER
    }
    else
    {
        puts("You first :D");       //ZERO for USER, ONE for COMPUTER
    }
    _sleep(1500);
    while(1)
    {
        if(is_tie(arr))
        {
            puts("Tie!!");
            _sleep(5000);
            break;
        }
        if(is_five(2,arr))
        {
            puts("You lose");
            _sleep(5000);
            break;
        }
        if(!game_ui(arr))   break;
        if(is_five(1,arr))
        {
            puts("You Win!!!");
            _sleep(5000);
            break;
        }
        prt_arr(arr,&fakeptr,&fakeptr,0);
        if(is_tie(arr))
        {
            puts("Tie!!");
            _sleep(5000);
            break;
        }
        _sleep(1200);
        compute(2,arr);
    }
    //Done
}
void replay(int *pn)
{
    int fake_ptr = -1;
    int arr[MAX][MAX];
    clean_arr(arr);
    int i, j;
    clrscr();
    if(*pn==-1)
    {
        puts("Please play the game first :D");
        _sleep(1500);
        return;
    }
    if(*pn==0)
    {
        for(i=0; i<c; i+=2)
        {
            arr[record[i][0]][record[i][1]] = 1;
            _sleep(1500);
            prt_arr(arr,&fake_ptr,&fake_ptr,1);
            if(i+1<c)
            {
                arr[record[i+1][0]][record[i+1][1]] = 2;
                _sleep(1500);
                prt_arr(arr,&fake_ptr,&fake_ptr,1);
            }
        }
    }
    else
    {
        for(i=0; i<c; i+=2)
        {
            arr[record[i][0]][record[i][1]] = 2;
            _sleep(1500);
            prt_arr(arr,&fake_ptr,&fake_ptr,1);
            if(i+1<c)
            {
                arr[record[i+1][0]][record[i+1][1]] = 1;
                _sleep(1500);
                prt_arr(arr,&fake_ptr,&fake_ptr,1);
            }
        }
    }
    puts("Press q to main menu");
    while(getch()=='q') return;

    //Done
}

int main_ui(void)
{
    char temp[MAX];
    int i = 0, j, k = 0;
    char ch;
    char itf[3][MAX] =
    {
        "1.Start!","2.Watch Replay","3.Exit"
    };
    printf("->  ");
    puts(itf[0]);
    puts(itf[1]);
    puts(itf[2]);
    puts("(SPACE:select\tW:UP\tS:DOWN)");

    while(1)
    {
        ch = getch();
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
            if(i<2) i++;
            break;
        case ' ':
            for(j=0; j<30; j++)   printf("\n");
            return i;
        }
        for(j=0; j<3; j++)
        {
            if(i==j)
                printf("->  ");
            puts(itf[j]);
        }
        puts("(SPACE:select\tW:UP\tS:DOWN)");
    }

}

int main(void)
{
    srand(time(NULL));
    main_menu();
    return 0;
}
