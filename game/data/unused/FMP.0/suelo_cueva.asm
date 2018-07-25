;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Exported throught MappyWin 1423
;; with help of MDPPY 0.1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	.align 1
	.globl suelo_cueva
suelo_cueva:
	dc.w	32	; width
	dc.w	22	; height
	dc.w	16	; nbr of colors
	dc.l	suelo_cueva_pal
	dc.w	2	; nbr of tiles
	dc.l	suelo_cueva_tiles
	dc.w	1	; nbr of layers
	dc.l	suelo_cueva_maps

	.align 1
suelo_cueva_pal:
	dc.w	0xF00
	dc.w	0x223
	dc.w	0x136
	dc.w	0x347
	dc.w	0x469
	dc.w	0x47A
	dc.w	0x58B
	dc.w	0x59C
	dc.w	0xFFF
	dc.w	0xFFF
	dc.w	0xFFF
	dc.w	0xFFF
	dc.w	0xFFF
	dc.w	0xFFF
	dc.w	0xFFF
	dc.w	0xFFF

	.align 1
suelo_cueva_tiles:

; tile 0
	dc.l	0x00000000
	dc.l	0x00000000
	dc.l	0x00000000
	dc.l	0x00000000
	dc.l	0x00000000
	dc.l	0x00000000
	dc.l	0x00000000
	dc.l	0x00000000

; tile 1
	dc.l	0x11111111
	dc.l	0x11111111
	dc.l	0x11111111
	dc.l	0x11111111
	dc.l	0x11111111
	dc.l	0x11111111
	dc.l	0x11111111
	dc.l	0x11111111

	.align 1
suelo_cueva_maps:
	dc.l	map_bg

	.align 1
map_bg:
; line 0
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 2
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 3
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 4
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 5
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 6
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 7
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 8
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 9
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 10
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 11
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 12
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 13
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 14
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 15
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 16
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 17
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 18
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 19
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 20
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
; line 21
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1
	dc.w	0x1