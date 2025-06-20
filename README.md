# SCT – Simple Compiler Tool

SCT (Simple Compiler Tool) is a lightweight compiler framework built from scratch using Lex and Yacc. It currently supports a custom C-like language and is designed in three incremental phases, each adding new language constructs and compiler features.

---

## Table of Contents

1. [Features](#features)
2. [Language Specification](#language-specification)
3. [Project Structure](#project-structure)
4. [Usage](#usage)
5. [Compiler Phases](#compiler-phases)
6. [Extensions & Roadmap](#extensions--roadmap)
7. [Contributing](#contributing)
8. [License](#license)

---

## Features

* **Lexical Analysis**: Implemented with Flex to tokenize identifiers, keywords, literals, and operators.
* **Syntax Analysis**: Grammar rules defined in Yacc/Bison for parsing expressions, statements, and declarations.
* **AST Generation**: Builds an Abstract Syntax Tree for semantic analysis and potential code generation.
* **Error Handling**: Reports syntax and semantic errors with line numbers.
* **Modular Design**: Separate include, source, and binary directories for clean organization.

---

## Language Specification

SCT’s language is a simplified, C-inspired language that supports:

* **Data Types**: `int`, `float`, `char`, and arrays thereof.
* **Control Flow**: `if`, `else`, `while`, `for`, and `return`.
* **Operators**: Arithmetic (`+`, `-`, `*`, `/`, `%`), relational (`<`, `>`, `<=`, `>=`, `==`, `!=`), logical (`&&`, `||`, `!`).
* **Functions**: Definition and calls with parameter passing.
* **Composite Constructs**: Structs, nested blocks, and scope management.

### Unsupported & Future Plans

* **Unsupported**: Pointers, dynamic memory allocation, floating-point precision control, and optimization passes.
* **Planned Extensions**: Code generation to x86\_64 assembly, optimization (constant folding, dead code elimination), and support for pointers and function pointers.

---

## Project Structure

```text
├── inc/              # Header files for shared definitions
├── src/              # Source files (compiler.l, compiler.y)
├── bin/              # Generated binaries and intermediate files
├── phases/           # Phase-specific directories with detailed READMEs
│   ├── phase1/       # Basic expressions, statements, symbol table
│   ├── phase2/       # Functions, compound types, enhanced AST
│   └── phase3/       # Advanced constructs and error recovery
├── Makefile          # Build and clean directives
└── README.md         # This file
```

---

## Usage

1. **Clone the repository**

   ```bash
   git clone https://github.com/CodeCraftsmanSandeep/Compiler.git
   cd Compiler
   ```

2. **Build**

   ```bash
   make all
   ```

   This will:

   * Run `yacc` on `src/compiler.y` to generate parser code.
   * Run `lex` on `src/compiler.l` to generate scanner code.
   * Compile both with `gcc` into `bin/compiler.out`.

3. **Clean**

   ```bash
   make clean
   ```

   Removes generated `.c`, `.h`, and the executable.

4. **Run**

   ```bash
   ./bin/compiler.out < source_file.sct > output.ast
   ```

   * Reads input `.sct` source files
   * Prints AST or error messages to stdout

---

## Compiler Phases

Each phase adds new language features and improvements. Detailed descriptions, test cases, and code are in `phases/phaseX`.

1. **Phase 1** – *Lexing & Parsing Basics*:

   * Token definitions, grammar rules for expressions and simple statements.
   * Symbol table for variable declarations and type checking.

2. **Phase 2** – *Functions & Scopes*:

   * Support for function definitions and calls.
   * Nested scopes and block-level symbol management.
   * AST enhancements for control flow.

3. **Phase 3** – *Advanced Constructs & Error Recovery*:

   * Structs, arrays, and complex type checking.
   * Improved error detection and recovery strategies.
   * Preparations for code generation and optimizations.

---

## Extensions & Roadmap

* **Code Generation**: Emit x86\_64 or LLVM IR for compiled code execution.
* **Optimizations**: Constant folding, inline expansions, dead code elimination.
* **Pointer Support**: Add pointers, pointer arithmetic, and memory management.
* **Integrated Testing**: Automated test harness for regression testing.
* **Interpreted Mode**: Offer an interpreter fallback for rapid prototyping.

---

## Contributing

Contributions, issues, and feature requests are welcome! Please:

1. Fork the repo
2. Create a feature branch (`git checkout -b feature/YourFeature`)
3. Commit your changes (`git commit -m "Add your message"`)
4. Push to the branch (`git push origin feature/YourFeature`)
5. Open a Pull Request

Please follow the project’s coding style and include test cases for new features.

---

## License

This project is released under the [MIT License](LICENSE).

---

© 2025 Sandeep Reddy — Built with passion & Lex/Yacc magic!
