#include "../../include/myhead.h"

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;
    local_win = newwin(height, width, starty, startx);
    box(local_win, ACS_VLINE, ACS_HLINE); /* 0, 0 是字符默认的行列起始位置*/

    wrefresh(local_win); /*刷新窗口缓冲，显示box */
    return local_win;
}