.code
MyProc proc
mov RAX, RCX
add RAX, RDX
ret
MyProc endp

FloatProc PROC
addsd xmm0, xmm1
ret
FloatProc ENDP

end
