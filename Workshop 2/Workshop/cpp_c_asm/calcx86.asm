; calcx86.asm - simple calculator - addition function only in assembly
; Windows x86 calling convention

;To add an assembler-language file to an existing Visual Studio C++ project
;Select the project in Solution Explorer. On the menu bar, choose Project, Build Customizations.
;
;In the Visual C++ Build Customization Files dialog box, check the checkbox next to masm
;(.targets,.props). Choose OK to save your selection and close the dialog box.
;
;On the menu bar, choose Project, Add New Item.
;
; In the Add New Item dialog box, select C++ file (.cpp) in the center pane. 
; In the Name edit control, enter a new file name that has a .asm extension instead of .cpp. 
; Choose Add to add the file to your project and close the dialog box.
; Create your assembler-language code in the .asm file you added. When you build your solution, 
; the MASM assembler is invoked to assemble the .asm file into an object file that is then linked 
; into your project. To make symbol access easier, declare your assembler functions as extern "C" 
; in your C++ source code, rather than using the C++ name decoration conventions in your 
; assembler-language source files.


.386                ; enable 80386 instructions
.model flat, c      ; flat memory model, C calling convention
.code

; int addWithAsmX86(int x, int y)
addWithAsmX86 PROC
    ; On x86 with __cdecl:
    ; [esp+4] = first argument (x)
    ; [esp+8] = second argument (y)

    mov eax, DWORD PTR [esp+4]   ; load x into eax
    add eax, DWORD PTR [esp+8]   ; add y
    ret                          ; return result in eax
addWithAsmX86 ENDP

END