#include <iostream>
#include <chrono>
#include <ctime>   
#include "File.h"
#include <string>
using namespace std;
int main() {
	Message* currentMsg = new Message(" Msg1 "); // ������ �������� �� �����������
	File & file = File::getInstance(); // ���������� Singleton class - File
	file.setPath("log.txt"); // ������ ���� �� log-�����
	file.messageToFile(*currentMsg); // �������� ����������� � log
	currentMsg = new Message("Msg 2");
	file.messageToFile(*currentMsg);
	return 0;
}