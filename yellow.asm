global yellow
extern fputc

section .data

section .bss

section .text

yellow:
        push    ebp
        mov     ebp, esp
        sub     esp, 24

        mov     eax, dword [ebp+8H]
        mov     dword [esp+4H], eax
        mov     dword [esp], 0
        call    fputc

        mov     eax, dword [ebp+8H]
        mov     dword [esp+4H], eax
        mov     dword [esp], 255
        call    fputc

        mov     eax, dword [ebp+8H]
        mov     dword [esp+4H], eax
        mov     dword [esp], 255
        call    fputc

        mov     esp, ebp
        pop     ebp
        ret
