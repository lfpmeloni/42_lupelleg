# ft_printf

## Goal

Write a library that contains 'ft_printf', a function that will mimic the original printf().

## Prototype

```c
int ft_printf(const char *format, ...);
```

## Format

The function will manage the following conversions: cspdiuxX%

| Conversion | Description |
| --- | --- |
| %c | Prints a single character |
| %s | Prints a string (as defined by the common C convention) |
| %p | The void * pointer argument has to be printed in hexadecimal format |
| %d | Prints a decimal (base 10) number |
| %i | Prints an integer in base 10 |
| %u | Prints an unsigned decimal (base 10) number |
| %x | Prints a number in hexadecimal (base 16) lowercase format |
| %X | Prints a number in hexadecimal (base 16) uppercase format |
| %% | Prints a percent sign |

These conversions must follow the behavior of the original printf(), including edge cases like zero, negative values and null pointers.

## Bonus part

Manage any combination of the following flags: '-0.' and the field minimum width under all conversions.
Manage all the following flags: '# +' (Yes, one of them is a space).

| Flags | Description |
| --- | --- |
| - | Left-align within the given field width; Right alignment is the default |
| 0 | Left-pads the number with zeroes (0) instead of spaces when padding is specified |
| . | Precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros |
| # | Used with x or X, a non-zero result has the string "0x" (or "0X" for 'X' conversions) prepended to it |
| ' '(space) | A blank should be left before a positive number produced by a signed conversion |
| + | A sign must always be placed before a number produced by a signed conversion |

## Allowed functions

va-list, va_start, va_arg, va_end

```c
va_list variable_name;
```

va_list is not a function, it is a structure that will be used by the rest of the allowed functions. The va_list structure will store the extra arguments, but we are not to initialize or free it. That is what va_start and va_end macros are for.

```c
void va_start(va_list argument_list, last_arg);
```

The va_start() macro initializes your argument_list for use by va_arg() and va_end() and must be called first.
The last_arg value is the name of the last argument of the calling function, the ft_printf() in this case.

```c
argument_type va_arg(va_list argument_list, argument_type);
```

Everytime it is called, it modifies the argument_list so that the next call to va_arg() returns the next argument in the list. The function returns the expanded value of the argument, which has the type and value of the next argument in the list.

```c
void va_end(va_list argument_list);
```

Each invocation of va_start() must be matched by a corresponding invocation of va_end() in the same function.
After the call to va_end(), the argument_list is undefined.
