#include <stdio.h>
#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>
char* syscall_names[] = {
	"sys_freemem",
	"sys_chprio",
	"sys_getpid",
	"sys_getprio",
	"sys_gettime",
	"sys_kill",
	"sys_receive",
	"sys_recvclr",
	"sys_recvtim",
	"sys_resume",
	"sys_scount",
	"sys_sdelete",
	"sys_send",
	"sys_setdev",
	"sys_setnok",
	"sys_screate",
	"sys_signal",
	"sys_signaln",
	"sys_sleep",
	"sys_sleep10",
	"sys_sleep100",
	"sys_sleep1000",
	"sys_sreset",
	"sys_stacktrace",
	"sys_suspend",
	"sys_unsleep",
	"sys_wait",
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
