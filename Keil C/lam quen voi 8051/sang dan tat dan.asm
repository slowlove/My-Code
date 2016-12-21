			ORG 0h	 
					main:
mov p0,#0
mov p1,#0
mov p2,#0
mov p3,#0
					mov a,#0
qt1: 
setb c
rlc a   	 
mov p0,a
lcall tre
mov c,0e7h		   ;so sanh bit cuoi cua thanh ghi A
jnc qt1
					mov a,#0
qt2:
setb c			 
rlc a  
mov p1,a
lcall tre
mov c,0e7h
jnc qt2
					mov a,#0
qt3:
setb c
rlc a	 
mov p2,a
lcall tre
mov c,0e7h
jnc qt3
					mov a,#0
qt4:
setb c			
rlc a	
mov p3,a
lcall tre
mov c,0e7h
jnc qt4
qt5:
clr c
rrc a
mov p3,a
lcall tre
mov c,0e0h		   ;so sanh bit dau tien cua thanh ghi A
jc qt5
					mov a,#0ffh
qt6:
clr c
rrc a
mov p2,a
lcall tre
mov c,0e0h
jc qt6
					mov a,#0ffh
qt7:
clr c
rrc a
mov p1,a
lcall tre
mov c,0e0h			
jc qt7
					mov a,#0ffh
qt8:
clr c
rrc a
mov p0,a
lcall tre
mov c,0e0h
jc qt8
					sjmp main
;;;;;;;;;;;;;;chuong trinh tao tre;;;;;;;;;;;;;
tre:
     mov r7,#0ffh
kt1: mov r6,#0ffh
kt2: djnz r6,kt2
     djnz r7,kt1
	 ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
end