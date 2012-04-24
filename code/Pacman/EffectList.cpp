#include "EffectList.h"


EffectList::EffectList()
{
}

void EffectList::update(double dt)
{
	for(unsigned int i = 0; i < list.size(); i++)
	{
		const double test = list.at(i)->getCounter();
		if( list.at(i)->getCounter() > 0 )
			list.at(i)->update(dt);
		else
		{
			SAFE_DELETE(list.at(i));
			list.erase(list.begin() + i--);
		}
	}

}
void EffectList::addEffect(BuffEffect* effect)
{
	list.push_back(effect);
}

EffectList::~EffectList()
{
	for(unsigned int i = 0; i < list.size(); i++)
		SAFE_DELETE(list.at(i));
}
