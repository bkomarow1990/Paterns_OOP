#pragma once
#include <iostream>
using namespace std;
__interface IMessage {
	void print()const;
};
class Message : public IMessage
{
public:
	Message(const string message="")
	{
		if (!message.empty())
		{
			text = message;
		}
		++id;
	}
	void print()const override {
		cout << id << " . " << text << endl;
	}
	const string& getText() const { return text; }
	const size_t& getId() const { return id; }
	
private:
	static size_t id;
	string text;
};

