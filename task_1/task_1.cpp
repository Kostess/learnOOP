﻿#include <iostream>

using namespace std;

class Integer {
private:
    int _num{};

public:
    Integer() {};

    Integer(int num) : _num(num) {};

public:
    Integer& operator=(int num);

    Integer& operator=(const Integer& obj);

    Integer operator+(const Integer& obj) const;

    Integer operator+(int num) const;

    Integer operator/(const Integer& obj) const;

    Integer operator/(int num) const;

    Integer operator%(const Integer& obj) const;

    Integer operator%(int num) const;

    Integer operator+=(const Integer& obj);

    Integer operator+=(int num);

    bool operator==(const Integer& obj) const;

    bool operator==(int num) const;

    friend ostream& operator<<(ostream& out, const Integer& obj);
};

ostream& operator<<(ostream& out, const Integer& obj) {
    out << "Integer(" << obj._num << ")";
    return out;
}

Integer& Integer::operator=(int num) {
    cout << "перегруженный оператор = для int" << endl;
    _num = num;
    return *this;
}

Integer& Integer::operator=(const Integer& obj) {
    cout << "перегруженный оператор = для Integer" << endl;
    if (this == &obj) return *this;
    _num = obj._num;
    return *this;
}

Integer Integer::operator+(int num) const {
    return Integer(_num + num);
}

Integer Integer::operator+(const Integer& obj) const {
    cout << "перегруженный оператор + для Integer" << endl;
    return Integer(_num + obj._num);
}

Integer Integer::operator/(int num) const {
    return Integer(_num / num);
}

Integer Integer::operator/(const Integer& obj) const {
    cout << "перегруженный оператор / для Integer" << endl;
    return Integer(_num / obj._num);
}

Integer Integer::operator%(int num) const {
    return Integer(_num % num);
}

Integer Integer::operator%(const Integer& obj) const {
    cout << "перегруженный оператор % для Integer" << endl;
    return Integer(_num % obj._num);
}

Integer Integer::operator+=(int num) {
    _num += num;
    return *this;
}

Integer Integer::operator+=(const Integer& obj) {
    cout << "перегруженный оператор += для Integer" << endl;
    _num += obj._num;
    return *this;
}

bool Integer::operator==(int num) const {
    return _num == num;
}

bool Integer::operator==(const Integer& obj) const {
    cout << "перегруженный оператор == для Integer" << endl;
    return _num == obj._num;
}

int main() {
    setlocale(LC_ALL, "ru");
    Integer num_1, num_2, result;
    num_1 = 10;
    cout << "Значение переменной num_1 с перегрузкой "
        << "оператора = для int: " << num_1 << endl;

    num_2 = num_1;
    cout << "Значение переменной num_2 с перегрузкой "
        << "оператора = для Integer: " << num_2 << endl;

    num_2 = num_1 + 35;
    cout << "Значение переменной num_2 с перегрузкой "
        << "оператора + для int: " << num_2 << endl;

    num_2 = num_2 + num_1;
    cout << "Значение переменной num_2 с перегрузкой "
        << "оператора + для Integer: " << num_2 << endl;

    num_2 += 10;
    cout << "Значение переменной num_2 с перегрузкой "
        << "оператора += для int: " << num_2 << endl;

    num_2 += num_1;
    cout << "Значение переменной num_2 с перегрузкой "
        << "оператора += для Integer: " << num_2 << endl;

    bool flag = num_1 == 10;
    cout << "Значение переменной flag с перегрузкой "
        << "оператора == для int: " << flag << endl;

    flag = num_1 == num_2;
    cout << "Значение переменной flag с перегрузкой "
        << "оператора == для Integer: " << flag << endl;


    result = num_1 / 2;
    cout << "Целочисленное деление 10 на 2 равно " << result << endl;

    result = num_1 % 2;
    cout << "Остаток от деления 10 на 2 равно " << result << endl;

}