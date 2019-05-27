#pragma once

class Implementor {
public:

	Implementor() = default;
	virtual ~Implementor() = default;

	virtual void show()=0;
};
