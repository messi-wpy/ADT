// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include"lexicon.h"
#include"queue.h"
#include"stack.h"

using namespace std;
void FindNeighbor(Queue<Stack<string>>&stackQueue,Lexicon &lexicon,Stack<string>&sta,string word2,Stack<string>&stackword);
void OutPutWord(Stack<string>stack);
bool CheckWord(string str1, string str2, Lexicon lex);
int main() {
    // TODO: Finish the program!
    //Lexicon dictionary("dictionary.txt");
    bool dicCheck=true,wordCheck=false;
    string word1,word2,dic;
    Stack<string>stackword;
    Queue<Stack<string>>stackQueue;
    Stack<string>stackCopy;
    cout<<"Please give me two English words, and I will change the first into the second by changing one letter at a time.";
    cout<<endl;
    cout<<"Dictionary file name? ";
    cin>>dic;
    while (dicCheck) {
    try{
       Lexicon dictionary(dic);
       dicCheck=false;
    }catch(ErrorException & ex){
        cout<<"Unable to open that file.  Try again."<<endl;
        cin>>dic;
        dicCheck=true;
    }
    }
    Lexicon dictionary(dic);
    while (!wordCheck) {
    cout<<"Word1:";
    cin>>word1;
    cout<<"Word2:";
    cin>>word2;
    wordCheck=CheckWord(word1,word2,dictionary);
    }
    stackCopy.add(word1);
    stackQueue.add(stackCopy);
    while (!stackQueue.isEmpty()) {
        FindNeighbor(stackQueue,dictionary,stackCopy,word2,stackword);
        if(!stackword.isEmpty()){
           OutPutWord(stackword);
        break;
        }
    }

    cout << "Have a nice day." << endl;
    return 0;
}
void FindNeighbor(Queue<Stack<string>> &stackQueue,Lexicon &lexicon,Stack<string>&sta,string word2,Stack<string>&stackword){
    Stack<string>stack=stackQueue.dequeue();
    string word=stack.peek();
    string wordcopy=word;
    for(int i=0;i<word.length();i++){
        //cout<<i<<endl;
        word=wordcopy;
        for(int n=97;n<=122;n++){
            word[i]=n;
            if(lexicon.contains(word)){
                   stack.add(word);
                   lexicon.remove(word);
                   if(word==word2){
                       stackword=stack;
                   }
                   stackQueue.enqueue(stack);
                   sta.add(word);
                   string unuseWord=stack.pop();
                   //cout<<word<<endl;
            }
        }
    }
}
void OutPutWord(Stack<string> stack){
    while (!stack.isEmpty()) {
        cout<<stack.pop()<<" ";
    }
    cout<<endl;
}
bool CheckWord(string str1,string str2,Lexicon lex){
    if(str1.length()==str2.length()&&lex.contains(str1)&&lex.contains(str2))
        return true;
    else {
        cout<<"please input two same length words and spell right";
        return false;
    }
}



