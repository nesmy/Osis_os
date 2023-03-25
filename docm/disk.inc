;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; DISK LOAD
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


disk_load:
	push dx																						; Store dx on stack so later we can recall
																										; how many sectors were request to be read.
																										; even if is is altered in the meantime

	mov ah, 0x02																			; BIOS read sector function
	mov al, dh																				; Read DH sectors
	mov ch, 0x00																			; select cylinder 0
	mov dh, 0x00 																			; Select head 0
	mov cl, 0x02 																			; Start reading drom second sector (i.e. after the boot sector)

	int 0x13																					; BIOS interrupt
	jc disk_error																			; jump if error (i.e. carry flag set)

	pop dx 																						; restore DX from the stack
	cmp dh,al 																				; if AL (sectors read) != DH (sector expected)
	jne disk_error 																		; display error message
	ret

disk_error:
	mov bx, DISK_ERROR_MSG
	call prints
	jmp $

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; VARIABLES
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

DISK_ERROR_MSG 			db "Disk read error!",0									
