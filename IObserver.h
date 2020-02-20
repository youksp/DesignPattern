#ifndef IOBSERVER_H
#define IOBSERVER_H

struct IObserver
{
	virtual void OnUpdate(void* data) = 0;
	virtual ~IObserver() {}
};

#endif

