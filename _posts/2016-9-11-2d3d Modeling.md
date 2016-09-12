---
layout: post
title: Week One&#58; 2D/3D Modeling
---

Our assignment for the first week was to model (raster, vector, 2D, 3D, render, animate, simulate, ...) a possible final project, and post it on our class page.

### What should I model?

My wife is always the one with the ideas. She suggested anything from minor trampolines to funky office supplies, but I am more practical: our toilet paper dispenser broke the other day; I felt it should be a good device to start learning with (some cylinders, a spring, and to-scale modeling)

As a potential final project, if this ends up to be it, I could add cool features to it like USB charging, speakers and BlueTooth support, FM radio and even a servo that will dispense the paper at the push of a button.

Electronics will come later - today we're all about modeling.

### Some photos

Here are some photos of the holder of what was once the dispenser. My aim, as a first step, is to fill in the missing piece.

![_config.yml]({{ site.baseurl }}/images/OldDispenser/OldDispenser1.JPG "OldDispenser1"){:height="200px"} ![_config.yml]({{ site.baseurl }}/images/OldDispenser/OldDispenser2.JPG "OldDispenser2"){:height="200px"} 
![_config.yml]({{ site.baseurl }}/images/OldDispenser/OldDispenser3.JPG "OldDispenser3"){:height="200px"} ![_config.yml]({{ site.baseurl }}/images/OldDispenser/OldDispenser4.JPG "OldDispenser4"){:height="200px"}

### Concept

I started by just drawing for myself the basic dimensions:

![_config.yml]({{ site.baseurl }}/images/NewDispenser/NewDispenserHandDrawn.JPG "NewDispenserHandDrawn"){:height="200px"} 

The base product will have an inner cylinder which will be able to fit the two metal pieces already mounted to my wall.
It will actually be made of two smaller ones with a spring between them, to allow for easy insertion into the slot. 
An outer tube will wrap the smaller cylinder to hide the spring and to provide a better grip to the toilet paper roll, to avoid jitter as it turns.

### 2D Model

#### Raster or Vector?
Rastered images have finite resolution and are not as good for modeling. So for my first 2D modeling exercise I decided to go with a vector-based model. The undisputed king here is [Adobe Illustrator](http://www.adobe.com/products/illustrator.html); it costs money but like any good drug, there's an evaluation period.

It took me about 2 hours, but here are a few images of the final result (wireframe and full): 

![_config.yml]({{ site.baseurl }}/images/NewDispenser/Vector2d.png "NewDispenserVector"){:height="200px"} 
![_config.yml]({{ site.baseurl }}/images/NewDispenser/Vector2d_full.png "NewDispenserVector"){:height="200px"} 

(the actual [.AI file]({{ site.baseurl }}/project_files/NewDispenser.ai) is vectorized, of course)

Here are some lessons I learned:

* Drawing to scale is important! I highly recommend snapping a grid and enabling the ruler. Keep a close eye on each image's height and width.
* Illustrator is a 2d modeling software, but we can still "think" in 3d; I loved the "revolve" effect that I learned of when trying to model the spring. [This](https://www.youtube.com/watch?v=-KT8Q_mn194) is a fantastic tutorial.

### 3D Model

Having the 2d model in my hand, I decided to proceed to 3d modeling. Weapon of choice for today: [Rhino 3D](https://www.rhino3d.com/download). After skimming several on-line tutorials this seemed rather intuitive so I decided to give it a shot.

3D modeling is more complex and takes some time getting used to. The following tutorials are recommended:

* [Interface Basics](https://vimeo.com/58212839?interface_basics_win)
* [Modeling and rendering a simple glass with Rhino](https://vimeo.com/49597954?simple_glass)
* [Learning Rhino - Helix](https://www.youtube.com/watch?v=j4OJgX_f0yg)

Below are some snapshots of the process and final product (which is again, exactly to scale with how I drew it in the first place). My favorite feature here is the different Display Modes (e.g. wireframe, shaded, and ghosted). The final 3DM file is available [here]({{ site.baseurl }}/project_files/NewDispenser.3dm)

* Creating the first cylinder:

![_config.yml]({{ site.baseurl }}/images/NewDispenser/1stCylinder.png "1st Cylinder"){:height="300px"} 

* Adding the helix:

![_config.yml]({{ site.baseurl }}/images/NewDispenser/AddedHelix.png "AddedHelix"){:height="300px"} 

* Adding the wrapping tube / final version with several Display Modes:

![_config.yml]({{ site.baseurl }}/images/NewDispenser/AddedTube.png "AddedTube"){:height="300px"} ![_config.yml]({{ site.baseurl }}/images/NewDispenser/Wireframe.png "Wireframe"){:height="300px"} ![_config.yml]({{ site.baseurl }}/images/NewDispenser/Ghosted.png "Ghosted"){:height="300px"}

### Additional touches

At this point I decided to remodel the holders for the dispenser rather than use the two that I already have at home, hopefully with the intent of making this THE ULTIMATE DISPENSER later, and adding electronics, etc.

The key feature here is the Boolean Difference tool that Rhino offers, as is explained in [this simple and effective tutorial](https://www.youtube.com/watch?v=Djh7ZSxuYYQ).

Here's a list of additional things I did:

* Added a USB socket. The actual socket itself was downloaded from [grabCAD](https://grabcad.com), an open source CAD library. I wrapped a box around it using the [BoundingBox](http://docs.mcneel.com/rhino/5/help/en-us/commands/boundingbox.htm) command and then extracted the box from the holder.

* Added support for hanging: Again, I found a model of a classic hinge in grabCAD. This was a bit more tricky because I had to create parallel holes in the holder itself for the nails. what I did was build three small cylinders around the hinge, move them to the big holder and then run a boolean difference tool.

Voila - the final product, TUTPD (The Ultimate Toilet Paper Dispenser) is now taking shape!

[Modelo](beta.modelo.io) is a super cool free service that allows one to upload 3dm files and embed into websites. Here's the final product, for your pleasure:

<iframe src="https://beta.modelo.io/embedded/iFDyXQYC-i?viewport=false&autoplay=false" width="640" height="360" frameborder="0" mozallowfullscreen webkitallowfullscreen allowfullscreen ></iframe>


