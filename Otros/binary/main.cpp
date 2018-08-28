#include <iostream>
#include <string>
#include <math.h>					// pow

using namespace std;

void toBinary(int, string&);		// convert an integer n to a binary
int toDecimal(string);				// convert a binary number to a decimal int
string getBinValue();				// ask for a decimal value to the user, return binary
string sumBinary(string, string);	// sum two binaries into another binary

int main()
{
	if (false)
	{
		int n;
		string out;
		// -1 prints /
		while (n != -1)
		{
			cout << "n: ";
			cin >> n;
			toBinary(n, out);
			cout << out << endl;
			out = "";
		}
	}
	else
	{
		string binaryA;
		string binaryB;
		string binaryResult;

		binaryA = getBinValue();
		binaryB = getBinValue();

		binaryResult = sumBinary(binaryA, binaryB);
		cout << "binary result: " << binaryResult << endl;
		cout << "decimal value: " << toDecimal(binaryResult) << endl;
	}
	return 0;
}

void toBinary(int n, string& out)
{
	if (n / 2 != 0)
		toBinary(n / 2, out);
	out += n % 2 + '0';
}

int toDecimal(string binary)
{
	int sum = 0;
	for (int i = binary.length() - 1; i >= 0; i--)
	{
		sum += (binary[binary.length() - 1 - i] - '0') * pow(2, i);
	}
	return sum;
}

string sumBinary(string a, string b)
{
	string result;
	string temp;
	int carry = 0;
	int binIntA = 0;
	int binIntB = 0;
	int diff = a.length() - b.length();

	// absolute value
	diff = diff >= 0 ? diff : -diff;

	// find bigger number and add 0 to the left
	if (a.length() > b.length())
	{
		for (int i = 0; i < a.length(); i++)
			if (i < diff)
				temp += '0';
			else
				temp += b[i - diff];
		b = temp;
	}
	else
	{
		for (int i = 0; i < b.length(); i++)
		if (i < diff)
			temp += '0';
		else
			temp += a[i - diff];
		a = temp;
	}

	// sum and carry
	result = a;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		binIntA = a[i] - '0';
		binIntB = b[i] - '0';
		result[i] = ((binIntA != binIntB) != carry) + '0';
		carry = (binIntA && binIntB) || (binIntA && carry) || (binIntB && carry);
	}

	// last carry
	if (carry)
		return '1' + result;
	else
		return result;
}

string getBinValue()
{
	int n;
	string out;

	cout << "n: ";
	cin >> n;

	toBinary(n, out);
	return out;
}
