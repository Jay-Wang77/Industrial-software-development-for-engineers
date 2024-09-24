#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

class nofileException : public exception {
public:
    virtual const char* what() const throw() {
        return "Die Datei existiert nicht";
    }
};


void read_file(const string& Dateiname) {
    ifstream file(Dateiname);
    if (!file.is_open()) {
        throw nofileException();
    }

    string buf;
    while (getline(file, buf)) {
        cout << buf << endl;
    }
    file.close();
}

int main() {
    string filename;

    // Benutzer nach Dateiname fragen
    cout << "Geben Sie den Dateinamen ein: ";
    getline(cin, filename);

    // c) try-catch-Block für Ausnahmebehandlung
    try {
        read_file(filename);
    } catch (const exception& e) {
        // fängt alle Ausnahmen ab, die von exception abgeleitet sind
        cout << "Fehler: " << e.what() << endl;
    }

    return 0;
}
