#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

unsigned int zfunctionC(unsigned int param) {
    // Step 1: Clear the 20th to 27th bits
    param &= 0xfffff00f;

    // Step 2: Shift by 8 bits to the left
    param <<= 8;

    // Step 3: Fill the right-most 8 bits with 1s
    param |= 0x000000ff;

    return param;
}


/*------------------------------------------------------------------------
*  task3 start --  user main program
*------------------------------------------------------------------------
*/
int prX;
void halt();

prch(c)
char c;
{
    int i;
    sleep(1);	
}
int task3()
{
//    kprintf("Task 3 (printsyscallsummary)\n");
    syscallsummary_start();        
    resume(prX = create(prch,2000,20,"proc X",1,'A'));
    sleep(2);
    syscallsummary_stop();
    printsyscallsummary();
//    kprintf("Task 3 (printsyscallsummary) done\n");
    return 0;
}

/*------------------------------------------------------------------------
*  task3 end --  user main program
*------------------------------------------------------------------------
*/


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
	task3();
	task3();
	return 0;
}
