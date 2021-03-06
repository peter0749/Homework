
void generate_demo(void)
{
    int arr[MAX][MAX];
    clean_arr(arr);
    int tar = 1;
    clrscr();
    generate_board();
    puts("Press q to main menu.");
    while(game_ui(arr,tar));
    return;
}

void coop(int *pn)
{
    int state;
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
        puts("White first :D");
        _sleep(1500);
        generate_board();
        if(!game_ui(arr,2)) return;
    }
    else
    {
        puts("Black first :D");
        _sleep(1500);
        generate_board();
    }

    while(1)
    {
        if(is_tie(arr))
        {
            puts("Tie!!");
            _sleep(5000);
            break;
        }

        state = is_n(2,arr,5);
        if(state==1)
        {
            puts("White is the winner!");
            _sleep(5000);
            break;
        }
        else if(state==-1)
        {
            puts("Black is the winner!");
            _sleep(5000);
            break;
        }
        if(!game_ui(arr,1))   return;

        state = is_n(1,arr,5);
        if(state==1)
        {
            puts("Black is the winner!");
            _sleep(5000);
            break;
        }
        else if(state==-1)
        {
            puts("White is the winner!");
            _sleep(5000);
            break;
        }
        //prt_arr(arr,&fakeptr,&fakeptr,0,0);
        if(is_tie(arr))
        {
            puts("Tie!!");
            _sleep(5000);
            break;
        }
        //_sleep(800);
        if(!game_ui(arr,2))   break;
    }
}

void game(int *pn, int difcult)     //difcult 0:easy 1:hard
{
    int state;
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
        _sleep(1500);
        generate_board();
        compute(2,arr,difcult,1);     //ZERO for USER, ONE for COMPUTER
    }
    else
    {
        puts("You first :D");       //ZERO for USER, ONE for COMPUTER
        _sleep(1500);
        generate_board();
    }

    while(1)
    {
        if(is_tie(arr))
        {
            puts("Tie!!");
            _sleep(5000);
            break;
        }

        state = is_n(2,arr,5);
        if(state==1)
        {
            puts("You lose");
            _sleep(5000);
            break;
        }
        else if(state==-1)
        {
            puts("You Win!!!");
            _sleep(5000);
            break;
        }
        if(!game_ui(arr,1))   break;

        state = is_n(1,arr,5);
        if(state==1)
        {
            puts("You Win!!!");
            _sleep(5000);
            break;
        }
        else if(state==-1)
        {
            puts("You lose");
            _sleep(5000);
            break;
        }

        prt_arr(arr,fakeptr,fakeptr,&fakeptr,&fakeptr,0,0);
        if(is_tie(arr))
        {
            puts("Tie!!");
            _sleep(5000);
            break;
        }
        _sleep(800);
        compute(2,arr,difcult,1);
        prt_arr(arr,fakeptr,fakeptr,&fakeptr,&fakeptr,0,0);
        _sleep(800);
    }
    //Done
}
void replay(int *pn)
{
    k = 0;
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
    generate_board();
    if(*pn==0)
    {
        for(i=0; i<c; i+=2)
        {
            arr[record[i][0]][record[i][1]] = 1;
            _sleep(900);
            prt_arr(arr,fake_ptr,fake_ptr,&fake_ptr,&fake_ptr,1,0);
            if(i+1<c)
            {
                arr[record[i+1][0]][record[i+1][1]] = 2;
                _sleep(900);
                prt_arr(arr,fake_ptr,fake_ptr,&fake_ptr,&fake_ptr,1,0);
            }
        }
    }
    else
    {
        for(i=0; i<c; i+=2)
        {
            arr[record[i][0]][record[i][1]] = 2;
            _sleep(900);
            prt_arr(arr,fake_ptr,fake_ptr,&fake_ptr,&fake_ptr,1,0);
            if(i+1<c)
            {
                arr[record[i+1][0]][record[i+1][1]] = 1;
                _sleep(900);
                prt_arr(arr,fake_ptr,fake_ptr,&fake_ptr,&fake_ptr,1,0);
            }
        }
    }
    gotoxy(0,21);
    puts("Press q to main menu");
    while(getch()=='q') return;

    //Done
}

