#include "HighScore.h"

HighScore::HighScore(){}
HighScore::HighScore(ID3DX10Font* font, ID3DX10Sprite* sprite) : listSize(10)
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

	readFile();
}

void HighScore::saveFile()
{
	fstream file(filename, ios::out | ios::binary);
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
	fstream file(filename, ios::in | ios::binary);
	if(file.fail())
		createFile();
	for(int i = 0; i < listSize; i++ )
	{
		getline(file, (string)entries.at(i));
		string points;
		getline(file, points);
		ss << points;
		ss >> score.at(i);
	}
	file.close();
}


//void HighScore::addEntry(string _entry)
//{
//	if(replaceAtIndex == -1)
//		return;
//
//	_entry = _entry != "" ? _entry.substr(0, 15) : "Anonymous";
//
//	entries.at(replaceAtIndex) = _entry;
//	saveFile();
//	readFile(false);
//}

//bool HighScore::checkAgainstHighScore(int _score)
//{
//	replaceAtIndex = -1;
//	for(int i = numberOfEntries - 1; i >= -1; i--)
//	{
//		if(i == -1 || (i > -1 && score.at(i) >= _score))
//		{
//			if(i + 1 < numberOfEntries)
//			{
//				replaceAtIndex = i + 1;
//				int tempScore;
//				string tempEntry;
//
//				for( int i = numberOfEntries - 1; i > replaceAtIndex; i-- )
//				{
//					tempEntry = entries.at(i - 1);
//					tempScore = score.at(i - 1);
//					entries.at(i) = tempEntry;
//					score.at(i) = tempScore;
//				}
//				score.at(replaceAtIndex) = _score;
//				entries.at(replaceAtIndex) = "---------------";
//
//				saveFile();
//				readFile(false);
//
//				return true;
//			}
//			else
//				return false;
//		}
//	}
//	replaceAtIndex = 0;
//	return true;
//}

//void HighScore::Draw(DxHandler* h)
//{
//	sprite->Begin(0);
//	char buffer[16];
//	for(int i = 0; i < numberOfEntries; i++)
//	{		
//		sprintf_s(buffer, "%d", i+1);
//
//		string entryText = (string)buffer + ". " + entries[i];
//
//		D3DXCOLOR col = i == replaceAtIndex ? D3DXCOLOR(0.524f, 0.227f, 0.227f, 1.0f) : D3DXCOLOR(0.324f, 0.027f, 0.027f, 1.0f);
//
//		font->DrawTextA(sprite, entryText.c_str(), -1, &r.at(i), DT_LEFT | DT_TOP, col);
//
//		sprintf_s(buffer, "%d", score[i]);
//
//		string scoreText = buffer;
//
//		r2.top = (long)(200 + i * 30);
//		r2.bottom = (long)(230 + i * 30);
//
//		font->DrawTextA(sprite, scoreText.c_str(), -1, &r2, DT_LEFT | DT_TOP , col);
//	}
//	sprite->Flush();
//	sprite->End();
//
//	h->getID3D10Device()->OMSetBlendState(NULL, 0, 0xffffffff);
//}
HighScore::~HighScore()
{
	SAFE_DELETE( font );
	SAFE_DELETE( sprite );
	SAFE_DELETE( defaultString );
}