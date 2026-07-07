/*
** EPITECH PROJECT, 2026
** main
** File description:
** main
*/

#include "../include/my.h"

double addition(double a, double b)
{
    double c = a + b;

    return c;
}

double substraction(double a, double b)
{
    double c = a - b;

    return c;
}

double multiplication(double a, double b)
{
    double c = a * b;

    return c;
}

double division(double a, double b)
{
    double c = 0;

    if (b == 0) {
        printf("Math Error\n");
        return c;
    }
    return (a / b);
}
typedef double (*calc_op_t)(double, double);

static calc_op_t which_function(double (*ptr)(double, double), char op)
{
    switch (op) {
        case '+':
            ptr = &addition;
            break;
        case '-':
            ptr = &substraction;
            break;
        case '*':
            ptr = &multiplication;
            break;
        case '/':
            ptr = &division;
            break;
        default:
            fprintf(stderr, "error! Bad operator\n");
            exit(84);
    }
    return ptr;
}

int main(int ac, char **av)
{
    char *line = NULL;
    size_t len = 0;
    int a = 0;
    int b = 0;
    int ret = 0;
    char op;
    double (*ptr)(double, double) = NULL;

    printf("Enter a simple calcul involving two number. Ex: 10 + 99\n");
    while (1) {
        printf("\e[0;36m~~> \e[0m");
        if (getline(&line, &len, stdin) == -1)
            return 84;
        line[strcspn(line, "\n")] = '\0';
        sscanf(line, "%d %c %d", &a, &op, &b);
        ptr = which_function(ptr, op);
        printf("Result = %.2f\n", ptr(a, b));
        free(line);
    }
    return 0;
}
