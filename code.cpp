#include <iostream>

#include <string>

#include <fstream>

using namespace std;


const int MAX_OPTIONS = 10; // Maximum number of options for each question

class project {

public:

    project() {

        cout << endl << endl;

        cout << "*" << endl << endl;

        cout << "<==>  POLL CONDUCTOR  <==>\n" << endl;

    }

};

class Poll : public project {

private:

    string questions[MAX_OPTIONS];

    string options[MAX_OPTIONS][MAX_OPTIONS];

    int optionsCount[MAX_OPTIONS];

    int userResponses[MAX_OPTIONS][MAX_OPTIONS];

    int questionCount;


public:

    Poll() {


        questionCount = 0;

    }


    void loadQuestionsAndOptions(const string& poll_questions) {

        ifstream file(poll_questions);

        string line;


        if (!file) {

            cerr << "Error: Could not open file for reading.\n";

            return;

        }


        while (getline(file, line)) {

            long int questionEnd = line.find("::");

            questions[questionCount] = line.substr(0, questionEnd);


            string optionsString = line.substr(questionEnd + 2);

            int start = 0, optionCount = 0;

            while (true) {

                int end = optionsString.find(",", start);

                if (end == string::npos) {

                    end = optionsString.length();

                }

                options[questionCount][optionCount++] = optionsString.substr(start, end - start);

                if (end == optionsString.length()) {

                    break;

                }

                start = end + 1;

            }

            optionsCount[questionCount] = optionCount;

            questionCount++;

        }

    }


    void takePoll() {

        string response;

        int userCount = 0;


        for (int i = 0; i < questionCount; ++i) {

            for (int j = 0; j < MAX_OPTIONS; ++j) {

                userResponses[i][j] = 0;

            }

        }


        ofstream outputFile("user_responses.txt");


        while (true) {

            cout << "Enter 'q' to quit or any other key to continue: ";

            cin >> response;


            if (response == "q" || response == "Q") {

                cout<<"Your response have been saved."<<endl;

                break;

            }


            userCount++;


            for (int i = 0; i < questionCount; ++i) {

                cout << questions[i] << ":\n";

                for (int j = 0; j < optionsCount[i]; ++j) {

                    cout << j + 1 << ". " << options[i][j] << "\n";

                }

                cout << "\n";


                int optionChoice;

                cout << "Enter your choice (1-" << optionsCount[i] << "): ";

                cin >> optionChoice;

                // Increment the corresponding option in userResponses array

                userResponses[i][optionChoice - 1]++;

            }

        }


        outputFile << "\nResults:\n\n";

        outputFile << "Number of Responses: " << userCount << endl;


        for (int i = 0; i < questionCount; ++i) {

            outputFile << questions[i] << " \n";

            int totalVotes = 0;

            for (int j = 0; j < optionsCount[i]; ++j) {

                outputFile << options[i][j] << ": " << userResponses[i][j] << " votes (" << userResponses[i][j] * 100.0 / userCount << "%)\n";

                totalVotes += userResponses[i][j];

            }

            outputFile << "\n";

        }


        outputFile.close();

    }

};


int main() {

    Poll poll;


/*

   must create questions file in the same folder ...

    questions file must contain questions in the format of :

    Question statement ?::option1,option2,...

   */

poll.loadQuestionsAndOptions("poll_questions.txt");

    poll.takePoll();


    return 0;

}

