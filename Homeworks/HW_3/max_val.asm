    .data

    .text
    .align    2
    .globl  main


main:
    li $v0, 5 #Get val
    syscall
    blez $v0, exit #checks if should exit
    move $t1, v0 #move to iters
    li $v0, 5 #Get val for max
    syscall
    move $t0, $v0 #Sets max val to input
    addi $t1, $t1, -1 #subtract one from to iterate

run_max:
    blez $t1, exit # break loop
    li $v0, 5 #Get val for max
    syscall
    addi $t1, $t1, -1 #subtract one from to iterate
    bgt $t1, $t0, reassign_max #reassign max val
    b run_max # Run loop again

reassign_max:
    move $t0, $v0
    b run_max #next value

exit:
    move $a0, $t0
    li $v0, 1 # prep Print
    syscall
    jr $ra
