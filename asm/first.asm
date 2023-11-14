%define ARRAY_SIZE 100
%define NEW_LINE 10

segment .data
FirstMsg        db   "First 10 elements of array", 0
format  db "%d:%d",10,0
%include "asm_io.inc"
segment .bss
array resd ARRAY_SIZE
segment .text
        extern puts,printf
        global  view_arr


view_arr:
        enter 0,0
        pusha
        dump_stack 1,2,50
        popa
        leave
        ret

