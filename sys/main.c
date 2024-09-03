#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <bitfunc.h>

unsigned int zfunctionC(unsigned int param) {
    // Step 1: Clear the 20th to 27th bits
    param &= 0xfffff00f;

    // Step 2: Shift by 8 bits to the left
    param <<= 8;

    // Step 3: Fill the right-most 8 bits with 1s
    param |= 0x000000ff;

    return param;
}

//struct	pentry	{
//	char	pstate;			/* process state: PRCURR, etc.	*/
//	int	pprio;			/* process priority		*/
//	int	pesp;			/* saved stack pointer		*/
//	STATWORD pirmask;		/* saved interrupt mask		*/
//	int	psem;			/* semaphore if process waiting	*/
//	WORD	pmsg;			/* message sent to this process	*/
//	char	phasmsg;		/* nonzero iff pmsg is valid	*/
//	WORD	pbase;			/* base of run time stack	*/
//	int	pstklen;		/* stack length			*/
//	WORD	plimit;			/* lowest extent of stack	*/
//	char	pname[PNMLEN];		/* process name			*/
//	int	pargs;			/* initial number of arguments	*/
//	WORD	paddr;			/* initial code address		*/
//	WORD	pnxtkin;		/* next-of-kin notified of death*/
//	Bool	ptcpumode;		/* proc is in TCP urgent mode	*/
//	short	pdevs[2];		/* devices to close upon exit	*/
//	int	fildes[_NFILE];		/* file - device translation	*/
//	int	ppagedev;		/* pageing dgram device		*/
//	int	pwaitret;
//};


void printprocstks(int prio)
{
        for (int pid = 0; pid < NPROC; pid++) {
                struct pentry   *proc = &proctab[pid];
                if (proc->pprio < prio) continue;
                // stack base, stack size, stacklimit, and stack pointer. Also, for each process, include the process name, the process id and the process priority.
                unsigned long   *sp;
		printf("current pid %d\n", currpid);
                if (pid == currpid) {
                        asm("movl %%esp, %0" : "=r" (sp));
                } else {
                        sp = (unsigned long *)proc->pesp;
                }
                printf("process name %s, id %d, prio %d, stack base 0x%x, stack size 0x%x, stacklimit 0x%x, stack pointer 0x%x \n",
                                proc->pname, pid, proc->pprio, proc->pbase, proc->pstklen, proc->plimit, sp);

        }
}


/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
int main()
{
	kprintf("\n\nHello CSC 501\n\n");
	kprintf("\n\ntest zfunction 0x%x \n\n", zfunction(0xaabbccdd));
	kprintf("\n\ntest zfunction C 0x%x \n\n", zfunctionC(0xaabbccdd));
	printprocstks(10);
	return 0;
}
