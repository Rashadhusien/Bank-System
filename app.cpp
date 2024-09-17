#include <iostream> 
#include <string>
using namespace std;


class Validation {

  public:

  static bool isNameValid(string& name) {
		if (name.size() < 5 || name.size() > 20) {
			return false;
		}
		for (int i = 0; i < name.size(); i++) {
			if (!isalpha(name[i])) {
				return false;
			}
		}

		return true;
	}

  static bool isPasswordValid(string& password) {
  return password.size() >= 8 && password.size() <= 20;
  }
  static bool isBalanceValid(double balance) {
    return balance >= 1500;
  }

  static bool isSalaryValid(double salary) {
    return salary >= 5000;
  }
  

};


class Person {
protected:
	int id;
	string name, password;
public:
	Person(){
		id = 1;
	}
	Person(int id, string name, string password) {
		this->id = id;
		// this->name = name;
		// this->password = password;
    setName(name);
    setPassword(password);
	}

	// void setId(int id) {
	// 	this->id = id;
	// }
	int getId() {
		return id;
	}
	void setName(string name) {
    if (Validation::isNameValid(name)) {
      this->name = name;
      cout<< "Successful operation!"<<endl;
    }else {
      this->name = "UNKNOWN";
      cout << "invalid name: must be alphabetic chars and min size 5 and max size 20\n";
    }
	}
	string getName() {
		return name;
	}
	void setPassword(string password) {
    if (Validation::isPasswordValid(password)) {
		this->password = password;
    cout<< "Successful operation!"<<endl;

    } else {

      cout << "Invalid Password: must be with min size 8 and max size 20\n";
    }
	}
	string getPassword() {
		return password;
	}
	void printData() {
		cout << "Id is: " << id<<endl;
		cout << "Name is " << name << endl;
	}
};
class Client : public Person {
	double balance;
public:
	Client() {}
	Client(int id, string name, string password, double balance) : Person(id, name, password){
		// this->balance = balance;
    setBalance(balance);
	}
	void setBalance(double balance) {
    if (Validation::isBalanceValid(balance)) {  // ceck balance
		this->balance = balance;

    cout<< "Successful operation!"<<endl;
    }else {
      cout << "faild: Invalid Balance\n";
    }
	}
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		if(amount>0){
        balance += amount;
        cout<< "Successful operation!"<<endl;
        cout<< "New Balance = "<<balance<<endl;
        }else{
            cout << "Transaction falid: you do not have enough amount."<<endl;
        }
    }
	void withdraw(double amount) {
		if (amount <= balance){
			balance -= amount;
      cout<< "Successful operation!"<<endl;
      cout<< "New Balance = "<<balance<<endl;
		}
		else{
			cout << "Transaction failed: you do not have enough balance."<<endl;
		}
	}
	void transferTo(Client& another, double amount) {
		if (amount <= balance)
		{
			balance -= amount;
			another.balance += amount;
      cout<< "Successful operation!"<<endl;
      cout<< "New Balance = "<<balance<<endl;
		}
		else{
			cout << "Transaction failed: you do not have enough balance." << endl;
		}
	}
	void checkBalance() {
		cout << "Current balance: " << balance << endl;
	}
	void printData() {
		Person::printData();
		cout << "The balance is: " << balance << endl;
	}
};

class Employee:public Person{
    double salary;
public:
    Employee(){}
    Employee(int id, string name, string password, double salary):Person(id,name,password) {
        // this->salary = salary;
        setSalary(salary);
    }
    void setSalary(double salary) {
      if (Validation::isSalaryValid(salary)) { // check salary
        this->salary = salary;
        cout<< "Successful operation!"<< endl;


      }else {
        cout << "Invalid salary: Min Salary 500 \n";
      }
    }
    double getSalary() {
        return salary;
    }
    void printData() {
        Person::printData();
        cout << "salary : " << salary << endl;
    }
};
class Admin: public Employee{
public:
    Admin(){}
    Admin(int id, string name,string password,double salary):Employee(id,name,password,salary){
    }
};


int main() {

  Client c1(101,"mohamed", "12345645886", 1000), c2(102, "seifhusein", "1564189152", 5000);


  c1.transferTo(c2, 10000);


  c1.printData();
  cout << endl;
  c2.printData();

  Employee e1(150, "mahmoud", "1253649", 12365), e2(151, "sameh", "22222222", 10000);


  

  e1.printData();
  cout << endl;
  e2.printData();


  return 0;
}