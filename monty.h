#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);

void add_to_queue(stack_t **, unsigned int);

void call_function(op_func, char *, char *, int, int);

void pall(stack_t **, unsigned int);/*Task 0*/

void push(stack_t **, unsigned int);/*Task 0*/

void pint(stack_t **, unsigned int);/*Task 1*/

void pop(stack_t **, unsigned int);/*Task 2*/

void swap(stack_t **, unsigned int);/*Task 3*/

void add(stack_t **, unsigned int);/*Task 4*/

void nop(stack_t **, unsigned int);/*Task 5*/

void sub(stack_t **, unsigned int);/*Task 6*/

void divide(stack_t **, unsigned int);/*Task 7*/

void multiply(stack_t **, unsigned int);/*Task 8*/

void modulus(stack_t **, unsigned int);/*Task 9*/



/*Error hanlding*/
void err(int error_code, ...);
void more_err(int error_code, ...);
/*void string_err(int error_code, ...);*/
/*void rotr(stack_t **, unsigned int);*/

#endif