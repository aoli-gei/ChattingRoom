
/*************************************************
  Copyright (C)  , FG , Ltd.
  File name:      myhead.h 
  Author:  FG    Version:  V1.0      Date: 25/11/2014
  Description:    本程序的头文件，定义了相关的数据类型和结构体。
 
  Function List:  无
*************************************************/

#include <stdio.h> 
#include <sys/types.h> 
#include <sys/socket.h>
#include <stdlib.h> 
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>

struct info_ip_port
{
    char ip[50];
    int port;
};
struct info
{
    char tmc[50];
    char ip[50];
    int port;
    char message[100];
    struct info_ip_port mation[50]; 
    int online_num;
    int flag; 
};

struct para
{
    struct info *information;
    int *socket;
};
extern struct para param[50];
extern char str[];
extern int num;
extern int exit_flag; 
extern struct info all;
extern pthread_mutex_t mutex;
extern int online_num;
extern char online[50][50];
extern struct info soc_info[50];

void pth_read(struct para *param);
void pth_write(void * arg);
void sever_work(int *socket);
int sever_init(int *socket);
void online_inform();
void offline(struct info *in);

