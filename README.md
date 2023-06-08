# Corewar
A reproduction of the Core War game. Assembly compiler and Virtual Machine.

## Corewar History

At the beginning of a game, each battle program is loaded into memory at a random location, after which each program executes one instruction in turn. The goal of the game is to cause the processes of opposing programs to terminate (which happens if they execute an invalid instruction), leaving the victorious program in sole possession of the machine.

The earliest published version of Redcode defined only eight instructions. The ICWS-86 standard increased the number to 10 while the ICWS-88 standard increased it to 11. The currently used ICWS-94 standard has 16 instructions. However, Redcode supports a number of different addressing modes and (from ICWS-94) instruction modifiers which increase the actual number of operations possible to 7168. The Redcode standard leaves the underlying instruction representation undefined and provides no means for programs to access it. Arithmetic operations may be done on the two address fields contained in each instruction, but the only operations supported on the instruction codes themselves are copying and comparing for equality.

## Instructions

As i said before there are several kind of instruction, here they are with short description:

1. **0x01 (live)** takes 1 parameter: 4 bytes that represent the player’s number.

2. **0x02 (ld)** takes 2 parameters. It loads the value of the first parameter into the second parameter,
which must be a register (not the PC).
ld 34, r3 loads the REG_SIZE bytes starting at the address PC + 34 % IDX_MODintor3.

3. **0x03 (st)** takes 2 parameters. It stores the first parameter’s value (which is a register) into
the second (whether a register or a number).

4. **0x04 (add)** takes 3 registers as parameters. It adds the content of the first two and puts the sum
into the third one (which must be a register).

5. **0x05 (sub)** Similar to add, but performing a subtraction.

6. **0x06 (and)** takes 3 parameters. It performs a binary AND between the first two parameters
and stores the result into the third one (which must be a register). and r2, %0,r3 puts r2 & 0 into r3.

7. **0x07 (or)** Similar to and, but performing a binary OR.

8. **0x08 (xor)** Similar to and, but performing a binary XOR (exclusive OR).

9. **0x09 (zjmp)** takes 1 parameter, which must be an index. It jumps to this index if the carry is worth 1.
Otherwise, it does nothing but consumes the same time.

10. **0x0a (ldi)** takes 3 parameters. The first two must be indexes, the third one must be a register.

11. **0x0b (sti)** takes 3 parameters. The first one must be a register. The other two can be indexes or registers.

12. **0x0c (fork)** takes 1 parameter, which must be an index. It creates a new program that inherits different statesfromtheparent.

13. **0x0d (lld)** Similar to ld

14. **0x0e (lldi)** Similar to ldi

15. **0x0f (lfork)** Similar to fork

16. **0x10 (aff)** takes 1 parameter, which must be a register. It displays on the standard output the character whose ASCII code
is the content of the register (in base 10).