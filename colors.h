#define NORMAL  "\x1B[0m"
#define RED  "\x1B[31m" //for warning
#define GREEN  "\x1B[32m" //for confirms
#define YELLOW  "\x1B[33m" 
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"
#define BOLD "\e[1m"
#define warning(x) cout << RED << "WARNING: " << x << endl << NORMAL

//https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c