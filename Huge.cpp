#include <iomanip>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Node {
public:
	string datas;
	Node* next;
	Node() :next(NULL) {}
	Node(string dt) :next(NULL), datas(dt) {}
};
class HugeInt {
public:
	Node* head;
	HugeInt() :head(NULL) {}
	bool isEmpty()
	{
		return head == NULL;
	}
	void clearAll() {
		Node* walk = head;
		Node* t = NULL;
		while (walk != NULL)
		{
			t = walk;
			walk = walk->next;
			delete t;
		}
		head = NULL;
	}
	int Len()
	{
		Node* walk = head;
		int l = 0;
		while (walk != NULL)
		{
			l++;
			walk = walk->next;
		}
		l = l * 3+l/3;
		return l;
	}
	void add(string dt)
	{
		if (dt != "-")
		{
			if (stoi(dt) > 999 || stoi(dt) < 0) return;
		}
		Node* t = new Node(dt);
		Node* walk = head;
		if (head == NULL) head = t;
		else
		{
			t->next = head;
			head = t;
		}
	}
	void print()
	{
		int first = 1;
		Node* walk = head;
		while (walk != NULL)
		{
			if (first == 1 && walk->datas != "-")
			{
				cout << stoi(walk->datas);
				first = 0;
			}
			else
			{
				cout << walk->datas;
			}

			if (walk->next != NULL && walk->datas != "-") cout << ",";
			walk = walk->next;
		}
	}
};

HugeInt SumHuge(Node* h1, Node* h2)
{
	stack <int> H1S;
	stack <int> H2S;
	int cnt1 = 0, cnt2 = 0;
	while (h1 != NULL)
	{
		H1S.push(stoi(h1->datas));
		h1 = h1->next;
		cnt1++;
	}
	while (h2 != NULL)
	{
		H2S.push(stoi(h2->datas));
		h2 = h2->next;
		cnt2++;
	}
	HugeInt temp;
	int sum = 0;
	int tail = 0;
	if (cnt1 >= cnt2)
	{
		sum = 0;
		tail = 0;
		while (!H1S.empty())
		{
			if (!H2S.empty())
			{
				sum = (H1S.top() + tail) + H2S.top();
				H1S.pop(); H2S.pop();
				if (sum == 0)
				{
					temp.add("000");
					tail = 0;
				}
				else if (sum > 0 && sum < 10)
				{
					temp.add("00" + to_string(sum));
					tail = 0;
				}
				else if (sum > 9 && sum < 100)
				{
					temp.add("0" + to_string(sum));
					tail = 0;
				}
				else if (sum < 1000) {
					temp.add(to_string(sum));
					tail = 0;

				}
				else if (sum == 1000)
				{
					tail = sum / 1000;
					temp.add("000");
				}
				else
				{
					tail = sum / 1000;
					if ((sum - 1000) > 0 && (sum - 1000) < 10)
					{
						temp.add("00" + to_string((sum - 1000)));
					}
					else if ((sum - 1000) > 9 && (sum - 1000) < 100)
					{
						temp.add("0" + to_string((sum - 1000)));
					}
					else {
						temp.add(to_string((sum - 1000)));
					}
				}
			}
			else
			{
				sum = H1S.top() + tail;
				H1S.pop();
				if (sum == 1000)
				{
					temp.add("000");
					tail = 1;
				}
				else
				{
					if (sum > 0 && sum < 10)
					{
						temp.add("00" + to_string(sum));
					}
					else if (sum > 9 && sum < 100)
					{
						temp.add("0" + to_string(sum));
					}
					else {
						temp.add(to_string(sum));
					}
					tail = 0;
				}
			}
		}
		if (tail == 1)
		{
			temp.add(to_string(1));
		}
	}
	sum = 0;
	tail = 0;
	if (cnt1 < cnt2)
	{
		while (!H2S.empty())
		{
			if (!H1S.empty())
			{
				sum = (H2S.top() + tail) + H1S.top();
				H2S.pop(); H1S.pop();
				if (sum == 0)
				{
					temp.add("000");
					tail = 0;
				}
				else if (sum > 0 && sum < 10)
				{
					temp.add("00" + to_string(sum));
					tail = 0;
				}
				else if (sum > 9 && sum < 100)
				{
					temp.add("0" + to_string(sum));
					tail = 0;
				}
				else if (sum < 1000) {
					temp.add(to_string(sum));
					tail = 0;
				}
				else if (sum == 1000)
				{
					tail = sum / 1000;
					temp.add("000");
				}
				else
				{
					tail = sum / 1000;
					if ((sum - 1000) > 0 && (sum - 1000) < 10)
					{
						temp.add("00" + to_string((sum - 1000)));
					}
					else if ((sum - 1000) > 9 && (sum - 1000) < 100)
					{
						temp.add("0" + to_string((sum - 1000)));
					}
					else {
						temp.add(to_string((sum - 1000)));
					}
				}
			}
			else
			{
				sum = H2S.top() + tail;
				H2S.pop();
				if (sum == 1000)
				{
					temp.add("000");
					tail = 1;
				}
				else
				{
					if (sum > 0 && sum < 10)
					{
						temp.add("00" + to_string(sum));
					}
					else if (sum > 9 && sum < 100)
					{
						temp.add("0" + to_string(sum));
					}
					else {
						temp.add(to_string(sum));
					}
					tail = 0;
				}
			}
		}
		if (tail == 1)
		{
			temp.add(to_string(1));
		}
	}
	return temp;
}
HugeInt SubHuge(Node* h1, Node* h2)
{
	stack <int> H1S;
	stack <int> H2S;
	int cnt1 = 0, cnt2 = 0;
	int Firsth1 = stoi(h1->datas);
	int Firsth2 = stoi(h2->datas);
	while (h1 != NULL)
	{
		H1S.push(stoi(h1->datas));
		h1 = h1->next;
		cnt1++;
	}
	while (h2 != NULL)
	{
		H2S.push(stoi(h2->datas));
		h2 = h2->next;
		cnt2++;
	}
	HugeInt temp;
	int sub = 0;
	int tail = 0;
	if (cnt1 > cnt2)
	{
		while (!H1S.empty())
		{
			if (!H2S.empty())
			{
				sub = (H1S.top() - tail) - H2S.top();
				H1S.pop(); H2S.pop();
				if (sub == 0)
				{
					temp.add("000");
					tail = 0;
				}
				else if (sub < 0) {
					sub = (sub + 1000);
					temp.add(to_string(sub));
					tail = 1;
				}
				else if (sub > 0 && sub < 10) {

					temp.add("00" + to_string(sub));
					tail = 0;
				}
				else if (sub > 9 && sub < 100) {

					temp.add("0" + to_string(sub));
					tail = 0;
				}
				else
				{
					tail = 0;
					temp.add(to_string(sub));
				}
			}
			else
			{
				temp.add(to_string(H1S.top() - tail));
				H1S.pop();
				tail = 0;
			}
		}
	}
	sub = 0;
	tail = 0;
	if (cnt1 < cnt2)
	{
		while (!H2S.empty())
		{
			if (!H1S.empty())
			{
				sub = (H2S.top() - tail) - H1S.top();
				H1S.pop(); H2S.pop();
				if (sub == 0)
				{
					temp.add("000");
					tail = 0;
				}
				else if (sub < 0) {
					sub = 1000 + sub;
					temp.add(to_string(sub));
					tail = 1;
				}
				else if (sub > 0 && sub < 10) {
					temp.add("00" + to_string(sub));
					tail = 0;
				}
				else if (sub > 9 && sub < 100) {

					temp.add("0" + to_string(sub));
					tail = 0;
				}
				else
				{
					tail = 0;
					temp.add(to_string(sub));
				}
			}
			else
			{
				temp.add(to_string(H2S.top() - tail));
				H2S.pop();
				tail = 0;
			}
		}
		temp.add("-");
	}
	sub = 0;
	tail = 0;
	if (cnt1 == cnt2)
	{
		if (Firsth1 >= Firsth2)
		{
			while (!H1S.empty())
			{
				if (!H2S.empty())
				{
					sub = (H1S.top() - tail) - H2S.top();
					H1S.pop(); H2S.pop();
					if (sub == 0)
					{
						temp.add("000");
						tail = 0;
					}
					else if (sub < 0) {
						sub = 1000 - (sub + 1000);
						temp.add(to_string(sub));
						tail = 1;
					}
					else if (sub > 0 && sub < 10) {

						temp.add("00" + to_string(sub));
						tail = 0;
					}
					else if (sub > 9 && sub < 100) {
						temp.add("0" + to_string(sub));
						tail = 0;
					}
					else
					{
						tail = 0;
						temp.add(to_string(sub));
					}
				}
				else
				{
					temp.add(to_string(H1S.top() - tail));
					H1S.pop();
					tail = 0;
				}
			}
		}
		if (Firsth1 < Firsth2)
		{
			while (!H2S.empty())
			{
				if (!H1S.empty())
				{
					sub = (H2S.top() - tail) - H1S.top();
					H1S.pop(); H2S.pop();

					if (sub == 0)
					{
						temp.add("000");
						tail = 0;
					}
					else if (sub < 0) {
						sub = 1000 - (sub + 1000);
						temp.add(to_string(sub));
						tail = 1;
					}
					else if (sub > 0 && sub < 10) {

						temp.add("00" + to_string(sub));
						tail = 0;
					}
					else if (sub > 9 && sub < 100) {

						temp.add("0" + to_string(sub));
						tail = 0;
					}
					else
					{
						tail = 0;
						temp.add(to_string(sub));
					}
				}
				else
				{
					temp.add(to_string(H2S.top() - tail));
					H2S.pop();
					tail = 0;
				}
			}
			temp.add("-");
		}
	}
	return temp;
}

HugeInt MultiHuge(Node* h1, Node* h2)
{
	stack <int> H1S;
	stack <int> H2S;
	int cnt1 = 0, cnt2 = 0;
	Node* ts = h2;
	while (h1 != NULL)
	{
		H1S.push(stoi(h1->datas));
		h1 = h1->next;
		cnt1++;
	}

	while (h2 != NULL)
	{
		H2S.push(stoi(h2->datas));
		h2 = h2->next;
		cnt2++;
	}

	HugeInt tempsum;
	long r = 1;
	while (!H1S.empty())
	{
		int rep = H1S.top() * r;
		H1S.pop();
		for (int i = 0; i < rep; i++)
		{
			tempsum = SumHuge(tempsum.head, ts);
		}
		r = r * 1000;

	}
	return tempsum;
}
int main()
{
	string h1, h2;
	int op = 0;
	HugeInt Huge1, Huge2;
	while (op != 7)
	{
		system("CLS");
		cout << "1.	Enter first HugeInt" << endl;
		cout << "2.	Enter second HugeInt" << endl;
		cout << "3.	Print first and Second HugeInt" << endl;
		cout << "4.	Perform + and print operands and result." << endl;
		cout << "5.	Perform - and print operands and result." << endl;
		cout << "6.	Perform * and print operands and result." << endl;
		cout << "7.	Exit" << endl << endl;
		cout << "Enter your opinion:";
		cin >> op;
		switch (op) {
		case 1: {
			Huge1.clearAll();
			cout << "Enter Huge Int-1:";
			cin >> h1;
			int dig = 1;
			for (int i = h1.length() - 1; i >= 0; i--)
			{
				if (dig == 3)
				{

					Huge1.add(h1.substr(i, 3));
					dig = 0;
				}
				dig++;
			}
			if (dig - 1 != 0)
				Huge1.add(h1.substr(0, dig - 1));
			break;
		}
		case 2: {
			Huge2.clearAll();
			cout << "Enter Huge Int-2:";
			cin >> h2;
			int dig = 1;
			for (int i = h2.length() - 1; i >= 0; i--)
			{
				if (dig == 3)
				{

					Huge2.add(h2.substr(i, 3));
					dig = 0;
				}
				dig++;
			}
			if (dig - 1 != 0)
				Huge2.add(h2.substr(0, dig - 1));
			break;

		}
		case 3: {
			cout << "First HugeInt =";
			Huge1.print();
			cout << endl;
			cout << "Second HugeInt=";
			Huge2.print();
			cout << endl;
			cin.ignore();
			cout << endl << "Press Enter to continue";
			getchar();

			break;
		}
		case 4: {
			HugeInt SumH;
			SumH = SumHuge(Huge1.head, Huge2.head);
			cout << setw(40-Huge1.Len()) << setfill(' ') << right;
			Huge1.print();
			cout << endl;
			cout << setw(40-Huge2.Len()) << setfill(' ') << right;
			Huge2.print();
			cout << endl;
			cout << "+"; 
			cout << setw(40) << setfill('_') << right;
			cout << " "<<endl;
			cout << setw(40-SumH.Len()) << setfill(' ') << right;
			SumH.print();
			cin.ignore();
			cout << endl << "Press Enter to continue";
			getchar();
			break;
		}
		case 5: {
			HugeInt SubH;
			SubH = SubHuge(Huge1.head, Huge2.head);
			cout << setw(40 - Huge1.Len()) << setfill(' ') << right;
			Huge1.print();
			cout << endl;
			cout << setw(40 - Huge2.Len()) << setfill(' ') << right;
			Huge2.print();
			cout << endl;
			cout << "-";
			cout << setw(40) << setfill('_') << right;
			cout << " " << endl;
			cout << setw(40 - SubH.Len()) << setfill(' ') << right;
			SubH.print();
			cin.ignore();
			cout << endl << "Press Enter to continue";
			getchar();
			break;
		}
		case 6: {

			HugeInt MultiH;
			MultiH = MultiHuge(Huge1.head, Huge2.head);
			cout << setw(40 - Huge1.Len()) << setfill(' ') << right;
			Huge1.print();
			cout << endl;
			cout << setw(40 - Huge2.Len()) << setfill(' ') << right;
			Huge2.print();
			cout << endl;
			cout << "x";
			cout << setw(40) << setfill('_') << right;
			cout << " " << endl;
			cout << setw(40 - MultiH.Len()) << setfill(' ') << right;
			MultiH.print();
			cin.ignore();
			cout << endl << "Press Enter to continue";
			getchar();
			break;
		}
		}
	}
}
