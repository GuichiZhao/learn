

;
; file: skel.asm
; This file is a skeleton that can be used to start assembly programs.

%include "asm_io.inc"
segment .data
prompt1 db "Enter a number: ", 0
;
; initialized data is put in the data segment here
;
v db 7
s dw "abc"


segment .bss
;
; uninitialized data is put in the bss segment
;


input resd 1
 

segment .text
        global  asm_main
asm_main:
        enter   0,0               ; setup routine
        pusha
        mov al,0
        cmp al,0
        jz thenblock
        mov ebx,2
        jmp next
thenblock:
        mov ebx,1
next:
        mov ecx,42

        call sub_dump_regs


        

        popa
        mov     eax, 0            ; return back to C
        leave                     
        ret


