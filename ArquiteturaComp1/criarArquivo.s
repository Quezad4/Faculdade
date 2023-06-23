section .data
	arq1 db 'teste.txt'
	
section .text
	global _start
	
_start:
	mov eax, 8
	mov ebx, arq1
	mov ecx, 777q
	
	int 80h

	mov eax, 1
	int 80h
