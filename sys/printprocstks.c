
#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

void printprocstks(int prio)
{
        for (int pid = 0; pid < NPROC; pid++) {
                struct pentry   *proc = &proctab[pid];
                if (proc->pprio < prio) continue;
                // stack base, stack size, stacklimit, and stack pointer. Also, for each process, include the process name, the process id and the process priority.
		unsigned long* sp;
		printf("current pid %d\n", currpid);
                if (pid == currpid) {
                        asm("movl %%esp, %0" : "=r" (sp));
                } else {
                        sp = (unsigned long *)proc->pesp;
                }
                printf("process name [%s]\n\tpid: %d\n\tpriority: %d\n\tbase: 0x%x\n\tlimit: 0x%x\n\tlen: 0x%x\n\tpointer: 0x%x \n",
                                proc->pname, pid, proc->pprio, proc->pbase, proc->plimit, proc->pstklen, sp);

        }
}
