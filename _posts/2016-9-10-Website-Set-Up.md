---
layout: post
title: Week One- Website set-up
---

The purpose of this post is mostly to get to know some Markdown features and play around with text and images.

(I'll admit; the last time I owned a website was in the 1999 [Geocities](https://en.wikipedia.org/wiki/Yahoo!_GeoCities) era; it was a website dedicated to The Simpsons and I was 14 years old).

### Website - How did I choose the environment I chose

My German blood makes me a true believer in version-controlled projects. Most of my experience was with [perforce](https://www.perforce.com/), but I've owned a Github account for a while now.

A good friend at [CODE@HBS](http://www.codehbsclub.com/) recently introduced me to Jekyll, a blog-building platform that works well with GitHub and is extremely easy to use, so I gave it a shot.

### Website - Setup

This site is based on Barry Clark's [Build a Blog with Jekyll and Github Pages](https://www.smashingmagazine.com/2014/08/build-blog-jekyll-github-pages/) tutorial. Here are the major steps I took after forking the project onto my own GitHub page:

At first, I updated the site through the web-based editor, and committed files immediately:

+ Personalized _config.yml
+ Added photo
+ Updated first Blog Entry \("Week Zero"\)

(By the way, if you want to make an unordered list in Markdown, you have to leave a blank line between the end of the last paragraph and the list. Ugh.)

At some point I noticed the site stopped updating; I've received an email from GitHub that the Jekyll build failed, but the error message was very vague. I decided to download the Jekyll Build tools to my personal computer to debug in an easier way\:

1. Downloaded [RubyInstaller](http://rubyinstaller.org/downloads/)
2. Downloaded [GitHub Desktop](https://desktop.github.com/)
3. Cloned my project to my local computer
4. [Built my site locally](https://help.github.com/articles/setting-up-your-github-pages-site-locally-with-jekyll/#step-4-build-your-local-jekyll-site).
5. Commit, push to GitHub

That's how I finally figured out the error:
This was because I used a colon ("\:") without the escape character \("\\"\) in the first Blog post. Lesson learned!

I also found this very useful [Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet).

### DevEnv
To add and summarize, here are my weapons of choice for maintaining this site\:

1. The [Gvim](http://www.vim.org/download.php#) editor is my love, now and forever. It has a steep learning curve, but I've been using it since I was 12 and can't really imagine using any other editor anymore.
2. [GitHub Desktop](https://desktop.github.com/)
3. Git command line tools (Git Shell)
4. [Jekyll](https://jekyllrb.com/)