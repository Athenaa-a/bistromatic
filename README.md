# Bistromatic

A project made by Epitech students.
---

## About the project

Bistromatic is a customisable calculator. You can change the base as well as replacing the operators with other characters.


## How to compile

Use the following command to compile the files:
`make -j`

Then, you'll have access to the binary.

## How to use

Use this:

`./calc base operators size_read`

- base: all the symbols of the base
- operators: the symbols for the parentheses and the 5 operators
- size_read: number of characters to be read

## Examples

Classic calcul:

`$>echo "3+3" | ./calc 0123456789 "()+-*/%"`

`6`
---

Change of base:

`$>echo "c+c" | ./calc abcdefghij "()+-*/%"`

`g`

---

Change of operators:

`$>echo "3c3" | ./calc 0123456789 "abcdefg"`

`6`