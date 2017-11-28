#include <iostream>
#include <array>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;
/*
Luke Moua
11/15/2017

This program calculates all possibilities of
a quadratic formula (assuming it's quadratic and consists of real numbers).
Also capable of outputting complex numbers (i.e imaginary)
*/
class Quadratic
{
public:
	void get_values(), output_values(), get_partial_solution();
	double computePosQuadratic(), computeNegQuadratic();
	bool isImaginary = isgreater((4*A*C), pow(B,2));
	
private:
	double A, B, C, D;
	string response;
};
//Retrieves input from the console
//and decides whether the solution is
//imaginary or not, then prompts if the user
//wants an imaginary answer, if not, terminate program
void Quadratic::get_values() {
	cout << "Enter your A value: \n";
		cin >> A;
		cout << "Enter your B value: \n";
				cin >> B;
				cout << "Enter your C value: \n";
				cin >> C;
				//Check if the result is an imaginary #
				if (isImaginary == true) {
					cout<<"Imaginary Number, do you want to continue?\n\n";
					cin >> response;
					if (response == "yes" || response == "Yes" || response == "YES") {
						//Compute the imaginary number
						D = sqrt((4 * A * C) - pow(B, 2));
					}
					else {
						exit(0);
					}
				}
				else {
					D = sqrt((pow(B, 2) - (4 * A * C)));
				}
}
void Quadratic::get_partial_solution() {
	if (isImaginary == true) {
		cout << "The ";
	}
}


//Outputs the answer into a readable format for the user
void Quadratic::output_values() {
	//If the square root part of the quadratic formula
	//is imaginary, then compute the parts separately and add
	//them in a readable format using i
	if (isImaginary == true) {
		cout << "\n\nYour answer is: \nx = "<<computePosQuadratic() << " + "<<D/(2*A)<<"i"
			<< "\n or x = " << computePosQuadratic() << " - "<<D/(2*A)<<"i\n\n"<<computePosQuadratic();
	} //Or else just compute the quadratic equation normally
	else {
		cout << "\n\nYour answer is:JAJA \nx = " << computePosQuadratic()
			<<"\n or x = " << computeNegQuadratic() <<"\n\n";
	}
}

//Computes the positive portion of the quadratic
//equation if and only if the solution is not imaginary
double Quadratic::computePosQuadratic() {
	double posFinalanswer;
		posFinalanswer = (-B + D) / (2 * A);
	return posFinalanswer;
}

//Returns the subtracted quadrartic solution of the formula
double Quadratic::computeNegQuadratic() {
	double negFinalanswer;
	negFinalanswer = (-B - D)/(2*A);
	return negFinalanswer;
}

int main() {
	//Create a quadratic class object
	Quadratic myQuad;

	//Get input from user interface
	myQuad.get_values();

	//When not imaginary
	myQuad.output_values();

	//Pauses the screen so that the user can read the console
	system("pause");
	//Required to run the program
	return 0;
}

