#include <iostream>
#include <dirent.h>
#include <sys/types.h>

class ListDIR  {
   public:
      void list_dir(const char *path) {
         struct dirent *entry;
         DIR *dir { opendir(path) };
         
         if (dir == NULL) {
            return;
         }
         while ((entry = readdir(dir)) != NULL) {
            std::cout << entry->d_name << '\n';
         }
         closedir(dir);
      }
};