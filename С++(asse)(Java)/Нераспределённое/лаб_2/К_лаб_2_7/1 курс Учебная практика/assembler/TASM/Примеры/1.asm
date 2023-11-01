                dosseg
                .model          small
                .data
x               dw      '‹Ÿ'
edw 		dw    	1
edb		db 	1
                .code
program:        mov     ax, @data
                mov     ds, ax
                mov     ax, x                   
                inc     al
		imul 	edw
		push    ax
		mov	al,byte ptr x
		cbw
		mov     bx,ax
		pop 	ax
                idiv    bx
                mov     x,ax                 
                mov     ah, 4ch
                int     21h
                end     program

