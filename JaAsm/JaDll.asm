.data

var1 dq 128

.code

AsmAlg proc buf:QWORD, part:QWORD, startofpart:SDWORD, endofpart:SDWORD, factor:sdword

push r13		; iterator po skladowych piksela czesci bitmapy (iZero)
push r9		;koniec czesci bitmapy
push r8		;poczatek czesci bitmapy
push rcx		; bufor pikseli RGB
push rdx		; czesc bitmapy

mov r10, 128;
movss xmm4,factor		; wspolczynnik kontrastu(factor) do xmm4
movd xmm6,r10

xor r13,r13		        ; zerowanie iZero



forLoop:

cmp r8,r9		 ; porownanie startu z end
jge endLoop		 ; jesli Startofpart => endofpart


sub byte ptr [rcx+ r8], 128		    ; buf[i] - 128
sub byte ptr [rcx+ r8 + 1], 128		; buf[i+1] - 128
sub byte ptr [rcx+ r8 + 2], 128		; buf[i+2] - 128

PMOVSXBD  xmm0,[rcx+r8]		;  4 wartosci do xmm0
PMOVSXBD xmm1,[rcx+r8+1]
PMOVSXBD xmm2,[rcx+r8+2]


CVTDQ2PS xmm0,xmm0
CVTDQ2PS xmm1,xmm1
CVTDQ2PS xmm2,xmm2

mulps xmm0,xmm4				; factor * buf[i] - 128
mulps xmm1,xmm4				; factor * buf[i + 1] - 128
mulps xmm2,xmm4				; factor * buf[i + 2] - 128

cvtps2dq xmm0,xmm0
cvtps2dq xmm1,xmm1
cvtps2dq xmm2,xmm2


paddd xmm0,xmm6			; (factor * buf[i] - 128) + 128
paddd xmm1,xmm6			; (factor * buf[i + 1] - 128) + 128
paddd xmm2,xmm6			; (factor * buf[i + 2] - 128) + 128


;movd xmm5, xmm0			; konwersja na zmiennoprzecinkowe
movd  eax, xmm0		; konwersja najmniej znaczacego elementu zmiennoprzecinkowego xmm5 na 32bitowy integer(dlateo eax a nie rax)

cmp eax,255					; porownanie wartosci skladowej z 255
jg g1						; jesli skladowa>255 to skok

cmp eax,0					; porownanie wartosci skladowej z 0
jl l1						; jesli skladowa<0 to skok 

mov byte ptr[rdx+r13], al	;zapisz obliczona pierwsza skladowa

second:

	
	;movd xmm5, xmm1		; konwersja na zmiennoprzecinkowe
	movd  eax, xmm1	; konwersja najmniej znaczacego elementu zmiennoprzecinkowego xmm5 na 32bitowy integer(dlateo eax a nie rax)


	cmp eax,255				; porownanie wartosci skladowej z 255
	jg g2					; jesli skladowa>255 to skok
	
	cmp eax,0				; porownanie wartosci skladowej z 0
	jl l2					; jesli skladowa<0 to skok 
	

	mov byte ptr[rdx+r13 + 1], al	;zapisz obliczona druga skladowa


third:
	

	movd  eax, xmm2	; konwersja najmniej znaczacego elementu zmiennoprzecinkowego xmm5 na 32bitowy integer(dlateo eax a nie rax)
	
	cmp eax,255				; porownanie wartosci skladowej z 255
	jg g3					; jesli skladowa>255 to skok
	
	cmp eax,0				; porownanie wartosci skladowej z 0
	jl l3					; jesli skladowa<0 to skok
	

	mov byte ptr[rdx+r13 + 2], al	;zapisz obliczona trzecia skladowa
	add r8, 3						;inkrementacja poczatku  (i+=3/ start+=3)
	add r13,3						;inkrementacja iZero +=3 
	jmp forLoop						; skok do petli for




g1:
	mov byte ptr[rdx+r13], 255		;wartosc pierwszej skladowej = 255
	jmp second						;skok do ustawienia drugiej skladowej


l1:
	mov byte ptr[rdx+r13],0			;wartosc pierwszej skladowej = 0
	jmp second						;skok do ustawienia drugiej skladowej


g2:
	mov byte ptr[rdx+r13 + 1], 255	;wartosc drugiej skladowej = 255
	jmp third						;skok do ustawienia trzeciej skladowej


l2:
	mov byte ptr[rdx+r13 + 1],0		;wartosc drugiej skladowej = 0
	jmp third						;skok do ustawienia trzeciej skladowej

g3:
	mov byte ptr[rdx+r13 + 2], 255	;wartosc trzeciej skladowej = 255
	add r8, 3						;inkrementacja poczatku  (i+=3/ start+=3)				
	add r13,3						;inkrementacja iZero +=3 
	jmp forLoop						; skok do petli for


l3:
	mov byte ptr[rdx+r13 + 2],0		;wartosc trzeciej skladowej = 0
	add r8, 3						;inkrementacja poczatku  (i+=3/ start+=3)	
	add r13,3						;inkrementacja iZero +=3
	jmp forLoop						; skok do petli for




endLoop:
	pop r13
	pop r9
	pop r8
	pop rcx
	pop rdx
	ret
	AsmAlg endp
end
