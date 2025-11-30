#pragma once
#include <godmode.foundation/$_namespaces.h>

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

#include <godmode.foundation/file/ContentItem.h>
#include <godmode.foundation/file/DirectoryAccessType.h>
#include <godmode.foundation/file/File.h>
#include <godmode.foundation/types/List.h>

godmode_foundation_file(class Directory : public ContentItem { $
    List<Directory *> directories;
    List<File *> files;
    constructor(Directory(String path, DirectoryAccessType directoryAccessType = DirectoryAccessType::SHALLOW_SCAN))
    destructor$(Directory())
    List<ContentItem *> getContentItemsRecursively();
    List<Directory *> getDirectoriesRecursively();
    List<File *> getFilesRecursively();
    List<ContentItem *> getContentItems();
    List<Directory *> getDirectories();
    List<File *> getFiles();
    static void create(String path);
    private$(DirectoryAccessType directoryAccessType)
    private$(void getContentItemsRecurrence(List<ContentItem *> *listContentItem, Directory *directory))
    private$(void getDirectoriesRecurrence(List<Directory *> *directoryList, Directory *directory))
    private$(void getFilesRecurrence(List<File *> *fileList, Directory *directory))
    private$(void initDirectory())
    private$(void initDirectoryTree())
    private$(void initDirectoryTreeRecurrence(String directoryPath, Directory *directory = 0))
})