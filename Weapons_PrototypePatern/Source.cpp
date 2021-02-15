#include <iostream>
#include <map>
using namespace std;
class Weapon abstract{
public:
	Weapon(const size_t& bullets=0,const size_t & spentBullets=1)
		:bullets(bullets), spentBullets(spentBullets)
	{}
	void shoot() {
		if (isPossible())
		{
			cout << "Shoot !!! Remains: " <<( bullets -= spentBullets )<< endl;
			return;
		}
		cout << "Haven`t ammo" << endl;
	}
	const bool isPossible() {
		return bullets >= spentBullets;
	}
	virtual Weapon* clone() = 0;
private:
	size_t bullets;
	size_t spentBullets;
};
class Pistol : public Weapon {
public:
	Pistol(const size_t& bullets = 0, const size_t& spentBullets = 1)
		:Weapon(bullets, spentBullets)
	{

	}
	Weapon* clone() override {
		return new Pistol(*this);
	}
};
class MiniGun : public Weapon {
public:
	MiniGun(const size_t& bullets = 0, const size_t& spentBullets = 3)
		:Weapon(bullets, spentBullets)
	{

	}
	Weapon* clone() override {
		return new MiniGun(*this);
	}
};
class WeaponStock {
	map<size_t, Weapon*> weapons;
public:
	void addWeapon(const size_t& id, Weapon* weapon) {
		weapons.insert({id,weapon});
	}
	Weapon* getWeapon(const size_t& id) {
		if (weapons.find(id) != weapons.end())
		{
			return weapons[id]->clone();
		}
		else {
			throw exception("Bad id");
		}
	}
};
int main() {
	Weapon* pistol = new Pistol(2,2);
	pistol->clone();
	//cout << "Adress" << pistol << " " << clone << endl;
	return 0;
}