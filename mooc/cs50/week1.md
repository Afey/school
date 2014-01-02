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

## Programming Constructs in C

### Conditions

Conditions in C look like so:

```C
if (condition)
{
    // do this
}
```

Note the encapsulation provided by the curly braces again. The // denotes a comment, a line of English that explains the code.

A two-way fork in logic looks like this:

```C
if (condition)
{
    // do this
}
else
{
    // do that
}
A three-way fork in logic looks like this:

if (condition)
{
    // do this
}
else if (condition)
{
    // do that
}
else
{
    // do this other thing
}
```

The quote strings and variables we’ve been passing to printf between the parentheses are known as arguments. An argument is a value that influences the behavior of the function.

### Boolean Expressions

The Boolean operators "and" and "or" are written as && and || in C:

```C
if (condition && condition)
{
    // do this
}
if (condition || condition)
{
    // do this
}
```

Note that & and | have different meaning!

### Switches

Switches are another way of implementing forks in logic. Instead of repeated "else if" blocks, you can handle cases like so:

```C
switch (x)
{
    case 1:
        // do this
        break;

    case 2:
        // do that
        break;

    default:
        // do this other thing
        break;
}
```

### For Loops

for loops take the following general structure:

```C
for (initializations; condition; updates)
{
    // do this again and again
}
```

Within the parentheses after the for keyword, there are three parts. Before the first semicolon, we are initializing a variable which will be our iterator or counter, often named i by convention. Between the two semicolons, we’re providing a condition which, if true, will cause another iteration of the loop to be executed. Finally, we provide code to update our iterator.

A snippet of code to print "hello, world!" ten times would look something like:

```C
for (int i = 0; i < 10; i++)
{
    printf("hello, world!\n");
}
```C

Recall that i++ is shorthand for "increment the value of i by 1." This loop continues executing so long as i < 10, which happens 10 times.

A while loop is functionally equivalent to a for loop, albeit with slightly different syntax. Consider this code that prints out "hello, world!" infinitely:

```C
while (true) {
    print("hello, world\n");
}
```

As soon as the condition between the parentheses after while evaluates to false, the loop will terminate. In this case, however, true will never be false, so the loop continues forever.

A do while loop executes before checking the condition it depends on. That means it will always execute at least once. The general structure is as follows:

```C
do
{
    // do this again and again
}
while (condition);
```

### Variables
Syntactically, declaring a variable looks like so:

```C
int counter;
counter = 0;
```

Declaring a variable means asking the computer for some number of bits in which to store a value, in this case the value of an integer. The second line of code above assigns the value 0 to the variable counter. = is the assignment operator and instructs the computer to put the right in the left.

We can do variable declaration and assignment all in one line:

```C
int counter = 0;
```

This one is a little easier to read and should be considered best practice.

### Functions
A function is a piece of code that can take input and can produce output. In some cases, a function can be a so-called black box. This means that the details of its implementation aren’t relevant. We don’t care how it does what it does, just that it does it.

Let’s represent printf with an actual black box onstage. We can write "hello, world" on a piece of paper to represent an argument to printf. We then place this piece of paper in the black box and, by whatever means, the words "hello, world" appear on the screen!

To make our hello program more dynamic, we asked the user for his or her name and passed that to printf:

```C
string name = GetString();
printf("hello, %s\n", name);
```

printf doesn’t return anything; it only has the side effect of printing to the screen. GetString, on the other hand, returns what the user typed in.

As with printf, we don’t necessarily care how GetString is implemented. We know that when we call it, we’ll be provided with a string after some amount of time. We can simulate this by retrieving from the black box a piece of paper with a student’s name (Obasi) written on it. We actually then make a copy of this string before storing it in name.

Now we have name written on one piece of paper which will act as the second argument to printf. Next we create the first argument by writing "hello, %s\n" on another piece of paper. Finally, we place these two pieces of paper in the black box and magically, "hello, Obasi" appears on the screen.

Functions that we implemented in the CS50 Library (cs50.h) include:

* GetChar

* GetDouble

* GetFloat

* GetInt

* GetLongLong

* GetString

Convention holds that C function names are lowercase, but we capitalized these just to make it clear that they belong to the CS50 Library.

A float is a number with a decimal point. A double is a number with a decimal point but with more numbers after the decimal point. These types returned by CS50 Library function require different number of bits to be stored. A char requires 8 bits, a float requires 32 bits, and a double requires 64 bits. A long long is an integer that is twice as big in memory (64 bits) as an int (32 bits). More on these types later.

The CS50 Library also contains two custom types:

* bool

* string

For convenience, we have created the symbols true and false to represent 1 and 0. Likewise for convenience, we have created a string type to store strings.

The actual types of variables available in C are as follows:

* char

* double

* float

* int

* long long

The printf function can take many different formatting characters. Just a few of them are:

* ```%c``` for char

* ```%i``` (or ```%d```) for int

* ```%f``` for float

* ```%lld``` for long long

* ```%s``` for string

A few more escape sequences:

* \n for newline

* \r for carriage return (think typewriter)

* \' for single quote

* \" for double quote

* \\ for backslash

* \0 for null terminator

## Hellos and More

###hello-0.c

As before, we’ll open a file in gedit on the Appliance and save it to the jharvard directory. We’ll call this file hello-0.c and write the following therein:

```C
int main(void)
{
    printf("hello, world\n");
}
```

When we type ```make hello-0``` in the terminal window at bottom, we get all sorts of compiler errors. At the top of these errors, which tend to compound each other, we see:

```
...implicitly declaring library function 'printf'...
```

This error message may seem overwhelming, but try looking for keywords. Right away we notice printf. We forgot to include the library that contains the definition of printf:

```C
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

### hello-1.c
To say hello to the user, we need a variable to store his or her name:

```C
#include <stdio.h>

int main(void)
{
    string name = "David";
    printf("hello, %s\n", name);
}
```

For now, we hardcode the value "David" into the variable name. This time when we compile (simply hit the up arrow to see previous commands in Linux), we get the following error:

```
...use of undeclared identifier 'string'
```

We need to also include the CS50 Library:

```C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = "David";
    printf("hello, %s\n", name);
}
```

Sigh, still more compiler errors. The topmost one says:

```
...multi-character character constant...
```

That doesn’t help us too much, but clang does point us to the problem are with a green caret. Turns out that in C, strings must be delimited by double quotes, not single quotes:

```C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = "David";
    printf("hello, %s\n", name);
}
```

### hello-2.c
Finally, let’s actually accept dynamic input from the user:

```C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("State your name: ");
    string name = GetString();
    printf("hello, %s\n", name);
}
```

This program compiles and functions correctly for normal names like Rob, Lauren, and Joseph. What about an empty name? It just prints out "hello, "; perhaps we should use a condition and a loop so that we keep prompting the user until he provides a non-empty name.

### adder.c

If we want to ask the user for integer input, we can use the GetInt function:

```C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for input
    printf("Give me an integer: ");
    int x = GetInt();
    printf("Give me another integer: ");
    int y = GetInt();

    // do the math
    printf("The sum of %i and %i is %i!\n", x, y, x + y);
}
```

Notice that we don’t need a separate variable to store the sum, we can inline x + y.

### conditions-0.c

conditions-0.c has a subtle bug in it:

```C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for an integer
    printf("I'd like an integer please: ");
    int n = GetInt();

    // analyze user's input (somewhat inaccurately)
    if (n > 0)
    {
        printf("You picked a positive number!\n");
    }
    else
    {
        printf("You picked a negative number!\n");
    }
}
```

Although this program is syntactically correct (it compiles and runs), it is logically incorrect (it declares 0 a negative number).

### conditions-1.c

To handle the corner case of 0, we need another fork in logic:

```C
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask user for an integer
    printf("I'd like an integer please: ");
    int n = GetInt();

    // analyze user's input
    if (n > 0)
    {
        printf("You picked a positive number!\n");
    }
    else if (n == 0)
    {
        printf("You picked zero!\n");
    }
    else
    {
        printf("You picked a negative number!\n");
    }
}
```

Note that to test equality, we use ==, not =, which is the assignment operator.

---
*Derived from CS50 Notes: [Week 1](http://d2o9nyf4hwsci4.cloudfront.net/2013/fall/lectures/1/m/notes1m/notes1m.html), [Week 1, continued](http://d2o9nyf4hwsci4.cloudfront.net/2013/fall/lectures/1/w/notes1w/notes1w.html)*