#ifndef ITEM_H
#define ITEM_H

class Item
{
	protected:
		int xPos;
		int yPos;
		char character;

	public:
		Item(int, int, char);
		int getXPos();
		int getYPos();
		virtual char getCharacter();
};

#endif