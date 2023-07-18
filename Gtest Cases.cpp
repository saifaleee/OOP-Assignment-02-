#include "pch.h"
#include "cstring"
#include "Car.h"
#include "Sequence.h"
#include "Sandwich.h"
#include "CustomerAccount.h"
#include "CSR.h"
#include "Matrix.h"
#include "String.h"

//----------Question #01----------

TEST(Q1, first) {
	Car car;
	car.setPetrolLevel(25);
	car.setPetrolLevel(50);
	ASSERT_EQ(25, car.getPetrolLevel());
}

TEST(Q1, second) {
	Car car(40);
	ASSERT_EQ(false, car.isEmpty());
}

TEST(Q1, third) {
	Car car;
	car.Refill();
	ASSERT_EQ(45, car.petrolLevel);
}

TEST(Q1, fourth) {
	Car car;
	car.Refill();
	ASSERT_EQ(false, car.MoveCar(50));
	ASSERT_EQ(true, car.MoveCar(33));
	ASSERT_EQ(12, car.petrolLevel);
}



//----------Question #02----------

TEST(Q2, first) {
	Sequence sequence;
	ASSERT_EQ(10, sequence.getLength());

	int* pseq = sequence.getSeq();
	for (int i = 0; i < 10; i++)
		ASSERT_EQ(0, *(pseq + i));

	Sequence sequence1(5, 20, 30, 40, 50, 60);
	int* pseq1 = sequence1.getSeq();
	ASSERT_EQ(5, sequence1.getLength());
	ASSERT_EQ(20, *pseq1);
	ASSERT_EQ(40, *(pseq1 + 2));
	ASSERT_EQ(60, *(pseq1 + 4));
}

TEST(Q2, second) {
	Sequence sequence1(5, 20, 30, 40, 50, 60);
	int* pseq1 = sequence1.getSeq();

	Sequence sequence2(sequence1);
	int* pseq2 = sequence2.getSeq();
	ASSERT_NE(pseq2, pseq1);
	ASSERT_EQ(5, sequence2.getLength());
	ASSERT_EQ(30, *(pseq2 + 1));
	ASSERT_EQ(50, *(pseq2 + 3));
}

TEST(Q2, third) {
	Sequence sequence(10, 8, 3, 2, 5, 6, 9, 3, 1, 10, 8);

	sequence.Sort(5);
	int* pseq = sequence.getSeq();
	ASSERT_EQ(2, *pseq);
	ASSERT_EQ(3, *(pseq + 1));
	ASSERT_EQ(6, *(pseq + 3));
	ASSERT_EQ(8, *(pseq + 4));
	ASSERT_EQ(10, *(pseq + 8));
	ASSERT_EQ(3, *(pseq + 6));
}

TEST(Q2, fourth) {
	Sequence sequence(8, 5, 5, 3, 9, 3, 5, 3, 9);

	ASSERT_EQ(3, sequence.RemoveDuplicates());
	int* pseq = sequence.getSeq();
	ASSERT_EQ(3, *pseq);
	ASSERT_EQ(5, *(pseq + 1));
	ASSERT_EQ(9, *(pseq + 2));
}

TEST(Q2, fifth) {
	Sequence sequence(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	sequence.Rotate(4);
	int* pseq = sequence.getSeq();
	ASSERT_EQ(7, *pseq);
	ASSERT_EQ(8, *(pseq + 1));
	ASSERT_EQ(9, *(pseq + 2));
	ASSERT_EQ(10, *(pseq + 3));
	ASSERT_EQ(1, *(pseq + 4));
	ASSERT_EQ(2, *(pseq + 5));
	ASSERT_EQ(5, *(pseq + 8));
	ASSERT_EQ(6, *(pseq + 9));
}



//----------Question #03----------

TEST(Q3, first) {
	Sandwich S;

	ASSERT_EQ(NULL, S.getName());
	ASSERT_EQ(NULL, S.getFilling());
	ASSERT_EQ(NULL, S.getSize());
	ASSERT_EQ(0.0, S.getPrice());
	ASSERT_FALSE(S.check_status());

	Sandwich S2(new char[] {"Sauce"}, 800);
	S2.setName(new char[] {"Zinger"});
	S2.setSize(new char[] {"medium"});

	ASSERT_EQ(0, strcmp("Zinger", S2.getName()));
	ASSERT_EQ(0, strcmp("Sauce", S2.getFilling()));
	ASSERT_EQ(0, strcmp("medium", S2.getSize()));
	ASSERT_EQ(800.0, S2.getPrice());
}

TEST(Q3, second) {
	Sandwich S(new char[]{"Sauce"}, 1000, new char[] {"Zinger"},
		new char[]{"large"}, true);

	ASSERT_EQ(0, strcmp("Zinger", S.getName()));
	ASSERT_EQ(0, strcmp("Sauce", S.getFilling()));
	ASSERT_EQ(0, strcmp("large", S.getSize()));
	ASSERT_EQ(1000.0, S.getPrice());
	ASSERT_TRUE(S.check_status());

	Sandwich S2(S);

	S2.setFilling(new char[] {"Mayonnaise"});

	ASSERT_EQ(0, strcmp("Zinger", S2.getName()));
	ASSERT_EQ(0, strcmp("Mayonnaise", S2.getFilling()));
	ASSERT_EQ(0, strcmp("large", S2.getSize()));
	ASSERT_EQ(1000.0, S2.getPrice());
	ASSERT_TRUE(S2.check_status());

	ASSERT_EQ(0, strcmp("Sauce", S.getFilling()));
}

TEST(Q3, third) {
	Sandwich S;
	S.setName(new char[] {"zinger"});
	S.setFilling(new char[] {"sauce"});
	S.setSize(new char[] {"big"});
	S.setPrice(1200);

	//because size can only be small, medium or large
	ASSERT_EQ(NULL, S.getSize());

	S.setSize(new char[] {"large"});

	ASSERT_FALSE(S.check_status());

	S.makeSandwich();

	ASSERT_EQ(0, strcmp("zinger", S.getName()));
	ASSERT_EQ(0, strcmp("sauce", S.getFilling()));
	ASSERT_EQ(0, strcmp("large", S.getSize()));
	ASSERT_EQ(1200.0, S.getPrice());
	ASSERT_TRUE(S.check_status());
}



//----------Question #04----------

TEST(Q4, first) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "FAST-NU";
	char address[] = "H-11";
	char city[] = "Islamabad";
	char state[] = "Pakistan";

	OpenCustomerAccount(customers, accountsOpen, name, address, city, state, 44000,
		33333333333333, 850000);

	ASSERT_EQ(0, strcmp("FAST-NU", customers[0]->name));
	ASSERT_EQ(0, strcmp("H-11", customers[0]->address.address));
	ASSERT_EQ(0, strcmp("Islamabad", customers[0]->address.city));
	ASSERT_EQ(0, strcmp("Pakistan", customers[0]->address.state));
	ASSERT_EQ(44000, customers[0]->address.zip_code);
	ASSERT_EQ(33333333333333, customers[0]->phoneNum);
	ASSERT_EQ(850000, customers[0]->balance);
}

TEST(Q4, second) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "FAST-NU";
	char address[] = "H-11";
	char city[] = "Islamabad";
	char state[] = "Pakistan";

	OpenCustomerAccount(customers, accountsOpen, name, address, city,
		state, 44000, 33333333333333, 850000);

	ASSERT_EQ(850000, customers[0]->balance);

	char account[] = "PK001";
	ASSERT_EQ(0, SearchCustomer(customers, accountsOpen, account));

	OpenCustomerAccount(customers, accountsOpen, new char[]{"FAST-NU1"},
		address, city, state, 44100, 33333333333344, 950000);

	int index = SearchCustomer(customers, accountsOpen, new char[] {"PK002"});

	ASSERT_EQ(0, strcmp("FAST-NU1", customers[index]->name));
	ASSERT_EQ(950000, customers[index]->balance);
	ASSERT_EQ(44100, customers[index]->address.zip_code);

	char fakeaccount[] = "PK101";
	ASSERT_EQ(-1, SearchCustomer(customers, accountsOpen, fakeaccount));
}

TEST(Q4, third) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "FAST-NU";
	char address[] = "H-11";
	char city[] = "Islamabad";
	char state[] = "Pakistan";

	for (int i = 0; i < 500; i++)
		OpenCustomerAccount(customers, accountsOpen, name, address, city, state, 44000,
			33333333333333, 850000);

	ASSERT_EQ(-1, SearchCustomer(customers, accountsOpen, new char[] {"PK449"}));
	ASSERT_LT(-1, SearchCustomer(customers, accountsOpen, new char[] {"PK001"}));
}

TEST(Q4, fourth) {
	CustomerAccount* customers[100];
	int accountsOpen = 0;

	char name[] = "FAST-NU";
	char address[] = "H-11";
	char city[] = "Islamabad";
	char state[] = "Pakistan";

	OpenCustomerAccount(customers, accountsOpen, name, address, city, state, 44000,
		33333333333333, 850000);

	OpenCustomerAccount(customers, accountsOpen, new char[] {"FAST-NU1"},
		address, city, state, 44100, 33333333333344, 850000);

	char account[] = "PK001";
	char fakeaccount[] = "PK500";
	ASSERT_EQ(true, UpdateCustomerAccount(customers, accountsOpen, account, 55555555555555));
	ASSERT_EQ(false, UpdateCustomerAccount(customers, accountsOpen, fakeaccount, 55555555555555));

	ASSERT_EQ(true, UpdateCustomerAccount(customers, accountsOpen, account, static_cast<float>(550000)));
	ASSERT_EQ(false, UpdateCustomerAccount(customers, accountsOpen, fakeaccount, static_cast<float>(550000)));

	Address add;
	add.address = new char[] { "NUCES" };
	add.city = new char[] { "Karachi" };
	add.state = new char [] { "Pakistan" };
	add.zip_code = 75600;

	ASSERT_EQ(true, UpdateCustomerAccount(customers, accountsOpen, new char[]{"PK002"}, add));
	ASSERT_EQ(false, UpdateCustomerAccount(customers, accountsOpen, fakeaccount, add));
}


//----------Question #05----------

TEST(Q5, first) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		employees[i].setCSRID(i + 1);
		employees[i].setName(new char[] {'E', 'M', 'P', char(i + 49), '\0'});
		employees[i].setHours((i + 1) * 5);
		employees[i].setComplaintsResolved((i + 1) * 2);
	}

	employees[0].setCSRID(-5);
	employees[2].setHours(-8);
	employees[4].setComplaintsResolved(-100);

	for (int i = 0; i < 7; i++)
	{
		ASSERT_EQ(i+1, employees[i].getCSRID());
		char name[] = { 'E', 'M', 'P', char(i + 49), '\0' };
		ASSERT_EQ(0, strcmp(name, employees[i].getName()));
		ASSERT_EQ((i + 1) * 5, employees[i].getHours());
		ASSERT_EQ((i + 1) * 2, employees[i].getComplaintsResolved());
	}
}

TEST(Q5, second) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		employees[i].setCSRID(i + 1);
		employees[i].setName(new char[] {'E', 'M', 'P', char(i + 49), '\0'});
		employees[i].setHours((i + 1) * 5);
		employees[i].setComplaintsResolved((i + 1) * 2);
	}

	ASSERT_EQ(employees[3].getCSRID(), getCSR_at(employees, 3).getCSRID());
	ASSERT_EQ(0, strcmp(employees[2].getName(), getCSR_at(employees, 2).getName()));

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	ASSERT_EQ(56, CSR::getTotalCpsResolved());

	ASSERT_EQ(28, static_cast<int>(employees[3].getPayrate()));
	ASSERT_EQ(30, static_cast<int>(employees[5].getPayrate()));
	ASSERT_EQ(26, static_cast<int>(employees[1].getPayrate()));

	ASSERT_EQ(415, static_cast<int>(employees[2].getWage()));
	ASSERT_EQ(736, static_cast<int>(employees[4].getWage()));
	ASSERT_EQ(1093, static_cast<int>(employees[6].getWage()));
}

TEST(Q5, third) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		employees[i].setCSRID(i + 1);
		employees[i].setName(new char[] {'E', 'M', 'P', char(i + 49), '\0'});
		employees[i].setHours((i + 1) * 5);
		employees[i].setComplaintsResolved((i + 1) * 2);
	}

	employees[3].setHours(45);
	employees[5].setHours(90);

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	SortByHours(employees);

	ASSERT_EQ(6, employees[0].getCSRID());
	ASSERT_EQ(4, employees[1].getCSRID());
	ASSERT_EQ(7, employees[2].getCSRID());
	ASSERT_EQ(3, employees[4].getCSRID());
	ASSERT_EQ(1, employees[6].getCSRID());

	ASSERT_EQ(90, employees[0].getHours());
	ASSERT_EQ(45, employees[1].getHours());
	ASSERT_EQ(35, employees[2].getHours());
	ASSERT_EQ(15, employees[4].getHours());
	ASSERT_EQ(5, employees[6].getHours());
}

TEST(Q5, fourth) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		employees[i].setCSRID(i + 1);
		employees[i].setName(new char[] {'E', 'M', 'P', char(i + 49), '\0'});
		employees[i].setHours((i + 1) * 5);
		employees[i].setComplaintsResolved((i + 1) * 2);
	}

	employees[3].setComplaintsResolved(145);
	employees[5].setComplaintsResolved(90);

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	SortByComplaintsRes(employees);

	ASSERT_EQ(4, employees[0].getCSRID());
	ASSERT_EQ(6, employees[1].getCSRID());
	ASSERT_EQ(7, employees[2].getCSRID());
	ASSERT_EQ(3, employees[4].getCSRID());
	ASSERT_EQ(1, employees[6].getCSRID());

	ASSERT_EQ(145, employees[0].getComplaintsResolved());
	ASSERT_EQ(90, employees[1].getComplaintsResolved());
	ASSERT_EQ(14, employees[2].getComplaintsResolved());
	ASSERT_EQ(6, employees[4].getComplaintsResolved());
	ASSERT_EQ(2, employees[6].getComplaintsResolved());
}

TEST(Q5, fifth) {
	CSR employees[7];

	for (int i = 0; i < 7; i++)
	{
		employees[i].setCSRID(i + 1);
		employees[i].setName(new char[] {'E', 'M', 'P', char(i + 49), '\0'});
		employees[i].setHours((i + 1) * 3);
		employees[i].setComplaintsResolved((i + 1) * 5);
	}

	employees[2].setHours(45);
	employees[4].setHours(90);
	employees[0].setHours(25);
	employees[3].setHours(70);
	employees[3].setComplaintsResolved(145);
	employees[5].setComplaintsResolved(90);
	employees[1].setComplaintsResolved(5);

	calcTotalComplaints(employees);
	calcAllEmployeeWages(employees);

	SortByComplaintsRes(employees);

	ASSERT_EQ(4, employees[0].getCSRID());
	ASSERT_EQ(6, employees[1].getCSRID());
	ASSERT_EQ(7, employees[2].getCSRID());
	ASSERT_EQ(5, employees[3].getCSRID());
	ASSERT_EQ(2, employees[6].getCSRID());

	ASSERT_EQ(2542, static_cast<int>(employees[0].getWage()));
	ASSERT_EQ(576, static_cast<int>(employees[1].getWage()));
	ASSERT_EQ(582, static_cast<int>(employees[2].getWage()));
	ASSERT_EQ(1177, static_cast<int>(employees[4].getWage()));
	ASSERT_EQ(152, static_cast<int>(employees[6].getWage()));
}



//----------Question #06----------

TEST(Q6, first) {
	String str(new char[] {"OOP-A02"});
	ASSERT_EQ(0, strcmp("OOP-A02", str.getdata()));

	String str1(5);
	ASSERT_EQ(5, str1.strLength());
	ASSERT_EQ(0, strcmp("", str1.getdata()));

	String str2(str);
	ASSERT_EQ(0, strcmp(str2.getdata(), str.getdata()));
	ASSERT_NE(str2.getdata(), str.getdata());
}

TEST(Q6, second) {
	String str(new char[] {"OOP-A02"});
	ASSERT_EQ(7, str.strLength());
	ASSERT_EQ(false, str.empty());
	str.clear();
	ASSERT_EQ(0, str.strLength());
	ASSERT_EQ(true, str.empty());
}

TEST(Q6, third) {
	String str(new char[] {"OOP-Assignment02"});
	ASSERT_EQ(0, str.charAt('O'));
	ASSERT_EQ(2, str.charAt('P'));
	ASSERT_EQ(5, str.charAt('s'));
	ASSERT_EQ(14, str.charAt('0'));

	String str1(new char[] {"Spring 2022"});
	ASSERT_EQ(3, str1.charAt('i'));
	ASSERT_EQ(1, str1.charAt('p'));
	ASSERT_EQ(5, str1.charAt('g'));
	ASSERT_EQ(6, str1.charAt(' '));
	ASSERT_EQ(7, str1.charAt('2'));
	ASSERT_EQ(8, str1.charAt('0'));
}

TEST(Q6, fouth) {
	String str(new char[] {"OOP-Assignment02"});
	ASSERT_EQ(false, str.equals(new char[] {"OOP"}));
	ASSERT_EQ(false, str.equals(new char[] {"Assignment02"}));
	ASSERT_EQ(false, str.equals(new char[] {"oop assignment02"}));
	ASSERT_EQ(true, str.equals(new char[] {"OOP-Assignment02"}));

	String str1(new char[] {"Spring 2022"});
	ASSERT_EQ(false, str1.equals(new char[] {"spring 2022"}));
	ASSERT_EQ(false, str1.equals(new char[] {"sprIng 2021"}));
	ASSERT_EQ(true, str1.equals(new char[] {"Spring 2022"}));
}

TEST(Q6, fifth) {
	String str(new char[] {"Awesome"});
	ASSERT_EQ(true, str.equalsIgnoreCase(new char[] {"awesome"}));
	ASSERT_EQ(true, str.equalsIgnoreCase(new char[] {"aweSoMe"}));
	ASSERT_EQ(false, str.equalsIgnoreCase(new char[] {"aews"}));
	ASSERT_EQ(true, str.equalsIgnoreCase(new char[] {"AWESOME"}));
}

TEST(Q6, sixth) {
	String str1(new char[] {"OOP-Assignment02"});
	ASSERT_EQ(false, str1.equalsIgnoreCase(new char[] {"oop assignment02"}));
	ASSERT_EQ(true, str1.equalsIgnoreCase(new char[] {"oop-assignment02"}));
	ASSERT_EQ(true, str1.equalsIgnoreCase(new char[] {"oOp-asSignMent02"}));
	ASSERT_EQ(false, str1.equalsIgnoreCase(new char[] {"OOP-AssignmentO2"}));

	String str2(new char[] {"SpriNg 2022"});
	ASSERT_EQ(true, str2.equalsIgnoreCase(new char[] {"spring 2022"}));
	ASSERT_EQ(false, str2.equalsIgnoreCase(new char[] {"sprIng 2021"}));
	ASSERT_EQ(false, str2.equalsIgnoreCase(new char[] {"SprIng 2O22"}));
	ASSERT_EQ(true, str2.equalsIgnoreCase(new char[] {"SPRING 2022"}));
}
TEST(Q6, seventh) {
	String str(new char[] {"OOP-Assignment02"});
	ASSERT_EQ(0, strcmp(str.substring(new char[] {"Ass"}, 2), "Assignment02"));
	ASSERT_EQ(NULL, str.substring(new char[] {"Ass"}, 5));
	ASSERT_EQ(0, strcmp(str.substring(new char[] {"nm"}, 2), "nment02"));
	ASSERT_EQ(0, strcmp(str.substring(new char[] {"-"}, 2), "-Assignment02"));
}

TEST(Q6, eighth) {
	String str(new char[] {"SpriNg 2022"});
	char* originalString = str.getdata();
	char* subString = str.substring(new char[] {"iN"}, 2);

	ASSERT_EQ(0, strcmp(subString, "iNg 2022"));
	ASSERT_NE(originalString + 3, subString);
}

TEST(Q6, ninth) {
	String str(new char[] {"OOP-Assignment02"});
	ASSERT_EQ(0, strcmp(str.substring(new char[] {"Ass"}, 2, 10), "Assignm"));
	ASSERT_EQ(NULL, str.substring(new char[] {"Ass"}, 5, 4));
	ASSERT_EQ(0, strcmp(str.substring(new char[] {"-"}, 2, 9), "-Assign"));
	ASSERT_EQ(0, strcmp(str.substring(new char[] {"A"}, 2, 30), "Assignment02"));
}

TEST(Q6, tenth) {
	String str(new char[] {"SpriNg 2022"});
	char* originalString = str.getdata();
	char* subString = str.substring(new char[] {"iN"}, 2, 8);

	ASSERT_EQ(0, strcmp(subString, "iNg 20"));
	ASSERT_NE(originalString + 3, subString);
}



//----------Question #07----------

TEST(Q7, first) {
	Matrix M(3, 4, 5, 6);

	ASSERT_EQ(2, M.getRow());
	ASSERT_EQ(2, M.getCol());

	ASSERT_EQ(3, M.getValue(0, 0));
	ASSERT_EQ(4, M.getValue(0, 1));
	ASSERT_EQ(5, M.getValue(1, 0));
	ASSERT_EQ(6, M.getValue(1, 1));
}

TEST(Q7, second) {
	Matrix M(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16


	ASSERT_EQ(4, M.getRow());
	ASSERT_EQ(4, M.getCol());

	ASSERT_EQ(4, M.getValue(0, 3));
	ASSERT_EQ(6, M.getValue(1, 1));
	ASSERT_EQ(11, M.getValue(2, 2));
	ASSERT_EQ(13, M.getValue(3, 0));
}

TEST(Q7, third) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	M2.setValue(1, 1, 60);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(6, M1.getValue(1, 1));
	ASSERT_EQ(60, M2.getValue(1, 1));
}

TEST(Q7, fourth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(136, M1.Total());
	ASSERT_EQ(8.5, M1.Average());
}

TEST(Q7, fifth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	M2.setValue(2, 1, 60);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(42, M1.RowTotal(2));
	ASSERT_EQ(92, M2.RowTotal(2));
}

TEST(Q7, sixth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	M2.setValue(1, 2, 60);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(32, M1.ColumnTotal(1));
	ASSERT_EQ(89, M2.ColumnTotal(2));
}

TEST(Q7, seventh) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	M2.setValue(2, 1, 60);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(12, M1.HighestInRow(2));
	ASSERT_EQ(60, M2.HighestInRow(2));
}

TEST(Q7, eighth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	M2.setValue(0, 1, 0);
	M1.setValue(3, 2, 5);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(0, M2.LowestInRow(0));
	ASSERT_EQ(5, M1.LowestInRow(3));
}

TEST(Q7, ninth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2 = M1.Transpose();
	//M1			 //M2
	// 1  2  3  4    1  5  9  13
	// 5  6  7  8    2	6  10 14
	// 9  10 11 12   3  7  11 15
	// 13 14 15 16   4  8  12 16

	ASSERT_EQ(2, M2.getValue(1, 0));
	ASSERT_EQ(15, M2.getValue(2, 3));
	ASSERT_EQ(7, M2.getValue(2, 1));
	ASSERT_EQ(8, M2.getValue(3, 1));
	ASSERT_EQ(10, M2.getValue(1, 2));
	ASSERT_EQ(9, M2.getValue(0, 2));
}

TEST(Q7, tenth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(34, M1.LeftDiagonalTotal());

	M1.setValue(2, 2, 34);

	ASSERT_EQ(57, M1.LeftDiagonalTotal());
}

TEST(Q7, eleventh) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	// 1  2  3  4
	// 5  6  7  8
	// 9  10 11 12
	// 13 14 15 16

	ASSERT_EQ(34, M1.RightDiagonalTotal());

	M1.setValue(1, 2, 34);

	ASSERT_EQ(61, M1.RightDiagonalTotal());
}

TEST(Q7, twelfth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	Matrix M3 = M1.Add(M2);
	// M1			M3
	// 1  2  3  4   2  4  6  8
	// 5  6  7  8	10 12 14 16
	// 9  10 11 12  18 20 22 24
	// 13 14 15 16  26 28 30 32

	ASSERT_EQ(12, M3.getValue(1, 1));
	ASSERT_EQ(8, M3.getValue(0, 3));
	ASSERT_EQ(28, M3.getValue(3, 1));
	ASSERT_EQ(18, M3.getValue(2, 0));
}

TEST(Q7, thirteenth) {
	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	Matrix M2(M1);
	M2.setValue(0, 0, 2);
	M2.setValue(1, 1, 8);
	M2.setValue(2, 2, 14);
	M2.setValue(3, 3, 20);

	Matrix M3 = M2.Subtract(M1);
	 //M1			//M3
	 //1  2  3  4   1  0  0  0
	 //5  6  7  8	0  2  0  0
	 //9  10 11 12  0  0  3  0
	 //13 14 15 16  0  0  0  4

	ASSERT_EQ(0, M3.getValue(0, 1));
	ASSERT_EQ(2, M3.getValue(1, 1));
	ASSERT_EQ(4, M3.getValue(3, 3));
	ASSERT_EQ(0, M3.getValue(2, 3));
}

TEST(Q7, fourteenth) {
	Matrix M(2, 3, 4, 5, 6, 7, 8, 9, 10);

	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	Matrix FM = M.Multiply(M1);

	ASSERT_EQ(0, FM.getCol());
	ASSERT_EQ(0, FM.getRow());

	Matrix N(6, 7, 8, 9, 10, 11, 12, 13, 14);

	Matrix X = M.Multiply(N);

  /* 2  3  4       6  7  8        87  96  105
	 5  6  7   *   9  10 11   =   168 186 204
	 8  9  10      12 13 14		  249 276 303		*/

	ASSERT_EQ(87, X.getValue(0, 0));
	ASSERT_EQ(96, X.getValue(0, 1));
	ASSERT_EQ(105, X.getValue(0, 2));
	ASSERT_EQ(168, X.getValue(1, 0));
	ASSERT_EQ(186, X.getValue(1, 1));
	ASSERT_EQ(204, X.getValue(1, 2));
	ASSERT_EQ(249, X.getValue(2, 0));
	ASSERT_EQ(276, X.getValue(2, 1));
	ASSERT_EQ(303, X.getValue(2, 2));
}

TEST(Q7, fifteenth) {
    Matrix X(9, 2, 3, 0, -5, 2, 3, 4, 100); 

    ASSERT_EQ(-5, X.FindkSmallest(1));
    ASSERT_EQ(2, X.FindkSmallest(3));
    ASSERT_EQ(3, X.FindkSmallest(4));
    ASSERT_EQ(100, X.FindkSmallest(7));

    // return largest value if k is greater than the indexes of the matrix 
    // or due to duplicates in matrix, k becomes greater than all the unique values

    // return 0 if k is less than 1

    ASSERT_EQ(100, X.FindkSmallest(9));
    ASSERT_EQ(100, X.FindkSmallest(12));
    ASSERT_EQ(0, X.FindkSmallest(0));
}

TEST(Q7, sixteenth) {
    Matrix X(9, 2, 3, 0, -5, 2, 3, 4, 100);

    ASSERT_EQ(100, X.FindkLargest(1));
    ASSERT_EQ(-5, X.FindkLargest(7));
    ASSERT_EQ(3, X.FindkLargest(4));
    ASSERT_EQ(4, X.FindkLargest(3));
    ASSERT_EQ(0, X.FindkLargest(6));

    // return smallest value if k is greater than the indexes of the matrix 
    // or due to duplicates in matrix, k becomes greater than all the unique values

    // return 0 if k is less than 1

    ASSERT_EQ(-5, X.FindkLargest(9));
    ASSERT_EQ(-5, X.FindkLargest(12));
    ASSERT_EQ(0, X.FindkLargest(0));
}

TEST(Q7, seventeenth) {
	Matrix M(2, 3, 4, 5, 6, 7, 8, 9, 10);

	Matrix M1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

	Matrix FM = M.merge(M1);

	ASSERT_EQ(0, FM.getCol());
	ASSERT_EQ(0, FM.getRow());

	Matrix N(6, 7, 8, 9, 10, 11, 12, 13, 14);

	Matrix X = M.merge(N);


  /* 2  3  4           6  7  8        2  3  4  6  7  8
	 5  6  7   merge   9  10 11   =   5  6  7  9  10 11
	 8  9  10          12 13 14		  8  9  10 12 13 14  */

	ASSERT_EQ(6, X.getValue(1, 1));
	ASSERT_EQ(10, X.getValue(2, 2));
	ASSERT_EQ(9, X.getValue(1, 3));
	ASSERT_EQ(12, X.getValue(2, 3));
	ASSERT_EQ(7, X.getValue(0, 4));
	ASSERT_EQ(11, X.getValue(1, 5));
	ASSERT_EQ(6, X.getValue(0, 3));
	ASSERT_EQ(10, X.getValue(1, 4));
}
