#include <iostream>
#include <fstream>
#include "artistMap.h"
//#include "artist.h"

using namespace std;

int main(int argc, char* argv[])
{
	ArtistMap *artists = new ArtistMap();
	
	if (argc == 2) {
		artists->read_artist_lists(argv[1]);
		artists->print_pairs();
	}
	else {
		cerr << "Requires artist_list.txt" << endl;
	}
	return 0;
}

/*
int main()
{
	ArtistData *a1 = new ArtistData("John", 6);
	//cout << a1->get_artist_name() << endl;
	a1->update_lists_appeared_in(7);
	a1->update_lists_appeared_in(8);
	a1->update_lists_appeared_in(9);
	a1->update_lists_appeared_in(10);
	a1->update_lists_appeared_in(12);

	//vector<int> test = a1->get_artist_vector();
	//cout << test.size() << endl;
	//cout << test.back() << endl;

	ArtistData *a2 = new ArtistData("Mary", 1);
	//cout << a2->get_artist_name() << endl;
	a2->update_lists_appeared_in(2);
	a2->update_lists_appeared_in(7);
	a2->update_lists_appeared_in(8);
	a2->update_lists_appeared_in(9);
	a2->update_lists_appeared_in(10);
	a2->update_lists_appeared_in(11);

	a1->over_fifty_pairs(a2->get_artist_vector());

	return 0;
}
*/
