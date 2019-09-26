// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include"map.h"
#include"vector.h"
#include"tokenscanner.h"
#include"random.h"
#include"filelib.h"
#include<string>

using namespace std;
void BuidMap(int n,TokenScanner &scan,Map<Vector<string>,Vector<string>>&map);
void startwords(Map<Vector<string>, Vector<string> > wordMap);
void OutputKey(Vector<string> key);
int main() {
    // TODO: Finish the program!
   ifstream infile;
   Map<Vector<string>,Vector<string>>wordMap;
   cout<<"input a num(N-Gram)"<<endl;
     int n;
     cin>>n;

   infile.open("cisneros.txt");
   TokenScanner scanner(infile);
   scanner.ignoreWhitespace();
  while(scanner.hasMoreTokens()){
        BuidMap(n,scanner,wordMap);

   }
  infile.close();
   // cout<<wordMap.toString();
  startwords(wordMap);
    return 0;
}

void BuidMap(int n,TokenScanner &scan,Map<Vector<string>, Vector<string> > &map){
    Vector<string>wordKey;
    string value;
    for(int i=1;i<n;i++){
        wordKey.add(scan.nextToken());

    }
    value=scan.nextToken();
    //恢复stream
    scan.saveToken(value);
    for(int i=0;i<n-2;i++){
        scan.saveToken(wordKey.get(wordKey.size()-1-i));

    }
    //buidmap
    if(map.containsKey(wordKey)){
        Vector<string>vec= map.get(wordKey);
        vec.add(value);
        map.put(wordKey,vec);
    }
    else {
        Vector<string>vec;
        vec.add(value);
        map.put(wordKey,vec);
    }


}
void startwords(Map<Vector<string>,Vector<string>>wordMap){
    cout<<"input the length"<<endl;
    int n;
    cin>>n;
    Vector<string>key;
    Vector<string>newKey;
    string word;
    key=randomKey(wordMap);
    OutputKey(key);
    for(int i=1;i<=n-2;i++){
    word=randomElement(wordMap[key]);
    cout<<word<<" ";
    key.remove(0);
    newKey=key;
    newKey.add(word);
    key=newKey;
    }
    cout<<"...";

}
void OutputKey(Vector<string>key){
    cout<<"...";
    for(int i=0;i<key.size();i++){
        cout<<key.get(i)<<" ";
    }
}
