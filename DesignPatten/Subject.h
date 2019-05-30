#pragma once
class Observer;
class Subject {
public:
	Subject();
	virtual ~Subject();

	virtual void attach(Observer* observer)=0;
	virtual void detach(Observer*observer)=0;
	virtual void notify()=0;
	virtual int statue()=0;
};

