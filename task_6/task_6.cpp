#include <iostream>
#include <locale>
using namespace std;

class Animal {
private:
	string _name{};
	string _type{};
	int _height{ -1 };
	double _weight{ -1.0 };

	int* _completed_in_day{};
	int _size{};

public:

	Animal() : _name(), _type(), _height(-1), _weight(-1.0), _completed_in_day(nullptr), _size(0) {};

	Animal(string name, string type, int height) : _name(name), _type(type), _height(height) {};

	Animal(string name, string type, int height, double weight) : Animal(name, type, height)
	{
		this->_weight = weight;
	};

	Animal(const int* completed_in_day) {
		if (!completed_in_day)
			return;
		_size = _msize((void*)completed_in_day) / sizeof(int);
		this->_completed_in_day = new int[_size];
		for (int i = 0; i < _size; ++i)
			this->_completed_in_day[i] = completed_in_day[i];
	}

	Animal(const Animal& animal)
		: _name(animal._name), _type(animal._type), _height(animal._height), _weight(animal._weight)
	{
		cout << endl;
	};

	~Animal() {
		delete[] _completed_in_day;
		_size = 0;
		cout << "деструктор вызван" << endl;
	};

public:
	void print_data_obj();

	string get_name();
	string get_type();
	int get_height() const;
	double get_weight() const;

	void set_name(string name);
	void set_type(string type);
	void set_height(int height);
	void set_weight(double weight);

	void print_array();

	Animal get_animal();
};

string Animal::get_name() { return this->_name; }
string Animal::get_type() { return this->_type; }
int Animal::get_height() const { return this->_height; }
double Animal::get_weight() const { return this->_weight; }

void Animal::set_name(string name) { this->_name = name; }
void Animal::set_type(string type) { this->_type = type; }
void Animal::set_height(int height) { this->_height = height; }
void Animal::set_weight(double weight) { this->_weight = weight; }

void Animal::print_data_obj() {
	cout << " Имя: " << this->_name
		<< " Рост: " << this->_height
		<< " Вес: " << this->_weight
		<< " Вид: " << this->_type << endl;
}

void Animal::print_array() {
	if (!_completed_in_day)
		return;
	for (int i = 0; i < _size; ++i)
		cout << _completed_in_day[i] << " ";
	cout << endl;
}

void print_animal(Animal animal) {
	cout << " Имя: " << animal.get_name()
		<< " Рост: " << animal.get_height()
		<< " Вес: " << animal.get_weight()
		<< " Вид: " << animal.get_type()
		<< endl;
}

Animal Animal::get_animal() { return *this; }

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "объявление и инициализация объекта" << endl;

	Animal animal_1,
		animal_2("Барсик", "кот", 35, 2.8),
		animal_3("Барсик", "кот", 35, animal_2.get_weight());

	animal_1.print_data_obj();
	animal_2.print_data_obj();
	animal_3.print_data_obj();

	int* pArray = new int[5];
	for (int i = 0; i < 5; ++i)
		pArray[i] = i;
	Animal amount_meat(pArray);
	amount_meat.print_array();

	delete[] pArray;

}


