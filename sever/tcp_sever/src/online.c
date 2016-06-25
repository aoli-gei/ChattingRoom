#include "../../include/myhead.h"

void online_inform()
{
    int i;          
        
    for(i = 0; i < online_num; i++)
    {
        strcpy((all.mation[i]).ip,soc_info[i].ip);
        (all.mation[i]).port = soc_info[i].port;
    }
    all.online_num = online_num;
    all.flag = 4;
    num++;

        printf("\nonline users:\n");
        printf("**************\n");
        if(online_num == 0)
        {
            printf("Now no users oline.\n");
        }
        else
        {
            for(i = 0; i < online_num; i++)
            {
                printf("%s:%d\n",(all.mation[i]).ip,(all.mation[i]).port);
            }
        }   
        printf("**************\n");   

}
void offline(struct info *in)
{
    struct info inform = *in;
    int i,j;
    for(i = 0; i < 50; i++)
    {
        if ((strcmp(soc_info[i].ip, inform.ip) == 0) && (soc_info[i].port == inform.port))
        {
            for(j = i; j < 49; j++)
            {
                strcpy(soc_info[j].ip, soc_info[j+1].ip);
                soc_info[j].port = soc_info[j+1].port;
            }
        }
    }

    online_num--;

    online_inform();
   
}