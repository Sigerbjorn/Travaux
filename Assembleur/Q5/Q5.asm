; ------------------------------------------
; NOM DU PROGRAMME: Q5
; DATE DE CREATION: 06/02/2018
; NOM: BAUDRU
; REMARQUES: 

; nasm -f elf32 nom_du_programme.asm
; gcc  -m32   
; nom_du_programme.o  -o  nom_du_programme_à_exécuter 
; ------------------------------------------

bits 32 ;
extern exit, printf, scanf

segment .data ; Declaration des variables

	ch1 db "Ceci est une chaine de caracteres",0
	format db "%s",0

segment .bss ; Declaration des variables non-initialisees

	ch2 resw 1

Segment .text ; Code brut du programme

global main

main: 

	mov eax, [ch1]
	mov [ch2], eax

	push ch2
	push format
	call printf

	push 0
	call exit
