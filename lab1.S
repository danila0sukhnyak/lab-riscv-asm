.data
N:
    .word 4
M:
    .word 2
matrix:
    .word 1, 1, 1, 1
    .word 2, 2, 2, 2
result:
    .word 0, 0

.text
.globl main

main:
    la a2, N
    la a3, M
    la a4, matrix
    call process
    mv a2, a0  # Переместите итоговую сумму в a2 для вывода
    call print
    call exit

print:
    # Вывод значения в a2
    addi a0, x0, 1  # print_int ecall
    mv a1, a2
    ecall
    ret

exit:
    addi a0, x0, 10
    ecall

process:
    lw t1, 0(a2)  # N
    lw t2, 0(a3)  # M
    mul t3, t1, t2  # Общее количество элементов в матрице

    addi a0, x0, 0  # Итоговая сумма

    addi t4, x0, 0  # Счетчик элементов
count_loop:
    lw t5, 0(a4)  # Загрузить текущий элемент
    add a0, a0, t5  # Добавить его к итоговой сумме
    addi a4, a4, 4  # Перейти к следующему элементу
    addi t4, t4, 1  # Увеличить счетчик
    blt t4, t3, count_loop  # Повторять, пока не обработаем все элементы

    ret