#include <iostream>
#include <memory>
using namespace std;
using ullong = unsigned long long;
class Budget {

private:
	Budget(const ullong& money = 0) 
		:money(money)
	{	}
	static Budget* instance;
public:
	void addMoney(const ullong& money) {
		this->money += money;
	}
	void spendMoney(const ullong& money) {
		this->money -= money;
	}
	static Budget* getInstance(const ullong& money) {
		if (instance==nullptr)
		{
			instance = new Budget(money);
		}
		return instance;
	}
	const ullong& getMoney()const { return money; }
private:
	ullong money;
};
Budget* Budget::instance = nullptr;
// pattern single ^


// pattern delivery 
__interface ITransport {
	void deliver(const size_t& distance);
};
class Ship : public ITransport {

public:
	Ship() = default;
	void deliver(const size_t& distance){
		cout << "Deliver by ship on distance " << distance << endl;
	}
};
class Truck : public ITransport {

public:
	Truck() = default;
	void deliver(const size_t& distance) {
		cout << "Deliver by truck on distance " << distance << endl;
	}
};
enum class Logistic{ROAD,SEA};
class Factory abstract {
public:
	static ITransport* createTransport(Logistic logistic) {
		if (logistic == Logistic::ROAD)
		{
			return new Truck();
		}
		else if (logistic == Logistic::SEA)
		{
			return new Ship();
		}
		throw std::exception("Bad type of logistics");
	}
};
//class SeaFactory : public Factory {
//public:
//	ITransport* createTransport() override{
//		return new Ship();
//	}
//};
//class RoadFactory : public Factory {
//public:
//	ITransport* createTransport() override {
//		return new Truck();
//	}
//};
// end of patten deliver
int main() {
	//Budget *b = Budget::getInstance(500000000000000);

	/*ITransport* t = new Truck();
	t->deliver(3000);*/
	ITransport* t = Factory::createTransport(Logistic::SEA);
	t->deliver(2222);
	t->deliver(2004);
	return 0;
}