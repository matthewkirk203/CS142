/* 
 * Matthew Kirk
 * Section: 4
 * Date: 11/7/2012
 * Midterm 2
 * Description: Determine the restaurant with the most likes from a file
 * Design:
 *   Read from a file and put names and counts into parallel vectors.
 *   Find the name with the largest corresponding like count.
 *	 Print that name
 * Test Cases:
 *   1) I included test files, but in order for them to be effective the program needs to work. See notes below.
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int string_to_int(string s) // I didn't use this. Oh well.
{
   istringstream strm;
   strm.str(s);
   int n = 0;
   strm >> n;
   return n;
}


int find (vector<string> vector, string word)
{
	unsigned int i = 0;
	for (i = 0; i < vector.size(); i++)
	{
		if (vector[i] == word)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	ifstream in_file; 
	cout << "What file would you like analyzed?\n";
	string file_location;
	cin >> file_location;
	in_file.open(file_location.c_str());
	istringstream stream;
	string word;
	vector<string> rest;
	vector<int> count;
	if (in_file.is_open()) //Check to ensure file opened correctly.
	{

		bool valid = true;
		do
		{
			valid = true;
			cout << "Would you like to be shown the data as it is read in? Enter Yes or No.\n";
			string choice;
			cin >> choice;
			string line;
			if (choice == "Yes") // With cout
			{
				while (getline(in_file, line)) //Reading file
				{
					cout << line << endl;
					stream.str(line);
					string temp_rest;
					int new_count;
					stream >> temp_rest >> new_count;
					int index = find(rest, temp_rest);
					if (index == -1)
					{
						rest.push_back(temp_rest);
						count.push_back(new_count);
					}
					else
					{
						count[index] += new_count;
					}
				}
			}
			else if (choice == "No") //No cout.
			{
				while (getline(in_file, line)) //Reading file
				{
					stream.str(line);
					string temp_rest = "";
					int new_count = 0;								//new_count is failing to be assigned after the first one. I could do the whole lab if it would assign correctly.
					stream >> temp_rest >> new_count;
					int index = find(rest, temp_rest);
					if (index == -1)
					{
						rest.push_back(temp_rest);
						count.push_back(new_count);
					}
					else
					{
						count[index] += new_count;
					}
				}
			}
			/*{
			bool check = alphacheck(word);
			int index = find(rest, word);
			if (check == true)
			{
			if (index == -1)
			{
			rest.push_back(word);
			}
			}
			else
			{
			int number = atoi (word);
			if (index == -1)
			{
			count.push_back(
			}
			}
			cout << word << endl;*/

			else
			{
				cout << "Invalid input. Please try again.\n\n";
				valid = false;
			}
		}
		while (valid == false);

		for (int i = 0; i < rest.size(); i++)
		{
			cout << rest[i] << "\t" << count[i] << "\n";
		}
		int largest = count[0];
		for (int i = 0; i < count.size(); i++)  // Finding most likes
		{
			if (count[i] > largest)
			{
				largest = count[i];
			}
		}
		cout << "The most liked restaurant is " << rest[largest] << " " << count[largest] << endl << endl;
	}
	else
	{
		cout << "Unable to open file.\n\n";
	}

	system("pause");
	return 0;
}