.code

AsmAlg proc buf:QWORD, part:QWORD, startofpart:SDWORD, endofpart:SDWORD, factor:real4

push r13			; iterator po skladowych piksela czesci bitmapy (iZero)
push r10		; factor
push r9			; poczatek czesci bitmapy
push r8			; koniec czesci bitmapy
push rcx			; bufor pikseli RGB
push rdx			; czesc bitmapy


xor r13, r13		 ; zerowanie iteratora iZero

forLoop:
	cmp r8,r9	; porownanie poczatku z koncem
	jge endLoop	; jesli start>=end to skocz do endLoop



	add r13,3	;inkrementacja iZero o 3
	jmp forLoop	;powrot do petli for



endLoop:
pop r13
pop r10
pop r9
pop r8 
pop rcx
pop rdx
AsmAlg endp
end
