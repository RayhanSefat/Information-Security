#include<bits/stdc++.h>
using namespace std;

void monoAlphabaticEncryption(int key){
    fstream fptr1;
    fptr1.open("Plain Text.txt");

    fstream fptr2;
    fptr2.open("Monoalphabatic ciphertext.txt");

    string plainText;
    while(getline(fptr1, plainText)){
        string cipher = plainText;
        for(int i = 0; i < plainText.size(); i++){
            if(cipher[i] == ' ') continue;
            int ascii_val = cipher[i] - 'a';
            ascii_val = (ascii_val + key) % 26;
            ascii_val += 'a';
            cipher[i] = (char) ascii_val;
        }
        fptr2 << cipher << endl;
    }

    fptr1.close();
    fptr2.close();
}

void monoAlphabaticDecryption(int key){
    fstream fptr1;
    fptr1.open("Monoalphabatic ciphertext.txt");

    fstream fptr2;
    fptr2.open("Monoalphabatic plaintext.txt");

    string cipher;
    while(getline(fptr1, cipher)){
        string plainText = cipher;
        for(int i = 0; i < cipher.size(); i++){
            if(plainText[i] == ' ') continue;
            int ascii_val = plainText[i] - 'a';
            ascii_val = (ascii_val - key + 26) % 26;
            ascii_val += 'a';
            plainText[i] = (char) ascii_val;
        }
        fptr2 << plainText << endl;
    }

    fptr1.close();
    fptr2.close();
}

void polyAlphabaticEncryption(string key){
    int sz = key.size();

    fstream fptr1;
    fptr1.open("Plain Text.txt");

    fstream fptr2;
    fptr2.open("Polyalphabatic ciphertext.txt");

    string plainText;
    while(getline(fptr1, plainText)){
        string cipher = plainText;
        for(int i = 0; i < plainText.size(); i++){
            if(cipher[i] == ' ') continue;
            int ascii_val = cipher[i] - 'a';
            int key_val = key[i % sz] - 'a';
            ascii_val = (ascii_val + key_val) % 26;
            ascii_val += 'a';
            cipher[i] = (char) ascii_val;
        }
        fptr2 << cipher << endl;
    }

    fptr1.close();
    fptr2.close();
}

void polyAlphabaticDecryption(string key){
    int sz = key.size();

    fstream fptr1;
    fptr1.open("Polyalphabatic ciphertext.txt");

    fstream fptr2;
    fptr2.open("Polyalphabatic plaintext.txt");

    string cipher;
    while(getline(fptr1, cipher)){
        string plainText = cipher;
        for(int i = 0; i < cipher.size(); i++){
            if(plainText[i] == ' ') continue;
            int ascii_val = plainText[i] - 'a';
            int key_val = key[i % sz] - 'a';
            ascii_val = (ascii_val - key_val + 26) % 26;
            ascii_val += 'a';
            plainText[i] = (char) ascii_val;
        }
        fptr2 << plainText << endl;
    }

    fptr1.close();
    fptr2.close();
}

int main(){
    monoAlphabaticEncryption(4);
    monoAlphabaticDecryption(4);
    polyAlphabaticEncryption("bangladesh");
    polyAlphabaticDecryption("bangladesh");

    return 0;
}
