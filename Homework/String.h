#ifndef String_h
#define String_h
#include <ostream>
class String {
public:
	char* buffer;
	String();
	String(const char*);
	String(String&);
	String operator +(String&);
	bool operator ==(const char*);
	int length();
	void clear();
private:
	int size;
friend std::ostream& operator <<(std::ostream&, String&);
};
#endif
