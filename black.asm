global black
extern fputc

section .data

section .bss

section .text

black:
        push    ebp
        mov     ebp, esp
        sub     esp, 24

        mov     eax, dword [ebp+8H]
        mov     dword [esp+4H], eax
        mov     dword [esp], 1
        call    fputc

        mov     eax, dword [ebp+8H]
        mov     dword [esp+4H], eax
        mov     dword [esp], 1
        call    fputc

        mov     eax, dword [ebp+8H]
        mov     dword [esp+4H], eax
        mov     dword [esp], 1
        call    fputc

        mov     esp, ebp
        pop     ebp
        ret
