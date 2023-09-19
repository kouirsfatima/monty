Stacks, Queues - LIFO, FIFO:

The Monty language:

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files:

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
 Here's a short explanation for each of these opcodes:

"PUSH: This opcode is used to push a value onto the stack.
PALL: This opcode is used to print all the values currently on the stack. It doesn't remove any values.

PINT: This opcode is used to print the value at the top of the stack .

POP: POP removes the top element from the stack. 

SWAP: This opcode swaps the positions of the top two elements on the stack. 

ADD: ADD is an arithmetic opcode that pops the top two elements from the stack, 

NOP: NOP stands for "No Operation." It's essentially a placeholder or a "do nothing" instruction.

Compilation & Output:

will be compiled this way:

``$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty``
1- Any output must be printed on stdout
2- Any error message must be printed on stderr
