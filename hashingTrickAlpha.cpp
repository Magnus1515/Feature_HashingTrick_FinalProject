#include<iostream>
#include <cmath>

//include it for istringstream
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
const int PRIME_CONST = 31;

vector<string> SeparateWords(string palabra){
      vector<string> arr;
      
      //Crete object of istringstream and
      //initialize assign input string
    istringstream iss(palabra);

    string word;
      //Extract each words only..no spaces.
      //This way it can handle any
      //special characters.

    while(iss >> word) {  
            //Display words
            arr.push_back(word);
            //cout<<word.c_str()<<endl;  
    }
    return arr;

    

}
int hashFunction(string key){
        int hashCode = 0;
        for (int i = 0; i < key.length(); i++) {
            hashCode += key[i] * pow(PRIME_CONST, i);
        }
        return hashCode;
}


int MapValue(int hash, int n = 20){
    int index = hash % n;
    return index;
    
}

vector<int> GetHashes(vector<string> arreglo){
    vector<int> vecHashes;
    int N = arreglo.size();
    for(int i=0;i < N;i++){
        int h = hashFunction(arreglo[i]); // variable donde guardamos hashes
        vecHashes.push_back(h);

    }
    return vecHashes;

} 
vector<int> GetIndex(vector <int> arreglo,int N = 20){
    vector<int> VecIndex;
    for(int i=0;i < N ;i++){
        int h = MapValue(arreglo[i], N); // variable donde guardamos los hashes con los vechashes y N
        VecIndex.push_back(h);

    }
    return VecIndex;


}
int main(){

    vector<string> h1 = SeparateWords("Este sabado David fue a comer tacos de adobada");
    vector<int> h2 = GetHashes(h1);
    vector<int> h3 = GetIndex(h2,h2.size());
    cout<<h3[0]<<endl;
    cout<<h3[1]<<endl;
    cout<<h3[4]<<endl;
    //cout<<h2[1];

    

    
    // cout << hashFunction("movies") << endl;
    // int h2= hashFunction("john");
    // cout<<MapValue(h2, TamañoInidice);
   
    
    // return 0;
}


    