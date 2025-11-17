#pragma once
#ifndef BASE_STORAGE_HPP
#define BASE_STORAGE_HPP

#include <fstream>
#include <functional>
#include <string>

#include "display/utilities.hpp"

template <typename T, typename FileIO, const std::string & FilePath>
class BaseStorage {
protected:
    static void for_each_item(const std::function<bool(const T &)> & callback);

    static void process_file(
        const std::function<void(T &, std::ofstream &)> & processor
    );
};

template <typename T, typename FileIO, const std::string & FilePath>
void BaseStorage<T, FileIO, FilePath>::for_each_item(
    const std::function<bool(const T &)> & callback
) {
    std::ifstream fin;

    if (!is_open_file(fin, FilePath.c_str())) {
        return;
    }

    while (!fin.eof()) {
        T item;
        if (FileIO::read_file(fin, item) && callback(item)) {
            break;
        }
    }
}

template <typename T, typename FileIO, const std::string & FilePath>
void BaseStorage<T, FileIO, FilePath>::process_file(
    const std::function<void(T &, std::ofstream &)> & processor
) {
    const std::string original_file = FilePath;
    std::string backup_file = FilePath;
    backup_file.insert(backup_file.size() - 4, "_new");

    // Rename <FilePath>s.txt into <FilePath>sTemp.txt
    if (rename(original_file.c_str(), backup_file.c_str()) != 0) {
        std::cerr << "Error renaming file" << std::endl;
        return;
    }

    std::ifstream fin;
    std::ofstream fout;

    // Re-create the old <FilePath>s.txt file without content
    if (!is_open_file(fin, backup_file) || !is_open_file(fout, original_file)) {
        return;
    }

    // Write from the file is renamed (<FilePath>s_new.txt) to <FilePath>s.txt,
    // and don't write the employee want to delete
    while (!fin.eof()) {
        T item;
        if (FileIO::read_file(fin, item)) {
            processor(item, fout);
        }
    }

    fin.close();
    fout.close();
    remove(backup_file.c_str());
}

#endif  // end BASE_STORAGE_HPP
