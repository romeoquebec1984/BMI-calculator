/*
William Adolph's
BMI calculator
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//declare functions prototypes
int getFeet();
double getInches();
string getName();
double getWeight();
double computeBMI(double,double,int);
void displayInfo(string, int, double,double,double );

int main() {

	//Declare Variables
	int feet{};
	double inches{};
	double meters{};
	string name{};
	double bmi{};
	double weightlbs{};
	double weightkgs{};
	double inchestotal{};

	//Ask user for their name, height, and weight 
	cout << endl << "Welcome to the Body Mass Index Calculator\n";
	name = getName();
	feet = getFeet();
	inches = getInches();
	weightlbs = getWeight();
	
	bmi = computeBMI(weightlbs, inches,feet);

	displayInfo(name, feet, inches, weightlbs, bmi);

	return 0;
}
int getFeet() {
	int feet{};
	cout << endl << "Please Enter Height" << endl;
	cout << "ft. ";
	cin >> feet;
	return feet;
}
double getInches() {
	double inches{};
	cout << endl << "in. ";
	cin >> inches;
	return inches;
}
string getName() {
	string name{};
	cout << endl << "Please Enter Your name : ";
	getline(cin, name);
	return name;
}
double getWeight() {
	double weightlbs;
	cout << "\nEnter weight in lbs :";
	cin >> weightlbs;
	return weightlbs;
}
double computeBMI(double weightlbs, double inches,int feet) {
	double bmi{};
	double inchestotal{};
	double weightkgs{};
	double meters{};

	weightkgs = 0.453592 * weightlbs;
	inchestotal = inches + (feet * 12);
	meters = 0.0254 * inchestotal;
	bmi = weightkgs / (pow(meters, 2));
	return bmi;
}
void displayInfo(string name, int feet, double inches, double weightlbs, double bmi) {


	cout << endl << name << endl;
	cout << endl << "Weight: " << weightlbs << " lbs" << endl;
	cout << endl << "Height: " << feet << "'" << inches << "''" << endl;
	cout << setprecision(2) << fixed;
	cout << endl << "BMI : " << bmi << endl;

	if (bmi < 18.5)
		cout << "underweight" << endl;
	else if (bmi >= 18.5 && bmi < 25)
		cout << "healthweight" << endl;
	else if (bmi >= 25 && bmi < 30)
		cout << "overweight";
	else
		cout << "obese :( ";

}

//#include <iostream>
//#include <iomanip>
//using namespace std; //introduces namespace std
//const double PAY_RATE = 9.25; //regular pay rate
//const double OVERTIME_RATE = 14.25; //overtime pay rate
//const int REGULAR_HOURS = 40; //regular hours
//
//// Function Prototypes
//double getHours();
//double calcPay(double);
//void display(double, double);
//int main(void)
//{
//	//declare and initialize variables
//	double hours = 0;
//	double salary = 0;
//	//Function Calls
//	hours = getHours();
//	salary = calcPay(hours);
//	display(hours, salary);
//
//	return 0;
//}
//double getHours() {
//	double hours = 0;
//	cout << "Please enter the total hours worked and press <Enter>: ";
//	cin >> hours;
//	return hours;
//}
//double calcPay(double hours) {
//	double salary = 0;
//	if (hours <= REGULAR_HOURS)
//		salary = PAY_RATE * hours;
//	else
//		salary = (PAY_RATE * REGULAR_HOURS) + (OVERTIME_RATE * (hours - REGULAR_HOURS));
//	return salary;
//}
//
//void display(double hours, double salary) {
//	cout << setprecision(2) << fixed << showpoint;
//	cout << endl << endl;
//	cout << "Hours Worked: " << hours << endl;
//	cout << "Salary: $" << salary << endl << endl;
//}