    #include "classesHeader.h"
#include "colors.h"
#include <chrono>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <conio.h>
#define divider() cout << "============================================\n" << NORMAL
#define print(x) cout << x << endl
#define header() cout <<"EEET2482/COSC2082 ASSIGNMENT\nMOTORBIKE RENTAL APPLICATION\n\nInstructor: Dr. Ling Huo Chong\nGroup: Group 12\ns3977994, Do Le Trang Hanh\ns3979391, Nguyen Minh Quan\ns3977955, Le Thien Son\ns3979542, Le Huu Toan\n"

using namespace std;

string adminUsn = "admin";
string adminPwd = "admin";  

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

Time::Time() {
  this->day = 0;
  this->month = 0;
  this->year = 0;
}

Time::Time(int day, int month, int year) : day(day), month(month), year(year) {}

void Time::setTime(int day, int month, int year) {
  this->day = day;
  this->month = month;
  this->year = year;
}

void Time::show() {
  string day = to_string(this->day);
  string month = to_string(this->month);
  string year = to_string(this->year);
  if (day.length() == 1) {
    day = "0" + day;
  }
  if (month.length() == 1) {
    month = "0" + month;
  }
  cout << day + "/" + month + "/" + year << endl;
}

string Time::getTime() {
  string day = to_string(this->day);
  string month = to_string(this->month);
  string year = to_string(this->year);
  if (day.length() == 1) {
    day = "0" + day;
  }
  if (month.length() == 1) {
    month = "0" + month;
  }
  return day + "/" + month + "/" + year;
}

void Time::setDay(int day) { this->day = day; }

int Time::getDay() { return this->day; }

void Time::setMonth(int month) { this->month = month; }

int Time::getMonth() { return this->month; }

void Time::setYear(int year) { this->year = year; }

int Time::getYear() { return this->year; }

bool operator>=(Time t1, Time t2) {
  bool isEqualOrGreater = false;
  if (t1.year >= t2.year) {
    if (t1.month >= t2.month) {
      if (t1.day >= t2.day) {
        isEqualOrGreater = true;
        return isEqualOrGreater;
      }
    }
  }
  return isEqualOrGreater;
}

bool operator<=(Time t1, Time t2) {
  bool isEqualOrSmaller = false;
  if (t1.year <= t2.year) {
    if (t1.month <= t2.month) {
      if (t1.day <= t2.day) {
        isEqualOrSmaller = true;
        return isEqualOrSmaller;
      }
    }
  }
  return isEqualOrSmaller;
}

bool operator==(Time t1, Time t2) {
  bool isEqual = false;
  if (t1.year == t2.year) {
    if (t1.month == t2.month) {
      if (t1.day == t2.day) {
        isEqual = true;
        return isEqual;
      }
    }
  }
  return isEqual;
}

bool isOverlap(const Time &start1, const Time &end1, const Time &start2,
               const Time &end2) {
  return start1.year <= end2.year && start2.year <= end1.year &&
         start1.month <= end2.month && start2.month <= end1.month &&
         start1.day <= end2.day && start2.day <= end1.day;
  // check if the 2 date ranges are overlapped
}

int period(Time start, Time end) {
  int totDayStart = start.day + 1, totDayEnd = end.day + 1;
  for (int i = 1; i <= start.month; i++) {
    if (i == 2) {
      totDayStart += 28;
    } else if ((i % 2 == 1 && i < 9) || (i % 2 == 0 && i >= 8)) {
      // odd months from Jan -> Jul and even months from Aug -> Dec have 31 days
      totDayStart += 31;
    } else if ((i % 2 == 0 && i < 8) || (i % 2 == 1 && i >= 8)) {
      totDayStart += 30;
    }
  }
  for (int i = 1; i <= end.month; i++) {
    if (i == 2) {
      totDayEnd += 28;
    } else if ((i % 2 == 1 && i < 9) || (i % 2 == 0 && i >= 8)) {
      totDayEnd += 31;
    } else if ((i % 2 == 0 && i < 8) || (i % 2 == 1 && i >= 8)) {
      totDayEnd += 30;
    }
  }
  return totDayEnd - totDayStart + (start.year - end.year) * 365;
}

Time readTime(string strTime) {
  int day, month, year;
  day = stoi(strTime.substr(0, 2));
  month = stoi(strTime.substr(3, 2));
  year = stoi(strTime.substr(6, 4));
  Time t;
  t.setTime(day, month, year);
  return t;
}

// Hanh (class Member)
Member::Member() {
  this->username = "";
  this->password = "";
  this->bikeID = 0;
  this->city = "";
  this->fullName = "";
  this->phoneNumber = "";
  this->idType = "";
  this->idNumber = "";
  this->licenseNo = "";
  this->creditPoint = 0;
  this->ratingScore = 0;
};

Member::Member(const string &username, int bikeID, const string &fullName,
               const string &phoneNumber, const string &idType,
               const string &idNumber, const string &password,
               const string &city, const string &licenseNo, Time expiryDate,
               int creditPoint, double ratingScore) {
  this->username = username;
  this->fullName = fullName;
  this->bikeID = bikeID;
  this->phoneNumber = phoneNumber;
  this->idType = idType;
  this->licenseNo = licenseNo;
  this->expiryDate = expiryDate;
  this->creditPoint = creditPoint;
  this->city = city;
  this->idNumber = idNumber;
  this->password = password;
  this->ratingScore = ratingScore;
  this->bikeID = bikeID;
}

void Member::viewMyInfo() {
  cout << "Username: " << this->username << endl;
  cout << "Full name: " << this->fullName << endl;
  cout << "Phone number: " << this->phoneNumber << endl;
  cout << "City: " << this->city << endl;
  cout << "ID Type: " << this->idType << endl;
  cout << "ID number: " << this->idNumber << endl;
  cout << "Phone number: " << this->phoneNumber << endl;
  cout << "License number: " << this->licenseNo << endl;
  cout << "License's expiry date: " << this->expiryDate.getTime() << endl;
  cout << "Credit point: " << this->creditPoint << endl;
  cout << "Your score: " << this->ratingScore << endl;
}

bool operator==(Member m1, Member m2) {
  bool isEqual = false;
  if (m1.username == m2.username) {
    isEqual = true;
    return isEqual;
  } else {
    return isEqual;
  }
}

void Member::setScore (double score) {
	this->ratingScore = score;
}


void Member::topUp() {
  cout << "TOP UP" << endl;
  cout << "Logging in one more time is required." << endl;
  int currentCredit;
  string oldCredit;
  fstream records;
  string enteredUsername, enteredPassword, username, password;
  bool loginSuccessful = false;
  cout << "LOGIN PAGE" << endl;
  cout << "\tEnter your username: ";
  cin >> enteredUsername;
  cout << "\tEnter your password: ";
  cin >> enteredPassword;
  records.open("records.txt", ios::in);
  if (!records.is_open()) {
    warning("System has failed to check member's information.");
    return;
  } else {
    string tempLine;
    int position;
    while (getline(records, tempLine)) {
      position = tempLine.find('|');
      username = tempLine.substr(0, position);
      tempLine.erase(0, position + 1);
      position = tempLine.find('|');
      password = tempLine.substr(0, position);
      if (username == enteredUsername && password == enteredPassword) {
        loginSuccessful = true;
        position = tempLine.find("|Creditpoint:") + 13;
        currentCredit = stoi(tempLine.substr(position, 2));
        oldCredit = tempLine.substr(position, 2);
        break;
      }
    }
    records.close();
    if (loginSuccessful) {
      clearScreen();
      cout << GREEN << "Logged in successfully!" << NORMAL << endl;
      cout << "Your balance: " << currentCredit << endl;
      cout << "Enter top up point: ";
      int point;
      cin >> point;
      currentCredit += point;
      cout << "Your balance after topup: " << currentCredit << endl;
    } else {
      clearScreen();
      warning("You have entered incorrect username or password!");
      return;
    }
  }
  // STORE THE NEW BALANCE INTO FILE RECORDS OF USERS
  ifstream fin("records.txt");
  // Check if the file was opened successfully
  if (!fin) {
    cerr << "Error opening file" << endl;
    return;
  }
  // Read the contents of the file into a string
  string text((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
  fin.close();
  // Search and replace operation on the string
  string search = "Creditpoint:" + oldCredit;
  string replace = "Creditpoint:" + to_string(currentCredit);
  size_t pos = 0;
  while ((pos = text.find(search, pos)) != string::npos) {
    text.replace(pos, search.length(), replace);
    pos += replace.length();
  }
  // Open the file for writing
  ofstream fout("records.txt", ios::trunc);
  // Check if the file was opened successfully
  if (!fout) {
    cerr << "Error opening file" << endl;
    return;
  }
  // Write the modified string back to the file
  fout << text;
  fout.close();
};

void Member::showBalance() {
  cout << fullName << "'s balance: " << this->creditPoint << endl;
};

int Member ::getBikeID() { return this->bikeID; }

string Member ::getUsername() { return this->username; };

string Member ::getPassword() { return this->password; };

string Member ::getUserInfoString() {
  stringstream ss;
  ss << username << "|" << password << "|" << bikeID << "|" << fullName << "|"
     << phoneNumber << "|" << idType << "|" << idNumber << "|" << city << "|"
     << licenseNo << "|" << expiryDate.getTime()
     << "|Creditpoint:" << creditPoint << "|Score:" << ratingScore << "\n";
  return ss.str();
}

void Member::viewRequest() {
  ifstream file;
  string line;
  ifstream review("review.txt");
  vector<string> reverse = reverseFile(review);
  file.open("request.txt");
  if (!file.is_open()) {
    cerr << "Failed to open the file." << endl;
  } else {
    while (getline(file, line)) {
      // Check if the first character of the line is the bikeID (as a character)
      if (line[0] == static_cast<char>('0' + bikeID)) {
        size_t position = line.find('|');
        cout << line.erase(0, position + 1) << "\n";
        stringstream ss(line);
        string usn;
        getline(ss, usn, '|');
        int reviewCount = 0;
        for (auto line : reverse) {
          if (reviewCount == 3) { // reversed the file because we want to read
                                  // the latest 3 reviews
            break;
          }
          if (line.substr(0, 1) == "R") { // R is for Renter review
            stringstream ss(line);
            string token, cleanedLine = ss.str().erase(0, 2);
            getline(ss, token, '|');
            if (token == "R") {
              getline(ss, token, '|');
              if (token.compare(usn) == 0) { // if the line in the file has the
                                             // same username then display it
                cout << "\t" << cleanedLine << endl;
                reviewCount++;
              }
            }
          }
        }
      }
    }
    acceptRequest();
    review.close();
    file.close();
  }
}

Member login() {
  string username, fullName, idType, password, city, phoneNumber, idNumber,
      licenseNo, enteredUsername, enteredPassword;
  int creditPoint, bikeID, day, month, year;
  double ratingScore;
  Time expiryDate;
  fstream records;
  bool loginSuccessful = false;
  cout << "LOGIN PAGE" << endl;
  cout << "\tEnter your username: ";
  cin >> enteredUsername;
  cout << "\tEnter your password: ";
  while (true) {
        char ch = _getch(); 
        if (ch == 13) 
            break;
        enteredPassword.push_back(ch);
        cout << '*'; 
    }
  records.open("records.txt", ios::in);
  if (!records.is_open()) {
    warning("System has failed to check member's information.");
    return Member();
  } else {
    string tempLine;
    int position;
    while (getline(records, tempLine)) {
      position = tempLine.find('|');
      username = tempLine.substr(0, position);
      tempLine.erase(0, position + 1);
      position = tempLine.find('|');
      password = tempLine.substr(0, position);
      tempLine.erase(0, position + 1);
      if (username == enteredUsername && password == enteredPassword) {
        loginSuccessful = true;

        position = tempLine.find('|');
        bikeID = stoi(tempLine.substr(0, position));
        tempLine.erase(0, position + 1);

        position = tempLine.find('|');
        fullName = tempLine.substr(0, position);
        tempLine.erase(0, position + 1);

        position = tempLine.find('|');
        phoneNumber = tempLine.substr(0, position);
        tempLine.erase(0, position + 1);

        position = tempLine.find('|');
        idType = tempLine.substr(0, position);
        tempLine.erase(0, position + 1);

        position = tempLine.find('|');
        idNumber = tempLine.substr(0, position);
        tempLine.erase(0, position + 1);

        position = tempLine.find('|');
        city = tempLine.substr(0, position);
        tempLine.erase(0, position + 1);

        position = tempLine.find('|');
        licenseNo = tempLine.substr(0, position);
        tempLine.erase(0, position + 1);

        position = tempLine.find('/');
        day = stoi(tempLine.substr(0, position));
        tempLine.erase(0, position + 1);

        position = tempLine.find('/');
        month = stoi(tempLine.substr(0, position));
        tempLine.erase(0, position + 1);

        position = tempLine.find('|');
        year = stoi(tempLine.substr(0, position));
        tempLine.erase(0, position + 13);

        expiryDate.setTime(day, month, year);

        position = tempLine.find('|');
        creditPoint = stoi(tempLine.substr(0, position));
        tempLine.erase(0, position + 7);

        position = tempLine.find('|');
        ratingScore = stod(tempLine.substr(0, position));
        tempLine.erase(0, position + 1);
        break;
      }
    }
    records.close();
    if (loginSuccessful) {
      clearScreen();
      cout << "Logged in successfully!" << endl;
      return Member(username, bikeID, fullName, phoneNumber, idType, idNumber,
                    password, city, licenseNo, expiryDate, creditPoint,
                    ratingScore);
    } else {
      clearScreen();
      warning("You have entered incorrect username or password!");
      return Member();
    }
  }
};

void view(int choice) {
  switch (choice) {
  case 1:
    viewBikeInfo();
    break;
  case 2:
        cout << "List of bikes: \n";
        viewBikeInfo();
        string input;
        
        while (true) {
            cout << "Enter ID of the Bike to see review (Press 'q' to return to the main menu): ";
            getline(cin, input);
            
            if (input == "q") {
                break;
            }
            
            ifstream file("review.txt");
            
            if (!file.is_open()) {
                cerr << "Failed to open the file." << endl;
                break;
            }
            
            string line;
            int count = 1;

            while (getline(file, line)) {
                string type, bikeID, rating, review;
                int position = 0;

                position = line.find('|');
                type = line.substr(0, position);
                line.erase(0, position + 1);

                position = line.find('|');
                bikeID = line.substr(0, position);
                line.erase(0, position + 1);

                position = line.find('|');
                rating = line.substr(0, position);
                line.erase(0, position + 1);

                review = line;

                if (bikeID == input) {
                    std::cout << "Review #" << count << std::endl;
                    std::cout << "BikeID:\t " << bikeID << "\n" << "Rating:\t " << rating << "\n" << "Review:\t " << review << "\n" << std::endl;
                    count++;
                }
            }

            file.close();
        }
        break;
    }
}

void updateAvg() {
  ifstream inputFile("review.txt");
  ofstream outputFile("reverse.txt");
  if (!inputFile.is_open()) {
    cerr << "Input file is not open." << endl;
    return;
  }

  vector<string> lines;
  string line1;

  while (getline(inputFile, line1)) {
    lines.push_back(line1);
  }

  for (int i = lines.size() - 1; i >= 0; --i) {
    outputFile << lines[i] << endl;
  }
  inputFile.close();
  outputFile.close();
  ifstream infile("reverse.txt");
  string line, def, lastUsername, checkUsername;
  double count = 1, total = 0, averageRating = 0;
  if (!infile.is_open()) {
    cout << "Error";
  } else {
    int position;
    getline(infile, line);
    position = line.find('|');
    line.erase(0, position + 1);
    position = line.find('|');
    lastUsername = line.substr(0, position);
    line.erase(0, position + 1);
    position = line.find('|');
    total += stod(line.substr(0, position));
    while (getline(infile, line)) {
      position = line.find('|');
      def = line.substr(0, position);
      line.erase(0, position + 1);
      if (def == "R") {
        position = line.find('|');
        checkUsername = line.substr(0, position);
        if (checkUsername == lastUsername) {
          line.erase(0, position + 1);
          position = line.find('|');
          total += stod(line.substr(0, position));
          count++;
        }
      }
    }
  }
  averageRating = total / count;
  infile.close();
  string newline, name;
  int pos;
  ifstream another("records.txt");
  if (!another.is_open()) {
    cout << "Error: Couldn't open" << endl;
  } else {
    ofstream tempFile("temp_records.txt");
    if (!tempFile.is_open()) {
      cout << "Error: Couldn't create a temporary file" << endl;
    } else {
      while (getline(another, newline)) {
        pos = newline.find('|');
        name = newline.substr(0, pos);

        if (name == lastUsername) {
          size_t scorePos = newline.find("Score:");
          if (scorePos != string::npos) {
            newline.replace(scorePos, newline.length() - scorePos,
                            "Score:" + to_string(averageRating));
          }
        }

        tempFile << newline << endl;
      }

      tempFile.close();
      another.close();

      if (remove("records.txt") != 0) {
        cerr << "Error: Failed to delete the old records.txt" << endl;
      }
      remove("reverse.txt");
      if (rename("temp_records.txt", "records.txt") != 0) {
        cerr << "Error: Failed to rename the temporary file" << endl;
      }
    }
  }
}

Member registerMember() {
  // Get information about attributes of the Member
  string username, fullName, idType, password, city, phoneNumber, idNumber,
      licenseNo;
  int creditPoint = 0, day, month, year;
  Time expiryDate;
  double ratingScore = 0;

  // Receive data from the user
  std::cout << "Guest User Registration:\n";
  cout << "Enter Username: ";
  getline(cin, username);

  fstream records("records.txt", ios::in);
  string tempLine;
  int position;
  bool matchedUsername =
      false; // this is used to mark whether the entered username already exists
  while (getline(records, tempLine)) {
    string tempUsername;
    position = tempLine.find('|');
    tempUsername = tempLine.substr(0, position);
    if (username == tempUsername) {
      matchedUsername = true;
      warning("This username already exists, please choose another name or "
              "enter 'e' to exit.");
      while (matchedUsername) {
        cout << "Guest User Registration:" << endl;
        cout << "Enter Username: ";
        getline(cin, username);
        if (username == "e") {
          std::cout << "Program exits!" << endl;
          records.close();
          return Member();
        }
        records.close();
        fstream records("records.txt", ios::in);
        while (getline(records, tempLine)) {
          string tempUsername;
          position = tempLine.find('|');
          tempUsername = tempLine.substr(0, position);
          if (username == tempUsername) {
            matchedUsername = true;
            warning("This username already exists, please choose another name "
                    "or enter 'e' to exit.");
            break;
          } else {
            matchedUsername = false;
            continue;
          }
        }
        continue;
      }
    }
  }

  cout << "Enter Password: ";
  getline(cin, password);

  cout << "Enter Full Name: ";
  getline(cin, fullName);

  cout << "Enter Phone Number: ";
  getline(cin, phoneNumber);

  cout << "Enter ID Type\n1. Citizen ID\t2. Passport" << endl;
  cout << ">> Your choice: ";
  string idChoice;
  getline(cin, idChoice);
  while (idChoice != "1" && idChoice != "2" && idChoice != "q") {
    cout << "Invalid option. Please re-enter." << endl;
    cout << "You can re-enter your city or press 'q' to quit registering." << endl;
    cout << "Enter ID Type\n1. Citizen ID\t2. Passport" << endl;
    cout << ">> Your choice: ";
    getline(cin, idChoice);
  } 
  if (idChoice == "1") {
    idType = "Citizen ID";
  } else if (idChoice == "2") {
    idType = "Passport";
  } else if (idChoice == "q") {
    cout << "Cancelled registeration!" << endl;
      clearScreen();
      return Member();
  }

  cout << "Enter ID/Passport Number: ";
  getline(cin, idNumber);

  cout << "Enter city\n1. Ha Noi\t2. Sai Gon" << endl;
  cout << ">> Your choice: ";
  string cityChoice;
  getline(cin, cityChoice);
  while (cityChoice != "1" && cityChoice != "2" && cityChoice != "q") {
    cout << "Invalid option. Please re-enter." << endl;
    cout << "You can re-enter your city or press 'q' to quit registering." << endl;
    cout << "Enter city\n1. Ha Noi\t2. Sai Gon" << endl;
    cout << ">> Your choice: ";
    getline(cin, cityChoice);
  } 
  if (cityChoice == "1") {
    city = "Ha Noi";
  } else if (cityChoice == "2") {
    city = "Sai Gon";
  } else if (cityChoice == "q") {
    cout << "Cancelled registeration!" << endl;
      clearScreen();
      return Member();
  }
	
  cout << "Enter license number: ";
  getline(cin, licenseNo);

  cout << "Enter day of license's expiry (DD): ";
  cin >> day;

  cout << "Enter month of license's expiry (MM): ";
  cin >> month;

  cout << "Enter year of license's expiry (YYYY): ";
  cin >> year;
  expiryDate.setTime(day, month, year);
  clearScreen();
  if (records.is_open()) {
    records.close();
  }

  string topUpChoice = "";
  cout << "To create account, you have to pay entry fee of $20." << endl;
  cout << "Would you like to pay?" << endl;
  cout << "1. Yes\t2. No" << endl;
  cout << "Your choice: ";
  cin.ignore(1, '\n');
  getline(cin, topUpChoice);

  while (topUpChoice != "1" && topUpChoice != "2") {
    cout << "Unvailable option. Please re-enter." << endl;
    cout << "1. Yes\t2. No" << endl;
    cout << "Your choice: ";
    getline(cin, topUpChoice);
  }

  if (topUpChoice == "1") {
	clearScreen();
    cout << "Top up successfully!" << endl;
    creditPoint = 20;
    cout << "Your balance: " << creditPoint << endl;
  } else {
	clearScreen();
    cout << "Failed to create account" << endl;
    return Member();
  }

  string choice = "";
  cout << "Do you want to register a bike?" << endl;
  cout << "1. Yes\t2. No" << endl;
  cout << "Your choice: ";
  getline(cin, choice);
  while (choice != "1" && choice != "2") {
    cout << "Unvailable option. Please re-enter." << endl;
    cout << "1. Yes\t2. No" << endl;
    cout << "Your choice: ";
    getline(cin, choice);
  }
  if (choice == "1") {
    Motorbike newBike;
    int bikeID;
    bikeID = newBike.registerBike();
    return Member(username, bikeID, fullName, phoneNumber, idType, idNumber,
                  password, city, licenseNo, expiryDate, creditPoint,
                  ratingScore);
  } else if (choice == "2") {
    int bikeID = 0;
    return Member(username, bikeID, fullName, phoneNumber, idType, idNumber,
                  password, city, licenseNo, expiryDate, creditPoint,
                  ratingScore);
  }
  return Member();
};

void save() {
  Member emptyMember;
  ofstream outputFile("records.txt", ios::app);
  if (!outputFile.is_open()) {
    cerr << "Error: Unable to open the file for writing.\n";
  } else {
    // CREATE A MEMBER WITH GIVEN ATTRIBUTES DATA FROM USER
    Member guest = registerMember();

    // STORE INFOS AS STRINGSTREAM IN FILE
    if (!(emptyMember == guest)) {
      outputFile << guest.getUserInfoString() << "\n";
      cout << "User info sucessully stored!\n";
    } else {
      cout << "Registeration failed!" << endl;
    }
  }

  // Close the file
  outputFile.close();
}

void Member::searchBike() {
	int startDay, startMonth, startYear, endDay, endMonth, endYear, cityChoice;
	Time startTime, endTime;
	string city = "";
	bool invalidOption = true; // to mark whether user has entered an invalid option

	// Get start time from user
	cout << "Enter start time: " << endl;
	cout << "\tDay (DD): ";
	cin >> startDay;
	cout << "\tMonth (MM): ";
	cin >> startMonth;
	cout << "\tYear(YYYY): ";
	cin >> startYear;
	startTime.setTime(startDay, startMonth, startYear);
	
	// Get end time for user
	cout << "Enter end time: " << endl;
	cout << "\tDay (DD): ";
	cin >> endDay;
	cout << "\tMonth (MM): ";
	cin >> endMonth;
	cout << "\tYear(YYYY): ";
	cin >> endYear;
	endTime.setTime(endDay, endMonth, endYear);


	string user = this->username;
	double score = this->ratingScore;

	// Error handling for cases that user enters an invalid string
  	while (invalidOption) {
	    cout << "Select city where the motorbike is located:" << endl;
	    cout << "\t1. Ha Noi\n\t2. Sai Gon" << endl;
	    cout << "Enter number: ";
	    cin >> cityChoice;
	    switch (cityChoice) {
	    case 1:
	        city = "Ha Noi";
	        invalidOption = false;
	        break;
	    case 2:
	        city = "Sai Gon";
	        invalidOption = false;
	        break;
	    default:
	        cout << "You have entered an invalid option, please re-enter." << endl;
	        break;
    	}
	}

	// Access to file "availability.txt" in reading mode
	ifstream availability("availability.txt", ios::in);

	// Check if the file "availability.txt" has been opened
	if (!availability.is_open()) {
	    warning("System has failed to check bike's availability.");
	    return;
  	}

	int rentingPeriod = period(startTime, endTime);
	string tempLine, start, end, tempBikeID;
	Time startT, endT;
	int position = 0;
	bool bikeFound = false; // to check if there is bike matching the search filter
	
	// Read all lines in file "availability.txt"
	while (getline(availability, tempLine)) {
		// Assign the first word found into string tempBikeID
	    position = tempLine.find('|');
	    tempBikeID = tempLine.substr(0, position);

		// Assign the first word found into string start, then convert start into Time
	    position = tempLine.find("start:") + 6;
	    start = tempLine.substr(position, 10);
	    startT.setTime(readTime(start).getDay(), readTime(start).getMonth(),
	                   readTime(start).getYear());

		// Assign the first word found into string end, then convert end into Time
	    position = tempLine.find("end:") + 4;
	    end = tempLine.substr(position, 10);
	    endT.setTime(readTime(end).getDay(), readTime(end).getMonth(),
	                 readTime(end).getYear());

		// Assign the required minimum score 
		position = tempLine.find("score:") + 6;
		string minScoreString = tempLine.substr(position);
		double minScore = stod(minScoreString);

		// Find a bike that has suitable available time range 
	    if (startTime >= startT && endTime <= endT) {
			// Access to "bikeInfo.txt"
			ifstream bikeInfo("bikeInfo.txt", ios::in);

			// Check if file "bikeInfo.txt" has been opened
			if (!bikeInfo.is_open()) {
				warning("System has failed to check bike's information.");
				return;
			}

			// Search bike section
			string tempLine1, tempBikeID1, tempSubString;
			int position1 = 0;
			while (getline(bikeInfo, tempLine1)) {
				// Find bike ID 
		        position1 = tempLine1.find('|');
		        tempBikeID1 = tempLine1.substr(0, position1);
		        int position2 = tempLine1.find("city:") + 5;

				// Find bike's credit per day
				int count = 0;
				for (int i = 0; i < tempLine1.size(); i++) {
					if (tempLine1[i] == '|') {
						count ++;
					}
				}
				
				string tempLine2 = tempLine1;
				int tempCount = count;
				while (tempCount >= 1) {
					position1 = tempLine2.find('|');
					tempLine2.erase(0, position1 + 1);
					tempCount--;
				}
				int creditPerDay = stoi(tempLine2);
				int totalCredit = rentingPeriod * creditPerDay; // calculate total cost 
				if (tempBikeID1 == tempBikeID && tempLine1[position2] == city[0] && totalCredit <= this->creditPoint && score >= minScore) { 
	          		bikeFound = true;
					// Print bike's model
          cout << "\nBike's ID: " << tempBikeID ;

					position1 = tempLine1.find('|');
					cout << "\nBike's model: ";
					tempLine1.erase(0, position1 + 1);
					position1 = tempLine1.find('|');
					tempSubString = tempLine1.substr(0, position1);
					cout << tempSubString << endl;
	
					// Print bike's color
					cout << "Bike's color: ";
					tempLine1.erase(0, position1 + 1);
					position1 = tempLine1.find('|');
					tempSubString = tempLine1.substr(0, position1);
					cout << tempSubString << endl;
					
					// Print bike's location
					cout << "Bike's location: ";
					tempLine1.erase(0, position1 + 6);
					position1 = tempLine1.find('|');
					tempSubString = tempLine1.substr(0, position1);
					cout << tempSubString << endl;
					
					// Print bike's engine size
					cout << "Bike's engine size: ";
					tempLine1.erase(0, position1 + 1);
					position1 = tempLine1.find('|');
					tempSubString = tempLine1.substr(0, position1);
					cout << tempSubString << endl;
					
					// Print bike's transmission type
					cout << "Bike's transmission type: ";
					tempLine1.erase(0, position1 + 1);
					position1 = tempLine1.find('|');
					tempSubString = tempLine1.substr(0, position1);
					if (tempSubString == "1") {
	            		tempSubString = "Manual Tranmission";
					} else if (tempSubString == "2") {
						tempSubString = "Automatic tranmission";
					} else if (tempSubString == "3") {
						tempSubString = "CVT transmission";
					} else {
						tempSubString = "Unrecognizable transmission";
					}
	          		cout << tempSubString << endl;
	
					// Print bike's engine size
					cout << "Bike's engine size: ";
					tempLine1.erase(0, position1 + 1);
					position1 = tempLine1.find('|');
					tempSubString = tempLine1.substr(0, position1);
					cout << tempSubString << endl;
					
					// Print bike's description
					cout << "Bike's description: ";
					tempLine1.erase(0, position1 + 1);
					position1 = tempLine1.find('|');
					tempSubString = tempLine1.substr(0, position1);
					cout << tempSubString << endl;
					
					// Print bike's credit per day
					cout << "Bike's credit per day: ";
					tempLine1.erase(0, position1 + 1);
					tempSubString = tempLine1;
					cout << tempSubString << endl << endl;
	        	}
	      	}
      		bikeInfo.close();
    	}
  	}
	availability.close();

	// Output when there is no matching bike found
	if (!bikeFound) {
    	cout << "There is no bike matching your search." << endl;
  } else {
    this->requestToRent();
  }
};

// Check if string can be converted to a Double
bool isDouble(const string& str) {
    bool result = true;
    try {
        // Convert string to double
        double d = stod(str);
    }
    catch (const invalid_argument& e) {
        // handle the exceptiop invalid_argument
        result = false;
    }
    catch (const out_of_range& e) {
        // handle the exceptiop out_of_range
        result = false;
    }
    return result;
}

// SONSONSONSONSONSONSONSONSONSONSOSONSONSOSN

void Member::listAvailableBike() {
  Time start, end;
  ifstream bikeInfo("bikeInfo.txt");
  ifstream available("availability.txt");
  fstream availability;
  availability.open("availability.txt", ios::out | ios::app);
  if (!bikeInfo.is_open() || !availability.is_open() || !available.is_open()) {
    warning("System has failed to check member's information.");
  } else {
    while (1) {
        //Get rent date range
      int dayStart, monthStart, yearStart, dayEnd, monthEnd, yearEnd;
      cout << "Please enter the start time (dd/mm/yyyy): ";
      scanf("%d/%d/%d", &dayStart, &monthStart, &yearStart);
      start.setTime(dayStart, monthStart, yearStart);
      cout << "Please enter the end time (dd/mm/yyyy): ";
      scanf("%d/%d/%d", &dayEnd, &monthEnd, &yearEnd);
      end.setTime(dayEnd, monthEnd, yearEnd);
      string line;
      vector<pair<Time, Time>> dateRanges; //store date range in a vector
      Time startDate, endDate;
        //record every line until end of file
      while (getline(available, line)) {
        stringstream ss(line);
        string token;
        size_t start_pos = string::npos;
        size_t end_pos = string::npos;
        getline(ss, token, '|');
          //check if bikeID is identical
        if (stoi(token) == bikeID) {
          start_pos = line.find("start:");
          end_pos = line.find("end:");
            //records dates in file to check if overlap
          if (start_pos != string::npos) {
            size_t nextPipe = line.find('|', start_pos);
            startDate =
                readTime(line.substr(start_pos + 6, nextPipe - start_pos - 6));
          }
          if (end_pos != string::npos) {
            size_t nextPipe = line.find('|', end_pos);
            endDate = readTime(line.substr(end_pos + 4, nextPipe - end_pos - 4));
          }
          dateRanges.push_back(make_pair(startDate, endDate));
        }
      }
        //check if overlap
      bool overlap = false;
      for (int i = 0; i < dateRanges.size(); i++) {
        if (isOverlap(start, end, dateRanges[i].first, dateRanges[i].second)) {
          overlap = true;
        }
      }
      if (!overlap) {
        break;
      }
    }
      //get bike info
    string line, cityName;
    int creditPerDay;
    while (getline(bikeInfo, line)) {
      stringstream ss(line);
      string token;
      size_t position = string::npos;
      getline(ss, token, '|');
      if (stoi(token) == bikeID) {
        position =
            line.find("city:"); // Find the position of "city:" in the line
        if (position != string::npos) {
          // Extract the city name from the line
          size_t nextPipe = line.find('|', position);
          size_t lastPipePosition = line.find_last_of('|');
          cityName = line.substr(position + 5,
                                 nextPipe - position - 5); // +5 to skip "city:"
          line.erase(0, lastPipePosition + 1);
          creditPerDay = stoi(line);
        }
        break;
      }
    }

	  // Ask if renter wants to add minimum required renter-rating
	string minRenterRating = "0";
	string choice;
	cout << "Do you want to add minimum required renter-rating (from 0 to 5)?" << endl;
	cout << "1. Yes\t2. No" << endl;
	cout << ">> Your selection: ";
	cin.ignore(1,'\n');
	getline(cin, choice);
	
	// Check if entered value is 1 or 2
	while (choice != "1" && choice != "2") {
		cout << "Invalid value. Please re-enter." << endl;
		cout << "Do you want to add minimum required renter-rating (from 0 to 5)?" << endl;
		cout << "1. Yes\t2. No" << endl;
		cout << ">> Your selection: ";
		cin.ignore(1,'\n');
		getline(cin, choice);
	}

	// User chose Yes, continue to ask user to enter minimum required renter-rating
	if (choice == "1") {
		cout << "Enter minimum required renter-rating: ";
		getline(cin, minRenterRating);

		// Check if minRenterRating is a double value or not, if not, ask user to re-enter
		while (!isDouble(minRenterRating)) {
			cout << "Invalid value. Please re-enter." << endl;
			cout << "Enter minimum required renter-rating: ";
			getline(cin, minRenterRating);
		}

		// when entered value is negative, assume user wants to set minRenterRating = 0
		if (stod(minRenterRating) < 0) {
			minRenterRating = "0";
			cout << "Negative value.\nThe minimum required score is set to 0." << endl;
		} else if (stod(minRenterRating) > 5) { // when entered value is greater than 5, assume user wants to set minRenterRating = 5
			minRenterRating = "5";
			cout << "Exceeded maximum value.\nThe minimum required score is set to 5." << endl;
		}
	}

      //total credit to rent
    int totalCredit = creditPerDay * period(start, end);
    bikeInfo.close();
      //write into file
    availability << bikeID << "|"
                 << "city:" << cityName << "|start:" << start.getTime()
                 << "|end:" << end.getTime() << "|score:" << stod(minRenterRating) << "|" << totalCredit << "\n";
    availability.close();
  }
}

void Member::unlistAvailableBike() {
    //get date from user
    int startDay, startMonth, startYear;
    cout << "Please input the date you want to unlist (dd/mm/yyyy): ";
    scanf("%d/%d/%d", &startDay, &startMonth, &startYear);
    Time start;
    start.setTime(startDay, startMonth, startYear);

    ifstream availableRead("availability.txt");
    ofstream temp("tempfile.txt");

    if (!availableRead.is_open() || !temp.is_open()) {
        warning("System has failed to check member's information.");
    } else {
        string line;
        size_t start_pos = string::npos;
        bool deleted = false;

        while (getline(availableRead, line)) {
            // Create a stringstream to parse the line
            stringstream ss(line);
            string token;
            Time startDate;
            getline(ss, token, '|');

            if (stoi(token) == bikeID) {
                start_pos = line.find("start:");
                if (start_pos != string::npos) {
                    size_t nextPipe = line.find('|', start_pos);
                    startDate = readTime(line.substr(start_pos + 6, nextPipe - start_pos - 6));
                }
                if (start == startDate && !deleted) {
                    // Skip this line (effectively deleting it)
                    deleted = true;
                } else {
                    // Write the line to the temporary file
                    temp << line << endl;
                }
            } else {
                // Write the line to the temporary file
                temp << line << endl;
            }
        }

        availableRead.close();
        temp.close();

        if (deleted) {
            // Remove the original file
            remove("availability.txt");
            rename("tempfile.txt", "availability.txt");
        } else {
            warning("No appropriate listing found");
            remove("tempfile.txt");
        }
    }
}

void Member::unlistAvailableBike(Time start) {
    ifstream availableRead("availability.txt");
    ofstream temp("tempfile.txt");

    if (!availableRead.is_open() || !temp.is_open()) {
        warning("System has failed to check member's information.");
    } else {
        string line;
        size_t start_pos = string::npos;
        bool deleted = false;

        while (getline(availableRead, line)) {
            // Create a stringstream to parse the line
            stringstream ss(line);
            string token;
            Time startDate;
            getline(ss, token, '|');

            if (stoi(token) == bikeID) {
                start_pos = line.find("start:");
                if (start_pos != string::npos) {
                    size_t nextPipe = line.find('|', start_pos);
                    startDate = readTime(line.substr(start_pos + 6, nextPipe - start_pos - 6));
                }
                if (start == startDate && !deleted) {
                    // Skip this line (effectively deleting it)
                    deleted = true;
                } else {
                    // Write the line to the temporary file
                    temp << line << endl;
                }
            } else {
                // Write the line to the temporary file
                temp << line << endl;
            }
        }

        availableRead.close();
        temp.close();

        if (deleted) {
            // Remove the original file
            remove("availability.txt");
            rename("tempfile.txt", "availability.txt");
        } else {
            warning("No appropriate listing found");
            remove("tempfile.txt");
        }
    }
}

Member findMember(string usernameParam) {
  string username, fullName, idType, password, city, phoneNumber, idNumber,
      licenseNo, enteredUsername, enteredPassword;
  int creditPoint, bikeID, day, month, year;
  double ratingScore;
  Time expiryDate;
  ifstream records("records.txt", ios::in);
  if (!records.is_open()) {
    return Member();
  }

  string tempLine;
  while (getline(records, tempLine)) {
    int position = 0;
    position = tempLine.find('|');
    username = tempLine.substr(0, position);
    if (username == usernameParam) {
      tempLine.erase(0, position + 1);

      position = tempLine.find('|');
      password = tempLine.substr(0, position);
      tempLine.erase(0, position + 1);

      position = tempLine.find('|');
      bikeID = stoi(tempLine.substr(0, position));
      tempLine.erase(0, position + 1);

      position = tempLine.find('|');
      fullName = tempLine.substr(0, position);
      tempLine.erase(0, position + 1);

      position = tempLine.find('|');
      phoneNumber = tempLine.substr(0, position);
      tempLine.erase(0, position + 1);

      position = tempLine.find('|');
      idType = tempLine.substr(0, position);
      tempLine.erase(0, position + 1);

      position = tempLine.find('|');
      idNumber = tempLine.substr(0, position);
      tempLine.erase(0, position + 1);

      position = tempLine.find('|');
      city = tempLine.substr(0, position);
      tempLine.erase(0, position + 1);

      position = tempLine.find('|');
      licenseNo = tempLine.substr(0, position);
      tempLine.erase(0, position + 1);

      position = tempLine.find('/');
      day = stoi(tempLine.substr(0, position));
      tempLine.erase(0, position + 1);

      position = tempLine.find('/');
      month = stoi(tempLine.substr(0, position));
      tempLine.erase(0, position + 1);

      position = tempLine.find('|');
      year = stoi(tempLine.substr(0, position));
      tempLine.erase(0, position + 13);

      expiryDate.setTime(day, month, year);

      position = tempLine.find('|');
      creditPoint = stoi(tempLine.substr(0, position));
      tempLine.erase(0, position + 7);

      position = tempLine.find('|');
      ratingScore = stoi(tempLine.substr(0, position));
      tempLine.erase(0, position + 1);

      records.close();

      return Member(username, bikeID, fullName, phoneNumber, idType, idNumber,
                    password, city, licenseNo, expiryDate, creditPoint,
                    ratingScore);
    }
  }
  records.close();
  return Member();
}

int Member::getCredit() { return this->creditPoint; }

void Member::setCredit(int point) { this->creditPoint += point; }

void Member::charge(int totalCredit, Time startTime, Time endTime) {
  ifstream request("request.txt", ios::in);
  string chargedRenter = "";
  if (!request.is_open()) {
    warning("System has failed to find renter's information.");
    return;
  }
  string tempLine;
  while (getline(request, tempLine)) {
    int position = 0;
    position = tempLine.find('|');
    string tempBikeID = tempLine.substr(0, position);
    tempLine.erase(0, position + 1);
    if (stoi(tempBikeID) == this->bikeID) { 
      position = tempLine.find('|');
      string tempUser = tempLine.substr(0, position); 

      position = tempLine.find('|');
      tempLine.erase(0, position + 1);
      string start = tempLine.substr(0, 10); 
      Time startT = readTime(start); 

      position = tempLine.find('|');
      tempLine.erase(0, position + 1);
      string end = tempLine.substr(0, 10);
      Time endT = readTime(end); cout << endT.getTime() << endl;

      if (startT == startTime && endT == endTime) {
        chargedRenter = tempUser;
      }
    }
  }

  request.close();

  if (chargedRenter != "") {
    Member chargedMem = findMember(chargedRenter);
    string oldCredit = to_string(chargedMem.getCredit());
    chargedMem.setCredit(-totalCredit);
    string currentCredit = to_string(chargedMem.getCredit());
    // STORE THE NEW BALANCE INTO FILE RECORDS OF USERS
    ifstream fin("records.txt");
    // Check if the file was opened successfully
    if (!fin) {
      cerr << "Error opening file" << endl;
      return;
    }
    // Read the contents of the file into a string
    string text((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();
    // Search and replace operation on the string
    string search = "Creditpoint:" + oldCredit;
    string replace = "Creditpoint:" + currentCredit;
    size_t pos = 0;
    while ((pos = text.find(search, pos)) != string::npos) {
      text.replace(pos, search.length(), replace);
      pos += replace.length();
    }
    // Open the file for writing
    ofstream fout("records.txt", ios::trunc);
    // Check if the file was opened successfully
    if (!fout) {
      cerr << "Error opening file" << endl;
      return;
    }
    // Write the modified string back to the file
    fout << text;
    fout.close();
    cout << "Payment successful!" << endl;
    return;
  } else {
    warning("System failed to charge renter");
    return;
  }
}

void Member::writeReviewBike() {
  cout << "Review the latest bike you rented" << endl;
  int countFoundBike = 0;
  bool accepted = false;
  ifstream request("request.txt", ios::in);
  ofstream tempRequest("tempRequest.txt", ios::out | ios::app);
  if (!request.is_open() || !tempRequest.is_open()) {
    warning("System failed to find bike's information.");
    return;
  }
  string tempLine = "";
  while (getline(request, tempLine)) {
    int foundBikeID;
    int position = 0;

    position = tempLine.find('|');
    foundBikeID = stoi(tempLine.substr(0, position));

    string tmp = tempLine.substr(position + 1);
    position = tmp.find('|');
    string foundUsername = tmp.substr(0, position);

    position = tempLine.find("Status:") + 7;
    string foundStatus = tempLine.substr(position, 1);

    if (foundStatus == "A") {
      accepted = true;
    }

    if (this->username == foundUsername && accepted) {
      tempRequest << tempLine << '\n';
      countFoundBike++;
    }
  }
  tempRequest.close();
  request.close();

  if (countFoundBike == 0) {
    cout << "You have not rented any bikes to write review." << endl;
    return;
  }

  ifstream tempRequest1;
  tempRequest1.open("tempRequest.txt", ios::in);
  if (!tempRequest1.is_open()) {
    warning("System failed to find bike's information.");
    return;
  }

  vector<string> reversed = reverseFile(tempRequest1);
  stringstream ss;
  string reviewString;
  double givenScore;
  cout << "\tScore (out of 5): ";
  cin >> givenScore;
  while (givenScore > 5 || givenScore < 0) {
    cout << "Score out of range." << endl;
    cout << "\tScore (out of 5): ";
    cin >> givenScore;
  }
  cout << "\tLeave a paragraph of feedback: " << endl << "\t>> ";
  cin.ignore(1, '\n');
  getline(cin, reviewString);
  for (string tempString : reversed) {
    string latestBikeID = "";
    int position = 0;
    position = tempString.find("|");
    latestBikeID = tempString.substr(0, position);
    ofstream review("review.txt", ios::out | ios::app);
    if (!review.is_open()) {
      warning("System failed to find bike's information.");
      return;
    }
    ss << "B|" << latestBikeID << "|" << fixed << setprecision(2) << givenScore
       << "|" << reviewString << '\n';
    review << ss.str();
    review.close();
    break;
  }
  tempRequest1.close();
}

void Member::writeReviewRenter() {
  cout << "Review your latest renter" << endl;
  int countFoundRenter = 0;
  bool accepted;
  ifstream request("request.txt", ios::in);
  ofstream tempRequest("tempRequest.txt", ios::out | ios::app);
  if (!request.is_open() || !tempRequest.is_open()) {
    warning("System failed to find renter's information.");
    return;
  }
  string tempLine = "";
  while (getline(request, tempLine)) {
    int foundBikeID;
    int position = 0;

    position = tempLine.find('|');
    foundBikeID = stoi(tempLine.substr(0, position));

    string tmp = tempLine.substr(position + 1);
    position = tmp.find('|');
    string foundUsername = tmp.substr(0, position);

    position = tempLine.find("Status:") + 7;
    string foundStatus = tempLine.substr(position, 1);

    if (foundStatus == "A") {
      accepted = true;
    }

    if (this->bikeID == foundBikeID && accepted) {
      tempRequest << tempLine << '\n';
      countFoundRenter++;
    }
  }
  tempRequest.close();
  request.close();

  if (countFoundRenter == 0) {
    cout << "No renter found." << endl;
    return;
  }

  ifstream tempRequest1;
  tempRequest1.open("tempRequest.txt", ios::in);
  if (!tempRequest1.is_open()) {
    warning("System failed to find renter's information.");
    return;
  }

  vector<string> reversed = reverseFile(tempRequest1);
  stringstream ss;
  string reviewString;
  double givenScore;
  cout << "\tScore (out of 5): ";
  cin >> givenScore;
  while (givenScore > 5 || givenScore < 0) {
    cout << "Score out of range." << endl;
    cout << "\tScore (out of 5): ";
    cin >> givenScore;
  }
  cout << "\tLeave a paragraph of feedback: " << endl << "\t>> ";
  cin.ignore(1, '\n');
  getline(cin, reviewString);
  for (string tempString : reversed) {
    int position = 0;
    position = tempString.find("|");
    string tempString2 = tempString.substr(position + 1);
    position = tempString2.find("|");
    string latestRenter = tempString2.substr(0, position);
    ofstream review("review.txt", ios::out | ios::app);
    if (!review.is_open()) {
      warning("System failed to find bike's information.");
      return;
    }
    ss << "R|" << latestRenter << "|" << fixed << setprecision(2) << givenScore
       << "|" << reviewString << '\n';
	
    review << ss.str();
    review.close();
    break;
  }
  tempRequest1.close();
  remove("tempRequest.txt");
  remove("tempRequest1.txt");
  updateAvg();
}

//This function is for finding the latest entry in the file
vector<string> reverseFile(ifstream &input) { 
  vector<string> linesReverse = {};
  if (!input.is_open()) {
    cout << "Error opening file" << endl;
  } else {
    string line;
    while (getline(input, line)) {
      linesReverse.insert(linesReverse.begin(), line);
    }
    return linesReverse;
  }
  return linesReverse;
}

void Member::requestToRent() {
  fstream availability, availability2,request;
  int enteredBikeID, bikeID, bikeID2, bikeID3,position, position2, position3;
  string enteredStartDay, enteredStartMonth, enteredStartYear, enteredEndDay, enteredEndMonth, enteredEndYear;
  string content1, content2;
  string tmpLine;
  string tmpLine2;
  string tmpLine3;
  string strbikeID, start, end;
  string requestedUser, start1, end1, status;
  string enteredStart, enteredEnd;
  string scoreextracted;
  string cityExtracted;
  string DayStart, MonthStart, YearStart, DayEnd, MonthEnd, YearEnd;
  string totalCredit;
  bool bikeIDnotMatched = true;

  request.open("request.txt", std::ios::in);
    if (!request.is_open()) {
      return;
    } else {
      string content3;
      request >> content3;
      request.close ();
      
      
      if (content3.length() != 0) {
        request.open("request.txt", std::ios::in);
        while(getline(request,tmpLine3)) {

          position3 = tmpLine3.find('|');
          bikeID2 = stoi(tmpLine3.substr(0, position3));
          tmpLine3.erase(0,position3 + 1);

          position3 = tmpLine3.find('|');
          requestedUser = tmpLine3.substr(0, position3);
          tmpLine3.erase(0,position3 + 1);

          position3 = tmpLine3.find('|');
          start1 = tmpLine3.substr(0, position3);
          tmpLine3.erase(0, position3 + 1);

          position3 = tmpLine3.find('|');
          end1 = tmpLine3.substr(0, position3);
          tmpLine3.erase(0, position3 + 1); 

          position3 = tmpLine3.find('|');
          status = tmpLine3.substr(0,position3);
          tmpLine3.erase(0,position3 + 1); 
          if (this->username == requestedUser) {
            cout << "You already requested to rent a bike or is renting a bike! \n";
            request.close();
            return;
          }
        }
        request.close();
      }
    }

    while (bikeIDnotMatched) {
      availability.open("availability.txt", std::ios::in);
      cout << "Please enter bikeID you want to rent:";
      cin >> enteredBikeID;
      
      cout << "Please enter start renting day of the bike (DD):";
      cin >> enteredStartDay;
      
      cout << "Please enter start renting month of the bike (MM):";
      cin >> enteredStartMonth;
      
      cout << "Please enter start renting year of the bike (YYYY):";
      cin >> enteredStartYear;
      
      cout << "Please enter end renting day of the bike (DD):";
      cin >> enteredEndDay;
      
      cout << "Please enter end renting month of the bike (MM): ";
      cin >> enteredEndMonth;
      
      cout << "Please enter end renting year of the bike (YYYY): ";
      cin >> enteredEndYear;
      

      while(getline(availability,tmpLine2)) {
      position2 = tmpLine2.find('|');
      strbikeID = tmpLine2.substr(0, position2);
      bikeID3 = stoi(strbikeID);
      tmpLine2.erase(0,position2 + 6);
    
      position2 = tmpLine2.find("|");
      cityExtracted = tmpLine2.substr(0,position2);
      tmpLine2.erase(0,position2 + 7);

      position2 = tmpLine2.find("/");
      DayStart = tmpLine2.substr(0,position2);
      tmpLine2.erase(0,position2 + 1);

      position2 = tmpLine2.find("/");
      MonthStart = tmpLine2.substr(0,position2);
      tmpLine2.erase(0,position2 + 1);

      position2 = tmpLine2.find("|");
      YearStart = tmpLine2.substr(0,position2);
      tmpLine2.erase(0,position2 + 5 );

      position2 = tmpLine2.find("/");
      DayEnd = tmpLine2.substr(0,position2);
      tmpLine2.erase(0,position2 + 1 ); 

      position2 = tmpLine2.find("/");
      MonthEnd = tmpLine2.substr(0,position2);
      tmpLine2.erase(0,position2 + 1);

      position2 = tmpLine2.find("|");
      YearEnd = tmpLine2.substr(0,position2);
      tmpLine2.erase(0,position2 + 7);

      position2 = tmpLine2.find("|");
      scoreextracted = tmpLine.substr(0,position2);
      tmpLine2.erase(0, position2 + 1);

      position2 = tmpLine2.find("|");
      totalCredit = tmpLine2.substr(0,position2);
      tmpLine2.erase(0, position2 + 1);
      
        if (bikeID3 == enteredBikeID && DayStart == enteredStartDay && MonthStart == enteredStartMonth && YearStart == enteredStartYear && DayEnd == enteredEndDay && MonthEnd == enteredEndMonth && YearEnd == enteredEndYear) {
        bikeIDnotMatched = false;
        } 
      }
      availability.close();
    }
    
  availability.close();
  availability.open("availability.txt", std::ios::in);

    if (!availability.is_open()) {
      cout << "There are no available bikes to rent" << endl;
    } else {
      availability >> content1;
      availability.close();

       if (content1.length() == 0) {
        cout << "There are no available bikes to rent" << endl;
        return; 
      } else {
        //availability.open("availability.txt",std::ios::in);
        //3|user2|13/09/2023|16/09/2023|Status:Pending
          stringstream ss;
          ss << enteredBikeID << "|" << this->username << "|" << enteredStartDay<< "/" << enteredStartMonth << "/" << enteredStartYear<< "|" << enteredEndDay << "/" << enteredEndMonth << "/" << enteredEndYear << "|"<< "Status:Pending" << endl;
              string a = ss.str();


          request.open("request.txt",std::ios::in);
          if (!request.is_open()) {
            request.open("request.txt",std::ios::out);
            request << a;
            cout << "Your request to rent bikeID " << enteredBikeID << " has been sent to the owner of the bike" << endl; 
            request.close();
              
          } else {
            request.close();
            request.open("request.txt",std::ios::app);
            request << a;
            cout << "Your request to rent bikeID " << enteredBikeID << " has been sent to the owner of the bike" << endl; 
            request.close();
          }

      }
    }
};


void Member::acceptRequest()
{
    int day, month, year, totalCredit;
    string usn;
    Time acceptTime;
    cout << "Please input the username that you want to accept: ";
    cin >> usn;
    cout << "Please input the start date of the request you want to accept: ";
    scanf("%d/%d/%d", &day,&month,&year);
    acceptTime.setTime(day,month,year);
    ifstream request("request.txt");
    ofstream tempFile("tempfile.txt");
    string line, lineDup;
    Time startDate, endDate;
    bool updated = false;
    while (getline(request, line))
    {
        // Create a stringstream to parse the line
        stringstream ss(line);
        string token;
        getline(ss, token, '|');
        if (stoi(token) == bikeID)
        {
            getline(ss, token, '|');
            if (token == usn)
            {
                getline(ss, token, '|');
                startDate = readTime(token);
                getline(ss, token, '|');
                endDate = readTime(token);
                if (startDate == acceptTime)
                {
                    if (line.find("Pending") != string::npos)
                    {
                        // Write the line to the temporary file
                        line.replace(line.find("Status:") + 7, 7, "Accepted");
                        tempFile << line << endl;
                        updated = true;
                    }
                    ifstream availableRead("availability.txt");

                    if (!availableRead.is_open())
                    {
                        warning("System has failed to check member's information.");
                    }
                    else
                    {
                        string lineDup;
                        size_t start_pos = string::npos;

                        while (getline(availableRead, lineDup))
                        {
                            // Create a stringstream to parse the line
                            stringstream ss(lineDup);
                            string tokenDup;
                            Time startDateDup;
                            getline(ss, tokenDup, '|');

                            if (stoi(tokenDup) == bikeID)
                            {
                                start_pos = lineDup.find("start:");
                                if (start_pos != string::npos)
                                {
                                    size_t nextPipe = lineDup.find('|', start_pos);
                                    startDateDup = readTime(lineDup.substr(start_pos + 6, nextPipe - start_pos - 6));
                                }
                                if (acceptTime == startDateDup)
                                {
                                    totalCredit = stoi(lineDup.substr(lineDup.find_last_of('|') + 1, lineDup.length()));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    request.close();
    ifstream requestDup("request.txt");
    while (getline(requestDup, lineDup))
    {
        stringstream ss(lineDup);
        string token;
        Time startCurrent, endCurrent;
        getline(ss, token, '|');
        if (stoi(token) == bikeID)
        {
            getline(ss, token, '|');
            getline(ss, token, '|');
            startCurrent = readTime(token);
            getline(ss, token, '|');
            endCurrent = readTime(token);
            if (!isOverlap(startDate, endDate, startCurrent, endCurrent))
            {
                tempFile << lineDup << endl;
            }
        }
        else
        {
            tempFile << lineDup << endl;
        }
    }
    requestDup.close();
    tempFile.close();

    if (updated)
    {
        remove("request.txt");
        rename("tempfile.txt", "request.txt");
    }
    else
    {
        cout << "No appropriate request of user " << usn << " found!" << endl;
        remove("tempfile.txt"); // Remove the temporary file if no updates were made
    }

    unlistAvailableBike(startDate);
    this->charge(totalCredit, startDate, endDate);
}

void Member:: cancelRequest(){
    ifstream request("request.txt");
    ofstream tempfile("tempfile.txt");
    string line;
    bool foundReq = false; 
    while (getline(request, line)){
      stringstream ss(line);
      string token;
      getline(ss, token, '|');
      getline(ss, token, '|');
      if(token == username){
        size_t position = line.find("Pending");
        if(position == string::npos){
          tempfile << line << endl;
        } else {
          foundReq = true;
        }
      } else {
        tempfile << line << endl;
      }
    }
    if(foundReq){
      remove("request.txt");
      rename("tempfile.txt", "request.txt");
    } else {
      warning("Did not find appropriate request!");
    }
}

int bikeIDgenerator() {
  fstream BikeInfo;
  string strbikeID;
  string tmpLine;
  string content;
  int position, MaxbikeID = 0, bikeID;
  BikeInfo.open("bikeInfo.txt", std::ios::in);
  if (!BikeInfo.is_open()) {
    BikeInfo.close();
    return MaxbikeID + 1;
  } else {
    BikeInfo >> content;
    BikeInfo.close();
    if (content.length() == 0) {
      return MaxbikeID + 1;
    } else {
      BikeInfo.open("bikeInfo.txt", std::ios::in);
      while (getline(BikeInfo, tmpLine)) {
        position = tmpLine.find('|');
        strbikeID = tmpLine.substr(0, position);
        bikeID = stoi(strbikeID);
        tmpLine.erase(0, position + 1);
        if (bikeID > MaxbikeID) {
          MaxbikeID = bikeID;
        }
      }
    }
  }
  BikeInfo.close();
  return MaxbikeID + 1;
}

Motorbike::Motorbike() {
  this->bikeID = 0;
  this->model = "";
  this->colour = "";
  this->city = "";
  this->engineSize = 0;
  this->transmissionType = 0;
  this->yearMade = 0;
  this->description = "";
  this->requiredRenterRatingScore = 0;
  this->creditPerDay = 0;
}

Motorbike::Motorbike(int bikeID, string model, string colour, string city,
                     int engineSize, int transmissionType, int yearMade,
                     string description, int creditPerDay) {
  this->bikeID = bikeID;
  this->model = model;
  this->colour = colour;
  this->city = city;
  this->engineSize = engineSize;
  this->transmissionType = transmissionType;
  this->yearMade = yearMade;
  this->description = description;
  this->creditPerDay = creditPerDay;
};

int Motorbike::registerBike()
{
  int cityNum;
  this->bikeID = bikeIDgenerator();
  cout << "Enter the bike's model: ";
  getline(cin, this->model);

  cout << "Enter the bike's colour: ";
  getline(cin, this->colour);

  cout << "Bike can only be registered in these cities:" << endl
       << "1. Ha Noi" << endl
       << "2. Sai Gon" << endl;
  cout << ">> Your choice: ";
  cin >> cityNum;

  while (cityNum != 1 && cityNum != 2)
  {
    cout << "Incorrect option! Please enter again." << endl;
    cout << "Bike can only be registered in these cities:" << endl
         << "1. Ha Noi" << endl
         << "2. Sai Gon" << endl;
    cout << ">> Your choice: ";
    cin >> cityNum;
  }

  if (cityNum == 1)
  {
    this->city = "Ha Noi";
  }
  else if (cityNum == 2)
  {
    this->city = "Sai Gon";
  }

  cout << "Enter the bike's engine Size (cc): ";
  cin >> this->engineSize;

  cout << "Tranmission types are: " << endl
       << "1. Manual Tranmission" << endl
       << "2. Automatic tranmission" << endl
       << "3. CVT transmission" << endl;
  cout << "Enter the bike's Tranmission Type(1,2, or 3): ";
  cin.ignore(1, '\n');
  cin >> this->transmissionType;
  while (this->transmissionType != 1 && this->transmissionType != 2 &&
         this->transmissionType != 3)
  {
    cout << "Incorrect option! Please enter again." << endl;
    cout << "Tranmission types are: " << endl
         << "1. Manual Tranmission" << endl
         << "2. Automatic tranmission" << endl
         << "3. CVT transmission" << endl;
    cout << "Enter the bike's Tranmission Type(1,2, or 3): ";
    cin.ignore(1, '\n');
    cin >> this->transmissionType;
  }

  cout << "Enter the bike manufactured year(YYYY): ";
  cin >> this->yearMade;

  cout << "Enter the bike's description: ";
  cin.ignore(1, '\n');
  getline(cin, this->description);

  cout << "Enter the bike's credit points per day when rented: ";
  cin >> this->creditPerDay;

  fstream BikeInfo;

  BikeInfo.open("bikeInfo.txt", std::ios::in);
  if (!BikeInfo.is_open())
  {
    cout << "There's no file related to bikeInfo.txt yet" << endl;
    cout << "Your bike info will be saved into bikeInfo.txt" << endl;

    BikeInfo.open("bikeInfo.txt", std::ios::out);
    stringstream ss;
    ss << this->bikeID << "|" << this->model << "|" << this->colour << "|city:"
       << this->city << "|" << this->engineSize << "|" << this->transmissionType
       << "|" << this->yearMade << "|" << this->description << "|"
       << this->creditPerDay << "\n";
    string a = ss.str();
    BikeInfo << a;
    cout << "Your bike has been saved!" << endl;
    BikeInfo.close();
  }
  else
  {
    BikeInfo.close();
    BikeInfo.open("bikeInfo.txt", std::ios::app);
    cout << "There is an existing bikeInfo.txt" << endl
         << "Your bike info will be saved into bikeInfo.txt" << endl;
    stringstream ss;
    ss << this->bikeID << "|" << this->model << "|" << this->colour << "|city:"
       << this->city << "|" << this->engineSize << "|" << this->transmissionType
       << "|" << this->yearMade << "|" << this->description << "|"
       << this->creditPerDay << "\n";
    string a = ss.str();
    BikeInfo << a;
    cout << "Your bike has been saved!" << endl;
    BikeInfo.close();
  }
  return this->bikeID;
};

void viewMemInfo () {  
  fstream records;
  
  int position;
  string tmpLine, tmpLine2;
  string username, password, fullName, phoneNumber, idType, idNumber, city, licenseNo;
  Time expiryDate; 
  int bikeID, day, month , year, creditPoint, ratingScore;


  records.open("records.txt", std::ios::in);
  cout << "All Members Info: \n";
  while(getline(records, tmpLine2)) {
    position = tmpLine2.find('|');
    username = tmpLine2.substr(0, position);
    tmpLine2.erase(0, position + 1);

    position = tmpLine2.find('|');
    password = tmpLine2.substr(0, position);
    tmpLine2.erase(0, position + 1);

    position = tmpLine2.find('|');
    bikeID = stoi(tmpLine2.substr(0, position));
    tmpLine2.erase(0, position + 1);

    position = tmpLine2.find('|');
    fullName = tmpLine2.substr(0, position);
    tmpLine2.erase(0, position + 1);

    position = tmpLine2.find('|');
    phoneNumber = tmpLine2.substr(0, position);
    tmpLine2.erase(0, position + 1);

    position = tmpLine2.find('|');
    idType = tmpLine2.substr(0, position);
    tmpLine2.erase(0, position + 1);

    position = tmpLine2.find('|');
    idNumber = tmpLine2.substr(0, position);
    tmpLine2.erase(0, position + 1);

    position = tmpLine2.find('|');
    city = tmpLine2.substr(0, position);
    tmpLine2.erase(0, position + 1);

    position = tmpLine2.find('|');
    licenseNo = tmpLine2.substr(0, position);
    tmpLine2.erase(0, position + 1);

    position = tmpLine2.find('/') ;
    day = stoi(tmpLine2.substr(0, position));
    tmpLine2.erase(0, position + 1);

    position = tmpLine2.find('/');
    month = stoi(tmpLine2.substr(0, position));
    tmpLine2.erase(0, position + 1);

    position = tmpLine2.find('|');
    year = stoi(tmpLine2.substr(0, position));
    tmpLine2.erase(0, position + 13);

    expiryDate.setTime(day, month, year);

    position = tmpLine2.find('|');
    creditPoint = stoi(tmpLine2.substr(0, position));
    tmpLine2.erase(0, position + 7);

    position = tmpLine2.find('|');
    ratingScore = stoi(tmpLine2.substr(0, position));
    tmpLine2.erase(0, position + 1);
    cout << "Username:\t" << username << "\n" << "Password:\t" << password << "\n" << "BikeID:\t\t"<<bikeID << "\n"  << "Full Name:\t" <<fullName << "\n"  << "Phone Number:\t" <<phoneNumber << "\n"  << "Id type:\t" << idType << "\n"  << "Id Number:\t"<<idNumber << "\n"  << "City:\t\t"<<city << "\n"  << "License Number:\t"<<licenseNo << "\n" << "Expiry Date:\t"<< expiryDate.getTime() << "\nCreditpoint:\t"  << creditPoint << "\nScore:\t\t" << ratingScore << "\n\n";
  }
  records.close();
}

void viewBikeInfo () {
  fstream bikeInfo;
  int position;
  string tmpLine, tmpLine2;
  string model, colour, city, description;
  Time expiryDate; 
  int bikeID, engineSize, transmissionType, yearMade, creditPerDay;

  bikeInfo.open("bikeInfo.txt", std::ios::in);
    while(getline(bikeInfo, tmpLine2)) {
      position = tmpLine2.find('|');
      bikeID = stoi(tmpLine2.substr(0, position));
      tmpLine2.erase(0, position + 1);

      position = tmpLine2.find('|');
      model = tmpLine2.substr(0,position);
      tmpLine2.erase(0,position + 1);

      position = tmpLine2.find('|');
      colour = tmpLine2.substr(0,position);
      tmpLine2.erase(0,position + 6 );

      position = tmpLine2.find('|');
      city = tmpLine2.substr(0,position);
      tmpLine2.erase(0,position + 1);

      position = tmpLine2.find('|');
      engineSize = stoi(tmpLine2.substr(0,position));
      tmpLine2.erase(0,position + 1);

      position = tmpLine2.find('|');
      transmissionType = stoi(tmpLine2.substr(0,position));
      tmpLine2.erase(0, position + 1);

      position = tmpLine2.find('|');
      yearMade = stoi(tmpLine2.substr(0,position));
      tmpLine2.erase(0,position + 1);

      position = tmpLine2.find('|');
      description = tmpLine2.substr(0,position);
      tmpLine2.erase(0,position + 1);

      position = tmpLine2.find('|');
      creditPerDay = stoi(tmpLine2.substr(0,position));
      tmpLine2.erase(0,position + 1);

      cout << "BikeID:\t\t\t" << bikeID << "\nModel:\t\t\t" << model << "\nColour:\t\t\t" << colour << "\nCity:\t\t\t" << city << "\nEngine Size:\t\t" << engineSize << "\nTranmission Type:\t" << transmissionType << "\nYear Made:\t\t" << yearMade << "\nDescription:\t\t" << description << "\nCredit Per Day:\t\t" << creditPerDay << "\n\n";
    } 
    bikeInfo.close();
}
    
int main_menu(){
    cout << NORMAL;
	fstream records;  // this file stores members' login information
    fstream bikeInfo; // this file stores bike's information (with bikeID which is not yet connected to the owner)
    
    header();
    divider();

    // DISPLAY MENU
    cout << "Use the app as 1. Guest   2. Member   3. Admin" << endl << endl;
    cout << "Enter your choice: ";

    // store the choice of user as a string to avoid infinite looping when user enters an invalid string
    
    string choice; // this variable stores user's selection from the menu
    getline(cin, choice);
    while (choice != "1" && choice != "2" && choice != "3") {
        warning("You have entered an invalid option, please re-enter.");
        cout << "Enter your choice: ";
        getline(cin, choice);
    }
    
    if (choice == "1") {
        int midstep;
        cout << "View Available Bike Information?\n\t1. Yes\n\t2. No" << endl << ">> Your selection: "; 
        cin >> midstep; 
        if (midstep == 1) view(stoi(choice)); cin.ignore(); 
        cout << "You have not had an account. Create now?\n\t1. Yes\n\t2. No" << endl;
        cout << ">> Your selection: ";
        string choice1;
        getline(cin, choice1);
        while (choice1 != "1" && choice1 != "2") {
            cout << "You have selected an invalid option. Please enter 1 or 2 only." << endl;
            cout << ">> Your selection: ";
            getline(cin, choice1);
        }
        if (choice1 == "1") {
            save();
        } else if (choice1 == "2") {
            cout << "Program terminates, have a good day." << endl;
        }
    } else if (choice == "2") {
        Member m = login();
        int loginSuccessful = 0;
        if(m.getUsername() != ""){loginSuccessful = 1;}
        else{
            cout << "Program exits." << endl;
            return 0;
        } 
       while(1) execMem(m, choice);
    } else if (choice == "3") {
        string inputUsn, inputPwd; 
        cout << "Please enter admin username: ";
        cin >> inputUsn;
        cout << "Please enter admin password: ";
        cin >> inputPwd;
        if(inputUsn == adminUsn && inputPwd == adminPwd){
          while(1) execAdmin();
        } else {
          cout << "Wrong Username or Password, Program terminates.";
        }
        clearScreen(); //clear
    }
    
    return 0;
}

int execMem(Member m, string choice){
    string memberChoice; // this string stores member's choice
    cout << "Menu for Member: " << endl;
    cout << "0. Exit" << endl;
    cout << "1. Search bikes" << endl;
    cout << "2. Top up" << endl;
    cout << "3. Accept a request" << endl;
    cout << "4. View Bikes with rating and reviews" << endl; 
    cout << "5. View renting requests" << endl;
    cout << "6. Show balance" << endl;
    cout << "7. View my information" << endl;
    cout << "8. Cancel request" << endl;
    cout << "9. Write review for the latest bike you rented" << endl;
    cout << "10. Write review for your latest renter" << endl;
		cout << "11. List your bike" << endl;
		cout << "12. Unlist your bike" << endl;

    cout << ">> Your selection: ";
    cin.ignore();
    cin >> memberChoice; 
    while (memberChoice != "0" && memberChoice != "1" && memberChoice != "2" && memberChoice != "3" && memberChoice != "4" && memberChoice != "5" && memberChoice != "6" && memberChoice != "7" && memberChoice != "8" && memberChoice != "9" && memberChoice != "10" && memberChoice != "11" && memberChoice != "12") {
      warning("You have selected an invalid option. Please re-enter.");
      
      cout << ">> Your selection: ";
      cin >> memberChoice; 
    }
    if (memberChoice == "0") {
      cout << "Program exits.\nThank you for using" << endl;
      exit(0);
    } else if (memberChoice == "1") {
        m.searchBike();
    } else if (memberChoice == "2") {
        m.topUp();
    } else if (memberChoice == "3") {
      	m.acceptRequest();
    } else if (memberChoice == "4") { 
        view(stoi(choice)); 
    } else if (memberChoice == "5") { 
        m.viewRequest();
    } else if (memberChoice == "6") { 
        m.showBalance();
    } else if (memberChoice == "7") { 
        m.viewMyInfo();
    } else if (memberChoice == "8") {
        m.cancelRequest();
    } else if (memberChoice == "9") {
        m.writeReviewBike();
    } else if (memberChoice == "10") {
        m.writeReviewRenter();
    } else if (memberChoice == "11") {
        m.listAvailableBike();
    } else if (memberChoice == "12") {
        m.unlistAvailableBike();
    } 
    while (memberChoice != "0"){
        if (1) {
            cout << "\nEnter any key to go back to the main menu ('q' to quit) ..." << endl;
            char keyPressed = _getch();
            if (keyPressed == 'q') {
                exit(0);  
            }
            clearScreen();
            execMem(m, choice);
    }

  }return 0;
}

int execAdmin() {
    string choice;
    cout << "Menu for admin:" << endl;
    cout << "\t0. Exit" << endl;
    cout << "\t1. View members information" << endl;
    cout << "\t2. View bikes information\n" << endl;
    cout << ">> Your selection: ";
    cin.ignore();
    cin >> choice;
    while(choice != "0" && choice != "1" && choice != "2"){
        cout << "Invalid selection, please enter again:";
        cin >> choice; 
    }
    if(choice == "0"){
        exit(0);
    } else if(choice == "1"){
        clearScreen();
        viewMemInfo();
    } else if(choice == "2"){    
        clearScreen();
        viewBikeInfo();
    }
    return 0;
}

