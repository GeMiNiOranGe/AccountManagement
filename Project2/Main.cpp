#include <iostream>
#include "CUser.h"
#include "CAdministrator.h"

using namespace std;

int main() {
	CAdministrator tempAdmin("Ng Van A", "280 ADV", "90910290", "ahsdj@mail.com", "", ""), tempAd;
	tempAd = tempAdmin;
	cout << tempAd.getFullName();
	return 0;
}
