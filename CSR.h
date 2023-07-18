#pragma once
class CSR {

public:
	int getCSRID();
	char* getName();
	int getHours();
	int getComplaintsResolved();
	float getPayrate();
	float getWage();
	void setCSRID(int);
	void setName(char*);
	void setHours(int);
	void setComplaintsResolved(int);
	void calcPayrate();
	void calcWage();
	static int getTotalCpsResolved();
};

CSR getCSR_at(CSR [7], int);
void calcTotalComplaints(CSR [7]);
void calcAllEmployeeWages(CSR[7]);
void SortByHours(CSR[7]);
void SortByComplaintsRes(CSR[7]);
void SortByWages(CSR[7]);
