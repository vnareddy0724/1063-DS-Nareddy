```cpp
/**
* @ProgramName: tail_insertion
* @Author: Vahini Nareddy 
* @Description: 
*     This program reads integers and append to list in both front and end format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 06 02 2017
*/


#include <iostream>

struct Node{
  int Data;
  Node *Next;
};

using namespace std;

class List{
private:
    Node *Head;
    Node *Tail;
public:
    List(){
      Head = NULL;
      Tail = NULL;
    }
    
    void FrontSert(int x){
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;
      
      if(Head){
        Temp->Next = Head;
      }

      Head = Temp;
      
    }
    
    /**
* @FunctionName: EndSert
* @Description: 
*     Takes integer as parameter and append the value to end of list
* @Params:
*    
*    int x - value to be inserted
*    
* @Returns:
*    void
*/   
       
    void EndSert(int x)
    {
      Node *Temp = new Node;
      Temp->Data = x;
      Temp->Next = NULL;


//Pointing head and tail to temp if list is empty

     if(!Head){
       
       Head=Temp;
       Tail=Head;
      }
      
      // updating tail for each entry of item in list
      else
      {
       
       Tail->Next=Temp;
        Tail=Temp;
        
        
      }
      
    }
    
       
    void PrintList(){
      if(!Head){
        cout<<"Empty"<<endl;
        return;
      }else{
        Node *Temp = Head;
        while(Temp != NULL){
          cout<<Temp->Data<<"->";
          Temp = Temp->Next;
        }
      }
    }

};


int main() {
    srand(97097807);
    List L;
    for(int i=0;i<10;i++){
      L.EndSert(rand()%100);
      //L.FrontSert(rand()%100);
      
    }
    L.PrintList();
    
    
    return 0;
}
```
