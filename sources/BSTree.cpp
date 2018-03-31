#include <iostream>
#include <string>
#include "BSTree.h"

using namespace std;
using namespace BSTree;

void MenuOut()
{
	cout << "Выберите одну из операций:" << endl;
	cout << "1. Вывести дерево на экран" << endl;
	cout << "2. Вывести список узлов дерева:" << endl;
	cout << "   a. Прямой обход" << endl;
	cout << "   b. Поперечный обход" << endl;
	cout << "   c. Обратный обход" << endl;
	cout << "3. Добавить узел в дерево" << endl;
	cout << "4. Удалить узел из дерева" << endl;
	cout << "5. Сохранить дерево в файл" << endl;
	cout << "6. Загрузить дерево из файла" << endl;
	cout << "7. Проверить наличие узла" << endl;
	cout << "8. Завершение работы" << endl << endl;
	
}

void Tree::addnode(int data, Node *&pNTree) //Функция добавления узла в дерево
{
	if (pNTree == nullptr) //Если узлов дерева нет
	{
		pNTree = new Node; //Создаём новый узел
		pNTree->data = data; //Записываем туда значения
		pNTree->pLeft = nullptr; //Делаем пустые указатели от этого узла налево и направо
		pNTree->pRight = nullptr;
	}

	if (data < pNTree->data) //Если добавленный элемент меньше текущего узла     
	{
		if (pNTree->pLeft != nullptr) // Если узел НЕ содержит пустого указателя налево
		{
			addnode(data, pNTree->pLeft); //Добавляем данные и указатель на левый узел
		}
		else
		{
			pNTree->pLeft = new Node; //Иначе делаем новый узел
			pNTree->pLeft->pLeft = nullptr; //Левую ветвь левого элемента
			pNTree->pLeft->pRight = nullptr; //Правую ветвь левого элемента
			pNTree->pLeft->data = data; //Записываем данные в левый узел
		}
	}


	if (data > pNTree->data) //Если больше текущего узла
	{ //Всё то же самое, на левую ветвь
		if (pNTree->pRight != nullptr)
		{
			addnode(data, pNTree->pRight);
		}
		else
		{
			pNTree->pRight = new Node;
			pNTree->pRight->pRight = nullptr;
			pNTree->pRight->pLeft = nullptr;
			pNTree->pRight->data = data;
		}
	}
}

void Tree::addel(int data) //Функция добавления элемента в узел
{
	addnode(data, proot);
}

void Tree::print_tree(Node *&pNTree)
{
	if (proot == nullptr)
	{
		std::cout << "Дерево пусто";
	}
	std::cout << "--" << pNTree->data;
}
