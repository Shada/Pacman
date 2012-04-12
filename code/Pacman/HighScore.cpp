#include "HighScore.h"


HighScore::HighScore(ID3DX10Font* font, ID3DX10Sprite* sprite) : listSize(10), replaceAtIndex(-1)
{
	this->sprite = sprite;
	this->font = font;

	defaultString = "------------";
	filename = "Highscore.hs";

	entries = vector<char*>(listSize);
	for( int i = 0; i < listSize; i++ )
	{
		entries.at(i) = defaultString;
	}
	score = vector<int>(listSize);

	r.left = (long)(SCREENWIDTH * .5f - 150);
	r.right = (long)(SCREENWIDTH * .5f + 150);
	r2.left = (long)(SCREENWIDTH * .5f + 80);
	r2.right = (long)(SCREENWIDTH * .5f + 300);

	readFile();
}

void HighScore::saveFile()
{
	fstream file(filename, ios::out);
	for(int i = 0; i < listSize; i++)
		file << entries.at(i) << endl << score.at(i) << endl;

	file.close();
}

void HighScore::createFile()
{
	fstream file(filename, ios::out);
	for(int i = 0; i < listSize; i++)
		file << defaultString << endl << 0 << endl;

	file.close();
}

void HighScore::readFile()
{
	stringstream ss;
	fstream file(filename, ios::in);
	if(file.fail())
		createFile();
	for(int i = 0; i < listSize; i++ )
	{
		string points;
		getline(file, (string)entries.at(i));
		getline(file, points);

		ss << points;
		ss >> score.at(i);

		if(i == replaceAtIndex && entries.at(i) == defaultString)
			entries.at(i) = "Anonymous";
	}
	file.close();
}

void HighScore::addEntry(string _entry)
{
	if(replaceAtIndex == -1)
		return;

	_entry = _entry != "" ? _entry.substr(0, 15) : "Anonymous";

	entries.at(replaceAtIndex) = (char*)_entry.c_str();
	saveFile();
	readFile();
}

bool HighScore::checkAgainstHighScore(int _score)
{
	replaceAtIndex = -1;
	for(int i = listSize - 1; i >= -1; i--)
	{
		if(i > -1 && score.at(i) >= _score)
		{
			if(i + 1 < listSize)
			{
				replaceAtIndex = i + 1;
				updateList(_score);
				return true;
			}
			else
				return false;
		}
	}
	replaceAtIndex = 0;
	updateList(_score);

	return true;
}

void HighScore::updateList(int _score)
{
	int tempScore;
	char* tempEntry;

	for( int i = listSize - 1; i > replaceAtIndex; i-- )
	{
		tempEntry = entries.at(i - 1);
		tempScore = score.at(i - 1);
		entries.at(i) = tempEntry;
		score.at(i) = tempScore;
	}
	score.at(replaceAtIndex) = _score;
	entries.at(replaceAtIndex) = defaultString;

	saveFile();
	readFile();
}

void HighScore::Draw(GraphicsManager *gm)
{
	sprite->Begin(0);
	char buffer[16];
	for(int i = 0; i < listSize; i++)
	{
		r2.top		= r.top		= (long)(200 + i * 30);
		r2.bottom	= r.bottom	= (long)(230 + i * 30);

		sprintf_s(buffer, "%d", i + 1);
		string entryText = (string)buffer + ". " + entries[i];

		D3DXCOLOR col = i == replaceAtIndex ? D3DXCOLOR(0.524f, 0.227f, 0.227f, 1.0f) 
											: D3DXCOLOR(0.324f, 0.027f, 0.027f, 1.0f);

		font->DrawTextA(sprite, entryText.c_str(), -1, &r, DT_LEFT | DT_TOP, col);

		sprintf_s(buffer, "%d", score[i]);

		font->DrawTextA(sprite, buffer, -1, &r2, DT_LEFT | DT_TOP , col);
	}
	sprite->Flush();
	sprite->End();

	gm->resetBlendState();
}

HighScore::~HighScore()
{
	SAFE_DELETE( font );
	SAFE_DELETE( sprite );
}