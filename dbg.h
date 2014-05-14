#ifndef __DBG_H__
#define __DBG_H__


#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

/* Colors: printf(KRED "Hello World\n") */
#define  KNRM  "\x1B[0m"
#define  KRED  "\x1B[31m"
#define  KGRN  "\x1B[32m"
#define  KYEL  "\x1B[33m"
#define  KBLU  "\x1B[34m"
#define  KMAG  "\x1B[35m"
#define  KCYN  "\x1B[36m"
#define  KWHT  "\x1B[37m"


/* Macros for debug: Use -D DEBUG to turn on these macros */
#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) \
        fprintf(stderr, "[DEBUG] %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif


#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) \
        fprintf(stderr, KRED "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, \
                __LINE__, clean_errno(), ##__VA_ARGS__)
        
#define log_warn(M, ...) \
        fprintf(stderr, KYEL "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, \
                __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) \
        fprintf(stderr, KGRN "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, \
                ##__VA_ARGS__)
            
#define check(A, M, ...) \
        if(!(A)) { log_err(M, ##__VA_ARGS__); errno = 0; goto error; }
        
#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno = 0; goto error; }
        
#define check_mem(A) check((A), "Out of memory")
        
#define check_debug(A, M, ...) \
        if(!(A)) { debug(M, ##__VA_ARGS__); errno = 0; goto error; }


#endif
