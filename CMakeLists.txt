cmake_minimum_required(3.10)

project(ADUL)

set(ADUL_TYPE STATIC)

set(SRCDIR sources)

set(SRCFILES 
$(SRCDIR)/tinyxml2.cpp
$(SRCDIR)/math.cpp
$(SRCDIR)/logs.cpp
$(SRCDIR)/timeManager.cpp

)

add_library(ADUL STA)