/* Naomi Zarrilli
 * Shapeways coding test 1/7/14
 * This file is a header for the implementation of hash table that will
 * represent the artists and the lists the artists appear in
 */

#ifndef __ARTISTSLIST_H__
#define __ARTISTSLIST_H__

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

//const double LOADMAX = 0.5;

using namespace std;

struct artist_data; {
	string artist;
	vector<int> lists_appeared_in;
};

class ArtistsList {
	public:
		ArtistsList();
		void process_lists(string list_artists, int list_count);
		~ArtistsList();
	private:
		bool artist_in_list(string artist);
		void process_artist(string artist, int list_num);
		void update_lists_appeared_in(string artist, int list_num);
		void find_pairs();
};


#endif
