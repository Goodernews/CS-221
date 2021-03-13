

factorial:
               # Save $a0 to the stack

         li    $t1, 1
         ble   $a0, $t1, case_one

recursive_case:
         addiu $a0, $a0, -1
         jal   factorial
         mult  $v0, $a0, $v0
         j     epilogue

case_one:
         li    $v0, 1

epilogue:
         jr $ra