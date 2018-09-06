// Study case of W. W. Zachary's Karate Club (1977)
// For UnB - Theory and Application of Graphs, 2018/2
// by Gabriel Bessa 16/0120811 and Andre Cassio  16/0xxxxxx

#include <bits/stdc++.h>

using namespace std;

//1. Reading karate.zip files

int open_file(){
  //Opening the file which will be read.
  ifstream myfile;
  myfile.open("karate.gml");
  //If the file is not opened, exits
  if(!myfile.is_open()){
    cout << "File doesnt exists, shutting down application" << endl;
    return -1;
  }else{
    //Keeps reading the file until the last character.
    while(true){
      string mystring;
      myfile >> mystring;
      if(myfile.eof()){
        break;
      }
    }
  }
  myfile.close();
  return 0;
}












int main(){
open_file();

return 0;
}















