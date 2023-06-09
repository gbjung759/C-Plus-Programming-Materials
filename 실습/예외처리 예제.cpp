#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class FileNotFoundException : public exception {
    string message;
public:
    FileNotFoundException(string _m): message("File not Found : " + _m){}

    const char * what() const throw() {
        return message.c_str();

    }
};


vector<int> load_vector(string filename){
    ifstream fin(filename);
    if(!fin){
        throw FileNotFoundException(filename);
    }

    int num, value;
    vector<int> result;

    fin >> num;
    for(int i = 0; i < num; i++){
        fin >> value;
        result.push_back(value);
    }

    return result;
}


int main(){

    try{
        vector<int> v = load_vector("values.dat");
    }
    catch(exception& e){
        cout << e.what() << endl;
    }

    return 0;
}
