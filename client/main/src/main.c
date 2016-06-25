#include "../../include/myhead.h"

struct info soc_info;
char ip[50];
int port = 0; 
char str[100];
char ip_temp[50];
int port_temp;


pthread_mutex_t mutex;

int main() 
{
    system("clear");
    client_init();

    return 0;  
}
