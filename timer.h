#define    timerclear(tvp)        (tvp)->tv_sec = (tvp)->tv_usec = 0
#define    timerisset(tvp)        ((tvp)->tv_sec || (tvp)->tv_usec)

#define    timercmp(tvp, uvp, cmp)                        \
    (((tvp)->tv_sec == (uvp)->tv_sec) ?                \
        ((tvp)->tv_usec cmp (uvp)->tv_usec) :            \
        ((tvp)->tv_sec cmp (uvp)->tv_sec))
#endif

#define    timeradd(tvp, uvp, vvp)                        \
    do {                                \
        (vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;        \
        (vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;    \
        if ((vvp)->tv_usec >= 1000000) {            \
            (vvp)->tv_sec++;                \
            (vvp)->tv_usec -= 1000000;            \
        }                            \
    } while (0)
#define    timersub(tvp, uvp, vvp)                        \
    do {                                \
        (vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;        \
        (vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;    \
        if ((vvp)->tv_usec < 0) {                \
            (vvp)->tv_sec--;                \
            (vvp)->tv_usec += 1000000;            \
        }                            \
    } while (0)
