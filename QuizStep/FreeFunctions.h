#pragma once
void SaveNameTofile(string n)
{
	ofstream name("Names.txt", ios::app);
	if (!name.is_open())
		throw exception("File is not opened");
	name << "~ " << n << endl;
	name.close();
}
void ReadNameFromFile()
{
	ifstream f("Names.txt", ios::in);
	if (!f.is_open())
		throw exception("File is not opened");
	string name;
	string symbol;
	while (!f.eof())
	{
		f >> symbol;
		if (!f.eof())
		{
			f >> name;
			cout << name << " ";
		}
	}
	f.close();
}
void deleteNameFromNames(const string& nameToDelete) {
	ifstream inFile("Names.txt", ios::in);
	ofstream outFile("TempNames.txt", ios::out);

	if (!inFile.is_open() || !outFile.is_open()) {
		throw exception("File is not opened");
	}

	string name;
	string symbol;

	while (!inFile.eof()) {
		inFile >> symbol;
		if (!inFile.eof()) {
			inFile >> name;
			if (name != nameToDelete) {
				outFile << "~ " << name << endl;
			}
		}
	}

	inFile.close();
	outFile.close();

	if (remove("Names.txt") != 0) 
		cout << "Error deleting file" << endl;	

	else 
		cout << "File deleted successfully" << endl;

	if (rename("TempNames.txt", "Names.txt") != 0) 
		cout << "Error renaming file" << endl;

	else 
		cout << "File renamed successfully" << endl;
	
}
void CheckNameInFile(string Name)
{
	ifstream f("Names.txt", ios::in);
	if (f.is_open())
	{
		string symbol;
		string name;
		bool isCheck = false;
		while (!f.eof())
		{
			f >> symbol;
			if (!f.eof())
			{
				f >> name;
				if (name == Name)
					throw exception("You have same name of this Name");
			}
		}
		f.close();
	}
}
void CheckNameInFile2(string Name)
{
	ifstream f("Names.txt", ios::in);
	if (f.is_open())
	{
		string symbol;
		string name;
		bool isCheck = false;
		vector<string> names;
		while (!f.eof())
		{
			f >> symbol;
			if (!f.eof())
			{
				f >> name;
				names.push_back(name);
			}
		}
		for (auto i : names)
		{
			if (i == Name)
				isCheck = true;
		}
		if(isCheck ==false)
			throw exception("You entered wrong name");
		f.close();
	}
}
void PrintList(vector<User*>* Users)
{
	int count = 1;
	for (auto i : *Users)
	{
		if (count <= 10)
			i->Print();
		count++;
	}
}
bool Compare(User* a, User* b)
{
	return a->GetScore() > b->GetScore();
}
void shuffleVector(vector<int>& vec) {
	int n = vec.size();

	std::srand(static_cast<unsigned>(std::time(0)));

	for (int i = n - 1; i > 0; --i) {
		int j = std::rand() % (i + 1);
		std::swap(vec[i], vec[j]);
	}
}
void ChangeColorRandom()
{
	srand(time(0));
	int i = (rand() % 14) + 1;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, i);
}

void ShuffleVector(vector<Question*>* Vector)
{
	for (size_t i = 0; i < Vector->size()/2; i++)
	{
		*Vector->at(i) = *Vector->at(Vector->size() / 2 - i);
	}
}
void deleteFile(string& file)
{
	string a = file + ".txt";
	if (remove(a.c_str() ) != 0)
		cout << "File not deleted " << endl;
	else cout << "File  deleted" << endl;
}
