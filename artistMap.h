/* Naomi Zarrilli
 * Shapeways coding test 1/7/14
 * This file is a header for the implementation of hash table that will
 * represent the artists and the lists the artists appear in
 */

#ifndef __ARTISTMAP_H__
#define __ARTISTMAP_H__

#include <iostream>
#include <string>
#include <unordered_map>
#include "artistData.h"

using namespace std;

class ArtistMap{
	public:
		ArtistMap();
		void read_artist_lists(char* filename);
		void print_pairs();
		~ArtistMap();
	private:
		unordered_map<string, ArtistData*> artists_and_lists;
		void process_list(string list, int list_num);
		void proces_artist(string artist_name, int list_num);
		void process_artist(string artist, int list_num);
		void update_lists_appeared_in(string artist, int list_num);
};


#endif
