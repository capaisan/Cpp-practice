#include <iostream>
using namespace std; //using to simplify the code

//implementing abstract classes

class Person{
protected:
  string name;
public:
  Person(string f): name(f){}
  virtual void output() const = 0;
};

class Student : public Person{
private:
  int id;
public:
  Student(string n): Person(n), id(0){}
  Student(string n, int a): Person(n), id(a){}
  void output() const override{ cout << name << ", ID #"  << id << endl; }
};

class Instructor : public Person{
private:
  string department;
public:
  Instructor(string n): Person(n), department("none"){}
  Instructor(string n, string d): Person(n), department(d){}
  void output() const override{ cout << name << " is in the department " << department << endl; }
};

void print(const Person &p){  p.output(); }

int main(){

  Person *p;

  p = new Student("Jeff", 16533);
  // print(*p);
  p->output();

  p = new Instructor("John", "math");
  // print(*p);
  p->output();

  return 0;
}
