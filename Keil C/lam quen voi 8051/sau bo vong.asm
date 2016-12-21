		org 0h
mov p0,#0
mov p1,#0
mov p2,#0
mov p3,#0
mov a,#7h
main:
lcall xoay
mov p0,r1
lcall tre


mov p1,p0
lcall tre
jnz main
sjmp main
;;;;;;;;;;;;;;chuong trinh xoay;;;;;;;;;;;;;;;;
xoay:
rl a
mov r1,a
ret
;;;;;;;;;;;;;;chuong trinh tao tre;;;;;;;;;;;;;
tre:
     mov r7,#0ffh
kt1: mov r6,#0ffh
kt2: djnz r6,kt2
     djnz r7,kt1
	 ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
end