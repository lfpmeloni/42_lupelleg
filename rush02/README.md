# Rush 02

## Instructions

Compile with Makefile: using cc -Wall -Wextra -Werror
Must be according to the norm (incuding the Makefile)
- rules: $NAME, clean and fclean
The program should take a number as argument and convert it to its written letters value
- executable name rush-02
- make fclean
- make
The program can take up to two arguments:
- If there is only one argument, it is the value you need to convert
- If there are two arguments, the first is the new reference dictionary and the second is the value
If the argument isnt positive, must return "Error" followed by new line
Should go beyond unsigned int
Must parse the dictionary as resource to the project
The values inside must be used to print the result and can be modified (added but not removed)
Any memory allocated on the heap (with malloc(3)) must be freed
Numbers are to be handled the same way atoi handles them
Trim the spaces before and after the value in the dictionary
Entries on dictionary can be stored on any order and can be empty lines inside
Any problem parsing the dict must produce "Dict Error\n" 
Bonus: using "-", ",", "and" to be closer to the correct written syntax, doing on different language using other dict, using read to read standard entry when there is no argument

## Required functions

### 0. Main execution flow

1. Reads the dictionary (numbers.dict or a custom file)
2. Parses dictionary entries
3. Convert the input into numbers
4. Outputs the corresponding word representation

### 1. Read the dictionary

Functions or file to read the dictionary
- [x] read_dictionary: Reads the dictionary file

### 2. Parsing entries

Function or file to split the dictionary entries into individual number-word pairs
- [x] parse_dictionary: Parses and stores entries for quick lookup

### 3. Decomposing numbers

Numbers are broken down into hundreds, tens, and units
- [ ] decompose_number: Break numbers into parts
- [ ] convert_number: Manages the conversion and handles different number formats

### 5. Printing the result

Functions and files to print the final number representation to standard output

### 6. Helper functions

- [x] ft_putstr: Prints out a string
- [x] ft_strlen: Computes string length
- [x] ft_strcmp: Compares two strings
- [x] ft_malloc: Allocates memory safelly (protecting it) - Remember to free later

## Edge cases to consider

1. Non-existent numbers: If not found in dict, decompose
2. Invalid file path: If dict cannot be opened, print error
3. Memory allocation fail: Safely exit on malloc error
4. Input validation: If the number provides incorrect arguments, print error
5. Handling special cases: Try exact match by adding to dict
    - 11 - 19 needs exact match
    - 007 should be interpreted as 7
    - Large numbers spilt into readable chuncks

## Logic Breakdown

1. Determine Magnitude: Identify the magnitude (thousands, millions, billions, etc.) using ft_strlen.
2. Decompose Number: Split the number into segments of three digits from left to right.
3. Convert Each Segment: Convert each segment into words.
4. Append Magnitude: Append the appropriate magnitude (thousand, million, billion, etc.).
5. Combine Results: Print the converted segments together with appropriate magnitudes.
- [ ] find_number from the dict
- [ ] convert_hundreds: Converts numbers less than 1000.
- [ ] convert_segment: Handles conversion of each segment and appending magnitudes.
- [ ] convert_number: Integrates all the steps and manages the overall process.

### How Makefile Works

A Makefile is a special file that contains a set of directives used by the make build automation tool to compile and build programs. The Makefile specifies how to derive the target program from the source files. Here are the key components:

Variables: Variables are used to simplify the Makefile and avoid repetition. They are defined with an = sign and can be used later in the Makefile by prefixing them with a $.

Rules: Rules specify how to build targets. A rule consists of:

Target: The file to be created or updated.

Prerequisites: The files that are needed to create the target.

Recipe: The commands to create the target from the prerequisites. Each command must be preceded by a tab character.

Components Explained
Variables
NAME: This is the name of the executable file that will be created. In this case, rush-02.

SRC: This variable lists all the source files needed to compile the project. It explicitly names each source file.

OBJ: This variable defines the object files corresponding to the source files. The $(SRC:.c=.o) syntax replaces the .c extension of each source file with .o.

CC: This is the compiler to be used. Here, cc is the chosen compiler.

CFLAGS: Compiler flags that are used to specify additional options for the compiler. In this case, -Wall -Wextra -Werror.

Rules
all: This is the default rule that gets executed when you run make without arguments. It depends on the target defined by $(NAME).

$(NAME): This rule specifies how to create the executable. It depends on the object files defined in $(OBJ). The recipe compiles these object files into the final executable.

%.o: %.c: This is a pattern rule that defines how to compile a .c file into a .o file. The $< variable represents the prerequisite (the .c file), and $@ represents the target (the .o file).

clean: This rule deletes the object files. It uses the rm -f command to forcefully remove the files without prompting for confirmation.

fclean: This rule deletes both the object files and the executable. It runs the clean rule first and then removes the executable.

re: This rule first runs fclean to delete all generated files, and then runs all to rebuild everything from scratch.

.PHONY: This special target tells make that the listed targets (all, clean, fclean, re) are not actual files, but just names for recipes to be executed. This helps avoid conflicts with files of the same name.

Compiler Flags Explained
-Wall: Enables all the compiler's warning messages. This helps catch potential issues in the code.

-Wextra: Enables additional warning messages that are not covered by -Wall.

-Werror: Treats all warnings as errors. This ensures that the code must be warning-free to compile successfully.

Object Files Explained
.o Files: Object files are compiled versions of source files. Each source file (.c) is compiled into an object file (.o). Object files contain machine code but are not yet linked together into an executable. The linker combines these object files to create the final executable.