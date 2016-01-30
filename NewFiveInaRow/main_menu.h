


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
            game_menu(&pn);
            break;
        case 1:
            coop(&pn);
            break;
        case 2:
            replay(&pn);
            break;
        case 3:
            clrscr();
            puts("Bye!");
            _sleep(900);
            return;
        }
    }
}

