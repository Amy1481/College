#include<iostream>
#include<string>
using namespace std;

class Teacher {
private:
  double salary;

public:
// Properties/Attributes
  string name;
  string dept;
  string sub;

  // Methods/Member Functions(as they become member of this class)
  void changeDept(string newDept){
      dept = newDept;
    }
    
    // ENCAPSULATION
    // class Account {
    // private:
    // double balance;
    // string password;
    // // Data hiding cause these are sensetive datas and not everyone can access these
    
    // public:
    //     string acctId;
    //     string username;
    // };

  // //   Setter sets private values 
  //   void setSalary(double s){
  //      salary = s;
  //   }
  
  // //   Getter gets private values
  //   double getSalary(){
  //     return salary;
  //   }
  
  //   Constructor (it is a function that does not have a return type)
  // Non-parameterized Constructor
  //   Teacher(){
    //     // cout << "Hi, I am a constructor!";
    //     dept = "Computer Science";
    //   }

    // Using constructor 
    // Creating an function so that we can cout all information of our teacher
     void getInfo(){
        cout << "Name : " << name << endl;
        cout << "Department : " << dept << endl;
        cout << "Subject : " << sub << endl;
        cout << "Salary : " << salary << endl;
    
     }

// Parameterized Constructor
// Parameters for each property is given like string s for string sub
// Teacher(string n,string d,string s,double sal){
//     // cout << "Hi, I am a constructor!";
//     // dept = "Computer Science";

//     // Initialization of obj using constructor
//     name = n;
//     dept = d;
//     sub = s;
//     salary = sal;
//   }

// this constructor
// Let we want our constructor variables(on the right side) not to be short but same as our obj properties(on the left side)
Teacher(string name,string dept,string sub,double salary){
    // But this is confusing for us  & for the compiler i.e which is the obj property thus to show obj properties we can use this pointer
    this->name = name;
    this->dept = dept;
    this->sub = sub;
    this->salary = salary;
  }

// Copy constructor
 Teacher(Teacher &orgObj) {  //Teacher obj is passed by reference meaning the object we are passing here is not the copy but the obj itself so all the changes inside this constructor is reflected inside original obj
    cout << "I am custom copy constructor";
    this->name = orgObj.name;
    this->dept = orgObj.dept;
    this->sub = orgObj.sub;
    this->salary = orgObj.salary;

 }

};

class Student {
public:
// Shallow copy
// Here we are going to make changes as properties are static meaning forms a stack
  string name;
//   double cgpa;
  double* cgpaPtr; //Now we have to allocate new memory for the pointer

//  Constructor 
  Student(string name,double cgpa){
    this->name = name;
    // this->cgpa = cgpa;
    cgpaPtr = new double; //Previously the pointer was pointing towards a blank memory now it can store a double type data so basically it means now dynamically the cgpaPtr is storing the memory address 
    *cgpaPtr = cgpa;
  }

// Copy constructor
  Student(Student &obj) { 
    cout << "I am custom copy constructor";
    this->name = obj.name;
    // this->cgpaPtr = obj.cgpaPtr;

    // Deep copy
    *cgpaPtr = *obj.cgpaPtr;
 }

// Destructor
 ~Student() {
   cout << "Hi, I am deleteing everything\n";
   delete cgpaPtr; //To delete dynamically allocated memory
//    Issues of destructor - Memory leaking
 }

  void getInfo() {
    cout << "name : " << name << endl;
    cout << "cgpa : " << cgpaPtr << endl;
  }
};

int main(){
    // Object syntax className variable;
    // Teacher t1; //This line of obj creation internally calls the constructor. Compiler automatically calls the constructor

    // To access any properties of the class we have to write 
    // t1.name = "Amy";
    // // t1.dept = "Computer Science";
    // t1.sub = "Python";
    // t1.setSalary(30000);
    
    // cout << t1.name << endl;
    // cout << t1.getSalary() << endl;
    // cout << t1.dept << endl;
    
    // Using constructor
    // Teacher t1("Amy","Computer science","C++",30000);
    // t1.getInfo(); //Then we call getInfo to print our values 

    // Copy constructor
    // Teacher t2(t1); //By default copy constructor is called
    // t2.getInfo();

// Shallow copy
    Student s1("Roman",9.7);
    Student s2(s1);
    // s2.getInfo();
    
    // Shallow copy
    // s1.getInfo();
    // *(s2.cgpaPtr) = 9.2;
    // s1.getInfo();

    // Deep copy
    s1.getInfo();
    *(s2.cgpaPtr) = 9.2;
    s1.getInfo();
    s2.name = "Ness";
    s2.getInfo();

    return 0;
}