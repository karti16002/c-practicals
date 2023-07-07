#include <iostream>
#include <string>

using namespace std;

void copy_string(string str1, string &str2) {
  /* Copies one string to another starting from the last index using pointers. */
  int p1 = str1.length() - 1;
  int p2 = 0;
  while (p1 >= 0) {
    str2[p2] = str1[p1];
    p1 -= 1;
    p2 += 1;
  }
}

bool find_word(string str, string word) {
  /* Finds whether a word occurs in the string (using string class function). */
  return str.find(word) != string::npos;
}

int count_vowels(string str) {
  /* Calculates the total number of vowels in the string. */
  int count = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
      count += 1;
    }
  }
  return count;
}

int main() {
  /* The main function. */
  int choice = 0;
  while (choice != 4) {
    cout << "1. Copy string" << endl;
    cout << "2. Find word" << endl;
    cout << "3. Count vowels" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        string str1, str2;
        cout << "Enter the first string: ";
        cin >> str1;
        str2 = "";
        copy_string(str1, str2);
        cout << "The copied string is: " << str2 << endl;
        break;
      }
      case 2: {
        string str, word;
        cout << "Enter the string: ";
        cin >> str;
        cout << "Enter the word: ";
        cin >> word;
        if (find_word(str, word)) {
          cout << "The word " << word << " occurs in the string" << endl;
        } else {
          cout << "The word " << word << " does not occur in the string" << endl;
        }
        break;
      }
      case 3: {
        string str;
        cout << "Enter the string: ";
        cin >> str;
        int count = count_vowels(str);
        cout << "The number of vowels in the string is: " << count << endl;
        break;
      }
      case 4: {
        cout << "Quitting..." << endl;
        break;
      }
      default: {
        cout << "Invalid choice" << endl;
        break;
      }
    }
  }

  return 0;
}
