//////////////////////////
// testing perpose only //
//////////////////////////

#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

// Replace SCRIPT with the shell script you want to run
string script = R"delim(SCRIPT)delim";

int run(string command, int output = 0)
{
    FILE *pipe = popen(command.c_str(), "r");

    char buffer[512];
    string result = "";
    while (!feof(pipe))
    {
        if (fgets(buffer, 512, pipe) != NULL)
        {
            for (int i = 0; buffer[i] != '\0'; i++)
            {
                if (buffer[i] == '>')
                    result += "&gt";
                else if (buffer[i] == '<')
                    result += "&lt";
                else if (buffer[i] == ' ')
                    result += "&nbsp;";
                else if (buffer[i] == '\t')
                    result += "&nbsp;&nbsp;";

                else
                    result += buffer[i];
            }
        }
    }
    pclose(pipe);
    if (output)
    {
        cout << result << endl;
    }
    return 0;
}

int main()
{
    // create script
    run("touch script.sh", 0);

    // inject script
    ofstream file("script.sh");
    file << script << endl;
    file.close();

    // run
    run("chmod 700 script.sh", 0);
    run("./script.sh", 1);
}