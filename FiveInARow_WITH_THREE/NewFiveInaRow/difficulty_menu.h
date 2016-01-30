
int difclty_select(void)
{
    char ch;
    int i = 0 , j = 0;
    char itf[2][MAX] =
    {
        "1.Easy","2.Hard"
    };
    printf("->  ");
    puts(itf[0]);
    puts(itf[1]);
    puts("(SPACE:select\tW:UP\tS:DOWN\tQ:RETURN)");

    while(1)
    {
        ch = getch();
        clrscr();
        switch(ch)
        {
        case 'w':        //Arrow UP
            if(i>0) i--;
            break;
        case 's':    //Arrow DOWN
            if(i<1) i++;
            break;
        case 'q':
            return -1;
        case ' ':
            return i;
        }
        for(j=0; j<2; j++)
        {
            if(i==j)
                printf("->  ");
            puts(itf[j]);
        }
        puts("(SPACE:select\tW:UP\tS:DOWN\tQ:RETURN)");
    }

}

void game_menu(int *pn)
{
    int status = 0;

    while(1)
    {
        clrscr();
        if((status = difclty_select()) == -1)   return;
        //printf("INDIFF.h##status = %d\n",status);
        //system("pause");
        game(pn,status);

    }
}
