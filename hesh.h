#pragma once
#define HASHF(x) (x)%10
#include <iostream>

struct Node 
{
	int data;
	Node* next;
};

class Hash 
{
private:
	Node* table[10];
public:
	Hash()
	{
		for (int i = 0; i < 10; i++)
			table[i] = nullptr;
	}

	Hash(const Hash& obj)
	{
		Node* temp = nullptr;

		for (int i = 0; i < 10; i++)
		{
			if (obj.table[i] != nullptr)
			{
				table[i] = new Node;
				table[i]->data = obj.table[i]->data;
				table[i]->next = obj.table[i]->next;

				if (obj.table[i]->next != nullptr)
				{
					temp = obj.table[i]->next;
					Node* tempMain = table[i];
					while (temp)
					{
						Node* temp1 = new Node;
						temp1->data = temp->data;
						temp1->next = temp->next;

						tempMain->next = temp1;

						tempMain = tempMain->next;
						temp = temp->next;
					}
				}
			}
			else
				table[i] = nullptr;
		}
	}

	~Hash() 
	{
		Node* temp = nullptr;

		for (int i = 0; i < 10; i++)
		{
			if (table[i] != nullptr)
			{
				temp = table[i];
				Node* tempPrev = table[i];

				while (temp)
				{
					tempPrev = temp;
					temp = temp->next;
					delete tempPrev;
				}
			}
		}
	}

	void InsertHash(const int& num);

	friend std::ostream& operator<<(std::ostream& stream, const Hash& obj);
	friend std::istream& operator>>(std::istream& stream, Hash& obj);
};