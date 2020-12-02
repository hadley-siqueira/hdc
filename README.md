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

The programming language is named Haard. The name is a play of the 
words 'hard', my name 'Hadley'. It also seems that Haard means fireplace or
something like that in Dutch (that's why the logo is a flame).

Haard is a compiled language and it will try to provide the following:

* Type inference
* Templates
* Classes
* Closures and/or lambdas
* A nice standard library
* Low-level access (for system development such as operating systems)
* Other stuff that I don't remeber right now

Below are some examples of the language syntax. The syntax is inpired mostly on 
Python, but Ruby, VHDL, C++, Java, Rust and others are used also as inspiration. 
Although the syntax is Python-like, the semantics are more similar to the ones of
C and C++.

You may wonder why I am creating this language. There are some reasons:

1. I've always wanted to learn how compilers work on detail and I believe this project
  can help me on this.
2. I like to work with homemade softcore processors in FPGA and with this project I aim to have
  a compiler that I can modify to my will
3. LLVM is a great project but using it would be against the objectives of item 1 of this list
4. I like to program in low-level but also like high-level stuff. I missed features in C in C++ that were
   present in other languages but not in C and C++. E.g.: 
    * use a simple import/use instead of include+ifdef. 
    * do not worry about recursive file inclusions
    * type inference without being verbose (no need to auto keyword and similar stuff)
    * closures
    * a nice standard library without having to resort to boost with verbose syntax

There are other reasons but I guess I don't need to explain all of them right now.

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
