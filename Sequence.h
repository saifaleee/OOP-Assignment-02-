#pragma once
class Sequence {

public:
	Sequence();
	Sequence(int, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
	Sequence(Sequence&);
	int getLength();
	int* getSeq();
	void Sort(int);
	int RemoveDuplicates();
	void Rotate(int);
	~Sequence();
};