#include<iostream>
#include<conio.h>
#include"conanim.h" // coanim header for use animations

using namespace std;

int main()
{
	while (true)
	{
		system("cls");
		int operation;

		cout << "CONANIM - Version 1.0.0\n\n"
			 << "List of Animations:\n"
			 << "1- Translate X\n"
			 << "2- Translate Y\n"
			 << "3- Wink\n"
			 << "4- Colorize\n"
			 << "5- Extend\n"
			 << "6- Extend to down\n"
			 << "7- Appear\n"
			 << "8- Hide\n"
			 << "_________________________________\n\n";

		cout << "Enter a number from list: ";
		cin >> operation;

		if (operation == 1)
		{
			system("cls");

			// Move a car to right and left
			Animation anim = Animation("    ______\n"
						   " __/      \\___\n"
						   "|             |\n"
						   "|_( )_____( )_|\n");
			anim.translateX(2, 2, 30, 0.1);
			anim.translateX(30, 2, 2, 0.1);
			_getch();
		}
		else if (operation == 2)
		{
			system("cls");

			// Move a rabbit to down and up
			Animation anim = Animation("(\\_/)\n"
						   "( .,.)\n"
						   "(~)_(~)\n");
			anim.translateY(20, 2, 15, 0.2);
			anim.translateY(20, 15, 2, 0.2);
			_getch();
		}
		else if (operation == 3)
		{
			system("cls");

			// Wink a cat
			Animation anim = Animation("   _.---.._             _.---...__\n"
						   ".-'   /\\   \\          .'  /\\     /\n"
						   "`.   (  )   \\        /   (  )   /\n"
						   "  `.  \\/   .'\\      /`.   \\/  .'\n"
						   "    ``---''   )    (   ``---''\n"
						   "            .';.--.;`.\n"
						   "          .' /_...._\\ `.\n"
						   "        .'   `.a  a.'   `.\n"
						   "       (        \\/        )\n"
						   "        `.___..-'`-..___.'\n"
						   "           \\          /\n"
						   "            `-.____.-' \n");
			anim.wink(4, 4, 6, 0.5);
			_getch();
		}
		else if (operation == 4)
		{
			system("cls");

			// Colorize a body builder
			Animation anim = Animation("_______oBBBBB8o______oBBBBBBB\n"
						   "_____o8BBBBBBBBBBB__BBBBBBBBB8________o88o,\n"
						   "___o8BBBBBB**8BBBB__BBBBBBBBBB_____oBBBBBBBo,\n"
						   "__oBBBBBBB*___***___BBBBBBBBBB_____BBBBBBBBBBo,\n"
						   "_8BBBBBBBBBBooooo___*BBBBBBB8______*BB*_8BBBBBBo,\n"
						   "_8BBBBBBBBBBBBBBBB8ooBBBBBBB8___________8BBBBBBB8,\n"
						   "__*BBBBBBBBBBBBBBBBBBBBBBBBBB8_o88BB88BBBBBBBBBBBB,\n"
						   "____*BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB8,\n"
						   "______**8BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB*,\n"
						   "___________*BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB8*,\n"
						   "____________*BBBBBBBBBBBBBBBBBBBBBBBB8888**,\n"
						   "_____________BBBBBBBBBBBBBBBBBBBBBBB*,\n"
						   "_____________*BBBBBBBBBBBBBBBBBBBBB*,\n"
						   "______________*BBBBBBBBBBBBBBBBBB8,\n"
						   "_______________*BBBBBBBBBBBBBBBB*,\n"
						   "________________8BBBBBBBBBBBBBBB8,\n"
						   "_________________8BBBBBBBBBBBBBBBo,\n"
						   "__________________BBBBBBBBBBBBBBB8,\n");
			anim.colorize(4, 4, 20, 0.5);
			_getch();
		}
		else if (operation == 5)
		{
			system("cls");

			// Extend some texts
			Animation anim = Animation("conanim.h for C++\n"
									   "Version 1.0.0\n\n"
									   "By conanim, you can use animation in console!");
			anim.extend(5, 5, 0.2);
			_getch();
		}
		else if (operation == 6)
		{
			system("cls");

			// Extend to down Aladdin face
			Animation anim = Animation("     ::::` ::::::::`` :::::::`   .ue@$$ `:::::::::::::::::::::\n"
						   "     ::` .:::::::``z, :::::`.e$$$$$$$$$$.`::::::::::::::::::::\n"
						   "    :` :::::::``,e$$$r`::: $$$$??'     `?b_ `::::::::::::::::::\n"
						   "   ' :::::::` ,?'   `?b,_` R$'     .,,.   `'iu ````:::::::::::::\n"
						   "    ::::::`   <  .,.   `?e. $$eeee$$$F???$ee,3$c   ..````::::::::.\n"
						   "   ::::::  ::  R$$$$$$$$e4$ $$$$$$$'e     3$$$$$.:.  ``:::::::::``:.\n"
						   "  `:::::: :::::`$F.   '?FJ$d$$$$$$'$L~. . .$$$$$L`!!~eec``::::::::.\n"
						   "  `::::::.```::.''$'     $$$$$$$$$.$$bKUeiz$$$$$$'!~ $$3$  `::::::::\n"
						   "     ``````` ..: 3`beeed $$$$$$$$$$e$$Ned$$$$$$$$'u@z$5$ ::: `:::::::\n"
						   "             ::: ^$NeeeP $$$$$$$$$$$$$$$$$$$$$$$$'$NNeP ::::::`::::::\n"
						   "            .:::: $$$$$F $$$$$$$?$$$$$$$$$$$$$$$$ $$F .:::::::::::::\n"
						   "           : .::: ?$$$$$ $$$$$$$?c$$$$$$$$$$$$$$F,e :::::::::::::``\n"
						   "             ::::,`$$$$$$,)?$$X$$$$$$$$$$$?$$$$$ $$ :::::::::::``\n"
						   "             ::':: '$$$$$$$$$$$$$$$$P?' .d$$$$$F,$$ :::::::::`\n"
						   "             `  :::.'$$$EC''???'?Cz=d'ud$$$$$$'.$$$ :::::`:`\n"
						   "                `:::.`?$$$bu. 4$$$??Le$$$$$$P'.$$$$ ::```\n"
						   "                  `::: `?$$$P$beee$$$$$$$$P'.d$$$$$\n"
						   "                          u`?$$$$$$$$$$F z$$$$$$$$Pu`$$$c.\n"
						   "                         c^$bu?R$$$$F'ue$$$$$$$$$$ $ $$$$$$bc.\n"
						   "                       e$$ $$$e,`'',e$$$$$$$$$$$$$$$ $$$$$$$$$'bc.\n"
						   "                    .e$$$$ '$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$$$$'d$$$$$be.\n"
						   "                ..e$$$$$$EJ,?$$$$$$$$$$$$$$$$$$$$$$$'$$$$$$$'d$$$$$$$$$$be\n");
			anim.extendToDown(0, 0, 0.2);
			_getch();
		}
		else if (operation == 7)
		{
			system("cls");

			// Appear a text
			Animation anim = Animation("I'm Here!");
			anim.appear(30, 15);
			_getch();
		}
		else if (operation == 8)
		{
			system("cls");

			// Hide a text
			Animation anim = Animation("Hello! I want to hide!");
			anim.extend(10, 5, 0.2);

			Sleep(1000);

			anim.hide();
			_getch();
		}
	}
	return 0;
}
