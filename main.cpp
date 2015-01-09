/* Naomi Zarrilli
 * January 8, 2015
 */

#include <iostream>
#include <fstream>
#include "artistMap.h"

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
	delete artists;
	return 0;
}
