; ------------------------------------------
; NOM DU PROGRAMME: Q3 
; DATE DE CREATION: 6/02/2018
; NOM: BAUDRU
; REMARQUES: 

; nasm -f elf32 nom_du_programme.asm
; gcc  -m32   
; nom_du_programme.o  -o  nom_du_programme_à_exécuter 
; ------------------------------------------

bits 32 ;
extern printf, scanf
extern exit

segment .data ; Declaration des variables

	msg1 db "Donner deux nombres",10,0
	format db "%d",0
	msg2 db "Le resultat est: %d",10,0

segment .bss ; Declaration des variables non-initialisees

	nb1 resb 1
	nb2 resb 1
	res resb 1

Segment .text ; Code brut du programme

global main
global addition
global soustraction

addition:

	push msg1
	call printf

	mov eax, nb1
	push nb1
	push format
	call scanf

	mov eax, nb2
	push nb2
	push format
	call scanf

	xor ebx,ebx
	mov bl,[nb1]
	add bl,[nb2]
	push ebx
	push msg2
	call printf

soustraction:

	push msg1
        call printf

        mov eax, nb1
        push nb1
        push format
        call scanf

        mov eax, nb2
        push nb2
        push format
        call scanf

        xor ebx,ebx
	mov bl,[nb1]
        sub bl,[nb2]
        push ebx
        push msg2
        call printf

main:
	call addition
	call soustraction

	push 0
	call exit
