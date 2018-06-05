#include <iostream>
#include <string>

using namespace std;

//single byte encrypt using xor encryption

int main(){
  char ch = 'l';
  char output;
  string str; //string to be inputted

  cin>>str; //reading from user
  //cout<<str.size()<<endl;
  if(str.size()==0){
    cout<<"in if\n"<<endl;
    return 0;}
  else{
    output = (str[0]&&ch)%26+97;;
    cout<<"output after 1st operation:"<<output<<endl;
    //cout<<"in else\n"<<endl;
    for(int i = 1; i < str.size(); i++){
      output = (output^str[i])%26+97;
      cout<<"in for loop\t"<<i+1<<" output\t"<<output<<endl;
    }
  }
  //cout<<output<<endl;
}
