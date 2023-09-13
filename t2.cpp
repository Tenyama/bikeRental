#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

//CLASS GUEST USER
class Guest{
    public:
};

//CLASS MEMBER T LÀM LẠI 
class Member {
private:
    string username;
    string password;
    string city;
    string fullName;
    string phoneNumber;
    string idType;
    int idNumber;
    int licenseNo; 
    int creditPoint;
public:
    Member(){};
    Member(const string& username, const string& fullName, const string& phoneNumber,
              const string& idType, int idNumber, const string& password, const string& city, int licenseNo, int creditPoint)
        : username(username), fullName(fullName), phoneNumber(phoneNumber),
          idType(idType), idNumber(idNumber), password(password), city(city), licenseNo(licenseNo), creditPoint(creditPoint){}

    string getUsername() const {
        return username;
    }
    string getPassword() const {
        return password;
    }

    string getUserInfoString() const {
        stringstream ss;
        ss << username << setw(10) << password << setw(10) << "|"  << fullName << setw(10) << "|"  << phoneNumber << setw(10) << "|"  << idType << setw(10) << "|"  << idNumber << setw(10) << "|"  << city << setw(10) << "|"  << licenseNo << setw(10) << "|"  << creditPoint << "\n";
        return ss.str();
        }
        
};

void login(fstream &records) { // T ĐÊ LOGIN LÀ FUNCTION RỜI Ở NGOÀI, TẠI VÌ KHI M LOGIN M TIẾN HÀNH LOGIN VỚI CƯƠNG VỊ LÀ GUEST. 
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
            cerr << "System has failed to check member's information." << endl;
            return;
        } else {
            while (records >> username >> password) {
            if (username == enteredUsername && password == enteredPassword) {
                loginSuccessful = true;
            }
            }
            records.close();
            if (loginSuccessful) {
            system("cls");
            cout << "Logged in successfully!" << endl;
            
            return;
            } else {
            system("cls");
            cout << "You have entered incorrect username or password!" << endl;
            
            return;
            }
        }
    }

//FUNCTION TO REGISTER USER
Member registerMember() {
    //LẤY THÔNG TIN VỀ ATTRIBUTES CỦA MEMBER
    string username, fullName, phoneNumber, idType, password, city;
    int idNumber, licenseNo, creditPoint = -20;
    //NHẬN DATA TỪ USER
    cout << "Guest User Registration:\n";
    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);
    cout << "Enter Full Name: ";
    getline(cin, fullName);
    cout << "Enter Phone Number: ";
    cin >> phoneNumber;
    cout << "Enter ID Type (Citizen ID/Passport): ";
    cin.ignore();
    getline(cin, idType);
    cout << "Enter ID/Passport Number: ";
    cin >> idNumber;
    cout << "Enter City: ";
    cin.ignore();
    getline(cin, city);
    cout << "Enter license number: ";
    cin >> licenseNo;
    return Member(username, fullName, phoneNumber, idType, idNumber, password, city, licenseNo, creditPoint);
}

void save(){

    // MỞ FILE
    ofstream outputFile("records.txt", ios::app);

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open the file for writing.\n";
    } else {
        //CREATE A MEMBER WITH GIVEN ATTRIBUTES DATA FROM USER
        Member guest = registerMember();

        //STORE INFOS AS STRINGSTREAM IN FILE
        outputFile << guest.getUserInfoString();

        // You can add member information to the file here if needed.
    }

    // Close the file
    outputFile.close();
    cout << "User info sucessully stored!\n";
}

int main() {
    save();
    login();
    return 0;
}
