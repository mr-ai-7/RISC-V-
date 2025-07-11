#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// R-format instructions map
typedef struct {
    char *name;
    char *funct7;
    char *funct3;
    char *opcode;
} Instruction;

// Registers map
typedef struct {
    char *name;
    int number;
} Register;

// Define the supported R-format instructions
Instruction r_format_instructions[] = {
    {"add", "0000000", "000", "0110011"},
    {"sub", "0100000", "000", "0110011"},
    {"and", "0000000", "111", "0110011"},
    {"or",  "0000000", "110", "0110011"},
    {"xor", "0000000", "100", "0110011"},
    {"sll", "0000000", "001", "0110011"},
    {"srl", "0000000", "101", "0110011"},
    {"sra", "0100000", "101", "0110011"}
};

// Define the registers and their numbers
Register registers[] = {
    {"x0", 0}, {"x1", 1}, {"x2", 2}, {"x3", 3}, {"x4", 4},
    {"x5", 5}, {"x6", 6}, {"x7", 7}, {"x8", 8}, {"x9", 9},
    {"x10", 10}, {"x11", 11}, {"x12", 12}, {"x13", 13}, {"x14", 14},
    {"x15", 15}, {"x16", 16}, {"x17", 17}, {"x18", 18}, {"x19", 19},
    {"x20", 20}, {"x21", 21}, {"x22", 22}, {"x23", 23}, {"x24", 24},
    {"x25", 25}, {"x26", 26}, {"x27", 27}, {"x28", 28}, {"x29", 29},
    {"x30", 30}, {"x31", 31}
};

// Function to find the instruction in the R-format instructions list
Instruction *find_instruction(char *name) {
    for (int i = 0; i < sizeof(r_format_instructions)/sizeof(Instruction); i++) {
        if (strcmp(r_format_instructions[i].name, name) == 0) {
            return &r_format_instructions[i];
        }
    }
    return NULL;
}

// Function to find the register number
int find_register(char *name) {
    for (int i = 0; i < sizeof(registers)/sizeof(Register); i++) {
        if (strcmp(registers[i].name, name) == 0) {
            return registers[i].number;
        }
    }
    return -1;
}

// Function to convert binary string to hexadecimal
unsigned int binary_to_hex(char *binary) {
    return (unsigned int)strtol(binary, NULL, 2);
}

// Function to convert a line of assembly code to machine code
void convert_to_machine_code(char *line) {
    char instr_name[10], rd[10], rs1[10], rs2[10];
    sscanf(line, "%s %[^,], %[^,], %s", instr_name, rd, rs1, rs2);

    Instruction *instr = find_instruction(instr_name);
    if (!instr) {
        printf("Unsupported instruction: %s\n", instr_name);
        return;
    }

    int rd_num = find_register(rd);
    int rs1_num = find_register(rs1);
    int rs2_num = find_register(rs2);

    if (rd_num == -1 || rs1_num == -1 || rs2_num == -1) {
        printf("Invalid register\n");
        return;
    }

    // Construct the binary string for the machine code
    char binary[33] = {0};
    snprintf(binary, 33, "%s%05d%05d%s%05d%s", instr->funct7, rs2_num, rs1_num, instr->funct3, rd_num, instr->opcode);

    // Convert binary to hexadecimal and print it
    printf("%08x\n", binary_to_hex(binary));
}

int main() {
    FILE *input_file = fopen("input.s", "r");
    FILE *output_file = fopen("output.hex", "w");

    if (!input_file || !output_file) {
        perror("Error opening file");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), input_file)) {
        // Convert the line of assembly to machine code
        convert_to_machine_code(line);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
