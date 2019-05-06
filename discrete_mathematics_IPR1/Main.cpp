#include<iostream>
#include<string>
#include<string>
#include<set>

using namespace std;

int func(int k, set<string>& ends, multiset<char>& bfw, string word);

int main()
{
	bool endWork = false;
	while (!endWork)
	{
		bool done = false;
		int k;
		set<string> endS;
		multiset<char>bfw{ 'a','b','d','f','f','g','g' };
		while (!done)
		{

			cout << "Enter \"k\"  min:1\tmax:" << bfw.size() << "\n";
			cin >> k;
			if ((k < 1) || (k > bfw.size()))
			{
				system("cls");
				cout << "Wrong range!\nTry again.\n";
			}
			else done = true;
		}
		func(k, endS, bfw, "");

		for (set<string>::iterator i = endS.begin(); i != endS.end(); i++)
		{
			cout << *i << endl;
		}
		cout << "Repeat?\n1-Yes;\n2-No;\n";
	}
	system("pause");
	return 0;

}



int func(int k, set<string>& ends, multiset<char>& bfw, string word)
{
	string temp;
	multiset<char> thisBfw = bfw;
	if (k == 0)
	{

		ends.insert(word);

		return 0;
	}
	for (multiset<char>::iterator i = thisBfw.begin(); i != thisBfw.end();)
	{
		temp = word + *i;
		multiset<char> ::iterator forDell = i;
		i++;
		thisBfw.erase(forDell);
		func(k - 1, ends, thisBfw, temp);
		if (thisBfw.begin() == thisBfw.end()) break;

	}
	return 0;
}
