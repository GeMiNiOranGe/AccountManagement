#include <iostream>
#include <string>
#include "CUser.h"
#include "CAdministrator.h"
#include "CEmployee.h"
#include "UIHaveNoUX.h"

using namespace std;

void check(CUser & temp) {
	temp.setPassword("hmmmm");
}

int main() {
	CEmployee tempEmployee("Ng Van A", "280 ADV", "90910290", "ahsdj@mail.com", "", ""), tempAd;
	tempAd = tempEmployee;
	check(tempEmployee);
	cout << tempEmployee.getPassword();
	tempEmployee.output();
	return 0;
}
