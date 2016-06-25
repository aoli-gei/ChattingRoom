#include "../../include/myhead.h"

void *pthwrite(struct parameter *para)
{
    int soc = *((*para).socket);
    WINDOW *send_msg_win = (*para).win; 
    
    char string[100];

    while(1)
    {
        memset(str, 0, 100);
        mvwgetstr(send_msg_win, 1, 1, string);
        //pthread_mutex_lock(&mutex);
        if(strcmp(string,"end") == 0)
        {
            endwin();
            exit(0); 
        }
        if(strcmp(string,"clear") == 0)
        {
            wclear(send_msg_win);
            box(send_msg_win, ACS_VLINE, ACS_HLINE);
            continue;
        }  
         
        strcpy(soc_info.message, string);
        get_time(soc_info.tmc);
        strcpy(soc_info.ip,ip_temp);
        soc_info.port = port_temp;

        send(soc, &soc_info, sizeof(struct info), 0); 
        
        wclear(send_msg_win);
        box(send_msg_win, ACS_VLINE, ACS_HLINE);
        wrefresh(send_msg_win);
      //  pthread_mutex_unlock(&mutex);

    }
}
