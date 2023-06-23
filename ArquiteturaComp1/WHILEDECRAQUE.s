section .data
	mens db 'Entre com uma frase: ', 10 
	tam equ $-mens

segment .bss
	b1 resb 500
	chupetinha resd 1
segment .bss
	b2 resb 500
	chupetinha2 resd 1

	
section .text
	global _start	


_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, mens
    mov edx, tam
    int 80h
    
    mov eax, 3 ;ler do trclado
    mov ebx, 0
    mov ecx, b1
    mov edx, 500
    int 80h ; vai retornar o tamanho da escrita do teclado em eax
    mov esi, 0
    
iniloop:
	mov al,[b1+esi]
	mov [b2+esi],al
	cmp al, 10
	je sai
	inc esi
	jmp iniloop
sai:
	mov eax, 4
	mov ebx, 1
	mov ecx, b2
	inc esi
	mov edx, esi
	int 80h
	
	mov eax, 1
	mov ebx, 0
	int 80h
	
	
	
