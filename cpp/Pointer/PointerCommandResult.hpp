#include <iostream>
#include <string>

using namespace std;

struct PointerCommandResult {
	public:
		PointerCommandResult(string message, bool success);
		string message;
		bool success;
};
