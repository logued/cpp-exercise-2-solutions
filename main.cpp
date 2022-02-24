#include <iostream>
//Solutions to Exercise 2                  Feb 2022

#include <iostream>
#include <ctime>
using namespace std;

void question2();
void question3();
void question4();
void question5();
void question6();
void question7();
void question9();
void question10();
void demoPassByReference(int& , double& );

int main()
{
	cout << "Solutions to Exercise 2" << endl;

    // question1() is to DRAW the Stack Frame
	question2();	// call by value, density()
	question3();
    question4();
	question5();
	question6();
	question7();
	question9();	// recursion, divide()
	question10();	// recursion, fibonacci()

	return 0;  // indicate successful termination of main()
}


// Q2 ********************************************************************************
// If we declare and define the function above the function in which it is called,
// then we don't need a function prototype at th etop of the program. The function
// header is used as the function prototype.

double density(double width, double height, double depth, double mass)  // pass by value
{
    // density = mass / volume
	return mass / (width * height * depth);
}

void question2()
{
	cout << "Q2. Density = mass / volume" << endl;

	double d = 0.0;
	d = density(10.00, 5.00, 3.00, 29.45);

	cout << "Density is: ";
	cout << d << endl;
}

// Q3 *****************************************************************************
int charToDecimal(char c)
{
	// return (int)c;	// old C language cast
	// return c;		// cast happens automatically

	return static_cast<int> (c);  // C++ static cast : char to int

    // a char is 1 byte long and an int is four bytes.
    // assigning a char into a byte puts the 1 byte char value into
    // the rightmost byte of the 4-byte int

    //NB, the rightmost byte in the int is a pattern of 8 bits.
    // It can be interpreted as a char - in which case it is looked up in the ASCII table,
    // OR, th e8 bits can be interpreted as a number, in which case the 8-bit binary pattern
    // represents a number (an int in this case)
}

void question3()
{
	cout << "Q3. static casting from char to int." << endl;
	cout << "ASCII value of character \'a\' is: " << charToDecimal('a') << endl;
}

// Q4 *******************************************************************************

void question4() {
    int x = 4;
    double y =5.55;
    demoPassByReference( x,y);   // pass two variables as arguments into a function.
    //  Whether they are passed by value or by reference depends on how the parameters
    //  are declared in the function.
}

// Pass by Reference  - (using Reference Parameters)
// Parameters - x is a reference to an int, and it is bound to x in question() when called
//              z is a reference to a double, and is bound to variable y in question4() when called
//    ( internally, the address of x in main is passed into the parameter x in the function)
//
void demoPassByReference(int& x, double& z)
{
    x = 2000;	// This WILL change the value of x in main, because here x is
                // a reference parameter that refers to the variable x in main().

    //TODO: Draw the Call-Stack, and you will see why this is so.

    z = 8.11;    // This WILL change the value of y in main(), because z is a reference to y in main()
}

// Q5  ***************************************************************************

void increment(int& intRef)	// parameter intRef is a reference to an integer
{
		intRef++;   // increments the value referred to by this reference
                    // intRef refers to the variable 'num' in function question5()
}

void question5()
{
	int num = 10;
	cout << "Q5. Before increment(int& n) : num=" << num << endl;
	increment(num);
	cout << "After increment(int& n) : num=" << num << endl;
}

// Q6 ****************************************************************************

void swapByReference(int& a, int& b )   // 'references to int' type parameters
{
	int temp = a;	// a is a reference to x (below), so it is another name for x
	a = b;          // b is a reference to  y (below), so b accesses y
	b = temp;
}
// if we don't declare the parameters as reference types using '&a' and '&b',
// then the arguments will be passed by value, and only the local copies of the arguments
// (stored in the parameter variables) will be swapped.
// The values in x and y in the calling function will not change.

void question6()
{
	cout << "Q6. swapByReference():" << endl;
	int x = 3;
	int y = 4;

	cout << "Before call to swapByReference(x,y); x=" << x << ",y=" << y << endl;
	swapByReference(x, y);
	cout << "After call to swapByReference(x,y); x=" << x << ",y=" << y << endl;
}

//Q7  https://en.cppreference.com/w/cpp/numeric/random/rand    **********************
//
int sumRandom(int start, int end)
{
	long sum = 0;
	int range = end - start;

	for (int i = 1; i <= 100; i++) {
		int n = ( rand() % range ) + start;
		cout << n << ",";
		sum += n;
	}
	return sum;
}

void question7()
{
	cout << "Q7. Sum of Randomly generated numbers in a range: ";
	long result = sumRandom(50, 200);
	cout << "Sum of 100 random numbers (from range 50-200) = " << result << endl;
}

// Question 9 ***************************************************************************
// Recursive divide function.
//
void divide(int n)
{
	cout << "In divide() : n = " << n << endl;
	if (n < 1) {        // stopping condition, does make recursive call, so starts a cascade of returns
		return;
	}
	else
	{
		divide(n / 2);	// recursive call, integer division, truncation of decimal part will occur
	}
}

void question9()
{
	cout << "Q9. Recursive divide" << endl;

	cout << "Enter an integer number: " << endl;
	int num = 0;
	cin >> num;

	divide(num);
}

// Q10  //////////////////////////////////////////////////////
// Assuming fibonacci sequence 0,1,1,2,3,5,8,... F(1)=0,F(2)=1
//
int fibonacci(int n)
{
	if (n == 1) return 0;// first fibonacci number F(1)

	if (n == 2) return 1; // second fibonacci number F(2)

	return( fibonacci(n - 1) + fibonacci(n - 2) );  // recursive calls
}

void question10()
{
	cout << "Q10. Fibonacci sequence" << endl;

	for (int i = 1; i <= 10; i++)
		cout << fibonacci(i) << ", ";

	cout << endl;
}