; calcx64.asm - simple calculator - addition function only in assembly
; Windows x64 calling convention

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

.code

; int addWithAsmX64(int a, int b)
addWithAsmX64 PROC
    ; Windows x64 calling convention:
    ; RCX = first argument (a)
    ; RDX = second argument (b)

    mov eax, ecx     ; move 'a' into eax
    add eax, edx     ; add 'b' to eax
    ret              ; return result in eax
addWithAsmX64 ENDP

END