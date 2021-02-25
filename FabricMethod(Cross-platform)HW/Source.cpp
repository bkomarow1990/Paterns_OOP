#include <iostream>
#include "Classes.h"
using namespace std;
int main() {
	WindowsButton winb1;
	HTMLButton webb1;
	WindowsDialog wdialog;
	wdialog.createButton();
	wdialog.createButton();
	wdialog.createButton();
	wdialog.render();

	return 0;
}