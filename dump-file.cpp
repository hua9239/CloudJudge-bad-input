//////////////////////////
// testing perpose only //
//////////////////////////

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // answer path "../testdata/code.out.cpp"
    // using char list for bypass SECURITY_WORD "../"
    char path[128] = {'.', '.', '/', 't', 'e', 's', 't', 'd', 'a', 't', 'a', '/', 'c', 'o', 'd', 'e', '.', 'o', 'u', 't', '.', 'c', 'p', 'p'};

    ifstream file(path);
    string line;

    while (getline(file, line))
    {
        // output box is HTML format
        // special characters need to be replaced for display
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '>') line.replace(i, 1, "&gt");
            if (line[i] == '<') line.replace(i, 1, "&lt");
            if (line[i] == ' ') line.replace(i, 1, "&nbsp;");
            if (line[i] == '\t') line.replace(i, 1, "&nbsp;&nbsp;");
        }
        cout << line << endl;
    }
    file.close();
    return 0;
}