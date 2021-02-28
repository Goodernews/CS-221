# This program read in two positive integers, a and b, from the user and
# prints a * b.
    .text
    .align 2
    .globl main
main:
    li   $v0, 5          # set up reading of first int
    syscall
    move $t0, $v0        # store first int, a, into $t0
    blez  $t0, done   # go to done if a not positive
    li   $v0, 5          # set up reading of first int
    syscall
    move $t1, $v0        # store first int, b, into $t1
    blt  $t1, $0, done   # go to done if b not positive

    move $t3, $0
loop:
    beq  $t0, $0, print
    add  $t3, $t3, $t1
    addi $t0, $t0, -1
    b loop

print:
    move $a0, $t3
    li   $v0, 1       # set up "print int" system call
    syscall           # execute system call

done:
    jr   $ra          # return from main method
