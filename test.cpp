#include <stdlib.h>
#include <cassert> 
#include <fstream>
#include <string>

using namespace std;

int main () {
	int success_fl = true;
        string s;       
	system("./backwhile 0 1 2 3 > testwhile_withparams.txt");
	system("./backwhile > testwhile_noparams.txt");
	system ("./paramsbackwards 0 1 2 3 > testfor_withparams.txt");
	system("./paramsbackwards > testfor_noparams.txt");
	ifstream while_params("testwhile_withparams.txt");
	ifstream while_noparams("testwhile_noparams.txt");
	ifstream for_params("testfor_withparams.txt");
	ifstream for_noparams("testfor_noparams.txt"); int while_count = 3;
	int for_count = 3;
	string no_param = "No parameters";
	while(getline(while_params, s)) {
		int param = stoi(s);
		if (assert(while_count == param) == false) success_fl = false;
		while_count--;
	}
	if (success_fl) cout << "test_while passed" << endl;
	else cout << "test_while failed" << endl;
	success_fl = true;
	while(getline(for_params, s)) {
		 int param = stoi(s);
		 if (assert(for_count == param) == false) success_fl = false;
		 for_count--;
	}
	if (success_fl) cout << "test_for passed" << endl;
	else cout << "test_for failed" << endl;
	getline(while_noparams, s);
	if (assert(no_param == s)) cout << "test_while with 0 param passed" << endl;
	else cout << "test_while with 0 param failed" << endl;
	getline(for_noparams, s);
	if (assert(no_param == s)) cout << "test_for with 0 param passed" << endl;
	else cout << "test_for with 0 param failed" << endl;
	return 0;
}
