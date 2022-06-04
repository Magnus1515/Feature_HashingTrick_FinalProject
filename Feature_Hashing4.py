import string
import pandas as pd
import numpy as np
#from tabulate import tabulate
#from prettytable from PrettyTable


## The two libraries provide the murmurhash3 hash function. 
from sklearn.utils import murmurhash3_32
#import mmh3 
# initialize string
text = 'denotes to January 2010.The album was released on April 26, 2010.'

# using the sum(), strip(), split() methods
#Metodo que nos contara las palabras y arrogara un n 

#Funcion que nos cuenta el numero de palabras en nuestra lista
    #result = sum([i.strip(string.punctuation).isalpha() for i in text.split()])
    #result = pd.value_counts(np.array(txt))
    #return result

 
# Returns number of words in string
def ConvertWords(string):
    OUT = 0
    IN = 1
    state = OUT
    wc = 0
 
    # Scan all characters one by one
    for i in range(len(string)):
 
        # If next character is a separator,
        # set the state as OUT
        if (string[i] == ' ' or string[i] == '\n' or
            string[i] == '\t'):
            state = OUT
 
        # If next character is not a word
        # separator and state is OUT, then
        # set the state as IN and increment
        # word count
        elif state == OUT:
            state = IN
            wc += 1
 
    # Return the number of words
    return wc
# print("a", a)

#2.- Formula para determinar las columnas que llevara nuestra tabla
def N_features(n):
    x = n-1
    exp = 2**x
    return exp

#1.- Funcion que nos separa la oracion en forma de lista y nos elimina los "."
def convert(lst):
    words = list(lst.split(" "))
    #for word in lst:
    #w = string(lst.split())
    b = [i.replace(".", "") for i in words]
    return b 

#3.- Formula que convierte nuesrtas palabras en hashes 
def ConverStringToHashes(txt):
    hashed_word = [murmurhash3_32(i) for i in txt]
    return (hashed_word)


#4.- obtener el valor del indices el cual es el residuo de la operacion
def Get_indixes(lista_hashes,n_features):
  lista_nueva = []
  
  for i in lista_hashes:
    
    x = abs(i % n_features)
    #print(x)  
    lista_nueva.append(x)
  
  return(lista_nueva)

#Convertir lista del numero de columnas que requerimos
def ConverLisToZeros(b):
    lst = []
    for i in range(0,b):
        lst.append(0)
    return lst 

#Obtener el numero mayor de indices 
def High_index(lst):
  indice_mayor = max(lst)
  return indice_mayor

#Obtiene el hash final el cual buscamos 
def FinalHashes(ListZeros, IndexList):  
  for i in IndexList:
    ListZeros[i] = 1
  return ListZeros


def FeatureHashing(text):
    a = ConvertWords(text)
    #print(a) 
    b = N_features(a)
    #print(b)
    x_hashes = convert(text)
    #print(x_hashes)
    hashes_solo = ConverStringToHashes(x_hashes)
    #print(hashes_solo)
    c = Get_indixes(hashes_solo,b)
    #print (c)
    z = ConverLisToZeros(b)
    high_index = High_index(c)
    return FinalHashes(z,c)
    




#return lista_nueva

#def AddIndexToTable(lista_indices):
#print(a)
# print("--------------------------------")
# print("Pruebas ")
# a = ConvertWords(text)
# print("Numero de palabras: ", ConvertWords(a))
# print(N_features(a))
# print("Tomamos la cantidad de palabras para realizar N_features ")
# b = N_features(a)


# x_hashes = convert(text)
# print("convierte la oracion en lista ", x_hashes)
# hashes_solo = ConverStringToHashes(x_hashes)
# print("Convierte las palabras en hashes ",hashes_solo)



# c = Get_indixes(hashes_solo,b)
# print("Indices de los hashes: ", c)

# z = ConverLisToZeros(b)
# print(z)
# print("Numero de 0: ")
# print(z.count(0))

# print('Mary had a little lamb'.count('a')
# print("3 --------------------------------")
#print("Numero mayor de los indices: ",High_index(c))

#high_index = High_index(c)



#x_x = FinalHashes(z,c)
#print("        ")
#print(FinalHashes(ConverLisToZeros(N_features(ConvertWords(text))),Get_indixes(ConverStringToHashes(convert(text),N_features)(ConvertWords(text)))))
with open('Book1.txt') as f:
   lines = f.readlines()
    #print(lines)
    #print(lines[0])
    #lista = lines.split("\n")


# archivo = open("Book1.txt","r")
# contenido = archivo.read()

# lista = contenido.split("\n")
print("Prueba 1: "," ")

#print(lines[0])
#print(FeatureHashing(text))
#print(text)

for i in range(len(lines)):
    print(lines[i])
    print(FeatureHashing(lines[i]))
#print(lines[0])
#print(FeatureHashing(lines[0]))
#print(lines[1])
#print(FeatureHashing(lines[1]))


# header = []
# for _ in range(b):
#   _ = ""
#   header.append(_)

# print(b)
#print("--------------------------------")
# print(convert(text))

# x_hashes = convert(text)
# print("convert", x_hashes)
# ConverStringToHashes(x_hashes)
# print("1 --------------------------------")
# hashes_solo = ConverStringToHashes(x_hashes)
# print(hashes_solo)
# print("2 --------------------------------")


# c = Get_indixes(hashes_solo,b)
# print("Indices de los hashes: ", c)
# print("3 --------------------------------")
# print("Numero mayor de los indices: ",High_index(c))

# high_index = High_index(c)

#print(header)
#index=np.arange(1), columns=np.arange(b)
#df = pd.DataFrame()
#df = pd.DataFrame(data, columns=64)

#print(df)
#df.replace({0: 10, 1: 100})


#print(ConverStringToHashes())

# value_list = [['Alex', 13,1, 'Chess', 10],
#                   ['Zia',  12,2, 'Monopoly', 25]]
# column_list = ["Name", "Age", "Number of Games", "Favourite Game", "Cost of Game"]

# print(tabulate(value_list, column_list, tablefmt="grid")
 

# def convert(lst):
#     words = lst.split()
#     return words 

#print(words)
#print(lst)
  
#print(l)
#print(lst)   