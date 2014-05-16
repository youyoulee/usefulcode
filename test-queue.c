#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "queue.h"


typedef struct client {
    char addr[32];
    int  port;

    LIST_ENTRY(client) entries;
} client_t;

int main (int argc, char const *argv[])
{
    LIST_HEAD(, client) client_list;
    LIST_INIT(&client_list);

    /* Add 10 clients to list */
    client_t *tmp = NULL;
    for(unsigned i = 0; i < 10; ++i) {
        client_t *c = (client_t *) malloc(sizeof(client_t));
        if (!c) {
            fprintf(stderr, "malloc error\n");
            exit(EXIT_FAILURE);
        }

        memset(c, 0, sizeof(client_t));

        strncpy(c->addr, "192.168.1.101", sizeof(c->addr));
        c->port = i+1;
        
        if (i == 0)
            LIST_INSERT_HEAD(&client_list, c, entries);
        else
            LIST_INSERT_AFTER(tmp, c, entries);
        
        tmp = c;
    }

    /* Check add result */
    client_t *c = NULL;
    client_t *t = NULL;
    printf("Addr\t\t\tPort\t\t\n");
    LIST_FOREACH_SAFE(c, &client_list, entries, t) {
        if (!c)
            continue;

        printf("%s\t\t", c->addr);
        printf("%d\t\t\n", c->port);
        
        /* Remove element */
        LIST_REMOVE(c, entries);
        free(c);
    }

    return 0;
}
