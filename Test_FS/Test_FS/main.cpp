#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	try
	{
		fstream file;
		file.open("test.csv", ios::out | ios::app);

		file.seekg(0, file.end);
		size_t len = file.tellg();
		cout << len << endl;

		if (len == 0)
		{
			file << "Date, Time, Temp, Hum\n";
		}

		for (int i = 20; i <= 25; i++)
		{
			file << i << "." << "10." << "2017" << ", ";
			file << "00:00" << ", ";
			file << i << "C, ";
			file << i + 10 << "%\n";
		}

		for (int i = 25; i >= 20; i--)
		{
			file << 25 + (26 - i) << "." << "10." << "2017" << ", ";
			file << "00:00" << ", ";
			file << i << "C, ";
			file << i + 10 << "%\n";
		}

		file.close();

		cout << "Written to file!" << endl;
	}
	catch (fstream::failure e)
	{
		cout << "Can't write to file!" << endl;
	}

	system("pause");
	return 0;
}