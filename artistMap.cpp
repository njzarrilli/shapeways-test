#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "artistMap.h"
#include "artist.h"

using namespace std;

ArtistMap::ArtistMap()
{
//	artists_and_lists = unordered_map(100, hasher,eql, alloc);
	//artists_and_lists.clear();

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
		//cout << "JUST FINISHED " << list_num << endl << endl;
		list_num++;
	}
	/*for (auto x = artists_and_lists.begin(); x != artists_and_lists.end();
			x++) {
		//if (!x.empty()) {
		cout << x->first << ": ";
		x->second->print_artist_vector();
		//}
	}*/
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
			//cout << artist_name << endl;
			process_artist(artist_name, list_num);
			artist_name.clear();
		}
	}
	//catches the last artist in the list
	//cout << artist_name << endl;
	process_artist(artist_name, list_num);
	//cout << "buckets: " << artists_and_lists.bucket_count() << endl;
}

void ArtistMap::process_artist(string artist_name, int list_num)
{
	unordered_map<string, ArtistData*>::const_iterator got = 
		artists_and_lists.find(artist_name);

	if (got == artists_and_lists.end()) {
		ArtistData *artist = new ArtistData(artist_name, list_num);
		std::pair<string,ArtistData*> new_artist (artist_name, artist);
		//cout << "inserting " << artist->get_artist_name() << endl;
		artists_and_lists.insert(new_artist);
	}
	else {
		//if (artists_and_lists.bucket_size(got->first) >= 1) {
			//iterate through buckets
		//}
		//cout << "updating " << artists_and_lists[got->first]->
		//	get_artist_name() << endl;
		artists_and_lists[got->first]->update_lists_appeared_in(list_num);
	}
}

void ArtistMap::print_pairs()
{
	for (auto x = artists_and_lists.begin(); x != artists_and_lists.end();
			x++) {
		auto z = x;
		z++;
		for (auto y = z; y != artists_and_lists.end(); y++) {
			//cout << "comparing " << x->first << "to " << y->first <<
			//		endl;
			if (x->second->over_fifty_pairs(y->second->
						  get_artist_vector())) {
				cout<< "PAIR: ";
				cout << x->second->get_artist_name() << " ";
				cout << y->second->get_artist_name() << endl;
			}
		//cout << x->first << endl;
		}
	}
}

ArtistMap::~ArtistMap()
{
	artists_and_lists.clear();
}

      
