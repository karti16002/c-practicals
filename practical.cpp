#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Declare variables
  string input_file_name, output_file_name;
  int words_count, lines_count, c++_lines_count;

  // Get the input and output file names from the user
  cout << "Enter the name of the input file: ";
  cin >> input_file_name;
  cout << "Enter the name of the output file: ";
  cin >> output_file_name;

  // Create input and output file streams
  ifstream input_file(input_file_name);
  ofstream output_file(output_file_name);

  // Initialize the variables
  words_count = 0;
  lines_count = 0;
  c++_lines_count = 0;

  // Read the input file and write its contents to the output file
  string line;
  while (getline(input_file, line)) {
    output_file << line << endl;

    // Count the number of words and lines
    words_count += count(line.begin(), line.end(), ' ');
    lines_count++;

    // Check if the line contains the word "c++"
    if (line.find("c++") != string::npos) {
      c++_lines_count++;
    }
  }

  // Close the input and output file streams
  input_file.close();
  output_file.close();

  // Print the number of words, lines, and lines containing "c++"
  cout << "The number of words copied is: " << words_count << endl;
  cout << "The number of lines copied is: " << lines_count << endl;
  cout << "The number of lines containing \"c++\" is: " << c++_lines_count << endl;

  return 0;
}
