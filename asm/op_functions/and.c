/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** and
*/

#include "corewar.h"

int and_size(body_t *body, int i)
{
    if (body->type[i] == T_DIR) {
        body->size[i] = DIR_SIZE;
        return (DIR_SIZE);
    }
    if (body->type[i] == T_IND) {
        body->size[i] = IND_SIZE;
        return (IND_SIZE);
    }
    if (body->type[i] == T_REG) {
        body->size[i] = R_SIZE;
        return (R_SIZE);
    }
    if (body->type[i] == T_LAB) {
        body->size[i] = LAB_SIZE;
        return (LAB_SIZE);
    }
    body->size[i] = NONE;
    return (NONE);
}

int and_op(body_t *body)
{
    int size = 0;

    if (!correct_type(body, 5))
        return (-1);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++)
        size += and_size(body, i);
    return (size + COD_BYTE + OP_NAME);
}