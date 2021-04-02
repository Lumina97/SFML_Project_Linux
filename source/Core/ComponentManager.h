#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include <iostream>
#include <list>
#include <algorithm>
#include "Components/Component.h"
/**
 * @todo write docs
 */

class ComponentManager
{
public:
    static void Update();
    static void AddComponent(Component* comp);
    static void RemoveComponent(Component* comp);



private:
   static std::list<Component*>* components;
};

#endif // COMPONENTMANAGER_H

