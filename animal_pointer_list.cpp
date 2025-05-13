#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat Meow" << endl;
    }
};

class Crow : public Animal {
  public:
    void speak(){
        cout << "Crow crowww crowww" << endl;
    }
};

class Koal : public Animal {
  public:
    void speak(){
        cout << "Koal koo koo" << endl;
    }
};
int main() {
    // Create a pointer list using an array of pointers
    Animal* animalList[5];

    animalList[0] = new Animal();
    animalList[1] = new Dog();
    animalList[2] = new Cat();
    animalList[3] = new Crow();
    animalList[4] = new Koal();

    // Loop through and call speak()
    for (int i = 0; i < 5; ++i) {
        animalList[i]->speak();  // Polymorphic call
    }

    // Clean up
    for (int i = 0; i < 5; ++i) {
        delete animalList[i];
    }

    return 0;
}