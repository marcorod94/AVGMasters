#include"String.h"

String::String() {}

String::String(const char* charset) {
	while (charset[size] != '\0') {
		++size;
	}
	buffer = new char[size];

	for (int j = 0; j < size; ++j) {
		buffer[j] = charset[j];
	}
}

String::String(const String& string) {
	size = string.size;
	buffer = new char[size];
	for (int i = 0; i < size; ++i) {
		buffer[i] = string.buffer[i];
	}
}

String String::operator +(const String& string) {
	int newSize = size + string.size + 1;
	char* newBuffer = new char[newSize];
	for (unsigned j = 0; j < size; ++j) {
		newBuffer[j] = buffer[j];
	}

	for (unsigned i = 0; i < string.size; ++i) {
		newBuffer[size + i] = string.buffer[i];
	}
	newBuffer[newSize - 1] = '\0';
	String aux(newBuffer);
	delete newBuffer;
	return aux;
}

bool String::operator ==(const char* charset) const {
	String aux(charset);
	if (size != aux.size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < aux.size; ++i)
		{
			if (buffer[i] != aux.buffer[i])
			{
				return false;
			}
		}
	}
	return true;
}

void String::clear() {
	delete buffer;
	buffer = nullptr;
	size = 0;
}

std::ostream& operator <<(std::ostream& os, const String& string) {
	for (int i = 0; i < string.size; ++i)
	{
		os << string.buffer[i];
	}
	return os;
}
