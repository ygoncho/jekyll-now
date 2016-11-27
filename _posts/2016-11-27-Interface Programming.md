---
layout: post
title: Week Twelve&#58; Interface Programming
---

Wrote a small program to interface with input- and output-devices

### Background

This week our assignment was to write a GUI to work with our input/output devices.

### Design

My final project will not be using any interface programming (the only UI will be the button that is pushed), so I used an old PCB I made from Embedded Programming week. As a reminder, here is the PCB:

[![_config.yml]({{ site.baseurl }}/images/EchoHelloWorld/Soldered.JPG "Soldered"){:height="200px"}]({{ site.baseurl }}/images/EchoHelloWorld/Soldered.JPG "Soldered"){:height="300px"}

[Trace]({{ site.baseurl }}/images/EchoHelloWorld/RulerYuvalFinal.png)

[Cut]({{ site.baseurl }}/images/EchoHelloWorld/RulerYuvalOuter.png)

### Code

The C embedded code today is very simple; it accepts the serial character 'y' as a command to turn the LED on, and 'n' as a command to turn it on. Additionally, every time the button is pressed or the LED status changes, the button status is transmitted via the serial connection: '1' for on and '0' for off.

[Here's the Embedded C code]({{ site.baseurl }}/project_files/yuval2.c)

[Here's the makefile]({{ site.baseurl }}/images/yuval2.c.make)

For the host code, I chose Python and [Tkinter](https://wiki.python.org/moin/TkInter); It's a fairly simple way to create easy GUI interfaces. Basically I open the serial connection and I have buttons to send 'y' or 'n' to turn the LED on or off, respectively. In addition, I listen for the connection. A cool on/off graphic changes on the screen when the button is pushed.

[Here's the Python code]({{ site.baseurl }}/project_files/if.py)

And here are the [On]({{ site.baseurl }}/images/Interface/on.bmp) and [Off]({{ site.baseurl }}/images/Interface/off.bmp) images.

Here's how the interface looks:

[![_config.yml]({{ site.baseurl }}/images/Interface/interface.png "interface"){:height="200px"}]({{ site.baseurl }}/images/Interface/interface.png "interface"){:height="300px"}

And here's a video of everything together:

<iframe width="560" height="315" src="https://www.youtube.com/embed/H0H13jJhR90" frameborder="0" allowfullscreen></iframe>


Yay.