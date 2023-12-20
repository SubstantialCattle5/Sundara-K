//
// Created by nilay on 12/20/23.
//

#ifndef NETWORKING_FILES_H
#define NETWORKING_FILES_H


unsigned long get_file_size(char *path);
void write_file(char *path, void *data, unsigned long size);
void append_file(char *path, void *data, unsigned long size);
void * read_file(char *path);


#endif //NETWORKING_FILES_H
