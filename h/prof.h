#include<profconst.h>

extern unsigned long prof_counter[];
extern unsigned long prof_duration[];
extern int is_prof;
extern char* syscall_names[];
extern unsigned long        ctr1000;

#define SYSCALL1(id, name, t1, v1) SYSCALL name(t1 v1) { \
	unsigned long start;	\
	if (is_prof) {	\
		prof_counter[id]++;	\
		start = ctr1000; 	\
	}	\
	SYSCALL ret = name##internal(v1);	\
	if (is_prof) {	\
		unsigned long end = ctr1000;	\
		if (end >= start) \
			prof_duration[id] += end - start;	\
	}	\
	return ret;	\
} 	\
SYSCALL name##internal(t1 v1)

#define SYSCALL2(id, name, t1, v1, t2, v2) SYSCALL name(t1 v1, t2 v2) { \
	unsigned long start;	\
	if (is_prof) {	\
		prof_counter[id]++;	\
		start = ctr1000; 	\
	}	\
	SYSCALL ret = name##internal(v1, v2);	\
	if (is_prof) {	\
		unsigned long end = ctr1000;	\
		if (end >= start) \
			prof_duration[id] += end - start;	\
	}	\
	return ret;	\
} 	\
SYSCALL name##internal(t1 v1, t2 v2)

#define SYSCALL3(id, name, t1, v1, t2, v2, t3, v3) SYSCALL name(t1 v1, t2 v2, t3 v3) { \
	unsigned long start;	\
	if (is_prof) {	\
		prof_counter[id]++;	\
		start = ctr1000; 	\
	}	\
	SYSCALL ret = name##internal(v1, v2, v3);	\
	if (is_prof) {	\
		unsigned long end = ctr1000;	\
		if (end >= start) \
			prof_duration[id] += end - start;	\
	}	\
	return ret;	\
} 	\
SYSCALL name##internal(t1 v1, t2 v2, t3 v3)

#define SYSCALL6(id, name, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6) SYSCALL name(v1, v2, v3, v4, v5, v6) \
	t1 v1; \
	t2 v2; \
	t3 v3; \
	t4 v4; \
	t5 v5; \
	t6 v6; \
	{ \
	unsigned long start;	\
	if (is_prof) {	\
		prof_counter[id]++;	\
		start = ctr1000; 	\
	}	\
	SYSCALL ret = name##internal(v1, v2, v3, v4, v5, v6);	\
	if (is_prof) {	\
		unsigned long end = ctr1000;	\
		if (end >= start) \
			prof_duration[id] += end - start;	\
	}	\
	return ret;	\
} 	\
SYSCALL name##internal(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6)
