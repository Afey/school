# Week 1 - ```CS50x```

## From Scratch to C

Recall that source code looks something like the following:

```C
int main(void)
{
    printf("hello, world\n");
}
```

The blue "say" puzzle piece from Scratch has now become printf and the orange "when green flag clicked" puzzle piece has become main(void).

However, source code is not something a computer actually understands. To translate source code into something the computer understands, we’ll need a compiler. A compiler is a program that takes source code as input and produces 0’s and 1’s, a.k.a. object code, as output.

We won’t trouble ourselves with knowing the exact mapping between a series of 0’s and 1’s and the "print" command. Rather, we’ll content ourselves with writing instructions at a higher level that can be translated to a lower level. This is consistent with one of the themes of the course: layering on top of the work of others.

Statements are direct instructions, e.g. "say" in Scratch or printf in C.

The "forever" loop from Scratch can be recreated with a while (true) block in C. The "repeat" loop from Scratch can be recreated with a for block in C.

Note that in C just as in Scratch, there are multiple ways of achieving the same goals.

In C, a loop that increments a variable and announces its value would look like so:

```C
int counter = 0;
while (true)
{
    printf("%i\n", counter);
    counter++;
}
```

Here we declare a variable named counter and then create an infinite loop that prints its value then increments it.

Boolean expressions are much the same in C as in Scratch. The less-than (<) and greater-than (>) operators are the same. One difference is that the "and" operator is represented as && in C.

Conditions in C look much the same as they do in Scratch:

```C
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else
{
    printf("x is equal to y\n");
}
```

## hello, world!

The CS50 Appliance is software running inside of your normal computer’s environment that simulates the environment of another operating system, namely Fedora Linux. At the bottom left of the Appliance window are three icons for gedit, Chrome, and Terminal. Since we can code in any text editor, let’s start by opening gedit.

In gedit, there are three main divisions of the window:

* on the left, the source code pane

* on the right, the actual text editor, where we write code

* on the bottom, the terminal, where we run commands

Note that all of your files by default save to the jharvard directory, which is unique to your Appliance and is not shared with other students. All of your files in the Dropbox subdirectory are automatically backed up in the cloud. In this directory, we’ll save our file as hello.c.

Now let’s quickly rewrite that first program in C:

```C
#include <stdio.h>

int main(void)
{
    printf("hello, world!\n");
}
```

To actually run this program, we click on the terminal at the bottom of gedit. To begin, we’re in the jharvard directory. On other operating systems, we can simply double click on another directory in order to open it. But in the terminal, we can only use the keyboard. So to get to the Dropbox folder, we instead type cd Dropbox. Now if we type make hello, we see a bit of cryptic syntax, but afterward, we can run ./hello and see our program execute successfully.

A single dot (.) refers to the current directory. Typing ./hello instructs the computer to look for a program named hello in the current directory. Type ls to see the contents of the current directory. In green, you’ll see hello, which is the executable program that we just compiled. Recall that we use a compiler to translate the source code above into the object code that the computer can actually understand.

## Compiling

When we type make hello in the terminal, the command that actually runs is as follows:

```bash
$ clang -ggdb3 -00 -std=c99 -Wall -Werror hello.c -lcs50 -lm -o hello
```

make is not actually a compiler, but rather a program that shortcuts these options to the compiler, which in this case is clang. The shorter version of the command above is:

```bash
$ clang -o hello hello.c
```

-o is a switch or flag, an option that influences the behavior of the program. In this case, the value provided after -o is hello, which becomes the name of the executable that the compiler creates. We could’ve typed -o hihihi and our executable would then have been named hihihi. The flags that we pass to a program are special examples of command-line arguments.

---
*Derived from [CS50 Notes](http://d2o9nyf4hwsci4.cloudfront.net/2013/fall/lectures/1/m/notes1m/notes1m.html)*