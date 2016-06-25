  
/*************************************************
  Copyright (C)  , FG , Ltd.
  File name:      myhead.h 
  Author:  FG    Version:  V1.0      Date: 25/11/2014
  Description:    本程序的头文件，定义了相关的数据类型和结构体。
 
  Function List:  无
*************************************************/

#include <ncurses.h>
#include <stdio.h> 
#include <sys/types.h> 
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>  
#include <pthread.h> 
#include <time.h>

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

struct parameter
{
    int *socket;
    WINDOW *win;
    WINDOW *send_msg_win;
    WINDOW *online_people_win;
};

extern struct info soc_info;
extern char ip[50];
extern int port;
extern char str[100];
extern char ip_temp[50];
extern int port_temp;
extern pthread_mutex_t mutex;



WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);
void client_init();
void win_init(WINDOW *send_msg_win,WINDOW *show_msg_win);
void get_time(char *tmc);
void *pthread(struct parameter *para);
void *pthwrite(struct parameter *para);
void online_print(struct info *sock,WINDOW *send_msg_win,WINDOW *online_people_win);

