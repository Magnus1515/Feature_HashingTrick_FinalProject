#include<iostream>
#include <cmath>

//include it for istringstream
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
const int PRIME_CONST = 31;

// int WordsCount(char *str){
//    int count = 0;
//    int temp = 0;
//    while (*str){
//       if (*str == ' ' || *str == '\n' || *str == '\t'){
//          temp = 0;
//       }
//       else if(temp == 0){
//          temp = 1;
//          count++;
//       }
//       ++str;
//    }
//    return count;
// }
//Funcion que nos ayudara a contar las palabras de nuestra oracion o palabra
int ContarPalabras2(string T){

    size_t NWords = T.empty() || T.back() == ' ' ? 0 : 1;
    for (size_t s = T.size(); s > 0; --s)
        if (T[s] == ' ' && T[s-1] != ' ') ++NWords;

    return NWords;
}
int N_featrues(int n){
  int x = n-1;
  int exp = pow(2, x);
  return exp; 

} 

std::vector<string> SeparateWords(string palabra){
      vector<string> arr;

    istringstream iss(palabra);

    string word;
   

    while(iss >> word) {  
            
            arr.push_back(word);
            
    }
    return arr;
    
}

unsigned int MurmurHash32(const std::string& str)
 {
      unsigned int hash = 1315423911;

      for(std::size_t i = 0; i < str.length(); i++)
      {
          hash ^= ((hash << 5) + str[i] + (hash >> 2));
      }

      return (hash & 0x7FFFFFFF);
 }

int hashFunction(string key){
        int hashCode = 0;
        for (int i = 0; i < key.length(); i++) {
            hashCode += key[i] * pow(PRIME_CONST, i);
        }
        return hashCode;
}

// Funcion que hace la operacion para poder encontrar el indice correcto
int Index(int lista_hashes, int n_features){
    int index = abs(lista_hashes % n_features);
    return index;
    
}
// Funcion que nos va a convertir a hashes nuestra palabras separadas de la funcion SeparateWords
vector<int> ConvertStringToHashes(vector<string> arreglo){
    vector<int> vecHashes;
    int N = arreglo.size();
    for(int i=0;i < N;i++){
        int h = MurmurHash32(arreglo[i]); // variable donde guardamos hashes
        vecHashes.push_back(h);

    }
    return vecHashes;

}

//Funcion con la que crearemos nuestra lista de ceros de la cantidad correcta
vector<int> ConvertListToZeros(int b){
    vector<int> lst;
    for (int i = 0; i < b; i++)
        lst.push_back(0);
    return lst;

}
// Funcion con la que obtendremos los indices llamando a nuestra funcion Index y eso lo guardaremos en un vector
vector<int> GetIndex(vector <int> arreglo,int N){
    vector<int> VecIndex;
    for(int i=0;i < N ;i++){
        int h = Index(arreglo[i], N); // variable donde guardamos los hashes con los vechashes y N
        VecIndex.push_back(h);
        //VecIndex.erase(VecIndex.begin());

    }
    return VecIndex;
}

// Funcion donde guardaremos los "1" en la posicion correcta segun los indices  
vector<int> FinalHashes(vector <int> ListaZeros,vector <int> IndexList)
{
    //vector<int>FinalHash;

    // lista indices = (6,1,8,2,3,1,2,2)
    // lista de ceros = (256, 0)
    for(int i = 0; i < IndexList.size(); i++){
        int x = IndexList[i];
        //ListaZeros.at(x)=1+ListaZeros.at(x);
        ListaZeros.at(x)=1;
    }
    return ListaZeros;
}

// Funcion donde pondremos a correr todas nuestras funciones para poder ejercutarlas
vector<int> FeatureHashing(string texto)
{
    // string texto = ("Este sabado David fue a comer tacos de adobada");
    // char str[] = "Este sabado David fue a comer tacos de adobada";
    // int b = WordsCount(str);
    int g = ContarPalabras2(texto); //En nuestra variable g contamos las palabras de nuestra oracion o palabra
    int c = N_featrues(g); //En esta variable guardamos la cantidad de extension que tendra el hash 
    vector<string> h1 = SeparateWords(texto); // En el vector h1 separamos las palabras de nuestra oracion
    vector<int> h2 = ConvertStringToHashes(h1); // En h2 Convertimos estas palabras en hashes al
    //
    vector<int> h3 = GetIndex(h2, c); // en h3 obtenemos los indices de nuestros hashes ya convertidos
    // 6,1,8,2,3,1,2,2, ejemplo de nuestros indices que desplegaria
    vector<int> h4 = ConvertListToZeros(c); // Creamos nuestra lista de ceros con la extension requerida
    vector<int> h5 = FinalHashes(h4,h3); // Colocamos los 1 en la posicion de los indices requerida y esta nuevo vecto sera nuestro hash final

    return h5; //regresamos h5 donde guardamos nuestro hash final

}
// Funcion que nos ayudara a poder imprimir nuestros vectores
void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}


// int dataLoad(string filename){

//     ifstream input;
//     int cc = 1;
//     string word = "algoritmo";
//     char* patron = &word[0];
//     input.open(filename);

    

//     if (!input.is_open()){
//         cout << "No pude leer el archivo";
//         return 1;
//     }
//     cout << "Patron encontrado en: " << endl;
//     while (input)
//     {
//         string line;        
//         getline(input, line);
//         char* texto = &line[0];               
//         rabinKarp(patron, texto, cc);
//         cc += 1;   
            
//     }
//     input.close();
//         return 1;      
//     } 

int main(){
    vector<int> h6 = FeatureHashing("David come tacos de canasta");
    print(h6);
    // string texto = ("Este sabado David fue a comer tacos de adobada");
    // //char str[] = "Este sabado David fue a comer tacos de adobada";
    // //int b = WordsCount(str);
    // int z = ContarPalabras(texto);
    // int g = ContarPalabras2(texto);
    // int c = N_featrues(g);
    // cout<< WordsCount(str); 
    // vector<string> h1 = SeparateWords(texto);
    // vector<int> h2 = ConvertStringToHashes(h1);
    // 
    // vector<int> h3 = GetIndex(h2, c);
    // // 6,1,8,2,3,1,2,2,
    // vector<int> h4 = ConvertListToZeros(c);
    // vector<int> h5 = FinalHashes(h4,h3);
    // vector<int> h2 = GetHashes(h1);
    // vector<int> h3 = GetIndex(h2,h2.size());
    //cout<<h3[0];
    //cout<<h3[0]<<endl;
    //cout<<h3[1]<<endl;
    //cout<<h3[4]<<endl;
    //cout<<h2[1];
    // for(auto it = h5.begin(); it != h5.end(); it++)
    // {
    //     std::cout << *it << ",";
    // }

 

    // for(int it = h5.begin(); it != h5.end(); it++)
    // {
    //     std::cout << *it << ",";
    // }
    
    

    // for (string elemento: h1)
    // {
    //     std::cout << elemento << std::endl;

    // }

    
    // cout << hashFunction("movies") << endl;
    // int h2= hashFunction("john");
    // cout<<MapValue(h2, TamañoInidice);
   
    
    return 0;
}


    