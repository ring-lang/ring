#include "../httplib.h"
using namespace httplib;

int main(int argc, char *argv[])
{

	Server svr;

	svr.Get("/hi", [](const Request &, Response &res) {
		res.set_content("Hello World!", "text/plain");
	});

	svr.listen("0.0.0.0", 8080);
	
	return 0;
}