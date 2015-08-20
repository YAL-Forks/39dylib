# 39dylib V2.0
#### Alpha 1

Welcome to the official repo for the 39dylib library! 39dylib is a socket library for Darwin (Mac OS X, iOS), Linux (Desktop and Android), and Windows. It was designed to provide a simple socket extension for Mark Overmars' and YoYo Games's GameMaker software, but you could probably find other uses for it too.

39dylib is based on and forked from Luke Graham's (39ster) popular 39dll library, which is in the public domain. 

You can get binaries for 39dylib from http://www.vetragames.com/software/. This is merely a repo for the source code.

## What is different from 39dll?

Lots of things. The main thing is that 39dylib is very portable. The code should compile on Mac OS X, iOS, Windows, Linux, and your toaster. 

39dylib 2.0 also has a revamped internal codebase. The idea is to clean up and polish everything internally in order to support future feature additions.

## Should I use 39dylib? Why?

39dylib (like 39dll) is fairly low level and doesn't really do a lot of work for you. There are a lot of networking libraries for Game Maker out there that are more modern and easier to use, like Faucet Networking. 

So the answer is: it depends. If you have an old project that uses 39dll then you should definitely use 39dylib. It's more modern and it's also multiplatform, but it remains fully compatible with 39dll.

If you are starting a new project and use GameMaker Studio, you're probably better off using GM's own native networking functionality. It runs on anything that Game Maker runs on and is easier to use as well.

If you're using an older (non networked) version of Game Maker or Game Maker Studio (GM:Studio Pre 1.3, classic Game Maker 5.0 to 8.1, or ENIGMA), and you need a portable networking library, then 39dylib is definitely for you. However if your project is Windows exclusive then a more modern library like Faucet is probably better. 

39dylib should be compatible with anything from old versions of Game Maker to Game Maker Studio. So if you like 39dll and are familiar with it, then 39dylib is for you. :) 

## Project Status

39dylib should be considered alpha software, and is still a WIP. It has been used for a number of commercial projects in the past, but not everything will work out of the box. 

- **Macintosh version:** fully ported!
- **iOS version:** fully ported!
- **Linux version:** port in progress.
- **Android version:** port in progress. 
- **Windows version:** fully ported!

## Licence 

39dylib is licensed under the GNU Lesser General Public Licence licence, version 2.1. You can read a copy of the licence [here](http://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html).

