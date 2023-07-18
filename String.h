#pragma once
class String {

public:
	String();
	String(int);
	String(char*);
	String(const String&);
	~String();
	int strLength();
	void clear();
	bool empty();
	char* getdata();
	int charAt(char);
	bool equals(char*);
	bool equalsIgnoreCase(char*);
	char* substring(char*, int);
	char* substring(char*, int, int);
	void print();

};
