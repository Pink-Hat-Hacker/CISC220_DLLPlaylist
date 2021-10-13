/*
 * DLL.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: pinkhathacker
 */




#include "DNode.hpp"
#include "DLL.hpp"
#include "Song.hpp"

#include <iostream>
#include <stdlib.h>

using namespace std;


DLL::DLL(){  // constructor - initializes an empty list
	last = NULL;
	first = NULL;
	numSongs = 0;
}
DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
	DNode *n = new DNode (t,l,m,s);
	first = n;
	last = n;
	numSongs=1;
}

DLL::~DLL(){
	//TODO: DESTRUCTOR
	//need to make a destructor here -- read instructions pdf
}




/*
 * This pushes a new node onto the end of the list. If there are no nodes in the list, it creates the
 * first node and adds it. Otherwise it places a new node onto the end of the list. t is the song’s
 * title,a is the song’s artist, m is the number of minutes the song runs for, and s is the number of
 * seconds the song runs for
 */
void DLL::push(string t, string a, int m, int s){
	//TODO:push DLL.cpp

	DNode *n = new DNode(t,a,m,s);

	if(numSongs == 0){
		first = n;
	}else{
		last = n;
	}

	numSongs++;
}

/*
 * This method should print out the list. Note that I have included a method for printing out each
 * song object in the song class definitions, called printSong(). If you call that, the songs will
 * printed out in the format you see in the output
 */
void DLL::printList(){
	//TODO: printList DLL.cpp
	DNode *current= first;

	while(current!=NULL){
		current->song->printSong();
		current = current->next;
	}
}

/*
 * This method finds the song with the title s and removes the node that holds that song from the
 * list. I have this method print the line,
 * Removing: songtitle, songartist………………………..songmin:songsec
 * In other words, I have it print the song it is removing.
 * (Note: if the song is the data in the last node in the list, this method calls the pop method (as
 * described below).
 */
int DLL::remove(string t){
	//TODO: remove DLL.cpp
	//EMMA
}

/*
 * This pops the last node off the list. If there is only one node on the list, it resets first and last to
 * NULL and the numSongs field to 0. It returns a song object.
 */
Song *DLL::pop(){
	//TODO:pop DLL.cpp

	//EMMA
}

/*
 * moves song with title s up one in the playlist.
 */
void DLL::moveUp(string t){
	//TODO: moveUp DLL.cpp
}

/*
 * moves song with title s down one in the playlist.
 */
void DLL::moveDown(string t){
	//TODO: movDown DLL.cpp
}


/*
 * This method traverses the list and adds up the minutes and seconds of each song to determine the total
 * duration of the list (i.e., all your songs in the playlist). Note that it uses call by pointer to update the
 * minutes and the seconds for outside of the method.
 */
void DLL::listDuration(int *tm, int *ts){
	//TODO: listDuration DLL.cpp
}

/*
 * This method randomly shuffles the songs so that they are in a different, random order.
 */
void DLL::makeRandom(){
	//TODO: makeRandom DLL.cpp
	DNode *current = first;
	DNode *random;

	int randomInd;

	for(int i = 0; i<numSongs; i++){
		random = current;
		randomInd = (rand()%numSongs+1);

		for(int j = 0; j < randomInd; j++){
			if(random->next == NULL){
				randomInd = j;
				break;
			}
		}
	}
}









