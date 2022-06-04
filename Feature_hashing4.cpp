// import numpy as np 
// import pandas as pd 


// c = CountVectorizer() #convierte una matrix con sus indices de palabras repetidas
// cd = c.fit_transform(['Python for data science','Python for machine learning'])
// print(c.vocabulary_)
// s1 = 'Python for data science'
// s2 = 'Python for machine learning'

// def hashing_trick(input_string,vector_size=20):
//   fv = [0]*vector_size #Genera 20 espacion del tamano del vector
//   for word in input_string.split(' '):
//     idx = abs(hash(word))%vector_size
//     fv[idx]=1 # si hace la funcion le asigna un 1
//   return fv

// print(hashing_trick(input_string='Python for data science',vector_size=20))
// print(hashing_trick(input_string='Python for machine learning',vector_size=20))

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

int N_featrues(int n){
  int x = n-1;
  int exp = pow(2, x);
  return exp; 

} 
  





int main(){
  // const char* arr[20];
  // char* array = new char[20];

  // for (int i=0; i< 10; i++){
  //   array[i] = i;
  //   std::cout << array[i]<< std::endl;
  // }
  int n = N_featrues(8);
  cout << n;

  std::vector<int> SeparateWords = "David come Tacos";







}