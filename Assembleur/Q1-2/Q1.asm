; ------------------------------------------
; NOM DU PROGRAMME:Q1
; DATE DE CREATION: 6/02/2018
; NOM: BAUDRU
; REMARQUES: 

; nasm -f elf32 nom_du_programme.asm
; gcc  -m32 nom_du_programme.o  -o  nom_du_programme_à_exécuter 
; ------------------------------------------

bits 32 ;
extern printf, scanf,exit

segment .data ; Declaration des variables
	msg1 db "Bonjour tout le monde",0
	msg2 db "Bonne journee",10,0
	format db "%s",0
	msg3 db "Donner votre nom",10,0
	msg4 db "Bonjour %s, bonne journee",10,0

segment .bss ; Declaration des variables non-initialisees

	nom resw 1
segment .text ; Code brut du programme

global main

main:

	push msg1
	call printf
	call scanf
	push msg2
	call printf

	push msg3
	call printf


	push nom
	push format
	call scanf

	push nom
	push msg4
	call printf

	push 0
	call exit
