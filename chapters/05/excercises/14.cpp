/*
Read (day-of-the-week,value) pairs from the standart input. For example:

Tuesday 23 Friday 56 Tuesday -3 Thursday 99

Collect all the values for each day of the week in a vector<int>. Write out
the values of the seven day-of-the-week vectors. Print out the sum of the
values in each vector. Ignore illegal days of the week, such Funday,
but accept common synonyns such as Mon and monday. Write out the
number of rejected values
*/

#include "std_lib_facilities.h"

constexpr int days_in_week = 7;
constexpr int index_not_found = -1;

constexpr int index_monday    = 0;
constexpr int index_tuesday   = index_monday + 1;
constexpr int index_wednesday = index_tuesday + 1;
constexpr int index_thursday  = index_wednesday + 1;
constexpr int index_friday    = index_thursday + 1;
constexpr int index_saturday  = index_friday + 1;
constexpr int index_sunday    = index_saturday + 1;


int find_day_of_the_week_index(string day_name) {
	
	vector<vector<string>> day_names{days_in_week};
	
	day_names[index_monday] = {"monday", "Monday", "Mon"};
	day_names[index_tuesday] = {"tuesday", "Tuesday", "Tue"};
	day_names[index_wednesday] = {"wednesday", "Wednesday", "Wed"};
	day_names[index_thursday] = {"thursday", "Thursday", "Thu"};
	day_names[index_friday] = {"friday", "Friday", "Fri"};
	day_names[index_saturday] = {"saturday", "Saturday", "Sat"};
	day_names[index_sunday] = {"sunday", "Sunday", "Sun"};
	
	for (int i = 0; i < day_names.size(); ++i) {
		for (int v = 0; v < day_names[i].size(); ++v) {
			if (day_name == day_names[i][v]) {
				return i;
			}
		}
	}
	
	return index_not_found;
	
}

int main()
{
	try
	{
		// make empty vector with 0-6 indices
		// every index contain a vector of int for each day of the week
		vector<vector<int>> week_data;
		for (int i = 0; i < days_in_week; ++i) {
			vector<int> day_data = {};
			week_data.push_back(day_data);
		}
		
		int rejected = 0;
		string day_name;
		int day_value = 0;
		while (cin >> day_name >> day_value) {
			// find out the index using day_name
			int day_index = find_day_of_the_week_index(day_name);
			// if the index was found..
			if (day_index != index_not_found) {
				// ... add value to the day vector
				week_data[day_index].push_back(day_value);
			} else {
				++rejected;
			}
		}
		
		// print out the sum of the values in each day vector
		for (int i = 0; i < week_data.size(); ++i){
			// calculate sum
			int sum = 0;
			for(int val : week_data[i]){
				sum += val;
			}
			// print the sum
			cout << "The sum for day " << i << " is " << sum << '\n';
		}
		
		// print out number of rejected values
		cout << "Number of rejected values: " << rejected << '\n';
		
		return 0;
	// handle errors	
	} catch (exception& e) {
		cerr << e.what();
		return 1;
	} catch (...) {
		cerr << "Unknown error";
		return 2;
	}
	
}