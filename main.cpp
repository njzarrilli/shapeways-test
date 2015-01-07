#include <iostream>
#include <fstream>
#include "artistsList.h"

using namespace std;

int main()
{
	ifstream in(filename);
	string list_artists;
	int lists_count = 0;

	while (! in.eof() ) {
		getline(in, list_artists);
		if (in.fail()) break;
		process_list(list_artists, lists_count);
		lists_count++;
	}
	return 0;
}
