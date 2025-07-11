# RISC-V
A simple assembler built in C to convert R-format RISC-V assembly code into 32-bit machine code in hexadecimal. Inspired by tools like Ripes, it handles error checking, register mapping, and outputs clean machine code.

📸 Demo
Input (input.s):

asm
Copy
Edit
add x1, x2, x3
sub x4, x5, x6
Console Output:

Copy
Edit
003100b3
40b28233
📌 Features
✅ Converts R-format instructions: add, sub, and, or, xor, sll, srl, sra

✅ Binary-to-hex conversion

✅ Built-in register lookup (x0 to x31)

✅ Basic error handling for unsupported instructions and invalid registers

✅ File input/output support

📂 File Structure
python
Copy
Edit
├── input.s         # RISC-V assembly input
├── output.hex      # Output machine code (optional)
├── main.c          # Assembler implementation
└── README.md       # Project documentation
⚙️ Usage
1️⃣ Compile the Assembler
bash
Copy
Edit
gcc main.c -o riscv_assembler
2️⃣ Create Input File
Create a file named input.s and add your R-format instructions:

asm
Copy
Edit
and x1, x2, x3
or x4, x5, x6
3️⃣ Run the Assembler
bash
Copy
Edit
./riscv_assembler
✅ Output
Machine code will be printed in hexadecimal in the terminal.

🧠 Instruction Reference
Instruction	funct7	funct3	opcode
add	0000000	000	0110011
sub	0100000	000	0110011
and	0000000	111	0110011
or	0000000	110	0110011
xor	0000000	100	0110011
sll	0000000	001	0110011
srl	0000000	101	0110011
sra	0100000	101	0110011

🛡️ Error Handling
❌ Unsupported instruction → Unsupported instruction: xyz

❌ Invalid register name → Invalid register

🚀 Future Improvements
Support for I/S/B/U/J instruction types

Write machine code to output.hex

Enhanced parsing with whitespace/tabs

Integration with GUI/CLI interface

Symbol table and label support

👨‍💻 Author
Made with ❤️ by a B.Tech AI student at IIT Hyderabad
Focused on exploring systems programming, compilers, and low-level architecture.
