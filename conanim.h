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

#include<iostream>
#include <math.h>
#ifdef WIN32
#include<Windows.h>
#else
#include <ncurses.h>
#include <unistd.h>
#endif
#include<string.h>

class Animation
{
private:
	std::string content_;
	int x_, y_;

	void gotoxy(int, int);
	void printContent(int, int);
	void clearPrevContent(int, int);
public:
	Animation(std::string);
	void translateX(int, int, int, float);
	void translateY(int, int, int, float);
	void wink(int, int, int, float);
	void colorize(int, int, int, float);
	void extend(int, int, float);
	void extendToDown(int, int, float);
	void appear(int, int);
	void hide();
};

void Animation::gotoxy(int x, int y)
{
#ifdef WIN32
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
  printf("%c[%d;%df", 0x1B, y, x);
#endif

}
void Animation::printContent(int x, int y)
{
	int line_count = 0;

	gotoxy(x, y);
	for (int i = 0; i < sizeof(content_); i++)
	{
		if (content_[i] == '\n') // Split each row in new line (x, y + line)
		{
			++line_count;
			gotoxy(x, y + line_count);
		}
		else
			std::cout << content_[i]; // Print each line
	}
}
void Animation::clearPrevContent(int x, int y)
{
	int line_count = 0;

	gotoxy(x, y);
	for (int i = 0; i < sizeof(content_); i++)
	{
		if (content_[i] == '\n') // Split each row in new line (x, y + line)
		{
			++line_count;
			gotoxy(x, y + line_count);
		}
		else
			std::cout << " "; // Erase each line with space ' '
	}
}

Animation::Animation(std::string content)
{
  content_ = content;
  x_ = 0;
  y_ = 0;
}
void Animation::translateX(int start_x, int start_y, int end_x, float speed)
{
	// Move to right or left
	x_ = start_x;
	y_ = start_y;
	int sleep_time = round(speed * 1000); // Set time in Milisecond
	int delta_x = abs(end_x - start_x);
	short sign = end_x >= start_x ? 1 : -1; // Determine that animation move to right or left

	printContent(start_x, start_y); // Print content at first time

	for (int i = 1; i <= delta_x; i++)
	{
#ifdef WIN32
		Sleep(sleep_time);
#else
    usleep(sleep_time);
#endif
		clearPrevContent(x_, start_y); // Clear previous place of content

		x_ += sign;
		printContent(x_, start_y); // Print content in new place
	}
}
void Animation::translateY(int start_x, int start_y, int end_y, float speed)
{
	// Move to up or down
	x_ = start_x;
	y_ = start_y;
	int sleep_time = round(speed * 1000); // Set time in Milisecond
	int delta_y = abs(end_y - start_y);
	short sign = end_y >= start_y ? 1 : -1; // Determine that animation move to up or down

	printContent(start_x, start_y); // Print content at first time

	for (int i = 1; i <= delta_y; i++)
	{
#ifdef WIN32
		Sleep(sleep_time);
#else
    usleep(sleep_time);
#endif
		clearPrevContent(start_x, y_); // Clear previous place of content

		y_ += sign;
		printContent(start_x, y_); // Print content in new place
	}
}
void Animation::wink(int x, int y, int count, float speed)
{
	// Wink content
	x_ = x;
	y_ = y;
	int sleep_time = round(speed * 1000); // Set time in Milisecond

	printContent(x, y); // Print content at first time

	for (int i = 0; i < count; i++)
	{
		clearPrevContent(x, y); // Clear content in (x, y) place
#ifdef WIN32
		Sleep(sleep_time);
#else
    usleep(sleep_time);
#endif

		printContent(x, y); // Print content in (x, y) place
#ifdef WIN32
		Sleep(sleep_time);
#else
    usleep(sleep_time);
#endif
	}
}
void Animation::colorize(int x, int y, int count, float speed)
{
	// Colorize content
	x_ = x;
	y_ = y;
	int sleep_time = round(speed * 1000); // Set time in Milisecond
	int color_number = 0;
#ifdef WIN32
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

	printContent(x, y); // Print content at first time

	for (int i = 0; i < count; i++)
	{
#ifdef WIN32
		Sleep(sleep_time);
#else
    usleep(sleep_time);
#endif

#ifdef WIN32
		SetConsoleTextAttribute(outcon, color_number);
#else
    std::cout << "\033[" << "00" << ";" << color_number <<"m"; // Set text color on gcc (linux)
#endif

    printContent(x, y); // Print content in (x, y) place

		color_number++;
		if (color_number > 15) // Color range between [0 ... F]
			color_number = 0;
	}
#ifdef WIN32
	SetConsoleTextAttribute(outcon, 7); // Change color to default white
#else
  std::cout << "\033[" << "00" << ";" << "37" <<"m"; // Set text color on gcc (linux)
#endif
}
void Animation::extend(int x, int y, float speed)
{
	// Extend each character of content
	x_ = x;
	y_ = y;
	int sleep_time = round(speed * 1000); // Set time in Milisecond
	int line_count = 0;

	gotoxy(x, y);
	for (int i = 0; i < sizeof(content_); i++)
	{
#ifdef WIN32
		Sleep(sleep_time);
#else
    usleep(sleep_time);
#endif

		if (content_[i] == '\n') // Split each row in new line (x, y + line)
		{
			++line_count;
			gotoxy(x, y + line_count);
		}
		else
			std::cout << content_[i]; // Print each line
	}
}
void Animation::extendToDown(int x, int y, float speed)
{
	// Extend each row of content
	x_ = x;
	y_ = y;
	int sleep_time = round(speed * 1000); // Set time in Milisecond
	int line_count = 0;

	gotoxy(x, y);
	for (int i = 0; i < sizeof(content_); i++)
	{
		if (content_[i] == '\n') // Split each row in new line (x, y + line)
		{
#ifdef WIN32
	  	Sleep(sleep_time);
#else
      usleep(sleep_time);
#endif

			++line_count;
			gotoxy(x, y + line_count);
		}
		else
			std::cout << content_[i]; // Print each line
	}
}
void Animation::appear(int x, int y)
{
	// Print content to place (x, y)
	x_ = x;
	y_ = y;

	printContent(x, y);
}
void Animation::hide()
{
	// Remove content from current place (x, y)
	clearPrevContent(x_, y_);
}
