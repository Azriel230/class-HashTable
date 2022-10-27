#include "hesh.h"

void Hash::InsertHash(const int& num) 
{
	int hashRes = HASHF(num);

	Node* temp = new Node;
	temp->data = num;
	temp->next = nullptr;

	if (table[hashRes] == nullptr)
		table[hashRes] = temp;
	else
	{
		Node* tempNext = table[hashRes];

		while (tempNext->next != nullptr)
			tempNext = tempNext->next;

		tempNext->next = temp;
	}

}

std::ostream& operator<<(std::ostream& stream, const Hash& obj)
{
	for (int i = 0; i < 10; i++)
	{
		if (obj.table[i] == nullptr)
		{
			stream << i << ": " << "NULL" << std::endl;
			continue;
		}

		Node* temp = obj.table[i];
		stream << i <<':';
		while (temp)
		{
			stream << ' ' << temp->data;
			temp = temp->next;
		}

		stream << std::endl;
	}

	return stream;
}

std::istream& operator>>(std::istream& stream, Hash& obj)
{
	int x = 0;
	stream >> x;
	obj.InsertHash(x);
	return stream;
}