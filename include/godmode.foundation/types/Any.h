#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/$_dependencies/boost.any.h>

godmode_foundation_types(class Any : public boost::any { $
    using boost::any::any;
    template <typename T> T as() const { return boost::any_cast<T>(*this); }
    template <typename T> bool is() const {  return type() == typeid(T); }
})