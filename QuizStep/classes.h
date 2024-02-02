#pragma once
class Answer
{
	string _answer1 = "", _answer2 = "", _answer3 = "", _answer4 = "";
	string _Ranswer = "";
public:
	Answer()
	{
		_answer1 = "";
		_answer2 = "";
		_answer3 = "";
		_answer4 = "";
		_Ranswer = "";
	}
	Answer(string a, string b, string c, string d, string ranswer)
	{
		_answer1 = a;
		_answer2 = b;
		_answer3 = c;
		_answer4 = d;
		_Ranswer = ranswer;
	}
	Answer(Answer& other)
	{
		this->_answer1 = other._answer1;
		this->_answer2 = other._answer2;
		this->_answer3 = other._answer3;
		this->_answer4 = other._answer4;
		this->_Ranswer = other._Ranswer;

	}

	Answer operator=(Answer& other)
	{
		this->_answer1 = other._answer1;
		this->_answer2 = other._answer2;
		this->_answer3 = other._answer3;
		this->_answer4 = other._answer4;
		this->_Ranswer = other._Ranswer;
		return *this;
	}
	bool checkAnswer(string answer)
	{
		if (answer == _Ranswer)
			return true;
		return false;
	}
	string GetAnswer1() { return _answer1; }
	string GetAnswer2() { return _answer2; }
	string GetAnswer3() { return _answer3; }
	string GetAnswer4() { return _answer4; }
	string GetRightAnswer() { return _Ranswer; }

};
class Question
{
	string* _question;
	Answer* _answers;
public:
	Question(string question, Answer answers)
	{
		_question = new string(question);
		_answers = new Answer(answers);
	}
	Question(string question, string a1, string a2, string a3, string a4, string Ra)
	{
		_question = new string(question);
		SetAnswers(a1, a2, a3, a4, Ra);
	}
	Question(Question& other)
	{
		this->_question = other._question;
		this->_answers = other._answers;
	}
	void SetAnswers(string a1, string a2, string a3, string a4, string Ra)
	{
		_answers = new Answer(a1, a2, a3, a4, Ra);

	}
	string* GetQuestion() { return _question; }
	Answer* GetAnswers() { return _answers; }
	void Print()
	{
		cout << *_question << endl;
		cout << _answers->GetAnswer1() << " " << _answers->GetAnswer2() << " " << _answers->GetAnswer3() << " " << _answers->GetAnswer4() << endl;
	}
	Question operator=(Question& other)
	{
		this->_question = other._question;
		this->_answers = other._answers;
		return *this;
	}

	~Question()
	{
		if (_question != nullptr)
		{
			delete _question;
			_question = nullptr;
		}
		if (_answers != nullptr)
		{
			delete _answers;
			_answers = nullptr;
		}

	}
};
class Quiz
{
	string* _name;
	vector<Question*>* _questions;
	int _count;
public:
	Quiz()
	{
		_name = nullptr;
		_questions = new vector<Question*>();
		_count = 0;
	}
	Quiz(string name)
	{
		this->_name = &name;
	}
	Quiz(string name, vector<Question*>* questions, int count)
	{
		_name = new string(name);
		_questions = questions;
		_count = count;
	}
	Quiz(Quiz& other)
	{
		this->_questions = other._questions;
		this->_count = other._count;
	}
	Quiz operator=(Quiz& other)
	{
		this->_questions = other._questions;
		this->_count = other._count;
	}
	void SetCount(int count)
	{
		if (count > 0)
			_count = count;
	}
	void SetName(string name)
	{
		if (name.length() < 3 || name.length() > 15)
			throw length_error("Name length is not right");
		if (this->_name == nullptr)
		{
			this->_name = new string(name);
		}
		else
		{
			delete this->_name;

		}
	}
	vector<Question*>* GetQuestions() { return _questions; }
	int GetCount() { return _questions->size(); }
	void SaveToFile(string file)
	{
		ofstream f(file, ios::out);
		if (!f.is_open())
			throw exception("File is not opened");
		for (auto i : *_questions)
		{
			f << "> " << *(i->GetQuestion()) << "\n"
				<< i->GetAnswers()->GetAnswer1() << " "
				<< i->GetAnswers()->GetAnswer2() << " "
				<< i->GetAnswers()->GetAnswer3() << " "
				<< i->GetAnswers()->GetAnswer4() << " "
				<< i->GetAnswers()->GetRightAnswer() << "\n";
		}
		f.close();
	}
	void ClearAllQuestionsAndAnswers()
	{
		for (size_t i = 0; i < _questions->size(); i++)
		{
			delete _questions->at(i);
			_questions->at(i) = nullptr;
		}
		_questions->clear();
	}
	void ReadFromFile(string file)
	{
		ifstream f(file + ".txt", ios::in);
		if (!f.is_open())
			throw exception("File is not opened");
		string question;
		string answer1, answer2, answer3, answer4, rightAnswer;
		string symbol;
		Question* question1;
		ClearAllQuestionsAndAnswers();
		while (!f.eof())
		{
			f >> symbol;
			if (!f.eof())
			{
				getline(f, question);
				f >> answer1 >> answer2 >> answer3 >> answer4 >> rightAnswer;
				question1 = new Question(question, answer1, answer2, answer3, answer4, rightAnswer);
				_questions->push_back(question1);
			}
		}
		f.close();
	}
	void AddQuestion(Question* question)
	{
		if (_count == 0)
		{
			_questions->push_back(question);
			_count++;
		}
		else
		{
			_questions->push_back(question);
			_count++;
		}


	}
	void Shuffle()
	{
		random_device rd;
		mt19937 randomEngine(rd());

		shuffle(_questions->begin(), _questions->end(), randomEngine);
	}
};
class User
{
	string name;
	string surname;
	int age;
public:
	int DuzSay = 0;
	int SehvSay = 0;
	int score = 0;
	User()
	{
		name = "";
		surname = "";
		age = 0;
		score = 0;
	}
	User(string name, string surname, int age)
	{
		SetName(name);
		SetSurname(surname);
		Setage(age);
		this->score = 0;
	}
	User(string name, string surname, int age, int score,int DuzSay, int sehvSay)
	{
		SetName(name);
		SetSurname(surname);
		Setage(age);
		this->score = score;
		this->DuzSay = DuzSay;
		this->SehvSay = sehvSay;
	}
	User(string name, string surname, int age, int score)
	{
		SetName(name);
		SetSurname(surname);
		Setage(age);
		this->score = score;
	}
	User(User& other)
	{
		this->name = other.name;
		this->surname = other.surname;
		this->age = other.age;
		this->score = other.score;
	}
	User operator=(User& other)
	{
		this->name = other.name;
		this->surname = other.surname;
		this->age = other.age;
		this->score = other.score;
		return *this;
	}
	void SetName(string name)
	{
		if (name.length() < 3 && name.length() > 15)
			throw length_error("Length is not right");
		this->name = name;
	}
	void SetSurname(string surname)
	{
		if (surname.length() < 3 && surname.length() > 15)
			throw length_error("lengh is nor right");
		this->surname = surname;
	}
	void Setage(int age)
	{
		if (age < 3 && age > 78)
			throw exception("age is bad");
		this->age = age;
	}
	void SetDuzSay(int count)
	{
		this->DuzSay = count;
	}
	void SetSehvSay(int count)
	{
		this->SehvSay = SehvSay;
	}
	string GetName() { return name; }
	string GetSurname() { return surname; }
	int GetAge() { return age; }
	int GetScore() { return score; }
	int GetDuzSay() { return DuzSay; }
	int GetSehvSay() { return SehvSay; }

	void Print()
	{
		cout << name << " : " << surname << " : " << age << " : " << score << " : " << DuzSay << " : " << SehvSay << endl;
	}
};
class UserDatabase
{
	vector<User*>* users2 = new vector<User*>();
public:

	void ClearUsers()
	{
		for (size_t i = 0; i < users2->size(); i++)
		{
			delete users2->at(i);
			users2->at(i) = nullptr;
		}
		users2->clear();
	}
	void AddUser(User* user)
	{
		users2->push_back(user);
	}
	void SaveTofileUser(string file)
	{
		ofstream f(file, ios::app);
		if (!f.is_open())
			throw exception("File is not opened");
		for (auto i : *users2)
		{
			f << "> " << i->GetName() << " " << i->GetSurname() << " " << i->GetAge() << " " << i->GetScore() << " " << i->DuzSay << " " << i->SehvSay << endl;
		}
		f.close();
	}
	void ReadFromFileUser(string file)
	{
		ifstream f("Users.txt", ios::in);
		if (!f.is_open())
			throw exception("File is not opened");
		string symbol, name, surname;
		int age, score, Dsay, SSay;
		ClearUsers();
		while (!f.eof())
		{
			f >> symbol;
			if (!f.eof())
			{
				f >> name >> surname >> age >> score >> Dsay >> SSay;
				User* a = new User(name, surname, age, score,Dsay,SSay);
				AddUser(a);
			}
		}
		f.close();
	}
	vector<User*>* GetUsers2() { return users2; }
	int GetCount() { return users2->size(); }
};

//class Result
//{
//	vector<User*> users;
//	string QName;
//	int DuzSay;
//	int SehvSay;
//public:
//	Result() = default;
//	Result(User* string name,int DuzSay,int SehvSAy)
//	{
//		this->user = user;
//		QName = name;
//		this->DuzSay = DuzSay;
//		this->SehvSay = SehvSAy;
//	}
//	void SetName(string name)
//	{
//		if (name.length() < 3 && name.length() < 18)
//			throw exception("Invalid length");
//		QName = name;
//
//	}
//	void WriteToFileResult(string file)
//	{
//		ofstream f(file, ios::out);
//		if (!f.is_open())
//			throw exception("File is not opened");
//		f <<"~ " << QName << " "
//			<< user->GetName()<< " "
//			<< user->GetSurname()<< " "
//			<< to_string(user->GetAge())<< " "
//			<< to_string(user->GetScore()) << " "
//			<< to_string(DuzSay) << " " 
//			<< to_string(SehvSay) << "\n";
//		f.close();
//	}
//	
//
//	~Result()
//	{
//		if (user != nullptr);
//		{
//			delete user;
//			user = nullptr;
//		}
//
//	}
////};