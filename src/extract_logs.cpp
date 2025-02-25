#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void extractLogs(const string &filename, const string &date)
{
    ifstream logFile(filename);
    if (!logFile)
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string outputFilename = "../output/output_" + date + ".txt";
    ofstream outputFile(outputFilename);
    if (!outputFile)
    {
        cerr << "Error creating output file: " << outputFilename << endl;
        return;
    }

    string logEntry;
    while (getline(logFile, logEntry))
    {
        if (logEntry.rfind(date, 0) == 0)
        {
            outputFile << logEntry << endl;
        }
    }

    logFile.close();
    outputFile.close();
    cout << "Logs for " << date << " saved to " << outputFilename << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: ./extract_logs YYYY-MM-DD" << endl;
        return 1;
    }

    string date = argv[1];
    string filename = "logs_2024.log";

    extractLogs(filename, date);
    return 0;
}

