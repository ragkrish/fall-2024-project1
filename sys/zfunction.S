/* zfunction.s - zfunction */

    .text
    .globl zfunction

zfunction:
   mov    0x4(%esp),%eax
   shl    $0x8,%eax
   and    $0xfff00f00,%eax
   or     $0xff,%al
   ret
