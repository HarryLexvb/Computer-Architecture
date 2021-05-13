.data
p1: .word 2,0
p2: .word 4,5 
p3: .word 20,10
p4: .word 10,3
p5: .word 5,2
num: .float 2.0

mensaje: .asciiz "El area seria de: "

.text
main:

    li $s3,0
    li $s4,0
    la $s0,p5
    la $s1,p4
    jal cargar
    la $s0,p4
    la $s1,p3
    jal cargar
    la $s0,p3
    la $s1,p2
    jal cargar
    la $s0,p2
    la $s1,p1
    jal cargar
    la $s0,p1
    la $s1,p5
    jal cargar

    sub $s5,$s3,$s4

    #vuelve numero flotante
    move $s6,$s5
    mtc1 $s6,$f1
    cvt.s.w $f1,$f1

    lwc1 $f5,num
    div.s $f1,$f1,$f5

    li $v0,4
    la $a0,mensaje
    syscall

    li $v0,2
    mov.s $f12,$f1
    syscall

    # programa muere
    li $v0,10
    syscall

cargar: 
    lw $t1,0($s0)
    lw $t2,4($s0)
    lw $t3,0($s1)
    lw $t4,4($s1)

    mul $t6,$t1,$t4
    add $s3,$s3,$t6

    mul $t7,$t2,$t3
    add $s4,$s4,$t7

    jr $ra