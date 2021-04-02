#include "ComponentManager.h"
#include "Log.h"

void ComponentManager::AddComponent(Component* comp)
{
    if(components->empty() == true)
    {
        components = new std::list<Component*>();
    }

    components->push_back(comp);
    LOG_INFO("Added Component: {0}", typeid(comp).name()  );

}

void ComponentManager::RemoveComponent(Component* comp)
{
    if(components->empty() == true)
    {
        components = new std::list<Component*>();
    }

    components->remove(comp);
    LOG_INFO("Removed Component: {0}", typeid(comp).name()  );
}


void ComponentManager::Update()
{
    if(components->empty() == false)
    {
        for(auto const& c : *components)
        {
            c->Update();
            LOG_INFO("Updated Component: {0}", typeid(c).name() );
        }
    }
    else
    {
        LOG_INFO("Component List is Empty!");
    }
}
