# ft_printf

*This project has been created as part of the 42 curriculum by oryad.*

## Description

ft_printf is a recreation of the standard C library function `printf()`. This project demonstrates an understanding of variadic functions in C and provides hands-on experience with formatted output. The implementation handles multiple conversion specifiers and returns the number of characters printed, just like the original `printf()`.

## Goal

The main objective is to:
- Understand and implement variadic functions using `<stdarg.h>`
- Handle various data type conversions and format specifiers
- Build a well-structured, extensible codebase following the 42 Norm
- Create a library that can be reused in future C projects

## Features

The function `ft_printf()` mimics the behavior of the standard `printf()` function with support for the following conversions:

| Specifier | Description |
|-----------|-------------|
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer address in hexadecimal |
| `%d` |`%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Percent sign |

## Getting Started

### Prerequisites

- GCC or Clang compiler
- Make utility
- Unix-based system (Linux, macOS)

### Installation

1. Clone the repository:
```bash
git clone <repository_url> ft_printf
cd ft_printf
```

2. Compile the library:
```bash
make
```

This will create the `libftprintf.a` library file.

### Usage

Include the header in your C file:
```c
#include "ft_printf.h"
```

Compile your program with the library:
```bash
cc -Wall -Wextra -Werror your_file.c libftprintf.a
```

Example usage:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

### Makefile Rules

- `make` or `make all` - Compiles the library
- `make clean` - Removes object files
- `make fclean` - Removes object files and the library
- `make re` - Recompiles the entire library

## Implementation Details

### Algorithm

The implementation uses a **format string parser** with the following approach:

1. **String Traversal**: The function iterates through the format string character by character
2. **Specifier Detection**: When a `%` character is encountered, the next character is analyzed
3. **Type Dispatch**: Based on the specifier, the appropriate conversion function is called using variadic arguments (`va_arg`)
4. **Character Counting**: Each function returns the number of characters printed, which are accumulated and returned

### Design Choices

**Variadic Functions** (`va_list`, `va_start`, `va_arg`, `va_end`):
- Allows handling an unknown number of arguments at compile time
- Essential for mimicking `printf()`'s behavior
- Provides type-safe access to variable arguments

**Modular Function Design**:
- Each conversion type has its own dedicated function
- Promotes code reusability and maintainability
- Makes debugging and testing easier
- Follows the 42 Norm requirement of small, focused functions

**Base Conversion Functions**:
- `ft_putnbr_base()` handles hexadecimal conversions generically
- Reduces code duplication between `%x`, `%X`, and `%p`
- Uses recursion to handle numbers of arbitrary size

### Key Implementation Details

1. **Integer Handling**: Special care for `INT_MIN` (-2147483648) to avoid overflow
2. **Null Pointers**: 
   - Strings: prints `(null)`
   - Pointers: prints `(nil)`
3. **Return Value**: Total character count matches original `printf()` behavior
4. **Error Handling**: Returns -1 if format string is NULL

## Project Structure

```
.
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_print_char_str.c
├── ft_print_numbers.c
├── ft_print_hex_ptr.c
└── README.md
```

## Resources

### Documentation
- [printf() man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic Functions in C](https://en.cppreference.com/w/c/variadic)
- [stdarg.h documentation](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)

### Articles and Tutorials
- [GeeksforGeeks - Variadic Functions](https://www.geeksforgeeks.org/variadic-functions-in-c/)
- Number base conversions in C
- 42 Norm documentation

### Development Approach

AI tools were **NOT** used in the development of this project, in accordance with 42's foundational phase guidelines. The implementation was developed through:
- Manual research and documentation reading
- Peer learning and discussions
- Trial and error debugging
- Understanding fundamental C concepts hands-on

This approach ensured:
- Deep understanding of variadic functions
- Proper learning of memory management
- Development of problem-solving skills
- Preparation for exam situations without AI assistance

## Author

**oryad** - 42 Student

## Acknowledgments

- 42 School for the project subject
- Fellow students for peer evaluation and discussions

## License

This project is part of the 42 School curriculum and follows its academic guidelines.

---

*Made with dedication at 42 School* 