#ifndef HANDLEMAIN_H
#define HANDLEMAIN_H
#pragma once

#include <string>
#include <fstream>
#include "CUser.h"
#include "Config.h"

using namespace std;

ofstream createFile(string strUsername);
ifstream openFile(string strUsername);
void deleteFile(string strUsername);

void showAccountInfo(string strUsername);

bool hasUsername(string strSourceFile, string strUsername);
bool hasAccount(string strSourceFile, string strUsername, string strPassword);

#endif
