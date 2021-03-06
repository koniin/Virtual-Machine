#include <stdbool.h>
#include <stdio.h>

typedef enum {
   PSH,
   ADD,
   POP,
   SET,
   HLT,
   MOV
} InstructionSet;

typedef enum {
   A, B, C, D, E, F,
   NUM_OF_REGISTERS
} Registers;

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
	SET, A, 5,
	MOV, A, B,
    HLT
};

int registers[NUM_OF_REGISTERS];

int ip = 0; // instruction pointer
int sp = -1; // stack pointer
int stack[256];
bool running = true;

int fetch() {
	return program[ip];
}

void eval(int instr) {
    switch (instr) {
        case HLT: {
            running = false;
            break;
		}
		case PSH: {
			stack[++sp] = program[++ip];
			break;
		}
		case POP: {
			int val_popped = stack[sp--];
			printf("popped %d\n", val_popped);
			break;
		}
		case ADD: {
			// first we pop the stack and store it as a
			int a = stack[sp--];

			// then we pop the top of the stack and store it as b
			int b = stack[sp--];

			// we then add the result and push it to the stack
			int result = b + a;
			sp++; // increment stack pointer **before**
			stack[sp] = result; // set the value to the top of the stack

			// all done!
			break;
		}
		case SET: {
			int reg = program[++ip];
			registers[reg] = program[++ip];
			break;
		}
		case MOV: {
			int reg = program[++ip];
			int regSecond = program[++ip];
			registers[regSecond] = registers[reg];
		}
    }
}

int main() {
	while (running) {
       eval(fetch());
       ip++;
	}
	printf("%i", registers[B]);
}