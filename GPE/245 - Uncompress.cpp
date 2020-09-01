#include <iostream>
#include <vector>

using namespace std;

int main () {

    string context;
    vector<string> word_dict;
    while (getline(cin, context)) {

        if (context[0] == '0') break;

        for (int i=0; context[i]; i++) {

            int index;
            string str;
            if (isalpha(context[i])) {

                str = "";
                while (isalpha(context[i])) {
                    str += context[i++];
                }
                word_dict.push_back(str);
                cout << str;
                i--;
            }
            else if (isdigit(context[i])) {

                index = 0;
                while(isdigit(context[i])) {

                    index = index*10 + (context[i++] - '0');
                }
                str = word_dict[word_dict.size()-index];
                word_dict.erase(word_dict.end()-index);
                word_dict.push_back(str);
                cout << str;
                i--;
            }
            else {
                cout << context[i];
            }
        }
        cout << "\n";
    }

    return 0;
}