#include "../../include/myhead.h"
 
void *pthread(struct parameter *para)
{   
    int soc = *((*para).socket);
    WINDOW *main_win = (*para).win;
    WINDOW *send_msg_win = (*para).send_msg_win;
    WINDOW *online_people_win = (*para).online_people_win;

    scrollok(main_win, 1);
    int temp;
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);

    while(1)
    {
        memset(&soc_info, 0, sizeof(struct info));
        temp = recv(soc, &soc_info, sizeof(struct info), 0); 
        pthread_mutex_lock(&mutex);
        if(0 == temp) 
        {
            endwin();
            printf("Sever accidently break!\n");
            exit(0); 
        }

        if(soc_info.flag == 4)
        {
            online_print(&soc_info,send_msg_win,online_people_win);

            box(main_win, ACS_VLINE, ACS_HLINE);
            wrefresh(main_win);
            wmove(send_msg_win, 1, 1);
            wrefresh(send_msg_win); 
            
            strcpy(soc_info.ip,ip);
            soc_info.port = port;
            pthread_mutex_unlock(&mutex);
            continue;
        }      
        else
        {
            if((strcmp(soc_info.ip,ip_temp) == 0) && (soc_info.port == port_temp))
            {
                wattron(main_win,COLOR_PAIR(2));
                wprintw(main_win, "  %s:%d %s \n",soc_info.ip,soc_info.port,soc_info.tmc);
                wrefresh(main_win);
                wattroff(main_win,COLOR_PAIR(2));
                wprintw(main_win, "  %s\n\n",soc_info.message);
                box(main_win, ACS_VLINE, ACS_HLINE);
                wrefresh(main_win);
                wmove(send_msg_win, 1, 1);
                wrefresh(send_msg_win); 
            }

            else
            {
                wattron(main_win,COLOR_PAIR(3));
                wprintw(main_win, "  %s:%d %s \n",soc_info.ip,soc_info.port,soc_info.tmc);
                wrefresh(main_win);
                wattroff(main_win,COLOR_PAIR(3));
                wprintw(main_win, "  %s\n\n",soc_info.message);
                box(main_win, ACS_VLINE, ACS_HLINE);
                wrefresh(main_win);
                wmove(send_msg_win, 1, 1);
                wrefresh(send_msg_win); 
            }
        }
        strcpy(soc_info.ip,ip);
        soc_info.port = port;
        pthread_mutex_unlock(&mutex);

    }
}
