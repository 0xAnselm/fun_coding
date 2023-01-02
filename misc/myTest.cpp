#include <string>
#include <stdio.h>

struct Person
{
    std::string name_;
    int age_;
    std::string ort_;
    void print();
    std::string greeting();
};

void Person::print() {
    printf("%s from %s\n", name_.c_str() , ort_.data());
}

std::string Person::greeting() {
    return "Hi " + name_ + " from " + ort_ + "\n";
}

std::string greeting(Person* const p) {
    p->name_ = "Ludwig";
    return "Hi " + p->name_ + " from " + p->ort_ + "\n";
}

int main(void) {
    Person p1 = {"Maxl", 3, "Munich"};
    p1.print();
    printf("%s", p1.greeting().c_str());
    printf("%s", greeting(&p1).c_str());
}
