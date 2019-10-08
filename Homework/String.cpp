#include"String.h"

String::String() {
	clear();
}

String::String(const char* charset) {
	size = 0;
	while (charset[size] != '\0') {
		size++;
	}
	buffer = new char[size];

	for (int j = 0; j < size; j++) {
		buffer[j] = charset[j];
	}
}

String::String(String& string) {
	size = string.length();
	buffer = new char[size];
	for (int i = 0; i < size; i++) {
		buffer[i] = string.buffer[i];
	}
}

String String::operator +(String& string) {
	int newSize = size + string.length() + 1;
	char* newBuffer = new char[newSize];
	for (unsigned j = 0; j < size; j++) {
		newBuffer[j] = buffer[j];
	}

	for (unsigned i = 0; i < string.length(); i++) {
		newBuffer[size + i] = string.buffer[i];
	}
	newBuffer[newSize - 1] = '\0';
	String aux(newBuffer);
	delete newBuffer;
	return aux;
}

bool String::operator ==(const char* charset) {
	String aux(charset);
	if (size != aux.length())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < aux.length(); i++)
		{
			if (buffer[i] != aux.buffer[i])
			{
				return false;
			}
		}
	}
	return true;
}

int String::length() {
	return size;
}
void String::clear() {
	delete buffer;
	buffer = nullptr;
	size = 0;
}

std::ostream& operator <<(std::ostream& os, String& string) {
	for (int i = 0; i < string.length(); i++)
	{
		os << string.buffer[i];
	}
	return os;
}
