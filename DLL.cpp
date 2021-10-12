/*
 * DLL.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: pinkhathacker
 */




#include "DNode.hpp"
#include "DLL.hpp"

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

//TODO: DESTRUCTOR
//need to make a destructor here -- read instructions pdf



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
int remove(string t){
	//TODO: remove DLL.cpp
}

/*
 * This pops the last node off the list. If there is only one node on the list, it resets first and last to
 * NULL and the numSongs field to 0. It returns a song object.
 */
Song *pop(){
	//TODO:pop DLL.cpp
}

/*
 * moves song with title s up one in the playlist.
 */
void moveUp(string t){
	//TODO: moveUp DLL.cpp
}

/*
 * moves song with title s down one in the playlist.
 */
void moveDown(string t){
	//TODO: movDown DLL.cpp
}

/*
 * This method randomly shuffles the songs so that they are in a different, random order.
 */
void makeRandom(){
	//TODO: makeRandom DLL.cpp
}









