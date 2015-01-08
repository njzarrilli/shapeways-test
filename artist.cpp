#include <iostream>
#include "artist.h"

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

void ArtistData::update_lists_appeared_in(int list_num)
{
	lists_appeared_in.push_back(list_num);
}

bool ArtistData::over_fifty_pairs(vector<int> currList)

{
	int pair_count = 0;
	int iter = 0;
	
	if (pairs_possible(currList) == false) {
		cout << "No possible pairs" << endl;
		return false;
	}
	iter = determine_iter(currList);
	//THIS CHECK MIGHT BE UNNECESSARY
	/*if (iter == -1) {
		cout << 
		return false;
	}*/
	cout << "FOUND ITER AT: " << iter << endl;
	//cout << "sizeof: " << lists_appeared_in.size() << endl;
		for (unsigned i = 0; i < lists_appeared_in.size(); i++) {
			//cout << "AT: " << lists_appeared_in[i] << endl;
			for (unsigned j = (unsigned)iter; j < currList.size(); 
					j++) {
				if (lists_appeared_in[i] == currList[j]) {
					cout << lists_appeared_in[i] << endl;
					pair_count++;
				}
			}
		}
		//if (pair_count >= 50) {
		//	return true;
		//}
	//}
	cout << "pair count: " << pair_count << endl;	
	return false;
}	

bool ArtistData:: pairs_possible(vector<int> currList)
{

	//if ((lists_appeared_in.size() < 49) || (currList.size() < 49)) {
	//	return false;
	//}
	//l: 6, 8, 9
	//curr: 1, 3, 5
	//if smallest val in list is greater than the greatest val in currList
	//there will be no overlapping vals because lists are sorted
	if (lists_appeared_in.front() > currList.back()) {
		cout << "IN FIRST PP CONDITIONAL" << endl;
		return false;
	}
	//l: 1, 3, 5
	//curr: 6, 8, 9
	//if greatest val in list is less than the smallest val in currList
	//there will be no overlapping vals because lists are sorted
	if (lists_appeared_in.back() < currList.front()) {
		cout << "IN SECND PP CONDITIONAL" << endl;
		return false;
	}
	return true;
}

//returns the first slot in the currList for potential overlap
int ArtistData::determine_iter(vector<int> currList)
{
	int lowest_list_num = lists_appeared_in.front();
	
	//l: 1, 3, 5, 8
	//curr: 5, 8, 9
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



