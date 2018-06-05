#include <iostream>
#include <string>

using namespace std;

typedef struct Node* node;
typedef struct linkedList* linkedL;

struct Node{
  string uid;
  node next;
};

struct linkedList{
  char hash_value;
  node head;
};

node createNode(string id){
  node n = (node)malloc(sizeof(struct Node));
  n->uid = id;
  n->next = NULL;
  return n;
}

linkedL createList(char ch){
  linkedL ls = (linkedL)malloc(sizeof(struct linkedList));
  ls->head = NULL;
  ls->hash_value = ch;
}

linkedL* createArray(){
  linkedL* array = (linkedL*)malloc(sizeof(linkedL)*26);
  int i = 0;
  for(char c = 'a'; c <= 'z' ; c++){
    array[i] = createList(c);
    //cout<<array[i]->hash_value<<endl;
    i++;
  }
  return array;
}

char hash_func(string str){
  char ch = 'l';
  char output;
  //string str; //string to be inputted

  //cin>>str; //reading from user
  //cout<<str.size()<<endl;
  if(str.size()==0){
    //cout<<"in if\n"<<endl;
    return 0;}
  else{
    output = (str[0]&&ch)%26+97;;
    //cout<<"output after 1st operation:"<<output<<endl;
    //cout<<"in else\n"<<endl;
    for(int i = 1; i < str.size(); i++){
      output = (output^str[i])%26+97;
      //cout<<"in for loop\t"<<i+1<<" output\t"<<output<<endl;
    }
  }
  return output;
}

linkedL* insertIntoHT(linkedL* a, char ch, string unique_id){
  for(int i = 0; i < 26; i++){
    if(a[i]->hash_value == ch){
      if(a[i]->head==NULL){
        node n = createNode(unique_id);
        a[i]->head = n;
        return a;
      }
      else{
        node n = createNode(unique_id);
        n->next = a[i]->head;
        a[i]->head = n;
        return a;
      }
    }
  }
}

void printList(linkedL * a){
  for(int i = 0; i < 26; i++)
    cout<<a[i]->hash_value<<endl;
}

void print(linkedL* a){
  for(int i = 0; i < 26; i++){
    if(a[i]->head!=NULL){
      cout<<a[i]->hash_value<<":"<<endl;
      node temp = a[i]->head;
      while(temp!=NULL){
        cout<<temp->uid<<endl;
        temp = temp->next;
      }
    }
  }
}

int main(){
  linkedL* arr = createArray();
  //printList(arr);
  string s1 = "abc";
  string uid1 = "1";
  string s2 = "abc";
  string uid2 = "2";
  string s3 = "cvffd";
  string uid3 = "3";

  arr = insertIntoHT(arr,hash_func(s1),uid1);
  arr = insertIntoHT(arr,hash_func(s2),uid2);
  arr = insertIntoHT(arr,hash_func(s3),uid3);

  print(arr);
}
