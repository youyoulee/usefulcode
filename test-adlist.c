#include "adlist.h"
#include "dbg.h"

#include <stdlib.h>

typedef struct test {
    char ip[20];
    int  port;
} test_t;

int match(void *ptr, void *key);

int main (int argc, char const *argv[])
{
    list *mylist = NULL;
    mylist = listCreate();
    check_mem(mylist);
    
    listSetFreeMethod(mylist, free);
    
    test_t *myt1 = (test_t *) malloc(sizeof(test_t));
    check_mem(myt1);
    strcpy(myt1->ip, "192.168.1.100");
    myt1->port = 1234;
    
    test_t *myt2 = (test_t *) malloc(sizeof(test_t));
    check_mem(myt2);
    strcpy(myt2->ip, "192.168.11.130");
    myt2->port = 4321;
    
    check_debug((listAddNodeTail(mylist, myt1) != NULL), "listAddNodeTail failed1");
    check_debug((listAddNodeTail(mylist, myt2) != NULL), "listAddNodeTail failed2");
    
    listIter *iter = listGetIterator(mylist, AL_START_HEAD);
    check_mem(iter);
    
    listNode *node = NULL;
    while ((node = listNext(iter)) != NULL) {
        test_t *t = (test_t *) node->value;
        log_info("ip  : %s", t->ip);
        log_info("port: %d", t->port);
    }
    
    listRelease(mylist);
    return 0;
    
error:
    if(mylist) listRelease(mylist);
    if(myt1) free(myt1);
    if(myt2) free(myt2);
    return -1;
}

int match(void *ptr, void *key)
{
    if (!ptr || !key)
        return -1;
    
    return 0;
}