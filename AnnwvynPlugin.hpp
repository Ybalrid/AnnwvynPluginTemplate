#pragma once

//To access the API of the Annwvyn engine
#include <Annwvyn.h>

//You need to create an user subsystem. The name of the class is the name of the plugin
class AnnUserSubSystemPluginExport PluginTemplate : public Annwvyn::AnnUserSubSystem
{
public:
	PluginTemplate();
	~PluginTemplate();
protected:
	void update() override;
	bool needUpdate() override;
};

//Once loaded, the plugin need to call a boostrap function. This macro will create it for you.
AnnUserSubSystemPluginBootDeclare(PluginTemplate);
