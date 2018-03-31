namespace BSTree
{
	struct Node //Структура узла
	{
		int data;
		Node *pRight;
		Node *pLeft;
	};

	class Tree //Класс дерева
	{
	private:
		Node * proot = nullptr;
		void addnode(int data, Node *&pNTree); //Функция добавления узла в дерево
		
	public:
		void addel(int data);//Функция добавления элемента в узел 
		void print_tree(Node *&pNTree);
	};
}
