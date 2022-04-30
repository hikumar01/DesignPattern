#include <iostream>

using namespace std;

class Base {
    Base* next; // 1. "next" pointer in the base class

public:
    Base() {
        next = 0;
    }

    void setNext(Base* n) {
        next = n;
    }

    void add(Base* n) {
        if (next) {
            next->add(n);
        } else {
            next = n;
        }
    }

    // 2. The "chain" method in the base class always delegates to the next obj
    virtual void handle(int i) {
        next->handle(i);
    }
};

class Handler1 : public Base {
public:
    void handle(int i) override {
        cout << "H1 ";
        if (i % 3 > 0) {
            Base::handle(i);
        }
    }
};

class Handler2 : public Base {
public:
    void handle(int i) override {
        cout << "H2 ";
        if (i % 3 > 1) {
            Base::handle(i);
        }
    }
};

class Handler3 : public Base {
public:
    void handle(int i) override {
        cout << "H3 ";
        if (i % 3 > 2) {
            Base::handle(i);
        }
    }
};

int main() {
    Handler1 root;
    Handler2 two;
    Handler3 thr;

    root.add(&two);
    root.add(&thr);
    // thr.setNext(&root);

    for (int i = 0; i < 10; i++) {
        cout << i << ": ";
        root.handle(i);
        cout << endl;
    }
}
