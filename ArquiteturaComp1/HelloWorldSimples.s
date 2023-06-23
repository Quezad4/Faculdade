section .text
global _start
mens db 'Hello World!', 10 
tam equ $-mens
_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, mens
    mov edx, tam
    int 80h
    mov eax, 1
    int 80h
    
