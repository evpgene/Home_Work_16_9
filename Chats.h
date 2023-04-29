#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "User.h"
#include "Message.h"

using namespace std;

class Chats
{
	//����������
	bool Q{ false };
	string userName;
	string pass;
	int cmd{ 0 };
	std::string cmd_input;
	char choice{ 'n' };
	vector<User> users; // ������ �������������
	vector<shared_ptr<Chat>> chats; // ������ ���������� �� ����
	Message messageTmp; //���������
	User userTmp; // ��������� ������������
	shared_ptr<User> currentUserPtr{ nullptr }; // ��������� �� �������� ������������
	shared_ptr<Chat> currentChatPtr{ nullptr }; // ��������� �� ������� ���

public:
	// Main menu
	void function0()
	{

		currentChatPtr = make_shared<Chat>(Chat("�����"));

		//������ ������������ ��� ������ ����
		userTmp.setID(static_cast<unsigned long long>(users.size()) + 1); //��������� ID
		userTmp.setLogin("�����");
		users.push_back(userTmp);


		while (!Q) //����
		{
			//���� ���� ������� ������������ - �� ������������� ���
			if (currentUserPtr)
			{
				std::cout << "�������� ������������: ";
				currentUserPtr->printUser();
			}

			std::cout << "������� �������� (0 - �����)" << std::endl;
			std::cin >> cmd_input;

			//��������� ������������ �����
			try
			{
				cmd = std::stoi(cmd_input);
			}
			catch (exception& except)
			{
				cout << endl << except.what() << endl;
				cmd = 0;
			}

			try //��������� ����������
			{
				switch (cmd)
				{
				case 0:
					std::cout << "0 - ������" << std::endl;
					std::cout << "1 - ������� ������ �������� ������������" << std::endl;
					std::cout << "2 - ��������������" << std::endl;
					std::cout << "3 - �������� ���������" << std::endl;
					std::cout << "8 - ����� �� ������� ������" << std::endl;
					std::cout << "9 - ����� �� ���������" << std::endl;
					std::cout << "��� ������������ ������ �������� �� ������ �����" << std::endl;
					break;

				case 1: //�������  ������ �������� ������������
					function1();
					break;
				case 2: // register user (check user)
					function2();
					break;
				case 3: //�������� ������������
					function3();
					break;
				case 8: // logoff
					function8();
					break;
				case 9: //����� �� ���������
					function9();
					break;
				default:
					std::cout << "��� ����� �������: " << cmd << std::endl;
					break;
				}
			}
			catch (exception& except)
			{
				cout << endl << except.what() << endl;
			}

		}
	}
	//�������  ������ �������� �����������
	void function1()
	{
		if (currentUserPtr)
		{
			std::cout << "�������� ������������: ";
			currentUserPtr->printUser();
			std::cout << endl;
			std::cout << "���� ��������� ������������: " << std::endl;
			currentUserPtr->printChatNames();

		}
		//������������� ����� ���� ������������������ �������������
		if (users.size() > 0)
		{
			std::cout << "������������������ ������������: " << std::endl; //users
			for (const auto& u : users)
				u.printUser();//print();
			std::cout << endl;
		}
		else
		{
			std::cout << "��� ������������������ �������������! " << std::endl;
		}
	}
	// register user (check user)
	void function2()
	{
		if (currentUserPtr)
		{
			std::cout << "�������� ������������: ";
			currentUserPtr->printUser();
		}
		if (currentChatPtr)
		{
			std::cout << "�������� ���: ";
			currentChatPtr->printChatName();
		}
		{
			//int foundElement{ 0 }; // ��������� ���������� ��� ������� ���������� ������������
			std::cout << "������� ���� ���" << std::endl; //login
			std::cin >> userName;
			std::cout << userName << endl;
			userTmp.setLogin(userName);

			int found_indx{ -1 };

			for (size_t i = 0; i < users.size(); i++)
			{
				if (users[i].getLogin() == userTmp.getLogin())
				{
					found_indx = i;
					break;
				}
			}

			// ���� ������������ � �������� ������� 
			if (found_indx >= 0) //���� ������������ ������
			{
				//���� ������
				std::cout << "������� ������: " << std::endl;
				std::string tmp_pass;
				std::cin >> tmp_pass;
				if (users[found_indx].getPass() == tmp_pass)
				{
					// �������� ��������� �� ���������� ������������
					currentUserPtr = make_shared<User>(users[found_indx]); //&users[found_indx];
					//������� - ��������� ���...
					std::cout << "�� ����� ���: ";
					currentUserPtr->printUser();
				}
				else
				{
					std::cout << "�� ����� �������� ������: " << std::endl;
				}
			}
			else //���� ������������ �� ������
			{
				std::cout << "��� ������ ������������" << std::endl;
				std::cout << "���������������� ������������ " << userTmp.getLogin() << "? (y/n)" << std::endl;
				std::cin >> choice;
				if (choice == 'y' || choice == 'Y' || choice == '�' || choice == '�') //���������������� ������������ � ��������� �������
				{
					std::cout << "������� ��� ������: " << std::endl;
					std::cin >> pass;

					userTmp.setPass(pass); // ������������� ������
					userTmp.setID(static_cast<unsigned long long>(users.size()) + 1); //��������� ID

					users.push_back(userTmp); //��������� ������������ � ������ �������������

					//���� ������������ ������������ � ������� 
					found_indx = -1;
					for (size_t i = 0; i < users.size(); i++)
					{
						if (users[i].getLogin() == userTmp.getLogin())
						{
							found_indx = i;
							break;
						}
					}

					if (found_indx >= 0) //���� ������������ ������
					{
						currentUserPtr = make_shared<User>(users[found_indx]);  //�������� ��������� �� ���������� ������������ ������������ � ������ ��� ������� �������������
					}
				}
				else if (choice == 'n')
				{

				}
			}
		}

	}
	//�������� ������������
	void function3()
	{
		//������� ��� ��������� ������������ 
		if (currentUserPtr)
		{
			std::cout << "�������� ������������: ";
			currentUserPtr->printUser();

			//������� ����� ���� �������������
			std::cout << "������������������ ������������: " << std::endl;
			for (const auto& u : users)
				u.printUser();

			{
				int found_indx{ 0 }; //��������� ���������� ��������� �������
				int id;  //��������� ���������� �������������
				std::string id_input;
				std::cout << "�������� ������������ ��� ���� (������� �����) " << std::endl;
				std::cin >> id_input;
				//��������� ������������ �����
				try
				{
					id = std::stoi(id_input);
				}
				catch (exception& except)
				{
					cout << endl << except.what() << endl;
					id = -1;
				}

				//����� ������������ � �������� id
				for (size_t i = 0; i < users.size(); i++)
				{
					if (users[i].getID() == id)
					{
						found_indx = i;
						break;
					}
				}

				if (found_indx != -1)
				{
					//����� ���������� ������������ ��� ������������ ��������� ���������
					std::cout << "������������ ������: ";
					users[found_indx].printUser();
				}
				else
				{
					std::cout << "��� ������ ������������! " << std::endl;
				}

				std::string chatName; //��� ���� ������ ����������
				std::string chatName_2; //��� ���� ������ ����������
				if (currentUserPtr)
				{
					if (users[found_indx].getLogin() == "�����") //��� ������������ - ����� � ��� ���� ����� ���� �����.
					{
						chatName = "�����";
					}
					else
					{
						//������������ ����� ���� ������ �����
						chatName = currentUserPtr->getLogin();
						chatName += users[found_indx].getLogin();
					}
					//������������ ����� ���� ������ �����
					chatName_2 = users[found_indx].getLogin();
					chatName_2 += currentUserPtr->getLogin();
				}

				{
					int indx{ -1 };
					for (size_t i = 0; i < chats.size(); i++)
					{
						if (chats[i]->getChatName() == chatName)
						{
							indx = i;
							break;
						}
					}

					int indx_2{ -1 };

					for (size_t i = 0; i < chats.size(); i++)
					{
						if (chats[i]->getChatName() == chatName_2)
						{
							indx_2 = i;
							break;
						}
					}

					if (!(indx == -1))
					{
						currentChatPtr = chats[indx];
						std::cout << "����� ��� ��� ����������: " << currentChatPtr->getChatName() << std::endl;
						currentChatPtr->printMessage();
					}
					else if (!(indx_2 == -1))
					{
						currentChatPtr = chats[indx_2];
						std::cout << "����� ��� ��� ����������: " << currentChatPtr->getChatName() << std::endl;
						currentChatPtr->printMessage();
					}
					else //���� ������ ���� ��� - ������ ��� � ��������� ��������� �� ���� � ������ ����� ������� ������������
					{
						currentChatPtr = make_shared<Chat>(chatName);
						chats.push_back(currentChatPtr);
						currentUserPtr->addChat(currentChatPtr); // ��������� ��� � �������� ������������
						if (currentUserPtr->getLogin() != users[found_indx].getLogin()) // ���� ���������� �� ��� ������� ������������
						{
							users[found_indx].addChat(currentChatPtr); // ��������� ��� � ������������ �����������
						}
					}

					//������� ���������
					{
						// ��������� ���������
						std::string tmpString;
						std::cout << "������� ���� ���������: "; //<< std::endl;
						cin.ignore();
						std::getline(std::cin, tmpString);

						// ������� ����/����� ����������� �� ������� �������
						time_t now = time(0);
						// ����������� now � ������ string
						char dt[26];
						ctime_s(dt, sizeof dt, &now);
						std::string str = dt;
						Message currentMessage;
						currentMessage.setMessage(tmpString);
						currentMessage.setTimeSend(str);
						if (currentUserPtr)
						{
							currentMessage.userName(currentUserPtr->getLogin());
						}
						currentChatPtr->addMessage(currentMessage);
						currentChatPtr->printMessage(); // ����������� ��� ������
						std::cout << endl;
					}
				}
			}
		}
		else
		{
			std::cout << "�� �� ����������������! " << std::endl;
		}

	}
	// logoff
	void function8()
	{
		if (currentUserPtr)
		{
			std::cout << "�� ����� �� ������� ������";
			currentUserPtr->printUser();
			std::cout << std::endl;
			currentUserPtr = nullptr;
		}
		else
		{
			std::cout << "������ ��� ����� �� ������� ������ ���������� � �� �����. �� �� ����� � ������ ������." << std::endl;
		}

	}
	//����� �� ���������
	void function9()
	{
		Q = true;
	}
};

