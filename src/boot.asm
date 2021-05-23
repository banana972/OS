global start

section .text
bits 32
extern kmain
start:
    call kmain
    hlt