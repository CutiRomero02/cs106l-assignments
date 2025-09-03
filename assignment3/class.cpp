#include "class.h"

MyItem::MyItem() {
    _size = 0;
    _name = "default";
}

MyItem::MyItem(int s, const std::string& n) {
    _size = s;
    _name = n;
}

MyItem::~MyItem() {
    
}

int MyItem::getData() const {
    return _size;
}

void MyItem::setData(int s) {
    _size = s;
}

void MyItem::modifyName(std::string& n) {
    n += "_mod";
}

void MyItem::modifyName() {
    int len = _size;
    for (int i = 0; i < len; i++) {
        modifyName(_name);
    }
}