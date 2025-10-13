#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int main() {
	string user = getenv("USER");
	string homedir = "/home/" + user + "/";
	string configfiledir = homedir + ".config/kawaiiclip/emoticons.txt";
	
	ifstream inputFile(configfiledir);
    cout << "\nKawaiiClip\n\n";

    vector<string> emoticons;
    string line;

    while (getline(inputFile, line)) {  // Read the file line by line
            emoticons.push_back(line);  // Add each line to the vector
	}

	inputFile.close();
	
    for (size_t i = 0; i < emoticons.size(); i++)  // Use size() method for the vector
        cout << i + 1 << " " << emoticons[i] << " \n";

    cout << endl;

    int index;
    cin >> index;

    cout << endl;

    string selectedEmoticon;
    if (index >= 1 && index <= static_cast<int>(emoticons.size())) { // yea im not familiar with using vectors, just works :3
        selectedEmoticon = emoticons[index - 1];
        string command = "echo '" + selectedEmoticon + "' | wl-copy";
        system(command.c_str());
    } else {
        cout << "\nInvalid input. Please enter a number between 1 and " << emoticons.size() << "." << endl;  // Use size() method
    }
    return 0;
}
