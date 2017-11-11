#include <AnnLogger.hpp>
#include "AnnwvynPlugin.hpp"

using namespace Annwvyn;

PluginTemplate::PluginTemplate() : AnnUserSubSystem("Plugin Template")
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

AnnUserSubSystemPluginBootImpl(PluginTemplate)
{
	return new PluginTemplate();
}