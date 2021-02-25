#pragma once
#include <iostream>
#include <vector>
using namespace std;
__interface Button {
	void render();
	void onClick();
};
class WindowsButton : public Button{
public:
	WindowsButton() = default;
	void render()override {
		cout << "Windows button rendered" << endl;
	}
	void onClick()override {
		cout << "Windows button clicked" << endl;
	}
};
class HTMLButton : public Button{
public:
	HTMLButton() = default;
	void render()override {
		cout << "HTML Button button rendered" << endl;
	}
	void onClick()override {
		cout << "HTML Button button clicked" << endl;
	}
};
class Dialog abstract {
public:
	Dialog() = default;
	void render() {
		for (auto& i : buttons)
		{
			i->render();
		}
	}
	virtual void createButton() = 0;

protected:
	vector<Button* >buttons;
};
class WindowsDialog : public Dialog {
public:
	WindowsDialog() :Dialog(){}
	void createButton() override {
		buttons.push_back(new WindowsButton());
	}
};
class WebDialog : public Dialog {
public:
	WebDialog() :Dialog(){}
	void createButton() override {
		buttons.push_back(new HTMLButton());
	}
};