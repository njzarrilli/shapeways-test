/* Naomi Zarrilli
 * January 8, 2015
 * Implementation file for artist.h. This file includes functions that update
 * or provide information regarding  an indivdual artist's vector of lists it 
 * has appeared
 */

#include <iostream>
#include "artistData.h"

using namespace std;

ArtistData::ArtistData(string name, int list_num)
{
	artist_name = name;
	lists_appeared_in.push_back(list_num);
}

string ArtistData::get_artist_name()
{
	return artist_name;
}

vector<int> ArtistData::get_artist_vector()
{
	return lists_appeared_in;
}

//USED FOR DEBUGGING PURPOSES
void ArtistData::print_artist_vector()
{
	for (vector<int>::iterator i = lists_appeared_in.begin();
			i != lists_appeared_in.end(); i++) {
			cout << ' ' << *i;
	}
	cout << endl;
}

void ArtistData::update_lists_appeared_in(int list_num)
{
	lists_appeared_in.push_back(list_num);
}

//Checks for pairs between the class instance's list and another list
//by iterating through the current list and checking the other list
//for each value in the current list.
//Note: relies on the artist's list vectors to be sorted
bool ArtistData::found_pairs(vector<int> otherList)
{
	int pair_count = 0;
	int iter = 0;
	
	if (pairs_possible(otherList) == false) {
		return false;
	}
	//sets the starting point for the inner loop
	iter = determine_iter(otherList);

	for (unsigned i = 0; i < lists_appeared_in.size(); i++) {
		for (unsigned j = (unsigned)iter; j < otherList.size(); 
				j++) {
			if (lists_appeared_in[i] == otherList[j]) {
				pair_count++;
				if (pair_count == 50) {
					return true;
				}
			}
		}
	}
	return false;
}	

//Initial checks before more performance costly searching functions are done
//If these do not pass, time is saved because no other operations are performed
//to find pairs
bool ArtistData:: pairs_possible(vector<int> currList)
{
	//if smallest val in list is greater than the greatest val in currList
	//there will be no overlapping vals because lists are sorted
	if (lists_appeared_in.front() > currList.back()) {
		return false;
	}
	//if greatest val in list is less than the smallest val in currList
	//there will be no overlapping vals because lists are sorted
	if (lists_appeared_in.back() < currList.front()) {
		return false;
	}
	return true;
}

//returns the first slot in the currList for potential overlap
//saves iterations in the searching loop that would otherwise be useless
int ArtistData::determine_iter(vector<int> currList)
{
	int lowest_list_num = lists_appeared_in.front();
	
	for (unsigned i = 0; i < currList.size(); i++) {
		if (lowest_list_num <= currList[i]) {
			return (int)i;
		}
	}
	return -1;
}

ArtistData::~ArtistData()
{
	lists_appeared_in.erase(lists_appeared_in.begin(),
				lists_appeared_in.end());
}
