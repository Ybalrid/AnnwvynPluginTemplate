# Annwvyn Template 

This project is a CMake based "template" to create a plugin for the Annwvyn game engine.

You need to have a funcitonning install of the Annwvyn SDK before using this plugin.
If this directory was shipped with the Annwvyn SDK installer, you have nothing to worry about.


## How to use

 1. Copy this directory somewhere else
 2. Open the CMakeLists.txt file and change the name of the project to the name of the plugin you are developing
 3. Generate with CMake in the build directory a project for your build configuration (Visual Studio 2017 or Unix Makefile for linux)
 4. Open the project (if applicable)
 5. Rename the name of the plugin class and the "bootsrap" macro definitions.

The project will build a shared library, that library has to be findable by the Annwvyn game. The plugin implement a
"User Space Subsystem". To load the plugin you only need the built binary, unless you need the user to access custom classes. (e.g. user defined event types, or specific user facing API)
In that case, you'll need to also provide export headers

To load a plugin inside the "client" game application, you just need to have the library findable by the dynamic loader, just this one call is needed:

```C++
    AnnGetEngine()->loadUserSubSystemFromPlugin("PluginTemplate");
```

Beside the name of hte plugin, there's 2nd defaulted to "true" boolean that specify if the file has to be loaded from the local directory. This is especially userfull on Linux while developing. If set to false, the normal library search methods of the OS will be used. (for linux users, see documentation about ldconfig and the associated environemnet variables)



