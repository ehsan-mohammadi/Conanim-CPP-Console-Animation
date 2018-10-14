/*
 _____ _____ _____ _____ _____ __ ______
|   __|     |   | |     |   | |  |      |  conanim.h for C++
|  |__|  |  | | | |  |  | | | |  |  ||  |  Version 1.0.0
|_____|_____|_|___|_| |_|_|___|__|_|  |_|

  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  Copyright (c) 2018 Ehsan Mohammadi

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
#ifndef CONANIM_H
#define CONANIM_H

#include<iostream>
#include<Windows.h>
#include<string.h>
#include<math.h>

class Animation
{
private:
	char* content_;
	int x_, y_;

	void gotoxy(int, int);
	void printContent(int, int);
	void clearPrevContent(int, int);
public:
	Animation(char *);
	void translateX(int, int, int, float);
	void translateY(int, int, int, float);
	void wink(int, int, int, float);
	void colorize(int, int, int, float);
	void extend(int, int, float);
	void extendToDown(int, int, float);
	void appear(int, int);
	void hide();
};

#endif