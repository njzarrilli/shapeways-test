#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "artistMap.h"
#include "artist.h"

using namespace std;

ArtistMap::ArtistMap()
{
}

void ArtistMap::read_artist_lists(char* filename)
{
	ifstream in(filename);
	string list;
	int list_num = 0;

	while (! in.eof()) {
		getline(in, list);
		if (in.fail()) break;
		process_list(list, list_num);
		cout << "JUST FINISHED " << list_num << endl << endl;
		list_num++;
	}
}

void ArtistMap::process_list(string list_artists, int list_num)
{
	string artist_name;
	
	//char test = list_artists[list_artists.length()];
	//cout << test << endl;
	/*for (int i = list_artists.length() - 1; i >= 0; i--) {
		if (list_artists[i] != ',') {
			//artist_name.push_back(list_artists[i]);
			artist_name += list_artists[i];
		}
		else {
			cout << artist_name << endl;
			//process_artist(artist_name, list_num);
			artist_name.clear();
		}
	}*/
	for (unsigned i = 0; i < list_artists.length(); i++) {
		if (list_artists[i] != ',') {
			artist_name += list_artists[i];
		}
		else {
			cout << artist_name << endl;
			process_artist(artist_name, list_num);
			artist_name.clear();
		}
	}
	//catches the last artist in the list
	cout << artist_name << endl;
	process_artist(artist_name, list_num);
}

void ArtistMap::process_artist(string artist, int list_num)
{
	unordered_map<string, ArtistData>::const_iterator got = 
		artists_and_lists.find(artist);

	if (got == artists_and_lists.end()) {
		ArtistData *artist = new ArtistData(artist, list_num);
		artists_and_lists.insert(artist);
		//create new Artist and insert
	}
	else {
		artists_and_lists[got->first].update_lists_appeared_in(list_num);
	}
}

void ArtistMap::print_pairs()
{
}

ArtistMap::~ArtistMap()
{
}

      