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
void shuffleVector(std::vector<int>& vec) {
	int n = vec.size();

	std::srand(static_cast<unsigned>(std::time(0)));

	for (int i = n - 1; i > 0; --i) {
		int j = std::rand() % (i + 1);
		std::swap(vec[i], vec[j]);
	}
}

void ShuffleVector(vector<Question*>* Vector)
{
	for (size_t i = 0; i < Vector->size()/2; i++)
	{
		*Vector->at(i) = *Vector->at(Vector->size() / 2 - i);
	}
}
