          .data

      .text
      .align    2
      .globl  main


main:
      li    $v0, 5 #Get val
      syscall
      li $t1, 0 #t1 is amount total
      b loop_sum

loop_sum:
      add $t1, $v0, $t1 #add to total
      addi $v0, $v0, -1 #subtract one from to iterate
      bgtz $t1, loop_sum #if not 0 run again


exit:
    move $a0, $t1
    li $v0, 1 # prep Print
    syscall
    jr $ra
