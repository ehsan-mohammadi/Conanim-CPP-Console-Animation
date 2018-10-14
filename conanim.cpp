#include "conanim.h"

void Animation::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Animation::printContent(int x, int y)
{
	int line_count = 0;

	gotoxy(x, y);
	for (int i = 0; i < strlen(content_); i++)
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
	for (int i = 0; i < strlen(content_); i++)
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

Animation::Animation(char* content)
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
		Sleep(sleep_time);
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
		Sleep(sleep_time);
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
		Sleep(sleep_time);

		printContent(x, y); // Print content in (x, y) place
		Sleep(sleep_time);
	}
}
void Animation::colorize(int x, int y, int count, float speed)
{
	// Colorize content
	x_ = x;
	y_ = y;
	int sleep_time = round(speed * 1000); // Set time in Milisecond
	int color_number = 0;
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);

	printContent(x, y); // Print content at first time

	for (int i = 0; i < count; i++)
	{
		Sleep(sleep_time);
		SetConsoleTextAttribute(outcon, color_number);
		printContent(x, y); // Print content in (x, y) place

		color_number++;
		if (color_number > 15) // Color range between [0 ... F]
			color_number = 0;
	}
	
	SetConsoleTextAttribute(outcon, 7); // Change color to default white
}
void Animation::extend(int x, int y, float speed)
{
	// Extend each character of content
	x_ = x;
	y_ = y;
	int sleep_time = round(speed * 1000); // Set time in Milisecond
	int line_count = 0;

	gotoxy(x, y);
	for (int i = 0; i < strlen(content_); i++)
	{
		Sleep(sleep_time);

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
	for (int i = 0; i < strlen(content_); i++)
	{
		if (content_[i] == '\n') // Split each row in new line (x, y + line)
		{
			Sleep(sleep_time);

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