/* Naomi Zarrilli
 * January 8, 2015
 * This is the implementation file of the ArtistMap class, including functions
 * for processing a file of last.fm artist lists and creating an unordered map
 * from this data, as well as searching for pairs between two artists
 */

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "artistMap.h"
#include "artist.h"

using namespace std;

ArtistMap::ArtistMap()
{
	for (auto x = artists_and_lists.begin(); x != artists_and_lists.end();
			x++) {
		x->second = NULL;
	}
}

//reads in a file line by line (list by list)
void ArtistMap::read_artist_lists(char* filename)
{
	ifstream in(filename);
	string list;
	int list_num = 0;

	while (! in.eof()) {
		getline(in, list);
		if (in.fail()) break;
		process_list(list, list_num);
		list_num++;
	}
}

//creates artist_names from a single list of artists and name by name sends each
//to a processing function
void ArtistMap::process_list(string list_artists, int list_num)
{
	string artist_name;
	
	for (unsigned i = 0; i < list_artists.length(); i++) {
		if (list_artists[i] != ',') {
			artist_name += list_artists[i];
		}
		else {
			process_artist(artist_name, list_num);
			artist_name.clear();
		}
	}
	//catches the last artist in the list
	process_artist(artist_name, list_num);
}

//determines whether the artist already exists in the unordered map of artists
//or is a new artist. If already exists, that artist's vector is updated to
//include the current list_num. If is it new, it is added to the map
void ArtistMap::process_artist(string artist_name, int list_num)
{
	unordered_map<string, ArtistData*>::const_iterator got = 
		artists_and_lists.find(artist_name);

	if (got == artists_and_lists.end()) {
		ArtistData *artist = new ArtistData(artist_name, list_num);
		std::pair<string,ArtistData*> new_artist (artist_name, artist);
		artists_and_lists.insert(new_artist);
	}
	else {
		artists_and_lists[got->first]->update_lists_appeared_in(list_num);
	}
}

//starts from the first element in the map and compares it to the element
//after it and onward
void ArtistMap::print_pairs()
{
	for (auto x = artists_and_lists.begin(); x != artists_and_lists.end();
			x++) {
		auto z = x;	//equivalent to setting y = x + 1
		z++;		//but can't easily be done in the lower loop
		for (auto y = z; y != artists_and_lists.end(); y++) {
			if (x->second->found_pairs(y->second->
						get_artist_vector())) {
				cout<< "PAIR: ";
				cout << x->second->get_artist_name() << " ";
				cout << y->second->get_artist_name() << endl;
			}
		}
	}
}

ArtistMap::~ArtistMap()
{
	for (auto x = artists_and_lists.begin(); x != artists_and_lists.end();
			x++) {
		if (x->second != NULL) {
			delete x->second;
		}
	}
	artists_and_lists.clear();
}
