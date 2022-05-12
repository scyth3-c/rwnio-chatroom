#include <iostream>
#include <http.h>


using namespace std;

int main(int argc, char *argv[]) {

	HTTP tasty("http://example.com/");

    tasty.get();
    
	cout<<tasty.genPerfomList();

	return 0;
}
