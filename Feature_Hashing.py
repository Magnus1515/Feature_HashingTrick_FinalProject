import string
## The two libraries provide the murmurhash3 hash function. 
#from sklearn.utils import murmurhash3_32
#import mmh3 
# initialize string
text = 'David fue a comer tacos de canasta'

# using the sum(), strip(), split() methods
#Metodo que nos contara las palabras y arrogara un n 
def ContarPalabras(txt):

    result = sum([i.strip(string.punctuation).isalpha() for i in text.split()])
    return result


a = ContarPalabras(text)

#Formula para determinar los las columnas de la tabla 
def N_features(n):
    x = n-1
    exp = 2**x
    return exp

def ConverStringToHashes(txt):
    hashed_word = [murmurhash3_32(i) for i in txt]
    print(hashed_word)

def convert(lst):
    words = lst.split()
    return words 

print(N_features(a))
b = N_features(a)

print(b)
print("--------------------------------")
print(convert(text))


#print(ConverStringToHashes())
