#include <iostream>
#include <string>
#include "CUser.h"
#include "CAdministrator.h"
#include "CEmployee.h"

using namespace std;

int main() {
	CEmployee tempEmployee("Ng Van A", "280 ADV", "90910290", "ahsdj@mail.com", "", ""), tempAd;
	tempAd = tempEmployee;
	tempEmployee.getFullName();
	tempEmployee.output();
	return 0;
}
