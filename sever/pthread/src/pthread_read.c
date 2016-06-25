#include "../../include/myhead.h"

void pth_read(struct para *param)
{
    int soc = *((*param).socket);
    struct info msg = *((*param).information);
    int temp;
    sleep(1);
    online_inform();
    while(1)
    {       
        memset(&msg, 0, sizeof(struct info));

        temp = recv(soc, &msg, sizeof(struct info), 0);
       // pthread_mutex_lock(&mutex);
        if(0 == temp)
        { 
            offline((*param).information);

            printf("Client accidently break!\n");
            exit_flag = 0;
            pthread_exit(pthread_self());
           
        } 
        printf("Time:%s Who:%s %d Message:%s\n",msg.tmc,msg.ip,msg.port,msg.message);

        //memset(&all, 0, sizeof(struct info));
        strcpy(all.ip,msg.ip);
        all.port = msg.port;
        strcpy(all.message,msg.message);
        strcpy(all.tmc,msg.tmc);
        all.flag = 0;
        printf("port :%d send messages!\n",msg.port);

        num++;     
       // pthread_mutex_unlock(&mutex);
    }

    pthread_exit(pthread_self());

}
