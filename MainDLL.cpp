/*
 * MainDLL.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: pinkhathacker
 */





#include <iostream>
#include <stdlib.h>
#include "Playlist.hpp"
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	//Playlist *list = new Playlist;
	Playlist *list = new Playlist("Halloween.txt");
}

