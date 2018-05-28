using namespace std;
namespace BSTree
{
	bool a = false;
	struct Node
	{
		int data;
		Node *Right;
		Node *Left;
	};

	class Tree
	{
		Node * root = nullptr;
		void add_node(int data, Node *&NTree)
		{
			if (NTree == nullptr)
			{
				NTree = new Node{ data, nullptr, nullptr };
			}

			if (data < NTree->data)
			{
				if (NTree->Left != nullptr)
				{
					add_node(data, NTree->Left);
				}
				else
				{
					NTree->Left = new Node{ data, nullptr, nullptr };
				}
			}


			if (data > NTree->data)
			{
				if (NTree->Right != nullptr)
				{
					add_node(data, NTree->Right);
				}
				else
				{
					NTree->Right = new Node{ data, nullptr, nullptr };
				}
			}
		}

		void check_tree()
		{
			if (root == nullptr)
			{
				cerr << "Дерево пусто" << endl;
				return;
			}
		}
		void print_tree(Node *root, int space)
		{
			if (root == nullptr)
			{
				return;
			}
			int count = 1;
			space = space + count;
			print_tree(root->Right, space);
			cout << endl;

			for (int i = count; i < space; i++)
			{
				std::cout << "	";
			}
			cout << "--" << root->data << endl;
			print_tree(root->Left, space);
		}
		void straight(Node * root)
		{
			check_tree();
			cout << root->data << " ";
			if (root->Left != nullptr)
			{
				straight(root->Left);
			}
			if (root->Right != nullptr)
			{
				straight(root->Right);
			}
		}
		void symmetric(Node *root)
		{
			check_tree();
			if (root->Left != nullptr)
			{
				symmetric(root->Left);
			}

			std::cout << root->data << " ";

			if (root->Right != nullptr)
			{
				symmetric(root->Right);
			}
		}
		void inverse(Node *root)
		{
			check_tree();
			if (root->Left != nullptr)
			{
				inverse(root->Left);
			}

			if (root->Right != nullptr)
			{
				inverse(root->Right);
			}

			cout << root->data << " ";
		}
		void insert(Node *NTree, int data)
		{
			if (data < NTree->data)
			{
				if (NTree->Left != nullptr)
				{
					insert(NTree->Left, data);
				}
				else
				{
					NTree->Left = new Node{ data, nullptr, nullptr };
				}
			}

			if (data > NTree->data)
			{
				if (NTree->Right != nullptr)
				{
					insert(NTree->Right, data);
				}
				else
				{
					NTree->Right = new Node{ data, nullptr, nullptr };
				}
			}
			else
			{
				cerr << "Узел уже существует в дереве" << endl;
				return;
			}
		}
		void write_to_file(Node * root, ofstream &fout)
		{
			fout << root->data << " ";
			if (root->Left != nullptr)
			{
				write_to_file(root->Left, fout);
			}
			if (root->Right != nullptr)
			{
				write_to_file(root->Right, fout);
			}
		}
		void read_from_file(Node *root, ifstream &fin,string filename)
		{
			int k = 0;
			string str;
			getline(fin, str);
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ' ')
				{
					k++;
				}
				fin.close();
				fin.open(filename);
				for (int i = 0; i <= k; i++)
				{
					fin >> str;
					add_node(atoi(str.c_str()));
				}
				fin.close();
			}
			
		}
		void check_node(Node *root, int data)
		{
			if (root->data == data)
			{
				cout << "Узел найден";
				a = true;
				return;
			}

			if (root->Left != nullptr)
			{
				check_node(root->Left, data);
			}
			if (root->Right != nullptr)
			{
				check_node(root->Right, data);
			}
		}
		void del_node(Node *&NTree, int data) //В разработке!
		{
			if (NTree->data == data)
			{
				Node *key = nullptr;
				if (NTree->Right == nullptr)
				{
					key = NTree->Left;
				}
				else
				{

				}
			}
		}
	public:
		Tree();
		void straight()
		{
			straight(root);
		}
		void symmetric()
		{
			symmetric(root);
		}
		void inverce()
		{
			inverse(root);
		}
		void add_node(int data)
		{
			add_node(data, root);
		}
		void print_tree()
		{
			check_tree();
			print_tree(root, 0);
		}
		void insert(int data)
		{
			check_tree();
			insert(root, data);
		}
		void write_to_file()
		{
			check_tree();
			string filename;
			char choose;
			cout << "Введите путь к файлу" << endl;
			cin >> filename;
			ofstream fout;
			cout << "Перезаписываем? (y/N)" << endl;
			cin >> choose;
			if (choose == 'y')
			{
				fout.open(filename, ios::out | ios::trunc);
				if (!fout.is_open())
				{
					cout << "Не удается открыть файл" << endl;
				}
				write_to_file(root, fout);
			}
			if (choose == 'N')
			{
				fout.open(filename, ios::out | ios::app);
				if (!fout.is_open())
				{
					cout << "Не удается открыть файл" << endl;
				}
				write_to_file(root, fout);
			}
			fout.close();
		}
		void check_node(int data)
		{
			check_tree();
			check_node(root, data);
			if (!a)
			{
				cout << "Узел не найден" << endl;
			}
		}
		void del_node(int data) //В разработке!
		{
			del_node(root, data);
		}
		void read_from_file()
		{
			check_tree();

			string filename;
			cout << "Введите путь к файлу" << endl;
			cin >> filename;
			ifstream fin;
			fin.open(filename);
			if (!fin.is_open())
			{
				cerr << "Файл с заданным путём не существует" << endl;
				return;
			}
			read_from_file(root, fin, filename);
			fin.close();
		}
		
		~Tree();
	};

}
