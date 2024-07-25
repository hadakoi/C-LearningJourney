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

![Screenshot 2024-07-25 211427](https://github.com/user-attachments/assets/55b12514-a81f-4f26-8b73-ef768220e517)

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

  ![Screenshot 2024-07-25 211736](https://github.com/user-attachments/assets/d203e166-bb1f-4e77-adfa-6509599ac6fc)

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

![Screenshot 2024-07-25 212105](https://github.com/user-attachments/assets/b2104f0e-a29e-4ac3-a82c-4dd3ad11cffe)

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
- Type Conversion
- Assignment 
- Conditional
- comma (,) operator

## Arithmetic

The binary arithmetic operators are +, -, *, / and the modulus operator %.
- The / operator when used with integers truncates any fractional part i.e.
E.g. 5/2 = 2 and not 2.5
- Therefore % operator produces the remainder when 5 is divided by 2 i.e. 1
- The % operator cannot be applied to float or double
- E.g. x % y wherein % is the operator and x, y are operands

When Working with these operators we must consider Precedence and Associativity

Precedence: One operator can have a higher priority, or precedence, over another operator. The operators within C are grouped hierarchically according to their precedence (i.e., order of
evaluation)
- Operations with a higher precedence are carried out before operations having a lower precedence.

High priority operators * / %

Low priority operators + -

- Example: * has a higher precedence than +
a + b * c → a+(b*c)

If necessary, you can always use parentheses in an expression to force the terms to be  evaluated in any desired order

## Relational 

An expression such as a < b containing a relational operator is called a relational expression.

The value of a relational expression is one, if the specified relation is true and zero if the relation is false.

E.g.:
10 < 20 is TRUE and 
20 < 10 is FALSE

The arithmetic expressions will be evaluated first & then the results will be compared. That is, arithmetic operators have a higher priority over relational operators. > >= < <= all have the same precedence and below them are the next precedence equality operators i.e. == and !=

![Screenshot 2024-07-25 232137](https://github.com/user-attachments/assets/290af0bf-3ddd-4f09-acb1-425174ac4b07)
![Screenshot 2024-07-25 232158](https://github.com/user-attachments/assets/576553e5-5de0-4105-81f2-c2ca6069d108)

## Logical 

## Increment and Decrement

The operator ++ adds 1 to the operand.

The operator -- subtracts 1 from the operand.

Both are unary operators.

Ex: ++i or i++ is equivalent to i=i+1

say

m = 5 and 
y = ++m

then the value of y and m would be 6.

However 

m = 5 and 
y = m++

Here y continues to be 5. Only m changes to 6.

Prefix operator ++ appears before the variable.

Postfix operator ++ appears after the variable.

![Screenshot 2024-07-25 232845](https://github.com/user-attachments/assets/c2d49eed-8694-40c2-a9e9-dc9da019dd51)
![Screenshot 2024-07-25 232822](https://github.com/user-attachments/assets/e0134749-964a-477d-90c9-be84a20d80c7)

## BitWise Operators

### -Bitwise Logical Operators

Bitwise Logical Operators consist off &(AND), |(OR), ^(EXOR)

Suppose x = 10, y = 15

z = x & y sets z=10 like this

0000000000001010 = x

0000000000001111 = y

0000000000001010 <-> z = x & y

![Screenshot 2024-07-25 233244](https://github.com/user-attachments/assets/2971a6b2-c142-4d30-b438-38b9e82fd02b)


### -Bitwise Shift Operators

These consist of << and >>
They are used to move bit patterns to the left or right and are used in the following form -> 

op << n or op >> n here op is the operand shifted and n is the number of positions

<< causes all the bits in the operand op to be shifted to the left by
n positions.
The leftmost n bits in the original bit pattern will be lost and the
rightmost n bits that are vacated are filled with 0’s.

the >> causes all the bits in operand op to be shifted to the
right by n positions. The rightmost n bits will be lost and the left most vacated bits are filled with 0’s if number is unsigned integer

![Screenshot 2024-07-25 233632](https://github.com/user-attachments/assets/a5eea945-3a02-496d-b4c0-17586346b33f)

### -Bitwise complement Operator

The complement operator(~) is an unary operator and inverts all
the bits represented by its operand.

Suppose x=1001100010001111

~x=0110011101110000 (complement)

Also called as 1’s complement operator.

## Type Convserions

The final result of an expression is converted to the type of the variable on
the left of the assignment sign before assigning the value to it
-  However the following changes are introduced during the final assignment
-  Float to int causes truncation of the fractional part
- Double to float caused rounding of digits
- Long int to int causes dropping of the excess higher order bits

This can also be done by using a Type cast operator than leaving it to the system

The general form of a type casting is (type-name) expression

int a = 150;

float f; 

f = (float) a / 100; // type cast operator

- The type cast operator has the effect of converting the value of the variable ‘a’ to type
float for the purpose of evaluation of the expression.
- This operator does NOT permanently affect the value of the variable ‘a’;
- The type cast operator has a higher precedence than all the arithmetic operators except the unary minus and unary plus.
- Examples of the use of type cast operator:

(int) 29.55 + (int) 21.99 results in 29 + 21\

(float)6 /(float)4 results in 1.5

(float)6 / 4 results in 1.5

When Assigning an integer value to a floating variable: does not cause any change in the value of the number; the value is simply converted by the system and stored in the floating format.

When Assign a floating-point value to an integer variable: the decimal portion of the number gets truncated

Integer arithmetic (division):

- int divided by int => result is integer division
- int divided by float or float divided by int

## Assignment Operators

The C language permits you to join the arithmetic operators with the
assignment operator using the following general format: op=, where op is an arithmetic operator, including +, –, *, /, and %.

Example: precedence of op:

a /= b + c

Equivalent to:

a = a / (b + c)

## Conditional Operators

condition ? expression1 : expression2

- condition is an expression that is evaluated first.
- If the result of the evaluation of condition is TRUE (nonzero), then expression1 is evaluated and the result of the evaluation becomes the result of the operation.
- If condition is FALSE (zero), then expression2 is evaluated and its result becomes the result of the operation.

maxValue = ( a > b ) ? a : b;

Equivalent to:

if ( a > b ) then maxValue = a

else maxValue = b

## Comma Operator

The coma operator is used basically to separate expressions.

i = 0, j = 10; // in initialization [ l → r ]

The meaning of the comma operator in the general expression e1, e2 is
“evaluate the sub expression e1, then evaluate e2; the value of the
expression is the value of e2 ”.

## Associativity and Precedence Table

![Screenshot 2024-07-25 234812](https://github.com/user-attachments/assets/41b47310-8333-4e64-8513-7d1990929b2d)
![Screenshot 2024-07-25 234827](https://github.com/user-attachments/assets/dd954b38-c35b-42c6-9943-7e7a4c78b809)
![Screenshot 2024-07-25 234848](https://github.com/user-attachments/assets/c0780ed0-34e1-4f69-9c66-d50e4212e4f4)
