#include <iostream>
#include <locale>
using namespace std;

class String
{
private:
	string _str;
	int _size;

public:
	String() : _str(), _size(0) {};

	String(string str) { _str = str; };

	String(string str, int size) : String(str) {
		_size = size;
	};

	String(const String& string) {
		_str = string._str;
		_size = string._size;
	}

	~String() {
		_str = "";
		_size = 0;
	};

public:
	string get_value();
	int get_size() const;

	void set_value(string str);

	void put(char symbol);

	void claer();

	void print_data_obj();

	String operator+(const String& obj) const;

	String operator+(string str) const;

	String operator*(int multiStr) const;

	friend ostream& operator<<(ostream& out, const String& obj);

};

ostream& operator<<(ostream& out, const String& obj) {
	out << obj._str;
	return out;
}

string String::get_value() { return this->_str; }

int String::get_size() const { return this->_str.length(); }

void String::set_value(string str) { _str = str; }

void String::put(char symbol) { _str = _str + symbol; }

void String::claer()
{
	_str = "";
	_size = 0;
}

void String::print_data_obj() {
	cout << "Значение: " << this->get_value() << " размер: " << this->get_size() << endl;
}

String String::operator+(string str) const {
	return String(_str + str);
}

String String::operator+(const String& obj) const {
	return String(_str + obj._str);
}

String String::operator*(int multiStr) const {
	string res;
	for (int i = 0; i < multiStr; i++) {
		res += _str;
	}
	return String(res);
}

int main()
{
	setlocale(LC_ALL, "Rus");

	String s("Привет, "), w("мир!");

	cout << s + w << endl;

	cout << s + "мир!" << endl;

	cout << s * 2;

}


