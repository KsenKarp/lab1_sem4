#include <stdlib.h>
#include <cassert> 
#include <fstream>
#include <string>

using namespace std;

int main () {
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
		assert(while_count == param);
		while_count--;
	}
	while(getline(for_params, s)) {
		 int param = stoi(s);
		 assert(for_count == param);
		 for_count--;
	}
	getline(while_noparams, s);
	assert(no_param == s);
	getline(for_noparams, s);
	assert(no_param == s);
	return 0;
}
