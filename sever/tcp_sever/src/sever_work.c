#include "../../include/myhead.h"

void sever_work(int *socketc)
{
    int soc = *socket;
    printf("Sever initializing...\n");
    /*****************socket**************/
    if((soc = socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
        perror("socket");
        exit(0);
    }
    /*****************bind**************/
    static struct sockaddr_in my_addr;                     //定义结构体变量
    memset(&my_addr, 0, sizeof(struct sockaddr_in));   //将结构体清空
    my_addr.sin_family = AF_INET;                   //表示采用IPv4网络协议
    my_addr.sin_port = htons(8888);     //表示端口号为8888    
    my_addr.sin_addr.s_addr = INADDR_ANY;
 
    if(bind(soc, (struct sockaddr*)&my_addr, sizeof(struct sockaddr_in)) == -1)
    { 
        perror("bind");
        printf("Port 8888 is occupied by other programme.\n");
        close(soc);
        exit(-1); 
    }
    /*****************listen**************/
    if(-1 == listen(soc,100))
    {
        perror("listen");
        close(soc);
        exit(-2);
    }
    printf("Sever init ok !\n");
//////////////////////////////////////////////////////////////////////////////
    int new_soc;   
    int port;
    int ret;
    int i = 0;
    int len = sizeof(struct sockaddr_in);
    pthread_t pthread,pthwrite;

    struct sockaddr_in client_soc;
    memset(&client_soc, 0, sizeof(struct sockaddr));

    while(1)
    {
        printf("Waiting for the %dst client to connectting...\n",online_num+1);

        new_soc = accept(soc, (struct sockaddr*)&client_soc, &len);

        port = ntohs(client_soc.sin_port);      
        write(new_soc,inet_ntoa(client_soc.sin_addr),100);
        write(new_soc,&port,100);

        soc_info[online_num].port = port;
        strcpy(soc_info[online_num].ip,inet_ntoa(client_soc.sin_addr));

        param[i].socket = &new_soc;
        param[i].information = &(soc_info[online_num]);

        printf("%s:%d successfully connect!\n",inet_ntoa(client_soc.sin_addr),ntohs(client_soc.sin_port));

        if(0 != (ret = pthread_create(&pthread, NULL, (void *)pth_read, &(param[i]))))
        {
            perror("pthread_create");
            printf("error!\n");
            exit(1);
        }
        
        if(0 != (ret = pthread_create(&pthwrite, NULL, (void *)pth_write, (void *)new_soc)))
        {
            perror("pthread_create");
            printf("error!\n");
            exit(1);
        }
        
        i++;
        online_num++;

    }

    close(new_soc);
    close(soc);

}









