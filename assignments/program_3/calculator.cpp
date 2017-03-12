

/**
* @ProgramName: Program-3
* @Author: Vahini Nareddy 
* @Description: 
*     This program reads infix expression and converts to postfix and Evaluates the 
* result from it.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 12 03 2017
*/


#include <iostream>

#include <string>

#include<sstream>

#include <cmath>

#include<fstream>

using namespace std;

class calculator{
  
public:
 
char *S;


int top=-1;

int size=10;

char *Q;

int NumItems=0;

int Front=0;


int Rear=0;
 
 //constructor
   
calculator(int l){
  size=l;
  S=new char[size];
 
  }
  
  
  /**
  * @FunctionName: infix
  * @Description: 
  *     converts infix expression to postfix and stores in queue.
  * @Params:
  *    exp-to be converted to postfix.
  * @Returns:
  *    void
  */
  
 
void infix(string exp){

   for(int i=0;i<exp.length();i++){

  
       if(exp[i]=='('){
        
         push('(');
        
       }
 
      else if(exp[i]=='+'){
     
        char op=S[top];
         
     
              if(op=='('){
               
            push('+');
               
          }
         
           else if(op=='*'||op=='-' || op=='+'){
              
             insert(op);
              
             pop();
                
           push(exp[i]);
              
             
               }
        
           else  if(op=='/'||op=='%'||op=='^'){
             
             insert(op);
              
             pop();
                
           push(exp[i]);
              
           }
             
          }
         
 
  else if(exp[i]=='*'){
     
char op=S[top];
     
   
            if(op=='('){
             
              push('*');
              
           }
              
           else if(op=='+'||op=='-'){
             
              push(exp[i]);
              
             
               }
            
            else if(op=='/'|| op=='%' || op=='^'||op=='*'){
                
           insert(op);
              
             pop();
             
              push(exp[i]);
               }
            
           }
   else if(exp[i]=='-'){
  
   char op=S[top];
     
   
            if(op=='('){
                
           push('-');
              
           }
              
          else if(op=='*'||op=='+'|| op=='-'){
            
               insert(op);
             
              pop();
            
               push(exp[i]);
             
              
               }
             
           else if(op=='/' || op=='%'|| op=='^'){
              
             insert(op);
             
              pop();
            
               push(exp[i]);
             
              
           }
               
            
           }
  
 else if(exp[i]=='/'){
  
    char op=S[top];
    
          if(op=='+'||op=='-'){
           
          push(exp[i]);
          
          }
          
          else if(op=='*'||op=='/'||op=='%')
          {
            insert(op);
          
         pop();
            
       push(exp[i]);
          }
           else
           {
             push(exp[i]);
           }
      
         }
        
  else if(exp[i]=='%'){
   
   char op=S[top];
     
        if(op=='+'||op=='-'){
             
            push(exp[i]);
            
            }
            
            else if(op=='*'||op=='/'||op=='%')
            {
              insert(op);
            
           pop();
              
         push(exp[i]);
            }
            
            else{
              push(exp[i]);
            }
            
             
          
         }
         
 else if(exp[i]=='^'){
   
   char op=S[top];
     
        if(op=='+'||op=='-'||op=='/'||op=='%'||op=='*'){
             
            push(exp[i]);
            
            }
          else{
            
             push(exp[i]);
          }
         }
   else if(exp[i]==')'){
   
          while(!empty()){
           
          char op=S[top];
            
           
          if(S[top]=='(' && top!=0){
          
           pop();
             }
          else if(top!=0){   
         insert(op);
            
         pop();
          }
          else if(top==0){
            break;
          }
           }
           }
           

   else{
     
        insert(exp[i]);
 
  }
   }
 }
   
   
    /**
  * @FunctionName: insert
  * @Description: 
  *     Adds a character to the queue
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */
   
   
 void insert(char c){
   
 if(QFull()){
    
  cout<<"Queue Full!"<<endl;
     
 return;
    }
   
 Q[Rear] = c;
 
   Rear = (Rear + 1) % size;
   
 NumItems++;
    return;
  }
  
  /**
  * @FunctionName: Pop
  * @Description: 
  *     Returns a character from the top of the queue
  * @Params:
  *    None 
  * @Returns:
  *    void
  */
   
char Pop(){
  
  if(QEmpty()){
     
 cout<<"Queue Empty!"<<endl;
     
 return false;
    }
   
 char Temp = Q[Front];
  
  Front = (Front + 1) % size;
    
NumItems--;
    
return Temp;
  }
  
  
  /**
  * @FunctionName: QEmpty
  * @Description: 
  *     Checks to see if queue is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */
  
 
 bool QEmpty(){
  
  return (NumItems == 0);
 
 }
 
 
 /**
  * @FunctionName: QFull
  * @Description: 
  *     Checks if queue is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */
 
 bool QFull(){
   
 return (NumItems == size);
 
 }
  
  
/**
  * @FunctionName: push
  * @Description: 
  *     Adds a character to the stack
  * @Params:
  *    char c - character to add 
  * @Returns:
  *    void
  */  
  
  

 void push(char x){
 
   if(!full()){
  
    S[++top] = x;
    
  //cout<<"top"<<top<<endl;
     
 
   }else{
    
  cout<<"Stack Overflow!"<<endl;
    
}
  }
  

 /**
  * @FunctionName: pop
  * @Description: 
  *     Returns a character from the top of the stack
  * @Params:
  *    None 
  * @Returns:
  *    void
  */

 
 char pop(){
   
 if(!empty())
     
 return S[top--];
   
 else
    
  return -1;
  
}


/**
  * @FunctionName: empty
  * @Description: 
  *     Checks to see if stack is empty.
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if empty / false otherwise
  */


 
 bool empty(){
   
 return top == -1;
  
}
  
  
 /**
  * @FunctionName: full
  * @Description: 
  *     Checks if stack is full
  * @Params:
  *    None 
  * @Returns:
  *    bool - true if full / false otherwise
  */  
  
bool full(){
 
   return top == size-1;
 
 }
 
 /**
  * @FunctionName: printStack
  * @Description: 
  *     Prints stack to stdout for debugging purposes
  * @Params:
  *    None
  * @Returns:
  *    void
  */
 
  
 void printStack(){
   
 for(int i=top;i>=0;i--){
   
   cout<<S[i]<<" ";
    }
   
 cout<<endl;
  }
  
  
  /**
  * @FunctionName: printqueue
  * @Description: 
  *     Prints queue to stdout for debugging purposes
  * @Params:
  *    string exp:to determine the size of queue based on exp given
  * @Returns:
  *    void
  */
  

  void printqueue(string exp){
   
 int l=0;
   
 for(int j=0;j<exp.length();j++){
     
 if(exp[j]=='('||exp[j]==')'){
      
  cout<<"";
    
  }
      else{
     
   l=l+1;
     
 }
   
 }
   
 
   for(int i=Front,j=0;j<NumItems;j++,i=(i+1)%l){
    
  cout<<""<<" ";
  
  }
    cout<<endl;
  
}
  
  
  
  /**
  * @FunctionName: postfix
  * @Description: 
  *     Evaluates postfix expression and store result in stack
  * @Params:
  *    None
  * @Returns:
  *    void
  */
  
  
  
  void postfix()
  {
    
  int result=0;
   
 for(int i=Front,j=0;j<NumItems;j++,i=(i+1)%size){
     
 char op=Q[i];
      
    
  if(op=='+'){
      
      char op1=S[top];
      
      pop();
       
      char op2=S[top];
      
      int a=int(op1-48);
      
      int b=op2-48;
      
      pop();
      
      int result=a+b;
      
      char r;
      
      stringstream ss;
      
      ss<<result;
       
      ss>>r;
      
      push(r);

   
      }
    
  else if(op=='*'){
     
      char op1=S[top];
      
      pop();
      
      char op2=S[top];
      
      int a=op1-48;
      
      int b=op2-48;
      
      pop();
      
      int result=a*b;
       
      char r;
      
      stringstream ss;
      
      ss<<result;
      
      ss>>r;
        
      push(r);
        
  
    }
     
 else if(op=='/'){
    
        char op1=S[top];
        
         pop();
        
        char op2=S[top];
        
        int b=op1-48;
         
        int a=op2-48;
        
        
         pop();
          
        
        result=(a/b);
        
        char r;
         
        stringstream ss;
        
        ss<<result;
        
        ss>>r;
        
        push(r);
          
 
     }
      
 else if(op=='%'){
     
          char op1=S[top];
          
          pop();
          
          char op2=S[top];
          
          int b=op1-48;
          
          int a=op2-48;
          
          
          pop();
          
          
          result=(a%b);
          
          char r;
          
          stringstream ss;
          
          ss<<result;
          
          ss>>r;
          
          push(r);
     
   
      }
      
      else if(op=='^'){
     
          char op1=S[top];
          
          pop();
          
          char op2=S[top];
          
          int b=op1-48;
          
          int a=op2-48;
          
          pop();
          
          int result=pow(a,b);
           
          char r;
          
          stringstream ss;
          
          ss<<result;
          
          ss>>r;
            
          push(r);
            
  
    }
     
      
    
  else if(op=='-'){
   
          char op1=S[top];
          
          pop();
          
          char op2=S[top];
          
          int b=op1-48;
          
          int a=op2-48;
          
          pop();
          
          
          int result=a-b;
          
          char r;
          
          stringstream ss;
          
          ss<<result;
          
          ss>>r;
          
          push(r);

   
      }
      
      
      

      else{
       
     
         push(op);
   
   }
  
    
      
    }
 
   
  }
};


int main()
{
 
  calculator c(25);
  
  string exp;
  int itr;
  char *A;
  ifstream ifile;  
  ofstream ofile;
  ifile.open("exp.txt");
  ifile>>itr;  
  cout<<"";
  while(itr!=0){
  
  ifile>>exp;
  
  int len=exp.length();
  
  A = new char[len];
  
  exp=exp+")";
  len=len+1;
 
 
 
  c.push('(');
  
  c.infix(exp);
 
 //c.printStack();
 
//c.printqueue(exp);
 
  c.pop();
  c.printStack();

 c.printqueue(exp);

 exp = exp.substr(0, exp.size()-1);
 cout<<exp<<" =";
 c.postfix();
 
 c.printStack();
 
 
 while ( !c.empty() )
{
  
    c.pop();
}
while ( !c.QEmpty() )
{
   
    c.Pop();
}
 
 itr=itr-1;
 
}
  return 0;
  
}
