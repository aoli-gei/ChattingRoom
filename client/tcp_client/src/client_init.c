#include "../../include/myhead.h"

void client_init()
{
    WINDOW *show_msg_win;
    WINDOW *send_msg_win;
    WINDOW *online_people_win;
/***************************************************************************************************** 

                                            win


  *****************************************************************************************************/
    int startx, starty, width, height;

    initscr(); /* 初始化并进入curses 模式*/
    cbreak(); /* 行缓冲禁止，传递所有控制信息*/
    keypad(stdscr, TRUE); 
  
    if(has_colors() == FALSE)
    { 
        endwin();
        printf("You terminal does not support color\n"); 
        exit(1);
    } 
    start_color();
/**********************send_msg_win************************/
    height = LINES / 3;
    width = COLS;
    starty = LINES - LINES / 3;
    startx = 0;
    send_msg_win = create_newwin(height, width, starty, startx);
   // init_pair(1, COLOR_BLACK, COLOR_WHITE);
    wrefresh(send_msg_win);
/********************message_win***************************/
    height = (LINES / 3) * 2 + 1;
    width = (COLS / 3) * 2 + 1;
    starty = 0;
    startx = 0;
    show_msg_win = create_newwin(height, width, starty, startx);
    wrefresh(show_msg_win);
/********************online_win***************************/
    height = (LINES / 3) * 2 + 1;
    width = COLS / 3;
    starty = 0;
    startx = COLS - COLS / 3; 
    wrefresh(stdscr);
    online_people_win = create_newwin(height, width, starty, startx);
    wrefresh(show_msg_win);

/*****************socket**************/
    int soc;
    int ret;

    if((soc = socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
        endwin();
        perror("socket");
        close(soc);
        exit(0);
    } 

/***************************************************************************************************** 

                                            socket


  *****************************************************************************************************/
    /*****************connect*************/
    struct sockaddr_in seraddr;
    memset(&seraddr, 0, sizeof(struct sockaddr_in));
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(8888);     //服务器的端口号
    seraddr.sin_addr.s_addr = inet_addr("192.168.1.180");  //服务器的IP
    if(connect(soc, (struct sockaddr*)&seraddr, sizeof(struct sockaddr)) == -1)
    {
        endwin();
        perror("connect");
        printf("Please check whether sever is running.\n");
        close(soc);
        exit(-1);
    }

    wprintw(show_msg_win, "\n  Connect successfully!\n");
    wprintw(show_msg_win, "  Sever: %s:%d\n","192.168.2.180",8888);
    read(soc,str,100);
    strcpy(soc_info.ip,str);
    strcpy(ip,str);
    strcpy(ip_temp,str);
    wprintw(show_msg_win, "  Client: %s",str);
    read(soc,&port,100);
    soc_info.port = port;
    port_temp = port;
    wprintw(show_msg_win,":%d\n\n",port);
    box(show_msg_win, ACS_VLINE, ACS_HLINE);
    wrefresh(show_msg_win);


/***************************************************************************************************** 

                                            pthread


*****************************************************************************************************/
    pthread_t pth_read,pth_write;

    if(pthread_mutex_init(&mutex,NULL) != 0 )
    {
        printf("Init metux error.");
        exit(1);
    }

    struct parameter para,para2,para3,para4;
    memset(&para, 0, sizeof(struct parameter));

    para.socket = &soc;
    para.win = show_msg_win;
    para.send_msg_win = send_msg_win;
    para.online_people_win = online_people_win;

    if(0 != (ret = pthread_create(&pth_read, NULL, (void *)pthread, &para)))  //读消息线程
    {
        endwin();
        perror("pthread_create");
        exit(1);
    }

    memset(&para2, 0, sizeof(struct parameter));
    para2.socket = &soc;
    para2.win = send_msg_win;

    if(0 != (ret = pthread_create(&pth_write, NULL, (void *)pthwrite, &para2)))//写消息线程
    {
        endwin();
        perror("pthread_create");
        exit(2);
    }
    wmove(send_msg_win,1,1);
    box(send_msg_win, ACS_VLINE, ACS_HLINE);
    wrefresh(send_msg_win);
  /*  para3.socket = &soc;
    para3.win = online_people_win;
    para3.send_msg_win = send_msg_win;
    if(0 != (ret = pthread_create(&pth_online_ask, NULL, (void *)pthread_online, &para3)))  //读消息线程
    {
        endwin();
        perror("pthread_create");
        exit(1);
    }*/
/*
    para4.socket = &soc;
    if(0 != (ret = pthread_create(&pth_online_ans, NULL, (void *)pthread_online_answer, &para4)))  //读消息线程
    {
        endwin();
        perror("pthread_create");
        exit(1);
    }*/

    /****wait***/
    pthread_join(pth_read, NULL);
    pthread_join(pth_write, NULL); 



    close(soc);
    endwin();
}
