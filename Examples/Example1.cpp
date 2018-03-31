#include <iostream>
#include <string>
#include "BSTree.cpp"

using namespace std;
using namespace BSTree;

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");
	Tree *tree = new Tree;
	for (int i = 1; i < argc; i++)
	{
		int x;
		x = atoi(argv[i]);
		tree->addel(x);
	}
label:
	MenuOut();

	unsigned int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		Tree::print_tree(Node *&pNTree);
		break;
	}
	case 2:
	{
		break;
	}
	case 3:
	{
		break;
	}
	case 4:
	{
		break;
	}
	case 5:
	{
		break;
	}
	case 6:
	{
		break;
	}
	case 7:
	{
		break;
	}
	case 8:
	{
		string exit;
	label_exit:
		cout << "Вы хотите выйти?" << endl;
		cin >> exit;
		if ((exit == "y") || (exit == "Y") || (exit == "yes") || (exit == "Yes"))
		{
			return 0;
		}

		if ((exit == "n") || (exit == "N") || (exit == "no") || (exit == "No"))
		{
			cout << endl;
			goto label;
		}

		else
		{
			cout << "Неверный ввод" << endl << endl;
			goto label_exit;
		}
		break;
	}
	default:
	{
		cout << "!!!!!!!!!!!!!Неверный ввод!!!!!!!!!!!!!" << endl << endl;
		goto label;
	}

	}
}
