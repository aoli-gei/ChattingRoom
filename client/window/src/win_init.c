#include "../../include/myhead.h"

void win_init(WINDOW *send_msg_win,WINDOW *show_msg_win)
{
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
   // start_color();

    height = LINES / 3;
    width = COLS;
    starty = LINES - LINES / 3;/*计算窗口中心位置的行数*/
    startx = 0; /*计算窗口中心位置的列数*/
    wrefresh(stdscr);
    send_msg_win = create_newwin(height, width, starty, startx);

    height = (LINES / 3) * 2 - 1;
    width = COLS;//10列
    starty = 0;/*计算窗口中心位置的行数*/
    startx = 0; /*计算窗口中心位置的列数*/
    show_msg_win = create_newwin(height, width, starty, startx);
}