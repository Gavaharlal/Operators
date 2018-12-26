//
// Created by Computer on 26.12.2018.
//

#include <sstream>
#include "MyIntegerSet.h"

using std::endl;

MyIntegerSet::MyIntegerSet(const MyIntegerSet &other) {
    data = other.data;
}

MyIntegerSet &MyIntegerSet::operator+=(const MyIntegerSet &other) {
    for (auto i : other.data) {
        data.emplace(i);
    }
    return *this;
}

MyIntegerSet &MyIntegerSet::operator-=(const MyIntegerSet &other) {
    if (*this == other) {
        data.clear();
    } else {
        for (auto i : other.data) {
            if (data.find(i) != data.end()) {
                data.erase(i);
            }
        }
    }
    return *this;

}

MyIntegerSet &MyIntegerSet::operator*=(const MyIntegerSet &other) {
    set<int> result;
    for (int a : data) {
        for (int b : other.data) {
            result.emplace(a * b);
        }
    }
    data = result;
    return *this;
}

MyIntegerSet &MyIntegerSet::operator/=(const MyIntegerSet &other) {
    set<int> result;
    for (int a : data) {
        for (int b : other.data) {
            if (b != 0) {
                result.emplace(a / b);
            }
        }
    }
    data = result;
    return *this;
}

MyIntegerSet &MyIntegerSet::operator%=(const MyIntegerSet &other) {
    set<int> result;
    for (int a : data) {
        for (int b : other.data) {
            result.emplace(a % b);
        }
    }
    data = result;
    return *this;
}

MyIntegerSet MyIntegerSet::operator+(const MyIntegerSet &other) {
    MyIntegerSet result = *this;
    result += other;
    return result;
}

MyIntegerSet MyIntegerSet::operator-(const MyIntegerSet &other) {
    MyIntegerSet result = *this;
    result -= other;
    return result;
}

MyIntegerSet MyIntegerSet::operator+() const {
    return *this;
}

MyIntegerSet MyIntegerSet::operator-() const {

    MyIntegerSet result;
    for (int a : data) {
        result += (-a);
    }

    return result;

}

MyIntegerSet &MyIntegerSet::operator+=(int arg) {
    data.emplace(arg);
    return *this;
}

MyIntegerSet MyIntegerSet::operator*(const MyIntegerSet &other) {
    MyIntegerSet result = *this;
    result *= other;
    return result;
}

MyIntegerSet MyIntegerSet::operator/(const MyIntegerSet &other) {
    MyIntegerSet result = *this;
    result /= other;
    return result;
}

MyIntegerSet MyIntegerSet::operator%(const MyIntegerSet &other) {
    MyIntegerSet result = *this;
    result %= other;
    return result;
}

MyIntegerSet &MyIntegerSet::operator|=(const MyIntegerSet &other) {
    set<int> result;
    for (int a : data) {
        for (int b : other.data) {
            result.emplace(a | b);
        }
    }
    data = result;
    return *this;
}

MyIntegerSet &MyIntegerSet::operator^=(const MyIntegerSet &other) {
    set<int> result;
    for (int a : data) {
        for (int b : other.data) {
            result.emplace(a ^ b);
        }
    }
    data = result;
    return *this;
}

MyIntegerSet &MyIntegerSet::operator&=(const MyIntegerSet &other) {
    set<int> result;
    for (int a : data) {
        for (int b : other.data) {
            result.emplace(a & b);
        }
    }
    data = result;
    return *this;
}

MyIntegerSet MyIntegerSet::operator|(const MyIntegerSet &other) {
    MyIntegerSet result = *this;
    result |= other;
    return result;
}

MyIntegerSet MyIntegerSet::operator^(const MyIntegerSet &other) {
    MyIntegerSet result = *this;
    result ^= other;
    return result;
}

MyIntegerSet MyIntegerSet::operator&(const MyIntegerSet &other) {
    MyIntegerSet result = *this;
    result &= other;
    return result;
}

std::ostream &operator<<(std::ostream &out, const MyIntegerSet &arg) {
    out << "Set contains " << arg.data.size() << " elements:\n";
    out << "    ";
    for (int a : arg.data) {
        out << a << " ";
    }
    out << endl;
    return out;
}

std::istream &operator>>(std::istream &in, MyIntegerSet &arg) {
    int a;
    in >> a;
    arg += a;
    return in;
}

MyIntegerSet &MyIntegerSet::operator++() {
    int result = 0;
    for (int i : data) {
        result+=i;
    }
    data.emplace(result);
    return *this;
}

const MyIntegerSet MyIntegerSet::operator++(int) {
    MyIntegerSet result = *this;
    ++(*this);
    return result;
}

MyIntegerSet &MyIntegerSet::operator--() {
    if (!data.empty()) {
        int biggest = *data.end();
        data.erase(biggest);
    }
    return *this;
}

const MyIntegerSet MyIntegerSet::operator--(int) {
    MyIntegerSet result = *this;
    --(*this);
    return result;
}

bool MyIntegerSet::operator<(const MyIntegerSet &rhs) const {
    return data < rhs.data;
}

bool MyIntegerSet::operator>(const MyIntegerSet &rhs) const {
    return rhs < *this;
}

bool MyIntegerSet::operator<=(const MyIntegerSet &rhs) const {
    return !(rhs < *this);
}

bool MyIntegerSet::operator>=(const MyIntegerSet &rhs) const {
    return !(*this < rhs);
}

bool MyIntegerSet::operator!=(const MyIntegerSet &rhs) const {
    return !(rhs == *this);
}

bool MyIntegerSet::operator==(const MyIntegerSet &arg) const {
    if (data.size() != arg.data.size()) return false;
    for (int a : data) {
        if (arg.data.find(a) == arg.data.end()) return false;
    }
    return true;
}

MyIntegerSet &MyIntegerSet::operator<<=(int arg) {
    set<int> result;
    for (int i : data) {
        result.emplace(i << arg);
    }
    data = result;
    return *this;
}

MyIntegerSet &MyIntegerSet::operator>>=(int arg) {
    set<int> result;
    for (int i : data) {
        result.emplace(i >> arg);
    }
    data = result;
    return *this;
}

MyIntegerSet MyIntegerSet::operator<<(int arg) {
    MyIntegerSet result = *this;
    result <<= arg;
    return result;
}

MyIntegerSet MyIntegerSet::operator>>(int arg) {
    MyIntegerSet result = *this;
    result >>= arg;
    return result;
}

int MyIntegerSet::operator[](size_t idx) const {
    if (idx >= data.size()) return -1;
    return 0;
}

MyIntegerSet &MyIntegerSet::operator-=(int arg) {
    if (data.find(arg) != data.end()) {
        data.erase(arg);
    }
    return *this;
}

MyIntegerSet::operator std::string() const {
    std::stringstream str;
    str << "Set contains " << data.size() << "elements:\n";
    str << "    ";
    for (int a : data) {
        str << a << " ";
    }
    str << endl;
    std::string result;
    str >> result;
    return result;
}

const MyIntegerSet MyIntegerSet::operator,(MyIntegerSet &v2) {
    MyIntegerSet res;
    res = *this;
    return res;
}

MyIntegerSet::MyIntegerSet(int arg) {
    data.emplace(arg);
}

MyIntegerSet::MyIntegerSet() = default;

MyIntegerSet &MyIntegerSet::operator=(const MyIntegerSet &other) = default;
