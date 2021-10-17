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
	//opposite of constructor?

	DNode *current = first;
	DNode *next;

	while(current != NULL){
		next = current->next;
		delete current;
		current = next;
	}
	last = NULL;
	first = NULL;
	numSongs = 0;
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
		last = first;
	}else{
		n->prev = last;
		last->next = n;
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

	while(current != NULL){
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
	DNode *temp= first;
	int x=0;
	while(temp!=NULL && x==0){
		if(temp->song->title == t){
			if(temp==last){
				if(temp->song->sec < 10){
					cout << "Removing: " << temp->song->title << ", " << temp->song->artist << ".............." << temp->song->min << ":0" << temp->song->sec << endl;
				}
				else{
					cout << "Removing: " << temp->song->title << ", " << temp->song->artist << ".............." << temp->song->min << ":" << temp->song->sec << endl;
				}
				pop();
				x=1;
			}
			else if(temp==first){
				if(temp->song->sec < 10){
					cout << "Removing: " << temp->song->title << ", " << temp->song->artist << ".............." << temp->song->min << ":0" << temp->song->sec << endl;
				}
				else{
					cout << "Removing: " << temp->song->title << ", " << temp->song->artist << ".............." << temp->song->min << ":" << temp->song->sec << endl;
				}
				first=temp->next;
				x=1;
			}
			else{
				if(temp->song->sec < 10){
					cout << "Removing: " << temp->song->title << ", " << temp->song->artist << ".............." << temp->song->min << ":0" << temp->song->sec << endl;
				}
				else{
					cout << "Removing: " << temp->song->title << ", " << temp->song->artist << ".............." << temp->song->min << ":" << temp->song->sec << endl;
				}
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				x=1;
			}
		}
		else{
			temp = temp->next;
		}
	}
	delete temp;
	return x;
}

/*
 * This pops the last node off the list. If there is only one node on the list, it resets first and last to
 * NULL and the numSongs field to 0. It returns a song object.
 */
Song *DLL::pop(){
	//TODO:pop DLL.cpp
//	if(first->next == nullptr){
//		first = NULL;
//		last = NULL;
//		numSongs = 0;
//	}
//
//	last->prev->next = NULL;
//	last = last->prev;

//EMMA
	DNode *temp = last;
	Song *x = temp->song;
	last=last->prev;
	delete temp;
	last->next = NULL;
	numSongs--;
	return x;
}

/*
 * moves song with title s up one in the playlist.
 */
void DLL::moveUp(string t){
	//TODO: moveUp DLL.cpp
	//EMMA
//	DNode *temp=first;
//	DNode *helper=NULL;
//	while(temp!=NULL){
//		if(temp->song->title == t){
//			//might only work if the song isn't first or last
//			helper=temp->prev;
//			temp->next->prev=temp->prev;
//			helper->prev->next=helper->next;
//			temp->prev->next=temp->next;
//			helper->next->prev=helper->prev;
//
//		}
//	}
//	delete temp;
//	delete helper;

	DNode *current = first;

	while(current->song->title != t){
		current = current->next;
	}

	if(current->prev == NULL){ //first case
		last->next = current;
		current->next->prev = NULL;
		first = current->next;
		current->prev = last;
		last = current;
		current->next = NULL;
		last->next = NULL;
	}else if(current->prev->prev == NULL){ //second case
		current->next->prev = current->prev;
		current->prev->next = current->next;
		current->next = current->prev;
		current->prev->prev = current;
		current->prev = NULL;
		first = current;
	}else if(current->next == NULL){ //last case
		current->prev->prev->next = current;
		current->prev->next = NULL;
		current->next = current->prev;
		DNode *temp;
		temp = current->prev->prev;
		current->prev->prev = current;
		last = current->prev;
		current->prev = temp;
	}else{ //middle case
		current->prev->prev->next = current;
		current->next->prev = current->prev;
		current->prev->next = current->next;
		current->next = current->prev;
		DNode *temp;
		temp = current->prev->prev;
		current->prev->prev = current;
		current->prev = temp;
	}
}

/*
 * moves song with title s down one in the playlist.
 */
void DLL::moveDown(string t){
	//TODO: movDown DLL.cpp
	//EMMA

	DNode *current = first;
	while(current->song->title != t){
		current = current->next;
	}

	//last
	if(current->next == NULL){
		current->prev->next = NULL;
		last = current->prev;
		first->prev = current;
		current->next = first;
		current->prev = NULL;
		first = current;
	}else if(current->prev == NULL){//first
		current->next->next->prev = current;
		current->next->prev = NULL;
		current->prev = current->next;

		DNode *temp = current->next->next;
		current->next->next = current;
		current->next = temp;
		first = current->prev;
	}else if(current->next->next == NULL){//second to last

//		point to current to prev to next = current to the next
//		current to next to prev = current to prev
//		current to prev = current to next
//		current to next to next = current
//		current to next = null
//		last = current

		current->prev->next = current->next;
		current->next->prev = current->prev;
		current->prev = current->next;
		current->next->next = current;
		current->next = NULL;
		last = current;
//		current = last;
	}else{//middle
		current->next->next->prev = current;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		current->prev = current->next;

		DNode *temp;
		temp = current->next->next;
		current->next->next = current;
		current->next = temp;
	}
}


/*
 * This method traverses the list and adds up the minutes and seconds of each song to determine the total
 * duration of the list (i.e., all your songs in the playlist). Note that it uses call by pointer to update the
 * minutes and the seconds for outside of the method.
 */
void DLL::listDuration(int *tm, int *ts){
	//TODO: listDuration DLL.cpp
	DNode *current = first;

	while(current != NULL){
		//calc total sec and min
		*ts += current->song->sec;
		*tm += current->song->min;
		//go to next song
		current = current->next;
	}
}

/*
 * This method randomly shuffles the songs so that they are in a different, random order.
 */
void DLL::makeRandom(){
	//TODO: makeRandom DLL.cpp
	DNode *current = first;
	DNode *random;
	int randInd;

	//goes through ref node to change them
	for(int i = 0; i < numSongs; i++){
		random = current;
		randInd = (rand()%numSongs + 1);//set rand node away from curr

		for(int j = 0; j < randInd; j++){//find rand node
			if(random->next == NULL){
				randInd = j;
				break;
			}
			random = random->next;
		}
		//move rand node to current node
		for(int x = 0; x < randInd; x++){
			moveUp(random->song->title);
		}
	}

	//fixes the first and last nodes
	randInd = (rand()%numSongs) + 1;
	for(int y = 0; y < randInd; y++){
		moveUp(current->song->title);
	}
	current = first;
	while(current->next != NULL){
		current = current->next;
	}
	last = current;
}









