section .data
	arq1 db 'teste2.txt',0
	mens db 'Escreva alguma coisa: '
	tam equ $-mens
section .bss
	teclado resb 500
	tamteclado resd 1
	descritor resd 1
	
section .text
	global _start
	
_start:
	mov eax, 8
	mov ebx, arq1
	mov ecx, 777q
	int 80h
	mov [descritor], eax
	
	mov eax, 4
	mov ebx, 1
	mov ecx, mens
	mov edx, tam
	int 80h
	
	mov eax, 3
	mov ebx, 0
	mov ecx, teclado
	mov edx, 500
	
	int 80h
	mov [tamteclado], eax
	
	mov eax, 4
	mov ebx, [descritor]
	mov ecx, teclado
	mov edx, [tamteclado]
	int 80h
	
	mov eax, 1
	mov ebx, 0 
	int 80h
	
	
	

	
