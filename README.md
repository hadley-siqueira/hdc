<p align="center">
  <img src="https://github.com/hadley-siqueira/hdc/blob/master/img/haard-logo.png" width="300">
</p>

# The Haard Compiler

Haard is a programming language with syntax inspired 
mainly from Python, but the semantics are more similar to C++. 

This repository contains the source code for the first compiler
of the language, which is being implemented in C++. It is still in
development and can't produce a 'hello, world' yet.

## Install from source

1. Clone the repository
2. Enter the directory
3. Create a folder named build and enter it
4. Run cmake
5. Run makefile
6. There will be a binary named hdc in the build folder

```
git clone https://github.com/hadley-siqueira/hdc.git
cd hdc
mkdir build
cd build
cmake ..
make
```

## The language

Below are some examples of the language

### A simple 'Hello, world'

```python
import std.io

def main : void
    println('hello, world!')
```

### A simple sum function

A function to add two numbers. Note that parameters are declared one per line. The syntax here
was inspired by VHDL where it is common to declare one input/output per line. The @ precedes the
parameter's name and then there is the type of the parameter. Comments uses #

```python
# a function that returns an int
def sum : int 
    @a : int
    @b : int

    return a + b
```

### Control flow

A sample program that shows some control flow

```python
import std.io

def foo : void
    i = 0

    while i < 10:
        println(i)
        ++i

    for i = 0; i < 10: ++i:
        println(i)

    for i in 0 .. 10:
        println(i)

    for i in range(0, 10):
        if i > 5:
            println('i is greater than 5')
        else:
            println('i <= 5')
```
