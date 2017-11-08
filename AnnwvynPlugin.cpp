#include <AnnLogger.hpp>
#include "AnnwvynPlugin.hpp"

PluginTemplate::PluginTemplate() : Annwvyn::AnnUserSubSystem("Plugin Template")
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
	Annwvyn::AnnDebug() << "This code is called once per loop";
}

AnnUserSubSystemPluginBootImpl(PluginTemplate)
{
	return new PluginTemplate();
}