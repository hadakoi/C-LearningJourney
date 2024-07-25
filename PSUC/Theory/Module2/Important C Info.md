# Variable Names

About Variables : 
- Variables are the symbolic names for storing computational data.
- Variable: a symbolic name for a memory location
- In C variables have to be declared before they are used
- A variable may take different values at different times during execution.
- Declarations reserve storage for the variable.
- Value is assigned to the variable by initialization or assignment


Rules for valid variable names (identifiers) :
- Name must begin with a letter or underscore ( _ ) and can be followed by any combination of letters, underscores, or digits.
- Key words cannot be used as a variable name.
- C is case-sensitive: sum, Sum, and SUM each refer to a different variable.
- Variable names can be as long as you want, although only the first 63 (or 31) characters might be significant.
- Choice of meaningful variable names can increase the readability of a program

Examples for Variable names ->








# Data Types

Basic data types: int, float, double, char, and void.

- int: can be used to store integer numbers (values with no decimal places).
- float: can be used for storing floating-point numbers (values containing decimal places).
- double: the same as type float, and roughly twice the size of float.
- char: can be used to store a single character, such as the letter a, the digit character 6, or a semicolon.
- void: is used to denote nothing or empty.


## Integer

The basic integer type is int.
The size of an int depends on the machine and on PCs it is normally 16 or 32 or 64

modifiers (type specifiers)
- short: typically uses less bits
- long: typically uses more bits
- Signed: both negative and positive numbers
- Unsigned: only positive numbers

## Character

A char variable can be used to store a single character. A character constant is formed by enclosing the character within a pair of single quotation marks. Valid examples: 'a’ .
- Character zero ( ‘0’ ) is not the same as the number (integer constant) 0.
- The character constant ‘\n’—the newline character—is a valid character
constant. It is called as an escape character.
- There are other escape sequences like, \t for tab, \v for vertical tab, \n for new line etc
- ASCII (American Standard Code for Information Interchange ) is the dominant
encoding scheme for characters.

Important Note -> 
- char letter; /* declare variable letter of type char */

- letter = ‘A';  OK 
- letter = A;  NO! Compiler thinks A is a variable 
- letter = “A";  NO! Compiler thinks “A" is a string 
- letter = 65;  ok because characters are internally stored as numeric values (ASCII code) 


## Floating-Point Types

Floating-point types represent real numbers
- Integer part
- Fractional part


The number 108.1517 breaks down into the following parts
- 108 - integer part
- 1517 - fractional part

Floating-point constants can also be expressed in scientific notation. The value

There are three floating-point type specifiers
- float
- double
- long double

## Void

2 uses of void are
- To specify the return type of a function when it is not returning
any value.
- To indicate an empty argument list to a function.

# Operators

The different operators are:
- Arithmetic
- Relational
- Logical
- Increment and Decrement
- Bitwise
- Assignment
- Conditional

## Arithmetic

