#include <iostream>
#include <fstream>
#include <memory>

class FileDeleter{
private:
    std::string filename;

public:
    FileDeleter(const std::string& fn) : filename(fn){}
    void operator()(std::ofstream* fp){
        fp->close();
        std::remove(filename.c_str());
        std::cout << "remove: " << filename << std::endl;
    }
};

int main()
{
    std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"), FileDeleter("tmpfile.txt"));
    return 0;
}
