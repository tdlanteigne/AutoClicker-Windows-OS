#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>




void MenuProgram()
{
std::cout<< std::setw(85) << "Hi! Welcome to the AutoClicker program!\n"; 
std::cout << std::setw(110) << "Press the enter key to enable the AutoClicker and the backspace key to disable the AutoClicker.\n";
//the \n line allows the message to be displayed on the next line

}

void AutoClicker()
{
	bool clicker = false; //sets the clicker to false

	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN)) //if the enter key is pressed, clicker = true
		{
		clicker= true;
		}
		else if (GetAsyncKeyState(VK_BACK)) //if the backspace key is pressed, clicker = false
		{
		clicker= false;
		system("CLS"); //clears the screen
		return;
		
		}
		if (clicker==true) //if clicker = true the mouse will be pressesd up and down repeatedly
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(5);	//this function is used to adjust the speed of the autoclicker
		}
	}
}




int main()
{
    std::cout << std::setw(80) << "Please press the space key to begin!\r"; //Modifies the text to align it to the center of the page
	//displays a message and erases it before next message is displayed
	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE)) //if the space key is hit
		{
			::MessageBox(NULL, ("OK! Let's get to clicking!"), ("AutoClicker"), MB_OK);
			//Displays message box that has to be clicked to continue the program
			system("CLS"); //clears the screen 
			MenuProgram(); 
			AutoClicker();
			std::string choice;
			bool result = false;

			while (true)
			{
				do
				{
					std::cout << std::setw(90) << "Do you want to quit the program? Yes or no only in lower case please.\n"; 
					std::cin >> choice;
				} while (choice.compare("yes") && choice.compare("no"));
				
					//if either call returns a zero in boolean/becomes true get out of the loop
					if (choice.compare("yes") == 0)
					{
						result = true;
						return 0; //exits the program
					}
					else (choice.compare("no") == 0);
					{
						result = true;
						system("CLS"); //clears the screen
						main(); //goes back to main() to restart the program
					}
				
			}
		}
	}
}

