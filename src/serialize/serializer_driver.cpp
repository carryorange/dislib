#include <iostream>
#include <unistd.h> // getopt

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1 
namespace {
    using namespace std;
    void printUsage() {

    }

    void parseArguments(int argc, char* argv[]) {
        char option;
        while ((option = getopt(argc, argv, "i:d:")) != -1) {
            cout << "option=" << option;
            if (optarg) {
                cout << ", optarg=" << optarg;
            }
            cout << "\n";
            if (option == '?') { break; }
        }

        cout << "optind=" << optind << endl;
        int c = optind;
        while (c < argc) {
            cout << "argv[" << c << "]="
                 << argv[c] << '\n';
            c++;
        }
    }
}

int main(int argc, char* argv[]) {
    parseArguments(argc, argv);

    return EXIT_SUCCESS;
}