#include <iostream>
#include <random>
using namespace std;

class Auth {
    private: 
        string name;
        char gender;
        int password;
    public: 
        string get_name() {
            return name;
        }
        void set_name(string re) {
            name = re;
        }
        int get_password() {
            return password;
        }
        void set_password(int pwd) {
            password = pwd;
        }
        char get_gender() {
            return gender;
        }
        void set_gender(char gen) {
            gender = gen;
        }
};

struct Error {
    int status;
    string message;
};

int deposit = 0, spend = 0;

bool enoughOrNot(int money) {
    if(money < 0 || money > deposit) {
        Error err;
        err.status = 400;
        err.message = "Invalid Amount";
        cout << err.status << " | " << err.message;
        return false;
    };
    return true;
};

int luckyNumber() {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> distribution(1, 1000);

    // Generate a random number between 1 and 1000
    return distribution(rng);
};

string checkGender(char gen) {
    if (gen == 'M' || gen == 'm') {
        return "Mr.";
    } else if (gen == 'F' || gen == 'f') {
        return "Miss.";
    } else {
        return "IG"; // Invalid Gender
    }
}

int main()
{
    /// __auth__
      Auth user;
      /// register
      string name;
      char gender, login, play;
      int pwd;
      
      /// login
      string log_name;
      int log_pwd;
      
      cout << "Please enter your name: "; cin >> name; cout << "\n";
      cout << "Please enter your gender(M/F): "; cin >> gender; cout << "\n";
     cout << "Please enter your password: "; cin >> pwd; cout << "\n";
     
     string user_gender = checkGender(gender);
     if (user_gender == "IG") {
        Error err;
        err.status = 400;
        err.message = "Bad Request!";
        cout << err.status << " | " << err.message;
        return 0;
     };;
     user.set_name(name); user.set_password(pwd); user.set_gender(gender);

     cout << "\n\nYour account " << user.get_name() << " is successfully registered!\n";
     cout << "If you want to keep play the game, you must login!(Y/y): ";
     cin >> login;
     if (!(login == 'Y' || login == 'y')) return 0;
     cout << "Please enter your name: "; cin >> log_name; cout << "\n";
     cout << "Please enter your password: "; cin >> log_pwd; cout << "\n";
     bool checkCredentials = log_name == user.get_name() && log_pwd == user.get_password();
     if (!checkCredentials) {
        Error err;
        err.status = 401;
        err.message = "Unauthorized Access!";
        cout << err.status << " | " << err.message;
         return 0;
     };

     cout << "Login successful!\n";
     cout << "Keep play the game?(Y/y): ";
     cin >> play;
     if (!(play == 'Y' || play == 'y')) return 0;
     cout << "\n\n\n";
     
    /// __end __auth__
    
    //// __game__start__
   int lucky_number;
   char play_again = 'y';
  
   cout << "\t\t\tWelcome to online lottery game " << user_gender << user.get_name(); cout << "\n\n";
   cout << "How much do you want to deposit in your account?\n\t\t\t= ";
   cin >> deposit;
   cout << "\nNow your Deposit in account: " << deposit << "\n\n";
   
   while(play_again == 'Y' || play_again == 'y') {
       cout << "Let's start the game..." << endl;
       cout << "How much do you want to spend?: ";
       cin >> spend;
       if(!enoughOrNot(spend)) return 0;
       cout << "What's your lucky number: ";
       cin >> lucky_number;
       cout << "\n";
       
       int LUCKY_NUMBER = luckyNumber();
       if (lucky_number != 2) {
           deposit -= spend;
           cout << "Missed this time. Lucky number is " << LUCKY_NUMBER << "\n";
           cout << "Now your final balance is " << deposit << "\n\n";
       } else {
           deposit += spend * 2;
           cout << "Wow, you won!!!";
           cout << "Now, your final balance is " << deposit << endl;
       }
          cout << "Do you want to play again?(Y/y): ";
          cin >> play_again;
          cout << "\n";
   }
   
       return 0;
}
