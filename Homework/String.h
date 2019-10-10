#ifndef String_h
#define String_h
#include <ostream>
class String {
public:
	String();
	String(const char*);
	String(const String&);
	String operator +(const String&);
	bool operator ==(const char*) const;
	int length() const;
	void clear();
private:
	char* buffer = nullptr;
	int size = 0;
friend std::ostream& operator <<(std::ostream&, const String&);
};

inline int String::length() const {
	return size;
}
#endif
