#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream f;
	f.open("example.txt", ios::in | ios::out | ios::trunc); // ios::app
	if(!f.is_open()) return -1;

	f << "Hello, world\n";

	string str;

	f.seekg.(0, ios::beg);
	//f >> str;
	
	if(!f.good()) return -1;

	cout << str << endl;

	f.close();

	return 0;
}
