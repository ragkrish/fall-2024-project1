/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */

SYSCALL1(SLEEP, sleep, int, n)
{
	// start time 
	STATWORD ps;    
	if (n<0 || clkruns==0)
		// end time
		return(SYSERR);
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
		// end time
		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);
	// end time
	return(OK);
}
