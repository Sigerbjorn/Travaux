; ------------------------------------------
; NOM DU PROGRAMME: Q4
; DATE DE CREATION: 6/02/2018
; NOM: BAUDRU
; REMARQUES: 

; nasm -f elf32 nom_du_programme.asm
; gcc  -m32   
; nom_du_programme.o  -o  nom_du_programme_à_exécuter 
; ------------------------------------------

bits 32 ;
extern printf, scanf, exit

segment .data ; Declaration des variables

segment .bss ; Declaration des variables non-initialisees

Segment .text ; Code brut du programme

global maFonction

maFonction: 
;CODE
