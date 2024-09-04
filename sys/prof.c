#include <profconst.h>
#include <stdio.h>
unsigned long prof_counter[MAX_SYSCALL];
unsigned long prof_duration[MAX_SYSCALL];
int is_prof = 0;
char* syscall_names[] = {
	"sleep",
	"create",
	"resume"
};

void syscallsummary_start() {
	is_prof = 1;
	for (int i = 0; i < MAX_SYSCALL; i++) {
	    prof_counter[i] = 0;
	    prof_duration[i] = 0;
	}
}


void syscallsummary_stop() {
	is_prof = 0;
}

void printsyscallsummary() {
	for (int i = 0; i < MAX_SYSCALL; i++) {
		//if (prof_counter[i]) {
		if (i < 3)
			printf("syscall %s freq %ld total time %ld ms. \n", 
				syscall_names[i], prof_counter[i], prof_duration[i]);
		//}
	}

}
