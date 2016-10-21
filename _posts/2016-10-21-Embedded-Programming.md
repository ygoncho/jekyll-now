---
layout: post
title: Week Seven&#58; Embedded Programming
---

An electronic lock, password protected.

### Background

The assignment for this week fell deep into my comfort zone. We were to write something for the FTDI board we made last time using embedded coding. My weapon of choice was embedded C.

### Spec sheet

First step: I read the spec sheet for the Attiny44. I focused on interrupts and io.
Here's the [link](http://www.atmel.com/images/doc8006.pdf).

### Design

My original idea was to make a cool little "Hangman game". About halfway through coding I tried to flash what I had, and got many overflows: My program was too big for the memory.
I also wanted to transfer some data around so played with eeprom r/w, until I realized I could just use a global variable.

I decided to code a password-protected LED: Only when entering the right password will the LED light up. Using an interrupt request by pushing the button, users will be able to reset the password.

Key takeaways:

* Global variables are more well accepted, but make sure you make them volatile or you will experience odd things in functions.
* Hard coded strings will take a lot of your memory. Be mindful of the size of the flash, this could easily cause issues. Code for space, not for readability, and comment when necessary (that won’t enter the flash).

### Links

* [Source Code]({{ site.baseurl }}/project_files/yuval.c)
* [Makefile]({{ site.baseurl }}/project_files/yuval.c.make)
* [Hex Code]({{ site.baseurl }}/project_files/yuval.c.hex)

### Demo

Project Demo:

<iframe width="560" height="315" src="https://www.youtube.com/embed/GY3EoKouipU" frameborder="0" allowfullscreen></iframe>

Code Review:

<iframe width="560" height="315" src="https://www.youtube.com/embed/rGsr9pfwnlU" frameborder="0" allowfullscreen></iframe>
