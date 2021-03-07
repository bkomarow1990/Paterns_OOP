#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Product {
public:
	Product(const string& name, const size_t& price)
	:price(price){
		setName(name);
	}
	void setName(const string& name) {
		if (name.empty())
		{
			return;
		}
		this->name = name;
	}
	const size_t& getPrice() const{
		return price;
	}
	virtual void print() const {
		cout << "============================" << endl;
		cout << "Name : " << name << endl;
		cout << "Price : " << price << endl;
		cout << "============================" << endl;
	}
protected:
	size_t price;
	string name;
	
};
class Bread : public Product{
public:
	Bread()
	:Product("Bread", 12){

	}
};
class Oil : public Product {
public:
	Oil()
		:Product("Oil", 24) {

	}
};
class Butter : public Product {
public:
	Butter()
		:Product("Butter", 33) {

	}
};
__interface IShoppingCart {
	void addProductInBasket(Product* product);
	void deleteProductFromBasket(Product* product);
	const size_t& getSumm();
	void payBasket();
};
__interface IPay {
	void pay();
};
class CreditCard : public IPay{
private:
	string name;
	int number;
	int cvv;
	int date;
public:
	CreditCard(const string& name, const int& number, const int& cvv, const int& date)
	:name(name),number(number),cvv(cvv),date(date){

	}
	void pay() override {
		cout << " You paid basket using card" << endl;
	}
};
class PayPal : public IPay {
private:
	string password;
	string email;

public:
	PayPal(const string& email, const string& password) :email(email), password(password) {}
	void pay() override {
		cout << " You paid basket using PayPal" << endl;
	}
};
class ShoppingCart : public IShoppingCart{
public:
	void addProductInBasket(Product * product) override {
		basket.push_back(product);
	}
	void deleteProductFromBasket(Product* product) override {
		auto it = find(basket.begin(), basket.end(), product);
		if (it==basket.end())
		{
			cout << "Can`t find your product" << endl;
			return;
		}
		basket.erase(it);
	}
	const size_t& getSumm() override {
		size_t summ = 0;
		for (auto& i : basket)
		{
			summ += i->getPrice();
		}
		return summ;
	}
	void payBasket() {
		if (pay_method == nullptr)
		{
			cout << "Enetr pay method" << endl;
			return;
		}
		pay_method->pay();
		basket.clear();
	}
	void setPayMethod(IPay* method) {
		if (method!= nullptr)
		{
			this->pay_method = method;
		}
	}
	void print()const {
		if (basket.empty())
		{
			cout << "Basket is empty! :(" << endl;
			return;
		}
		for (auto& i : basket)
		{
			i->print();
		}
	}
	ShoppingCart() = default;
	~ShoppingCart()
	{
		for (auto& i : basket)
		{
			if (i!= nullptr)
			{
				delete i;
				i = nullptr;
			}
		}
		if (pay_method != nullptr)
		{
			delete pay_method;
			pay_method = nullptr;
		}
	}
private:
	vector<Product*> basket;
	IPay * pay_method;
};

int main() {
	ShoppingCart scart;
	scart.addProductInBasket(new Butter());
	scart.addProductInBasket(new Oil());
	cout<<"Summ: "<< scart.getSumm() <<endl;
	scart.payBasket();
	cout << "Before: " << endl;
	scart.print();
	cout << "After: " << endl;
	scart.setPayMethod(new PayPal("privetmedved@gmail.com","qwerty12345"));
	scart.payBasket();
	scart.print();
	return 0;
}