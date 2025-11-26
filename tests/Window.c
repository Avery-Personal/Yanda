/*
===========================================================
                            |
                     TEST INFORMATION

TEST NAME: Window.c
CREATION DATE: 25/11/21 | International Date Format
LAST MODIFIED: 25/11/21 | International Date Format

===========================================================
                      TEST PURPOSE

This test is to mark & benchmark the first stage of Yanda.
It's to test top-level functions with the Yanda.h header.

If working correctly, the program should open an empty
black window with a command prompt to the side.

===========================================================
                   LICENSE INFORMATION

The following software is protected under the MIT license.
More detailed information is present at the root LICENSE
file AND OR the end of the file.

===========================================================
*/

#include "../src/Yanda.h"
#include "../include/Yanda_event.h"

int main() {
    YANDA_Initialize();

    YANDA_Window *WINDOW = YANDA_CreateWindow("Window Testing", 800, 600);

    while (YANDA_Update(WINDOW)) {
        
    }

    YANDA_DestroyWindow(WINDOW);
    YANDA_Shutdown();
}

/*

All source code & software are available under the MIT license:
    MIT License

    Copyright (c) 2025 Averi

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

*/
