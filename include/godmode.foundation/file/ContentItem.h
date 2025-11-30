#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/types/StringRepresentable.h>

godmode_foundation_file(class ContentItem : public StringRepresentable { $
    bool isDirectory = false;
    constructor(ContentItem())
    constructor(ContentItem(String path))
    constructor(ContentItem(String path, String name))
    constructor(ContentItem(const ContentItem &contentItem))
    destructor$(ContentItem())
    void initPath(String path);
    void initPath(String path, String name);
    virtual bool load(String path, String name = "");
    virtual bool save(String path = "");
    virtual void recreate();
    void setPath(String path);
    void setName(String name);
    void setExtension(String extension);
    void setContext(String context);
    String getPath() const;
    String getName() const;
    String getNameWithExtension() const;
    String getExtension() const;
    String getContext() const;
    virtual String toString();
    static String getFileName(String path);
    static String getFileExtension(String file);
    static String getContext(String path);
    void markAsDirectory(bool isDirectory = true);
    static bool exists(String path);
    protected$(String path)
    protected$(String name)
    protected$(String context)
    protected$(String extension)
    s11n$declareSplit()
})
s11n$export(ContentItem);