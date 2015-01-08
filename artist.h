/* Naomi Zarrili
 * January 1, 2015
 * artist.h defines the ArtistData class
 */

#ifndef __ARTIST_H__
#define __ARTIST_H__

#include <iostream>
#include <vector>

using namespace std;

class ArtistData {
	public:
		ArtistData(string name, int list_num);
		string get_artist_name();
		vector<int> get_artist_vector();
		void update_lists_appeared_in(int list_num);
		bool found_pairs(vector<int> currList);
		~ArtistData();
	private:
		string artist_name;
		vector<int> lists_appeared_in; //list will be sorted
		bool pairs_possible(vector<int> currList);
		int determine_iter(vector<int> currList);
};

#endif
