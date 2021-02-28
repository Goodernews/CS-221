         .data
         .align    2
         .text

         .globl  main

main:
         li    $t1, 0 #default print val
         li    $v0, 5
         syscall
         move  $t0, $v0 # load to temporary value
         b     is_greater

is_greater: #met first 
         addi  $t0, $t0, -97 
         bgezal $t0, is_less #meets lower bound ascii
         b exit

is_less:
         addi  $t0, $t0, -25
         bgezal $t0, exit #meets lower bound ascii
         addi  $t1, $v0, -32
         b exit
         

exit:
         move $a0, $t1
         li   $v0, 1
         syscall
         jr    $ra