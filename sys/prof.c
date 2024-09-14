#include <profconst.h>
#include <stdio.h>
//#include <proc.h>
//unsigned long prof_counter[MAX_SYSCALL];
//unsigned long prof_duration[MAX_SYSCALL];
//int is_prof = 0;
#include <conf.h>
#include <kernel.h>
#include <proc.h>
char* syscall_names[] = {
	"sys_sleep",
	"sys_create",
	"sys_resume"
};

void syscallsummary_start() {
	unsigned long *prof_counter = proctab[currpid].prof_counter; 
	unsigned long *prof_duration = proctab[currpid].prof_duration; 
	int* is_prof = &proctab[currpid].is_prof; 
	*is_prof = 1;
	for (int i = 0; i < MAX_SYSCALL; i++) {
	    prof_counter[i] = 0;
	    prof_duration[i] = 0;
	}
}


void syscallsummary_stop() {
	int *is_prof = &proctab[currpid].is_prof;
	*is_prof = 0;
}

void printsyscallsummary() {
	unsigned long *prof_counter = proctab[currpid].prof_counter; 
	unsigned long *prof_duration = proctab[currpid].prof_duration;
	printf("Process [pid: %d]\n", currpid);
	for (int i = 0; i < MAX_SYSCALL; i++) {
		if (prof_counter[i]) {
			printf("\tSyscall: %s, count: %ld, average execution time: %ld (ms) \n", 
				syscall_names[i], prof_counter[i], prof_duration[i]/prof_counter[i]);
		}
	}

}
