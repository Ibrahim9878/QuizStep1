#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <list>
#include <algorithm>
#include <cassert>
#include <random>
using namespace std;
#include"classes.h"
#include"FreeFunctions.h"
#include"Global Variable.h"

class System
{
public:
	static void Main()
	{
		Quiz quiz;
		UserDatabase users;
		try
		{
			while (true) {
			BaseMenu:
				system("cls");
				cout << Animation << endl;
				cout << menu << endl;
				int secim;
				cout << "Your choice: ";
				cin >> secim;
				if (secim == 1)
				{
				b:
					cin.ignore();
					Sleep(100);
					system("cls");
					string QName;
					cout << "Enter Quiz name: ";
					getline(cin, QName);
					CheckNameInFile(QName);
					quiz.SetName(QName);
					int count;
					cout << "Enter Count: ";
					cin >> count;
					do
					{
						int a = 1;
						vector<Question*> questions;
						for (size_t i = 0; i < count; i++)
						{

							cin.ignore();
							string question;
							string a1, a2, a3, a4, Ra;
							cout << "Enter Your question: ";
							getline(cin, question);
							cout << "Enter Answers (a1,a2,a3,a4,Ra) : ";
							cin >> a1 >> a2 >> a3 >> a4 >> Ra;
							int choose;
							/*if (a == 1)
							{
								Question* q = new Question(question, a1, a2, a3, a4, Ra);
								questions.push_back(q);
							}*/
							a++;
							cout << "Choose a thing: ";
							cin.ignore();
							
							if (i == count - 1)
							{
								Question* q = new Question(question, a1, a2, a3, a4, Ra);
								questions.push_back(q);
								int choose2;
								while (true)
								{
									cout << menuCQ2 << endl;
									cout << "Choose a thing: ";
									cin >> choose2;
									if (choose2 == 1)
									{
										goto b;
									}
									else if (choose2 == 2)
									{
										for (auto j : questions)
										{
											quiz.AddQuestion(j);
										}
										break;
									}
									else
									{
										cout << "You choosed wrong" << endl;
									}
								}
								break;
							}
							cout << menuCQ << endl;
							cin >> choose;
							if (choose == 1)
							{
								Question* q = new Question(question, a1, a2, a3, a4, Ra);
								questions.push_back(q);
								continue;
							}
							else if (choose == 2)
							{
								goto b;
							}
							else if (choose == 3)
							{
								for (auto j : questions)
								{
									quiz.AddQuestion(j);
								}
								break;
							}
							else
							{
								cout << "You choosed Wrong" << endl;
							}

						}
						break;
					} while (true);
					quiz.SaveToFile(QName + ".txt");
					SaveNameTofile(QName);
				}
				else if (secim == 2)
				{
					
					int Myi = 0;
					int secim2;
					int count1 = 1;
					int DuzSay = 0, SehvSay = 0;
					cin.ignore();
					string name, surname;
					int age;
					cout << "Enter your Name: ";
					getline(cin, name);
					cout << "Enter Your Surname: ";
					getline(cin, surname);
					cout << "Enter your Age: ";
					cin >> age;
					User* user = new User(name, surname, age);
					try
					{
						cin.ignore();
						ReadNameFromFile();

						string choose;
						cout << endl << "Choose one of theese names: ";
						getline(cin, choose);
						quiz.ReadFromFile(choose);
						quiz.SetName(choose);
						quiz.Shuffle();
						vector<string> answers;
						
						string answer;
						while (true)
						{
						c:
							quiz.GetQuestions()->at(Myi)->Print();
							cout << "Your Answer: ";
							getline(cin, answer);
							answers.push_back(answer);
							if (count1 == 1)
							{
								while (true)
								{
									cout << menuSQ3 << endl;
									cout << "Choose a thing: " << endl;
									cin >> secim2;
									if (secim2 == 1)
									{
										Myi++;
										count1++;
										cin.ignore();
										goto c;
									}
									else if (secim2 == 2)
									{
										for (size_t i = 0; i < 1; i++)
										{
											if (quiz.GetQuestions()->at(i)->GetAnswers()->checkAnswer(answers[i]))
											{
												user->score += 1;
												user->DuzSay++;
											}
											else user->SehvSay++;

										}
										users.AddUser(user);
										users.SaveTofileUser("Users.txt");
										goto BaseMenu;
									}
									else
									{
										cout << "You choosed wrong" << endl;
									}
								}
							}
							else if (count1 == quiz.GetCount())
							{
								while (true)
								{
									cout << menuSQ2 << endl;
									cout << "Choose a thing: " << endl;
									cin >> secim2;
									if (secim2 == 1)
									{
										Myi--;
										count1--;
										cin.ignore();
										goto c;
									}
									else if (secim2 == 2)
									{
										for (size_t i = 0; i < quiz.GetCount(); i++)
										{
											if (quiz.GetQuestions()->at(i)->GetAnswers()->checkAnswer(answers[i]))
											{
												user->score += 1;
												user->DuzSay++;
											}
											else user->SehvSay++;

										}
										users.AddUser(user);
										users.SaveTofileUser("Users.txt");
										goto BaseMenu;
									}
									else
									{
										cout << "You choosed wrong" << endl;
									}
								}
							}
							else
							{
								while (true)
								{
									cout << menuSQ1 << endl;
									cout << "Choose a thing: " << endl;
									cin >> secim2;
									if (secim2 == 1)
									{
										Myi++;
										count1++;
										cin.ignore();
										goto c;
									}
									else if (secim2 == 2)
									{
										Myi--;
										count1--;
										cin.ignore();
										goto c;
									}
									else if (secim2 == 3)
									{
										for (size_t i = 0; i < 1; i++)
										{
											if (quiz.GetQuestions()->at(i)->GetAnswers()->checkAnswer(answers[i]))
												user->score += 1;

										}
										users.AddUser(user);
										users.SaveTofileUser("Users.txt");
										goto BaseMenu;
									}
									else
									{
										cout << "You choosed wrong" << endl;
									}
								}
							}
							
							
						}

						
					}
					catch (exception& ex)
					{
						cout << ex.what() << endl;
					}
				}
				else if (secim == 3)
				{
					users.ReadFromFileUser("Users.txt");
					sort(users.GetUsers2()->begin(), users.GetUsers2()->end(), Compare);

					cout << " Name:" << "Surname:" << "Age:" << "Score:" << "DuzSay:" << "SehvSay" << endl;

					PrintList(users.GetUsers2());
					system("pause");
				}
				else if (secim == 0)
				{
					break;
				}
				else
					cout << "Secim Yanlisdir" << endl;
			}
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
		}
	}
};

int main()
{
	System::Main();
}