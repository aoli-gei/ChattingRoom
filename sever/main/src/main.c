#include "../../include/myhead.h"

char str[100] = {0};
int num = 0;
int exit_flag = 1;
struct info soc_info[50];
struct para param[50];
struct info all;
int online_num = 0;
char online[50][50];
 
pthread_mutex_t mutex;

int main()
{
    system("clear");
    int soc;
    
    sever_work(&soc);
}
 