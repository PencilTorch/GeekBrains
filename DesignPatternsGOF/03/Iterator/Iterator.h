#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <string>

class Simple {
public:
    Simple() {}
    Simple(std::string name, std::string town, int age) :
        _name(name), _town(town), _age(age) {}

    void printData() const {
        std::cout << _name << " " << _town << " " << _age << std::endl;
    }
protected:
    std::string _name;
    std::string _town;
    int _age;
};


class IIterator {
public:
    virtual ~IIterator() {}
    virtual bool hasNext() const = 0;
    virtual Simple next() = 0;
    virtual bool hasPrev() const = 0;
    virtual Simple prev() = 0;
};

class VectorIterator : public IIterator {
public:
    VectorIterator(const std::vector<Simple>& data) : _data(data), _pos(0) {}
    bool hasNext() const override {
        return _pos < _data.size();
    }
    Simple next() override {
        Simple temp;
        temp = _data[_pos++];
        return temp;
    }
    bool hasPrev() const override {
        return _pos > 0;
    }
    Simple prev() override {
        Simple temp;
        temp = _data[--_pos];
        return temp;
    }
private:
    std::vector<Simple> _data;
    size_t _pos;
};

class ListIterator : public IIterator {
public:
    ListIterator(const std::list<Simple>& data) : _data(data) {}
    bool hasNext() const override {
        return it != _data.end();
    }
    Simple next() override {
        Simple temp;
        temp = *it++;
        return temp;
    }
    bool hasPrev() const override {
        return it != _data.begin();
    }
    Simple prev() override {
        Simple temp;
        temp = *(--it);
        return temp;
    }
private:
    std::list<Simple> _data;
    std::list<Simple>::iterator it = _data.begin();
};

class DequeIterator : public IIterator {
public:
    DequeIterator(const std::deque<Simple>& data) : _data(data), _pos(0) {}
    bool hasNext() const override {
        return _pos < _data.size();
    }
    Simple next() override {
        Simple temp;
        temp = _data[_pos++];
        return temp;
    }
    bool hasPrev() const override {
        return _pos > 0;
    }
    Simple prev() override {
        Simple temp;
        temp = _data[--_pos];
        return temp;
    }
private:
    std::deque<Simple> _data;
    size_t _pos;
};

class ArrayIterator : public IIterator {
public:
    ArrayIterator(const std::array<Simple, 10>& data) : _data(data), _pos(0) {}
    bool hasNext() const override {
        return _pos < _data.size();
    }
    Simple next() override {
        Simple temp;
        temp = _data[_pos++];
        return temp;
    }
    bool hasPrev() const override {
        return _pos > 0;
    }
    Simple prev() override {
        Simple temp;
        temp = _data[--_pos];
        return temp;
    }
private:
    std::array<Simple, 10> _data;
    size_t _pos;
};


class VectorCollection : public Simple {
public:
    VectorCollection() {}
    void addSimple(const Simple& data) {
        _data.push_back(data);
    }
    IIterator* createIterator() const {
        return new VectorIterator(_data);
    }
private:
    std::vector<Simple> _data;
};

class ListCollection : public Simple {
public:
    ListCollection() {}
    void addSimple(const Simple& data) {
        _data.push_back(data);
    }
    IIterator* createIterator() const {
        return new ListIterator(_data);
    }
private:
    std::list<Simple> _data;
};

class DequeCollection : public Simple {
public:
    DequeCollection() {}
    void addSimple(const Simple& data) {
        _data.push_back(data);
    }
    IIterator* createIterator() const {
        return new DequeIterator(_data);
    }
private:
    std::deque<Simple> _data;
};

class ArrayCollection : public Simple {
public:
    ArrayCollection() {}
    void addSimple(const Simple& data) {
        if (_pos < _data.size()) {
            _data[_pos++] = data;
        }
    }
    IIterator* createIterator() const {
        return new ArrayIterator(_data);
    }
private:
    std::array<Simple, 10> _data;
    size_t _pos = 0;
};
