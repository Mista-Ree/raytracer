#ifndef _SCENE_H
#define _SCENE_H

#include <deque>
#include "shape.h"

using namespace std;

template <class T>
class Scene {

protected:
	deque<T> queue;

public:
	virtual void add(T a) = 0;
	virtual T get(int i) = 0;

	typename deque<T>::iterator begin() {
		return queue.begin();
	}

	typename deque<T>::iterator end() {
		return queue.end();
	}


};

class ShapeScene : public Scene < Shape* > {
public:
	void add(Shape* s);
	Shape* get(int i);
};

#endif