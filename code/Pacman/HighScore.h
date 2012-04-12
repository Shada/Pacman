#pragma once
#include "stdafx.h"
#include "GraphicsManager.h"

class HighScore
{
private:
	vector<char*> entries;
	vector<int> score;

	ID3DX10Font* font;
	ID3DX10Sprite* sprite;

	RECT r, r2;

	int listSize, replaceAtIndex;

	// Looks like this ------------
	char* defaultString;
	string filename;

	void readFile();
	void saveFile();
	void createFile();
	// When someone makes it into the highscore the list needs to be updated, 
	// the file updated and read again
	void updateList(int _score);

public:

	HighScore(ID3DX10Font* font,ID3DX10Sprite* sprite);
	~HighScore();

	void Draw(GraphicsManager *gm);
	// Should be called when the player has entered his or hers alias. Keeps track on whether
	// the entry should be added or not and is able to handle eventuall missing strings
	void addEntry(string _entry);
	bool checkAgainstHighScore(int _score);
	
	// Returns the position (first, seconds and so on)
	int getIndex() { return replaceAtIndex + 1; }
};