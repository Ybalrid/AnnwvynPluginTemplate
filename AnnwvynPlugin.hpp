#pragma once

#include <Annwvyn.h>

class AnnUserSubSystemPluginExport PluginTemplate : public Annwvyn::AnnUserSubSystem
{
public:
	PluginTemplate();
	~PluginTemplate();
protected:
	void update() override;
	bool needUpdate() override;
};

AnnUserSubSystemPluginBootDeclare(PluginTemplate);