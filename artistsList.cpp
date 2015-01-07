#include <iostream>
#include "artistsList.h"

using namespace std;


struct artist_data; {
	string artist;
	vector<int> lists_appeared_in;
};

Artist::Artist(string artist_name, int list_num)
{
	artist = artist_name;
	lists_appear_in.push_back(list_num);
}

void Artists::update_lists_appeared_in(int list_num)
{
	lists_appeared_in.push_back(list_num);
}

bool Artists::over_fifty_pair(vector<int> currList, vector<int> otherList)
{
	int pair_count = 0;
	int iter = 0;

	if ((currList.size() < 49) || (otherList.size() < 49)) {
		return false;
	}
	else {
		for (int i = 0; i < currList.size(); i++) {
			for (int j = iter; i < otherList.size(); j++) {
				if (currList[i] = otherList[j]) {
					pair_count++;
				}
			}
		}
		if (pair_count >= 50) {
			return true;
		}
	}
	return false;

}

/*
bool optimization_checks(vector<int> currList, vector<int> otherList)
{
	//no overlapping lists so no pairs
	if (currList[0] > otherList[back]) {
		return false;
	}
		
	//optimization: determines iterator starting point,
	//relies on the vectors being sorted
	for (int i = 0; i < otherList.size(); i++) {
		if (currList[0] <= otherList[i]) {
			iter = i
			break;
		}
	}
	//no overlapping lists so no pairs
	if (iter == 0) {
		return false;
	}
}
*/

void process_lists(string list_artists, int list_count);
~ArtisstList();
bool artist_in_list(string artist);
void process_artist(string artist, int list_num);
void update_lists_appeared_in(string artist, int list_num);
void find_pairs();
      
