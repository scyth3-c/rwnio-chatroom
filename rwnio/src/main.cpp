#include <iostream>
#include <http.h>

using namespace std;

int main(int argc, int *argv[]) {


	HTTP http("http://example.com");
	http.get();
	cout<<http.Response();
	
	
	
	return 0;
}
