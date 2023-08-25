#include <iostream>
#include <string>

using namespace std;

class MyString
{
public:
	MyString() {
		str = nullptr;
		length = 0;
	}
	MyString(const char *str)
	{
		length = strlen(str);
		this->str = new char[length+1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}
	~MyString()
	{
		delete[] this->str;
	}

	MyString& operator = (const MyString& other) {
		if (this->str != nullptr) {
			delete[] str;
		}
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
		return *this;
	}

	MyString operator+(const MyString& other) {
		MyString newStr;
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);
		newStr.length = thisLength + otherLength;
		newStr.str = new char[newStr.length + 1];
		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}
		newStr.str[newStr.length] = '\0';
		return newStr;
	}

	MyString(const MyString& other) {
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	bool operator == (const MyString &other){
		if (this->length != other.length) {
			return false;
		}
		for (int i = 0; i < length; i++) {
			if (this->str[i] != other.str[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator !=(const MyString& other) {
		return !(this->operator==(other));
	}

	void Print() {
		cout << str;
	}

	int Length() {
		return length;
	}

	char &operator [](int index) {
		return this->str[index];
	}

	MyString(MyString&& other) {
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}

private:
	char* str;
	int length;
};


int main() {

	MyString str("test");
	str[0] = 'q';
	MyString str2("hello");
	MyString result = str + str2;
	result.Print();
	return 0;
}