#include <iostream>
#include "room.h"

using namespace std;

int main(int argc, char *argv[])
{

	Room tasty(argc, argv);
	tasty.MainLoop();

	return 0;
}
