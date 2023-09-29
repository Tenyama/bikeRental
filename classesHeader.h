#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

void clearScreen();

vector<string> reverseFile(ifstream &input);

class Time {
private:
  int day;
  int month;
  int year;

public:
  Time();
  Time(int day, int month, int year);
  void setTime(int day, int month, int year);
  void show();
  string getTime();
  void setDay(int day);
  int getDay();
  void setMonth(int month);
  int getMonth();
  void setYear(int year);
  int getYear();
  friend int period(Time start, Time end);
  friend bool operator>=(Time t1, Time t2);
  friend bool operator<=(Time t1, Time t2);
  friend bool operator==(Time t1, Time t2);
  friend bool isOverlap(const Time &start1, const Time &end1,
                        const Time &start2, const Time &end2);
};

Time readTime(string strTime);

bool isOverlap(const Time &start1, const Time &end1, const Time &start2,
               const Time &end2);

class Member {
private:
  string username; // username must not contain any blank space(s)
  string password;
  string city;
  string fullName;
  string phoneNumber;
  string idType;   // citizenID or passport
  string idNumber; 
  string licenseNo;
  Time expiryDate;
  int creditPoint; // expiryDate of the driver's license
  int bikeID;
  double ratingScore;

public:
	Member();
	Member(const string &username, int bikeID, const string &fullName,
		 const string &phoneNumber, const string &idType,
		 const string &idNumber, const string &password, const string &city,
		 const string &licenseNo, Time expiryDate, int creditPoint,
		 double ratingScore);
	int getBikeID();
	string getUsername();
	string getPassword();
	string getUserInfoString();
	void topUp();
	void charge(int totalCredit);
	void showBalance();
	void searchBike();
	void listAvailableBike();
	void unlistAvailableBike();
    void unlistAvailableBike(Time start);
	void writeReviewBike();
	void writeReviewRenter();
	void requestToRent();
	void viewRequest();
	void acceptRequest();
    void cancelRequest();
	friend bool operator==(Member m1, Member m2);
	void charge (int totalCredit, Time startTime, Time endTime);
    int getCredit();
    void setCredit(int point);
	void setScore (double score);
	void viewMyInfo();
};

bool isDouble(const string& str);
Member login();
Member findMember (string usernameParam);
void save();
void view(int choice);
void updateAvg();
Member registerMember();
int main_menu();
int execMem(Member m, string choice);
int execAdmin();

class Motorbike {
private:
	int bikeID;
	string model;
	string colour;
	string city;
	int engineSize;
	int transmissionType; // Let user choose or input 1 to 3 (each number corresponding to a transmission type);
	int yearMade;
	string description;
	double requiredRenterRatingScore;
	int creditPerDay;

public:
	Motorbike();
	Motorbike(int bikeID, string model, string colour, string city,
			int engineSize, int transmissionType, int yearMade,
			string description, int creditperDay);
	int registerBike();
	int getBikeID() { return bikeID; };
	string getmodel() { return model; };
	string getcolour() { return colour; };
	string getBikeCity() { return city; };
	int getengineSize() { return engineSize; };
	int gettransmissionType() { return transmissionType; };
	int getyearMade() { return yearMade; };
	string getdescription() { return description; };
};

void viewBikeInfo();
void viewMemInfo();

int period(Time start, Time end);