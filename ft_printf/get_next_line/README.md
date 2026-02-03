# get_next_line

*This project has been created as part of the 42 curriculum by oryad.*

## Description

get_next_line is a function that reads and returns one line at a time from a given file descriptor. This project demonstrates an understanding of file I/O, static variables, and memory management in C. The implementation efficiently reads lines from files or stdin using a configurable buffer size.

## Goal

The main objective is to:
- Understand and implement file descriptor-based I/O in C
- Master the use of static variables for maintaining state between function calls
- Implement efficient buffer management for line reading
- Build a reusable function following the 42 Norm
- Handle edge cases such as files without newlines and reading from multiple descriptors

## Features

The function `get_next_line()` reads and returns one line at a time with the following characteristics:

| Feature | Description |
|---------|-------------|
| **Line Reading** | Reads one complete line (including the newline character if present) |
| **Buffer Management** | Uses an internal buffer of configurable size for efficient I/O |
| **Multiple FDs** | Can handle reading from multiple file descriptors simultaneously |
| **Return Value** | Returns 1 if a line was read, 0 at EOF, -1 on error |
| **Memory Handling** | Allocates memory only when necessary, no memory leaks |
| **Newline Handling** | Properly handles files with or without trailing newlines |

## Getting Started

### Prerequisites

- GCC or Clang compiler
- Make utility (optional)
- Unix-based system (Linux, macOS)

### Installation

1. Clone the repository:
```bash
git clone <repository_url> get_next_line
cd get_next_line
```

2. Compile the function into your project:
```bash
cc -Wall -Wextra -Werror your_file.c get_next_line.c get_next_line_utils.c
```

Or include in your compilation commands as needed.

### Usage

Include the header in your C file:
```c
#include "get_next_line.h"
```

Example usage:
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((get_next_line(fd, &line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Compilation Flags

To adjust the buffer size, compile with the `-D` flag:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=4096 your_file.c get_next_line.c get_next_line_utils.c
```

Default BUFFER_SIZE is typically 42 bytes.

## Implementation Details

### Algorithm

The implementation uses a **static buffer strategy** with the following approach:

1. **Static Buffer Initialization**: A static buffer maintains partial line data between function calls
2. **Buffer Reading**: Raw data is read from the file descriptor into the buffer
3. **Line Extraction**: Characters are processed from the buffer until a newline is found
4. **Dynamic Allocation**: The line is built dynamically, allocating memory as needed
5. **Buffer Management**: Remaining unprocessed data is preserved for the next call

### Design Choices

**Static Variables**:
- Maintains buffer state between function calls without global variables
- Allows handling multiple file descriptors independently
- Reduces the need for external state management
- Provides encapsulation within the function scope

**Modular Function Design**:
- `get_next_line()` handles the main logic and memory allocation
- Utility functions handle string operations and character processing
- Promotes code reusability and maintainability
- Follows the 42 Norm requirement of small, focused functions

**Buffer Management**:
- Fixed-size static buffer reduces memory overhead
- Efficient single read operation per function call in most cases
- Handles incomplete lines gracefully by preserving state

### Key Implementation Details

1. **File Descriptor Handling**: Supports reading from multiple FDs simultaneously
2. **Newline Detection**: Properly identifies and includes newline characters in returned lines
3. **EOF Handling**: Correctly identifies end-of-file and returns remaining buffered data
4. **Error Handling**: Returns -1 for read errors, handles edge cases
5. **Memory Management**: All allocated memory must be freed by the caller

## Project Structure

```
.
├── get_next_line.h
├── get_next_line.c
├── get_next_line_utils.c
└── README.md
```

## Resources

### Documentation
- [read() man page](https://man7.org/linux/man-pages/man2/read.2.html)
- [open() man page](https://man7.org/linux/man-pages/man2/open.2.html)
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)
- [Dynamic Memory Allocation](https://www.gnu.org/software/libc/manual/html_node/Memory-Allocation.html)

### Articles and Tutorials
- GeeksforGeeks - File I/O in C
- Understanding file descriptors in Unix
- Static variable patterns in C
- 42 Norm documentation

### Development Approach

AI tools were **NOT** used in the development of this project, in accordance with 42's foundational phase guidelines. The implementation was developed through:
- Manual research and documentation reading
- Peer learning and discussions
- Trial and error debugging
- Understanding fundamental C concepts hands-on

This approach ensured:
- Deep understanding of file I/O operations
- Proper learning of memory management with file reading
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
