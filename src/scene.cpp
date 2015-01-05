#include "scene.h"


void ShapeScene::add(Shape* s) {
	double z = s->getPosition().z();
	if (queue.size() == 0) {
		queue.push_back(s);

	}
	else {
		for (deque<Shape*>::iterator it = queue.begin();
			it != queue.end(); ++it) {
			if (z <= (*it)->getPosition().z()) {
				queue.insert(it, s);
				break;
			}
		}
	}

}

Shape* ShapeScene::get(int i) {
	return queue.at(i);
}



