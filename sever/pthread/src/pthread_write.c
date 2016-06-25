#include "../../include/myhead.h"

void pth_write(void * arg)
{
    int soc = (int)arg;

    while(1)
    {
        int temp = num;
        while(1) 
        {
            if(exit_flag == 0)
            { 
                exit_flag = 1;
                pthread_exit(pthread_self());
            } 

            if(num != temp)
            {
                // pthread_mutex_lock(&mutex);                
                send(soc, &all, sizeof(struct info), 0);

                if(all.flag == 4)
                {
                    printf("Online Info Send Over.\n");
                }
                else
                {
                    printf("Sending...:Time:%s Who:%s %d Message:%s\n",all.tmc,all.ip,all.port,all.message);
                }
                //  pthread_mutex_unlock(&mutex);
        
                break;
            }
        }
    }

    pthread_exit(pthread_self());
}
