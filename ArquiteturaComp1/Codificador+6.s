section .data
	mens db 'Entre com uma frase:'
	tam equ $-mens
	
segment .bss
	b1 resb 500
	la resd 1
	
segment .bss
	b2 resb 500
	lb resd 1
	
segment .bss
	tamanho resd 1
	
section .text
	global _start
	
_start:
	mov ecx, mens
	mov edx, tam
	call exibestr
	call leteclado
	mov esi, 0
	jmp iniloop
	
iniloop:
	mov al, [b1+esi]
	add al, 6
	mov [b2+esi], al
	cmp esi, eax
	je sai
	inc esi
	jmp iniloop
	
sai:
	mov ecx, b2
	mov edx, esi
	call exibestr
	
	mov eax, 1
	mov ebx, 0
	int 80h
	
	
leteclado:
	mov eax, 3
	mov ebx, 0
	mov ecx, b1
	mov edx, 500
	int 80h
	mov esi, 0
	ret
	
exibestr:
	mov eax, 4
	mov ebx, 1
	int 80h
	ret
