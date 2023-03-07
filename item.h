#include<iostream>
#include<fstream>
#include<string>

#ifndef ITEM_H
#define ITEM_H

class Item
{
	private:
		int id;
		double price;
		std::string name;
		std::string description;

	public:
		void set_id(int);
		int get_id();

		void set_price(double);
		double get_price();
};

#endif
