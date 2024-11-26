.386
.model flat, stdcall
option casemap:none
include \masm32\macros\macros.asm
include \masm32\include\masm32.inc
include \masm32\include\kernel32.inc
includelib \masm32\lib\masm32.lib
includelib \masm32\lib\kernel32.lib

.data
a dword 0
b dword 0
c dword 0
uno dword 0
dos dword 0
tres dword 0
def dword 0
hola dword 0
adios dword 0

.code
main:
push a
push b
pop ebx
pop eax
add eax, ebx
push eax
pop eax
mov c, eax
ret
print str$(eax)
print chr$(10)
exit
end main
funcion:
push 3
pop eax
mov tres, eax
push 2
pop eax
mov uno, eax
ret
print str$(eax)
print chr$(10)
exit
end funcion
