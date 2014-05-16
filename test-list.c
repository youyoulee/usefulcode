#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct client {
    struct list_head    head;
    int    port;
    const char *addr;
} client_t;

static void append(client_t *client_list, const char *addr, int port)
{
    client_t *aclient = (client_t *) malloc(sizeof(client_t));
    if (!aclient)
        exit(1);
    
    aclient->addr = addr;
    aclient->port = port;
    
    list_add_tail(&aclient->head, &client_list->head);
}

int main (int argc, char const *argv[])
{
    client_t client_list;
    client_t *client;
    
    INIT_LIST_HEAD(&client_list.head);
    
    append(&client_list, "Lee", 12345);
    append(&client_list, "Yan", 54321);
    append(&client_list, "lee", 12345);
    
    list_for_each_entry(client, &client_list.head, head) {
        printf("addr: %s\t port: %d\n", client->addr, client->port);
    }
    
    return 0;
}