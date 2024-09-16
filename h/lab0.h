#include<proc.h>

long zfunction(long param);
void printprocstks(int prio);

extern char* syscall_names[];
extern unsigned long        ctr1000;

#define SYSCALL1(id, name, t1, v1) SYSCALL name(t1 v1) { \
        unsigned long *prof_counter = proctab[currpid].prof_counter; \
        unsigned long *prof_duration = proctab[currpid].prof_duration; \
        int is_prof = proctab[currpid].is_prof; \
        unsigned long start;    \
        if (is_prof) {  \
                prof_counter[id]++;     \
                start = ctr1000;        \
        }       \
        SYSCALL ret = name##internal(v1);       \
        if (is_prof) {  \
                unsigned long end = ctr1000;    \
                if (end >= start) \
                        prof_duration[id] += end - start;       \
        }       \
        return ret;     \
}       \
SYSCALL name##internal(t1 v1)

#define SYSCALL2(id, name, t1, v1, t2, v2) SYSCALL name(t1 v1, t2 v2) { \
        unsigned long *prof_counter = proctab[currpid].prof_counter; \
        unsigned long *prof_duration = proctab[currpid].prof_duration; \
        int is_prof = proctab[currpid].is_prof; \
        unsigned long start;    \
        if (is_prof) {  \
                prof_counter[id]++;     \
                start = ctr1000;        \
        }       \
        SYSCALL ret = name##internal(v1, v2);   \
        if (is_prof) {  \
                unsigned long end = ctr1000;    \
                if (end >= start) \
                        prof_duration[id] += end - start;       \
        }       \
        return ret;     \
}       \
SYSCALL name##internal(t1 v1, t2 v2)

#define SYSCALL3(id, name, t1, v1, t2, v2, t3, v3) SYSCALL name(t1 v1, t2 v2, t3 v3) { \
        unsigned long *prof_counter = proctab[currpid].prof_counter; \
        unsigned long *prof_duration = proctab[currpid].prof_duration; \
        int is_prof = proctab[currpid].is_prof; \
        unsigned long start;    \
        if (is_prof) {  \
                prof_counter[id]++;     \
                start = ctr1000;        \
        }       \
        SYSCALL ret = name##internal(v1, v2, v3);       \
        if (is_prof) {  \
                unsigned long end = ctr1000;    \
                if (end >= start) \
                        prof_duration[id] += end - start;       \
        }       \
        return ret;     \
}       \
SYSCALL name##internal(t1 v1, t2 v2, t3 v3)


#define SYSCALL6(id, name, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6) SYSCALL name(v1, v2, v3, v4, v5, v6) \
        t1 v1; \
        t2 v2; \
        t3 v3; \
        t4 v4; \
        t5 v5; \
        t6 v6; \
        { \
        unsigned long *prof_counter = proctab[currpid].prof_counter; \
        unsigned long *prof_duration = proctab[currpid].prof_duration; \
        int is_prof = proctab[currpid].is_prof; \
        unsigned long start;    \
        if (is_prof) {  \
                prof_counter[id]++;     \
                start = ctr1000;        \
        }       \
        SYSCALL ret = name##internal(v1, v2, v3, v4, v5, v6);   \
        if (is_prof) {  \
                unsigned long end = ctr1000;    \
                if (end >= start) \
                        prof_duration[id] += end - start;       \
        }       \
        return ret;     \
}       \
SYSCALL name##internal(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6)


#define FREEMEM    0
#define CHPRIO     1
#define GETPID     2
#define GETPRIO    3
#define GETTIME    4
#define KILL       5
#define RECEIVE    6
#define RECVCLR    7
#define RECVTIM    8
#define RESUME     9
#define SCOUNT     10
#define SDELETE    11
#define SEND       12
#define SETDEV     13
#define SETNOK     14
#define SCREATE    15
#define SIGNAL     16
#define SIGNALN    17
#define SLEEP      18
#define SLEEP10    19
#define SLEEP100   20
#define SLEEP1000  21
#define SRESET     22
#define STACKTRACE 23
#define SUSPEND    24
#define UNSLEEP    25
#define WAIT       26

#define MAX_SYSCALL 50

void syscallsummary_stop();
void syscallsummary_start();
void printsyscallsummary();
