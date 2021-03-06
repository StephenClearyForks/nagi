# NAGI Source

**By Nick Sonneveld**


### Introduction

This is the public release of the NAGI source code.

NAGI (New Adventure Game Interpreter) is a clone of Sierra's own AGI which
they created and used through the 80's to produce a whole bunch of great
adventure games like Space Quest, Leisure Suit Larry and Kings Quest. NAGI was
created by disassembling the original AGI executable and writing equivalent C
code that would run under SDL which is a free generic library for low-level
access to graphics and audio. It can read both v2 and v3 game data for the PC.

I am still supporting and working on NAGI!  I just feel it's time to release
the source code as well.  If you are working on a similiar interpreter or a
tool to help develop AGI games, then hopefully you'll find some use in the
NAGI source code.  The original source was released April 18th, 2002.

The current source release supports Linux and some some minor bug fixes!
Check it out!


### Current Developers:

  * [Nick Sonneveld][1] - Original author
  * [Gareth McMullin][2] - Linux port and tweaking
  * [Claudio Matsuoka][3] - has pledged to support the project.


### License

NAGI's source has been released under the X11 license.  This means you can use
the source in any project you want and you do not have to provide the source
if that is your wish.  You have to make sure you acknowledge my copyright and
you cannot use my name as an endorsement of something else.  No warranties are
implied either.

The X11 license has been deemed to be [compatible with the GPL license][4].
For the full license, check out of the bottom of this page.


###  Systems Supported

  * Windows - NAGI was originally written for Windows using the SDL Library
  * Linux - a new version, ported by Gareth McMullin


### Build Requirements

In order to successfully build NAGI from the provided source code, you will
need:

  * gcc - [MinGW][5] is an excellent compiler for Windows
  * Make - automating compilation  (available through cygwin or the ported
mingw tools)
  * Sed - an attempt at dependancy generation
  * [SDL Library Headers][6] - NAGI links to this
  * SDL Runtime Library - necessary to run NAGI.  Usually is provided with SDL
Library


### How to Build

Make sure SDL include files are available using #include <sdl/sdl.h>

The mingw tools, sed and make will need to be in the system path.  Depending
on the operation system you need to type in:

  * "make -f Makefile.win"
  * "make -f Makefile.linux"

For Windows (since Linux version only has one build)

  * "make -f xx" - compile NAGI and NAGI-console
  * "make -f xx nagi" - compile NAGI
  * "make -f xx nagi-console" - compile NAGI with console support

All files are produced in a directory called "../bin".  This is easily changed
in the makefile.


### Suggestions

These are some things that I planned to work on:

  * New save game format to make it less fragile and compatible across other
free interpreters
  * Save menu, controller and thumbnail info in save games
  * Font scaling
  * Clean sound code
  * Optimised x1 x2 graphics scale modes
  * beeping for agi errors
  * GUI to configure NAGI options (using wxWindows?)
  * Links with AGI Studio to aid debugging
  * MIDI generation
  * Ability to split ini keys on several lines
  * Screenshots
  * Separate ini file in game directory overides main ini
  * cache of found games
  * After quitting game, go back to game menu
  * Dialogue box to enter commands
  * Selectable gui backgrounds
  * 256 colour / palette hacks
  * support for Amiga mouse commands
  * support for AGInfo's game checksum list
  * support early interpreter's sprite handling (fix Donald Duck, AGI Trek,
Xmas demo sprite glitches)
  * transition screen fades between new rooms
  * fix windib support (SDL problem?)
  * joystick support
  * patches for copy protection

Hopefully that will give you some ideas if you want to hack NAGI.


### Disassembled Code

Also in another package are files I used for disassembling NAGI.  Some code,
before I started writing straight into C, is available here along with files
that are compatible with the early free DOS version of IDA (interactive
disassembler).  If you have a legal commercial Windows version, it should be
able to read them in and convert them.

If any of the disassembled comments looks wrong, it possibly is.  I learnt
proper C and how to read assembler from this project so my initial guesses may
be wrong.


### Support

Send me any emails if you want more information on NAGI or how the source code
fits together.  As long as it doesn't get too demanding, I won't mind
answering any questions.


### X11 License

The license in full: (applies to all source code)

    COPYRIGHT AND PERMISSION NOTICE

    Copyright (c) 2001, 2001 Nick Sonneveld

    All rights reserved.

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the
    "Software"), to deal in the Software without restriction, including
    without limitation the rights to use, copy, modify, merge, publish,
    distribute, and/or sell copies of the Software, and to permit persons
    to whom the Software is furnished to do so, provided that the above
    copyright notice(s) and this permission notice appear in all copies of
    the Software and that both the above copyright notice(s) and this
    permission notice appear in supporting documentation.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT
    OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
    HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL
    INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING
    FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
    NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
    WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

    Except as contained in this notice, the name of a copyright holder
    shall not be used in advertising or otherwise to promote the sale, use
    or other dealings in this Software without prior written authorization
    of the copyright holder.

[Nick Sonneveld][7]




   [1]: mailto:sonneveld.at.hotmail.com

   [2]: mailto:g_mcm.at.mweb.co.za

   [3]: mailto:claudio.at.helllabs.org

   [4]: http://www.gnu.org/licenses/license-list.html

   [5]: http://www.mingw.org

   [6]: http://www.libsdl.org/

   [7]: mailto:sonneveld.at.hotmail.com

