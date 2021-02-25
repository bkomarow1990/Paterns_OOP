#pragma once
#include <iostream>
#include "Message.h"
#include <fstream>
using namespace std;
class File
{
private:
	string path;
	File(const string& path)
	{
		setPath(path);
	}
public:
	File(const File&) = delete; // заборона копіювати 
	File& operator = (const File&) = delete; // заборона присвоювати
	void messageToFile(const Message& msg) const;
	void setPath(const string& path);
	const string& getPath() const
	{
		return path;
	}
	static File& getInstance();

};


inline void File::messageToFile(const Message& msg) const
{
	ofstream fileOut(path , ios::app); 
	if (!fileOut)
	{
		cerr << "Error to open file" << endl;
		return;
	}
	cout << "Loged succefly" << endl;
		fileOut << msg.getId()<<". "<<msg.getText()<< endl;
		fileOut.close();
}

inline void File::setPath(const string& path)
{
	if (path.empty())
	{
		return;
	}
	this->path = path;
}

File& File::getInstance()
{

	static File s("path"); // одинак
	return s;

}
	/*Singleton& obj = Singleton::getInstance();
	cout << "data  = " << obj.getData() << endl;

	Singleton& obj2 = Singleton::getInstance();
	obj2.setData(200);
	cout << "data  = " << obj.getData() << endl;*/

