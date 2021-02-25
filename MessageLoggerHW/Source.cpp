#include <iostream>
#include <chrono>
#include <ctime>   
#include "File.h"
#include <string>
using namespace std;
int main() {
	Message* currentMsg = new Message(" Msg1 "); // Робимо вказівник на повідомлення
	File & file = File::getInstance(); // Ініціалізуємо Singleton class - File
	file.setPath("log.txt"); // Задаємо шлях до log-файлу
	file.messageToFile(*currentMsg); // Записуємо повідомлення в log
	currentMsg = new Message("Msg 2");
	file.messageToFile(*currentMsg);
	return 0;
}