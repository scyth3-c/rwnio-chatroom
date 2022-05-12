#include <iostream>
#include <seed.h>

using namespace std;

int main(int argc, char *argv[]) {

    Seed tasty("kevin");
	tasty.genSeed();
	cout<<tasty.getSeed();


	return 0;
}
