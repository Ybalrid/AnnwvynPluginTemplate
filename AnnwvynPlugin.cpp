#include <AnnLogger.hpp>
#include "AnnwvynPlugin.hpp"

using namespace Annwvyn;

PluginTemplate::PluginTemplate() :
 AnnUserSubSystem("Plugin Template")
{
}

PluginTemplate::~PluginTemplate()
{
}

bool PluginTemplate::needUpdate()
{
	return true;
}

void PluginTemplate::update()
{
	AnnDebug() << "This code is called once per loop";
}

//This macro implement the bootstrap function of the plugin. Need to dynamically allocate your plugin and return a pointer to it
//You need to provide the name of your plugin in parentheses
AnnUserSubSystemPluginBootImpl(PluginTemplate)
{
	return new PluginTemplate();
}
