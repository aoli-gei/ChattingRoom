#include "../../include/myhead.h"

void online_print(struct info *sock,WINDOW *send_msg_win,WINDOW *online_people_win)
{
    struct info soc = *sock;
    int i;
    
    init_pair(4, COLOR_RED, COLOR_BLACK); 
    wclear(online_people_win);
    wmove(online_people_win,1,1);
    wprintw(online_people_win," online people\n");
    wprintw(online_people_win,"  *************\n");
    wrefresh(online_people_win);

    wattron(online_people_win,COLOR_PAIR(4));

    for(i = 0; i < soc.online_num; i++)
    {
        wprintw(online_people_win,"  %s:%d\n",(soc.mation[i]).ip,(soc.mation[i]).port);
    }

    wrefresh(online_people_win);
    wattroff(online_people_win,COLOR_PAIR(4));
    box(online_people_win, ACS_VLINE, ACS_HLINE);
    wrefresh(online_people_win);

    wmove(send_msg_win, 1, 1);
    wrefresh(send_msg_win);
}
