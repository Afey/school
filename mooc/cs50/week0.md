# Week 0 - ```CS50x```

## Binary

At the lowest level of computers, information is represented by electricity. You can think of the transistors that store this information as desk lamps that can be either on or off. The off state represents the number 0 and the on state represents the number 1.

To represent larger numbers, we use more than one desk lamp or transistor. Each desk lamp corresponds to a single bit of information. Just as each lamp has two possible states (on and off), each bit can take two possible values (1 and 0). With 2 desk lamps, we can represent 2 * 2 = 4 possible values. With 3 desk lamps, we can represent 2 * 2 * 2 = 8 possible values.

Writing binary numbers is identical to writing the decimal numbers that you’re familiar with. A number like 123 can be broken out like so:

```
100's   10's   1's
1       2      3
```

In binary, the 100’s, 10’s, and 1’s columns are replaced with 4’s, 2’s, and 1’s columns. Only the numbers 0 and 1 are allowed in each column.

```
4's    2's   1's
1      1     1
```
With 1 * 4, 1 * 2, and 1 * 1, we represent the number 7.

## ASCII

Now that we have binary to represent numbers, we need a way to represent alphabetic characters. Enter ASCII, an encoding system which represents every alphabetic character with a given number. For example, an uppercase "A" is represented by the number 65 and an uppercase "Z" is represented by the number 90.

With this encoding system, we can begin to spell out words. If we bring 8 volunteers on stage, we can allow each of them to represent a single bit. Together, they represent a number that we can map to a letter. When a volunteer raises her hand, her digit is a 1. Otherwise, her digit is a 0. After three rounds of this, we can represent the numbers 66, 79, and 87, or, according to our ASCII chart, the characters B, O, and W. And with that, our volunteers take a bow!

## Algorithms

### The Famous Phonebook Example

Back in the days when phone numbers weren’t stored in cell phones, you might have actually had to look them up in a phonebook. How did you go about that? If you wanted to look up someone with the last name "Smith," you could flip through the phonebook one page at a time. You don’t need to be a computer scientist to know that this is an inefficient approach.

Instead, we could start by flipping to the middle of the phonebook. Now we break the problem into two. Since we know that "Smith" isn’t in the left half of the alphabet, we can literally tear the phonebook in half, throw away the left half of the phonebook, and leave ourselves with only the right half. Once again, we flip to the middle and find ourselves at "R." We can again throw away the left half. As we continue tearing the book in half and throwing away pieces of it, we will eventually be left with a single page on which the name "Smith" appears (assuming it was there in the first place).

How do these two approaches compare in terms of their times to solve the problem? In the graph below, the first steep line (n in red) represents the approach of turning one page at a time. The second steep line (n/2 in yellow) represents a slightly improved approach of turning two pages at a time. The curve (log n in green) represents our "tear and throw away" approach. As the size of the problem grows, the time to solve that problem doesn’t grow nearly as fast. In the context of this problem, n is the number of pages in the phonebook. As we go from 500 to 1000 to 2000 pages in the phonebook, we need only tear the phonebook in half one or two more times.

[!](http://d2o9nyf4hwsci4.cloudfront.net/2013/fall/lectures/0/w/notes0w/runtimes.png)

### Counting People

In order to illustrate programming examples, we’ll often use pseudocode. Pseudocode is English-like syntax meant to represent a programming language. Check out this TED-Ed video which introduces the concept of an algorithm using pseudocode.

Let’s take a look at another problem: counting the number of students in this lecture hall. We can solve this problem using a very simple algorithm:

```pseudocode
stand up and assign yourself the number 1

pair off with someone standing, add your numbers together, and adopt the sum as your new number

one of you should sit down; the other should go back to step 2
```

This algorithm gives us 637, which is close to the correct number of 729. Hooray! Using the algorithm above, we got to this number much faster (in only 9-10 steps) than we would have if we had pointed to each person individually (729 steps). Why is it so much faster? Each execution of the algorithm cuts the problem in half, just like in the phonebook example. Even if there were 4 billion students in the lecture hall, it would only take us 32 executions of this algorithm to count them all!

## Steganography

Steganography is the art of hiding information within images. Although it appears to be random noise, this image is actually of something much more interesting:

[!](http://d2o9nyf4hwsci4.cloudfront.net/2013/fall/lectures/0/w/notes0w/iron_puzzle.png)

The actual code for hiding information in this picture is something like the following:

```JavaScript
im = new SimpleImage("iron-puzzle.png");
for (x = 0; x < im.getWidth(); x++) {
        for (y = 0; y < im.getHeight(); y++) {
                // code for each x,y pixel here
        }
}
```

This code may look like gibberish to you, but it’s actually not that hard to break down. Line 1 simply opens up an image. Lines 2 through 4 walk through the dots that make up the image. Now let’s add some lines of code that remove all of the blue and green from these dots and bump up the red by a factor of ten:

```JavaScript
im = new SimpleImage("iron-puzzle.png");
for (x = 0; x < im.getWidth(); x++) {
  for (y = 0; y < im.getHeight(); y++) {
    im.setBlue(x, y, 0);
    im.setGreen(x, y, 0);
    red = im.getRed(x, y);
    im.setRed(x, y, red * 10);
  }
}
print(im);
```

Just allow yourself to be wowed by the result:

[!](http://d2o9nyf4hwsci4.cloudfront.net/2013/fall/lectures/0/w/notes0w/iron_solution.png)