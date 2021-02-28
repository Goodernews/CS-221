    .data

    .text
    .align    2
    .globl  main

string arr #intialize string

main:
    li $t0, 0 # load length
    $t1 # load first

loop:
    blez $t1, exit #condtion to terminate
    addi $t0, $t0, 1 #add one to length
    #shift to next byte in word
    b loop


exit:
    move $a0, $t1
    li $v0, 1 # prep Print
    syscall
