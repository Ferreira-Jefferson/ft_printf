# ft_printf

This project is part of the 42 School curriculum. It consists of re-implementing the `printf` function from the C standard library, providing formatted output functionality with support for various format specifiers.

## Table of Contents
- [About](#about)
- [Project Structure](#project-structure)
- [Format Specifiers](#format-specifiers)
- [Usage](#usage)
- [Compiling](#compiling)
- [Testing](#testing)
- [License](#license)

## About

`ft_printf` is a custom implementation of the standard C library `printf` function. The goal is to understand how formatted output works under the hood, handle variadic functions, and implement a robust parsing system for format specifiers. This project builds upon the `libft` library and extends it with printf functionality.

## Project Structure

The project is organized as follows:

```
ft_printf/
├── ft_printf.c           # Main ft_printf implementation
├── ft_printf.h           # Header file with function prototypes
├── main.c                # Test suite and examples
├── Makefile              # Build script
├── LICENSE               # GPL v3 License
├── libft/                # Custom C library
│   ├── libft.h           # Library header
│   ├── Makefile          # Library build system
│   └── *.c               # Library functions
└── objs/                 # Object files directory
```

## Format Specifiers

The ft_printf function supports the following format specifiers:

- **%c** - Single character
- **%s** - String of characters
- **%p** - Pointer address in hexadecimal format
- **%d** - Signed decimal integer
- **%i** - Signed integer (same as %d)
- **%u** - Unsigned decimal integer
- **%x** - Unsigned hexadecimal integer (lowercase)
- **%X** - Unsigned hexadecimal integer (uppercase)
- **%%** - Literal percent sign

All format specifiers are implemented according to the 42 subject requirements and follow the standard printf behavior.

## Usage

1. **Clone the repository:**
   ```bash
   git clone <repository-url>
   cd ft_printf
   ```

2. **Build the library:**
   ```bash
   make
   ```

3. **Include in your project:**
   - Add `ft_printf.h` to your source files.
   - Link the compiled `libftprintf.a` with your project during compilation:
     ```bash
     gcc your_program.c -L. -lftprintf -o your_program
     ```

4. **Example usage:**
   ```c
   #include "ft_printf.h"

   int main(void)
   {
       ft_printf("Hello, %s!\n", "World");
       ft_printf("Number: %d\n", 42);
       ft_printf("Hex: %x\n", 255);
       ft_printf("Pointer: %p\n", &main);
       return (0);
   }
   ```

## Compiling

- To compile the library:
  ```bash
  make
  ```
- To compile with bonus features:
  ```bash
  make bonus
  ```
- To clean object files:
  ```bash
  make clean
  ```
- To remove all binaries:
  ```bash
  make fclean
  ```
- To recompile from scratch:
  ```bash
  make re
  ```
- To run tests:
  ```bash
  make test
  ```

## Testing

The project includes a comprehensive test suite in `main.c` that compares ft_printf output with the standard printf function. The tests cover:

- Character output and edge cases
- String handling including NULL strings
- Integer formatting (positive, negative, limits)
- Unsigned integer handling
- Hexadecimal formatting (both cases)
- Pointer address formatting
- Percent sign handling
- Combined format specifiers

You can also use third-party testers available for ft_printf to validate the implementation.

## License

This project is licensed under the GNU General Public License v3.0 (GPLv3). See the [LICENSE](LICENSE) file for details.

---

*Project developed as part of the 42 School curriculum.*