#include <iostream>
using namespace std;
#include "Land.h"

Land::Land()
{
	return;
}

void Land::buildLand()
{
	cout << "How many Castles do you want?" << endl;
	int n = 0;
	cin >> n;
	system("cls");
	for (int i = 0; i < n; i++)
	{
		Castle* temp = new Castle();
		cout << "How many Soldiers does Castle #" << i << " need?" << endl;
		int m = 0;
		cin >> m;
		system("cls");
		for (int j = 0; j < m; j++)
		{
			double power = 0;
			double velocity = 0;
			cout << "How much is the #" << j << " Power?" << endl;
			cin >> power;
			system("cls");
			cout << "How much is the #" << j << " Velocity?" << endl;
			cin >> velocity;
			system("cls");
			Soldier* kemp = new Soldier(power, velocity);
			temp->insertSoldier(kemp);
		}
		this->here.addVertex(*temp);
	}

	cout << "How many Pathes do you want?" << endl;
	int o = 0;
	cin >> o;
	system("cls");
	for (int i = 0; i < o; i++)
	{
		cout << "Enter length of The #" << i << ": ";
		double length = 0;
		cin >> length;
		cout << endl << "Enter path's head id: ";
		string head_id = "";
		cin >> head_id;
		cout << endl << "Enter path's tail id: ";
		string tail_id = "";
		cin >> tail_id;
		system("cls");
		Castle* head = Castle::findCastleById(head_id);
		Castle* tail = Castle::findCastleById(tail_id);

		Path* femp = new Path(length, head, tail);
		Vertex<Castle>* h_temp = new Vertex<Castle>(*head);
		Vertex<Castle>* t_temp = new Vertex<Castle>(*tail);
		Edge<Castle, Path>* aemp = new Edge<Castle, Path>();
		here.addEdge(*aemp);

		cout << "Enter output capacity: ";
		int output_capacity = 0;
		cin >> output_capacity;
		system("cls");
	}
}
