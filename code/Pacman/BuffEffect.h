#pragma once
class BuffEffect
{
protected:
	// will be the amount of time it will be active
	// is decreased over time and when it reaches 0 the 
	// effect will be removed from the class handling effects
	float counter;
public:
	BuffEffect(void);
	~BuffEffect(void);

	virtual void update(float dt) = 0;
	const float getCounter() { return counter; }
};

