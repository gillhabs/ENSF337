// 2020 - Exercise B
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

const int size = 6;
using namespace std;
struct City {
    double x, y;
    char name[30];
};

void write_binary_file(City cities[], int size, char* filename);
/* PROMISES: attaches an ofstream object to a binary file named "filename" and
 * writes the content of the array cities into the file.
 */

void print_from_binary(char* filename);
/* PROMISES: attaches an ifstream object to a binary file named "filename" and
 * reads the content of the file (one record at a time and displays it on the
 * screen.
 */

int main() {
    char bin_filename[] = "cities.bin";
    
    City cities[size] = {{100, 50, "Calgary"},
        {100, 150, "Edmonton"},
        {50, 50, "Vancouver"},
        {200, 50, "Regina"},
        {500, 50, "Toronto"},
        {200, 50, "Montreal"}};
    
    write_binary_file(cities, size, bin_filename);
    cout << "\nThe content of the binary file is:" << endl;
    print_from_binary(bin_filename);
    return 0;
}

void write_binary_file(City cities[], int size, char* filename){
    ofstream stream(filename, ios::out | ios::binary);
    if(stream.fail()){
        cerr << "failed to open file: " << filename << endl;
        exit(1);
    }
    
    for(int i =0; i < size; i++)
        stream.write((char*)&cities[i], sizeof(City));
    stream.close();
}

void print_from_binary(char* filename) {
    City z[100];
    double x_coordinate, y_coordinate;
    char name[30];
    ifstream in_stream(filename, ios::in | ios::binary);
    if(!in_stream){
        cout << "failed to open file: " << filename << endl;
        exit(1);
    }
    
    in_stream.seekg(0L, ios::end);
    unsigned long long n = in_stream.tellg()/sizeof(City);
    in_stream.seekg(0L, ios::beg);
    in_stream.read((char*)z, sizeof(City) * n);
    
    int i = 0;
    while(i < n){
        cout << "Name: " << z[i].name << ", x coordinate: " << z[i].x << ", y coordinate: " << z[i].y << endl;
        i++;
    }
    in_stream.close();
}
