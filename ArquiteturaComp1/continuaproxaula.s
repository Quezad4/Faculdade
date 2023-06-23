section .text
global _start
mens db 'Entre com uma frase: ', 10 
tam equ $-mens

segment .bss
mens2 resb 10
tam2 resd 



_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, mens
    mov edx, tam
    int 80h
    
    mov eax, 3 ;ler do trclado
    mov ebx, 0
    mov ecx, mens2
    mov edx, 10
    int 80h ; vai retornar o tamanho da escrita do teclado em eax
    ;novo print
    mov [tam2], eax ; tam2 é ponteiro, to salvando no que ele aponta
    
    
    sair:
	mov eax, 1
	mov ebx, 0
	int 80h
